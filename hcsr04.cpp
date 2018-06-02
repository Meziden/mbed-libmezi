#include "mbed.h"
#include "hcsr04.h"

hcsr04::hcsr04(PinName trig_pin, PinName recv_pin):trigger(trig_pin),receiver(recv_pin)
{
    distance  = 0;
    done = 0;
}

float hcsr04::getdistance()
{
    done = 0;
    trigger = 1;
    wait_us(10);
    
    //setting up functions
    receiver.rise(callback(this,&hcsr04::callback_rising));
    receiver.fall(callback(this,&hcsr04::callback_falling));
    receiver.enable_irq();
    timeout.attach(callback(this,&hcsr04::callback_timeout),HCSR04_TIMEOUT);
    trigger = 0;
    
    while(done == 0)
        continue;
    
    return distance;
}

void hcsr04::callback_timeout()
{
    receiver.rise(NULL);
    receiver.fall(NULL);
    distance = -1;
    done = -1;
    timeout.detach();
}

void hcsr04::callback_rising()
{
    //timeout.detach();
    timer.reset();
    timer.start();
}

void hcsr04::callback_falling()
{
    timer.stop();
    distance = (timer.read_us()) * 0.5 * 0.00034;
    done = 1;
}
