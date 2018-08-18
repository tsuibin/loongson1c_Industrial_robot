#!/bin/sh


echo 1700000 > /sys/class/pwm/pwmchip0/pwm5/duty_cycle
echo 1700000 > /sys/class/pwm/pwmchip0/pwm4/duty_cycle
usleep 100000
echo 950000 > /sys/class/pwm/pwmchip0/pwm0/duty_cycle
usleep 100000
echo 700000 > /sys/class/pwm/pwmchip0/pwm1/duty_cycle
usleep 100000

echo 1700000 > /sys/class/pwm/pwmchip0/pwm0/duty_cycle
usleep 100000

echo 1650000 > /sys/class/pwm/pwmchip0/pwm5/duty_cycle
echo 1675000 > /sys/class/pwm/pwmchip0/pwm4/duty_cycle
usleep 100000
echo 1600000 > /sys/class/pwm/pwmchip0/pwm5/duty_cycle
echo 1650000 > /sys/class/pwm/pwmchip0/pwm4/duty_cycle
usleep 100000
echo 1550000 > /sys/class/pwm/pwmchip0/pwm5/duty_cycle
echo 1625000 > /sys/class/pwm/pwmchip0/pwm4/duty_cycle
usleep 100000
echo 1500000 > /sys/class/pwm/pwmchip0/pwm5/duty_cycle
echo 1600000 > /sys/class/pwm/pwmchip0/pwm4/duty_cycle
usleep 100000
echo 1450000 > /sys/class/pwm/pwmchip0/pwm5/duty_cycle
echo 1575000 > /sys/class/pwm/pwmchip0/pwm4/duty_cycle
usleep 100000
echo 1400000 > /sys/class/pwm/pwmchip0/pwm5/duty_cycle
echo 1550000 > /sys/class/pwm/pwmchip0/pwm4/duty_cycle
usleep 100000
echo 1350000 > /sys/class/pwm/pwmchip0/pwm5/duty_cycle
echo 1525000 > /sys/class/pwm/pwmchip0/pwm4/duty_cycle
usleep 100000
echo 1300000 > /sys/class/pwm/pwmchip0/pwm5/duty_cycle
echo 1500000 > /sys/class/pwm/pwmchip0/pwm4/duty_cycle
usleep 100000

echo 1200000 > /sys/class/pwm/pwmchip0/pwm1/duty_cycle
usleep 500000
echo 700000 > /sys/class/pwm/pwmchip0/pwm1/duty_cycle
usleep 500000
echo 1200000 > /sys/class/pwm/pwmchip0/pwm1/duty_cycle
usleep 500000
echo 700000 > /sys/class/pwm/pwmchip0/pwm1/duty_cycle
usleep 500000
echo 1200000 > /sys/class/pwm/pwmchip0/pwm1/duty_cycle
usleep 500000
echo 700000 > /sys/class/pwm/pwmchip0/pwm1/duty_cycle
usleep 500000

echo 1350000 > /sys/class/pwm/pwmchip0/pwm5/duty_cycle
echo 1525000 > /sys/class/pwm/pwmchip0/pwm4/duty_cycle
usleep 100000
echo 1400000 > /sys/class/pwm/pwmchip0/pwm5/duty_cycle
echo 1550000 > /sys/class/pwm/pwmchip0/pwm4/duty_cycle
usleep 100000
echo 1450000 > /sys/class/pwm/pwmchip0/pwm5/duty_cycle
echo 1575000 > /sys/class/pwm/pwmchip0/pwm4/duty_cycle
usleep 100000
echo 1500000 > /sys/class/pwm/pwmchip0/pwm5/duty_cycle
echo 1600000 > /sys/class/pwm/pwmchip0/pwm4/duty_cycle
usleep 100000
echo 1550000 > /sys/class/pwm/pwmchip0/pwm5/duty_cycle
echo 1625000 > /sys/class/pwm/pwmchip0/pwm4/duty_cycle
usleep 100000
echo 1600000 > /sys/class/pwm/pwmchip0/pwm5/duty_cycle
echo 1650000 > /sys/class/pwm/pwmchip0/pwm4/duty_cycle
usleep 100000
echo 1650000 > /sys/class/pwm/pwmchip0/pwm5/duty_cycle
echo 1675000 > /sys/class/pwm/pwmchip0/pwm4/duty_cycle
usleep 100000
echo 1700000 > /sys/class/pwm/pwmchip0/pwm5/duty_cycle
echo 1700000 > /sys/class/pwm/pwmchip0/pwm4/duty_cycle
usleep 100000

echo 1700000 > /sys/class/pwm/pwmchip0/pwm5/duty_cycle
echo 1700000 > /sys/class/pwm/pwmchip0/pwm4/duty_cycle
usleep 100000
echo 950000 > /sys/class/pwm/pwmchip0/pwm0/duty_cycle
usleep 100000
echo 700000 > /sys/class/pwm/pwmchip0/pwm1/duty_cycle
usleep 100000

exit 0
