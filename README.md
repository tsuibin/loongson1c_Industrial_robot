# loongson1c_Industrial_robot
WSYU Linux Group for HACKTHON 2018

#舵机参数
```
int pwm_enable; //舵机使能标志位
int pwm_gpio; //舵机角度控制pin
int period;//周期
int high_us;//高电平脉宽，决定舵机转角，限制在0.5ms到2.5ms之间
```

#测试舵机 
```
write argvs to /sys/class/pwm/pwmchip0/pwm[x]/duty_cycle
```
[x] is 0 ~ 5
