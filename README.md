# mbed-libmezi

### 一些mbed类库
  
**警告: 某些重载构造函数的预设针脚名(PinName)只能用于NXP LPC1768开发板，如果您使用不同的硬件平台，请在创建对象时使用正确的PinName，否则可能导致硬件损坏。** 

### 现已支持：
**max7219 / MAX7219 8x8点阵LED驱动器**
- 封装自SPI接口，支持多路显示。

**l298n / L298N 两相步进电机驱动器**
- 封装自GPIO，支持同时控制多路电机。
- 需要mbed OS库支持多线程操作。该库仍在活跃开发且可能不稳定，头文件包含也可能不再适用。如果您仍然觉得不满意，可以用ticker写一个。

**hcsr04 / HC-SR04 超声距离传感器**
- 使用中断，程序设计量程0.02至8.50m。
- 使用时请务必使用5V供电，若使用3.3V会无法收到返回信号。
  
**amux16 / 16路模拟信号 多路复用器**
- 只有一个模拟输入？不存在的。

**hmc5883l / HMC5883L IIC接口 三轴磁场计**
- 封装自I2C，可手动输入校准值,自动校准tan90°
- 提供原始数据输出接口，可根据该数据算出椭圆/球的偏移及比例，构造函数已加入比例较正，未实现偏移校正。
  
**ds1307 / DS1307 RTC时钟芯片**  
- 封装自I2C，内建mydate_t数据结构。
  
**xy160d / XY160D 直流电机驱动器**
- 封装自PWM，已加入正反转间刹车功能。
- 该类仅对应一路电机驱动，对于一块具有两路驱动XY160D驱动板，可以有两个对象。
  
**tcs230 / TCS230 颜色传感器**  
- 使用中断，支持RGB/HSV两种颜色识别模式。

**exskl_psensor 莫合实业外骨骼传感器**
- exskl_psensor为纯数据类，需要与xy160d+amux16配合使用。

**exskl_glove 莫合实业外骨骼传感器-动作追踪型**
- exskl_glove为纯数据类，需要与xy160d+amux16配合使用。

### 即将完成
**mpu6050 / MPU6050 电子加速度计-陀螺仪**  
**hc12 / HC-12 汇承433MHz无线串口**  

