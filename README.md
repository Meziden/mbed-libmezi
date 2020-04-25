# mbed-libmezi

### 一些mbed类库, 现已支持：
  
**SerialCLI / ANSI终端-命令行界面 3.0**
- 内置哈希-溢出表，时间复杂度O(1)的函数匹配，支持int (\*)(int, char**)型回调函数。
- 使用示例见examples/main_SerialCLI.cpp
- \[正在进行\]：指令历史与VT102光标操作支持。
- \[已修复\]: mbed OS 5上SerialCLI::rxirq_clb()与Serial::attach()不兼容。

**PID / 单路PID控制器**
- 将float geterror(void)函数与void setctl(float signal_ctl)函数在该控制器初始化时传入，即可进行PID控制。
- 示例：`PID myPIDController(geterror, setctl)`

**max7219 / MAX7219 8x8点阵LED驱动器**
- 封装自SPI接口，支持多路显示。

**ssh1106 / SSH1106 128x64 1.3英寸OLED显示屏 v2.1**
- 使用半异步SPI数据传输，帧率提高。
- 修复了和SerialCLI v3.0在低SPI速率下的兼容性问题。
- 具有位置可选的ASCII字符显示与简单的图形绘制填充功能。
- \[正在进行\]: Spectrum UI与动画效果集成。

**wsedp4in2 / Waveshare 4.2英寸E-INK显示屏**(进行中)
- 具有位置可选的ASCII字符显示与简单的图形绘制填充功能。

**joystick424 / 由 424强 提供的2路模拟+1路数字摇杆**
- 支持即时读取
- 可选事件驱动模式。

**spectrum / Spectrum 用于简易用户界面的树形数据节点**
- 把功能名与执行函数/界面预览函数构成的节点组织为一棵树，以便在用户界面中导航。
- 支持Daemon类型节点，适用于后台服务。

**l298n / L298N 两相步进电机驱动器**
- 封装自GPIO，支持同时控制多路电机。
- 需要mbed OS库支持多线程操作。该库仍在活跃开发且可能不稳定，头文件包含也可能不再适用。如果您仍然觉得不满意，可以用ticker写一个。

**hcsr04/hcsr04_fullasync / HC-SR04 超声距离传感器**
- 使用中断，程序设计量程0.02至5.30m。
- 使用时请务必使用5V供电，若使用3.3V会无法收到返回信号。
  
**mpu6050 / MPU6050 电子加速度计-陀螺仪** 
- 支持直接读取三轴加速度与三轴角速度。
- 暂不支持姿态检测。 
  
**imujy61 / JY61 经过社会主义改造的MPU6050**
- 直接读取角度，使用uart接收中断异步更新。精彩时刻，无需等待。
- mbed::Serial类以及 SerialBase类近期在整合Callback类，可能出现函数参数匹配问题。
  
**encoder / Coding Disk GPIO码盘**
- 使用中断，仅使用少量处理器时间。
  
**amux16 / 16路模拟信号 多路复用器**
- 只有一个模拟输入？不存在的。

**hmc5883l / HMC5883L IIC接口 三轴磁场计**
- 封装自I2C，可手动输入校准值,自动校准tan90°
- 提供原始数据输出接口，可根据该数据算出椭圆/球的偏移及比例，构造函数已加入比例较正，未实现偏移校正。
  
**ds1307 / DS1307 RTC时钟芯片**  
- 封装自I2C，内建mydate_t数据结构。

**lm35 / LM35温度传感器**
- 计划中
  
**xy160d / XY160D 直流电机驱动器**
- 封装自PWM，已加入正反转间刹车功能。
- 该类仅对应一路电机驱动，对于一块具有两路驱动XY160D驱动板，可以有两个对象。
  
**tcs230 / TCS230 颜色传感器**  
- 使用中断，支持RGB/HSV两种颜色识别模式。

**hand_exskl 莫合实业手部外骨骼驱动**
- 状态机+PID混合电机调度。
- 依赖xy160d提供H桥驱动函数库。

**utils 杂项**
- 复数类型，FFT...

