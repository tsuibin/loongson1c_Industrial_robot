#!/bin/sh

echo 0 > /sys/class/pwm/pwmchip0/export
echo 3 > /sys/class/pwm/pwmchip0/export
echo 4 > /sys/class/pwm/pwmchip0/export
echo 5 > /sys/class/pwm/pwmchip0/export
echo 2 > /sys/class/pwm/pwmchip0/export
echo 1 > /sys/class/pwm/pwmchip0/export
echo 1 > /sys/class/pwm/pwmchip0/pwm0/enable
echo 1 > /sys/class/pwm/pwmchip0/pwm3/enable
echo 1 > /sys/class/pwm/pwmchip0/pwm4/enable
echo 1 > /sys/class/pwm/pwmchip0/pwm5/enable
echo 1 > /sys/class/pwm/pwmchip0/pwm2/enable
echo 1 > /sys/class/pwm/pwmchip0/pwm1/enable
echo 20000000 > /sys/class/pwm/pwmchip0/pwm0/period
echo 20000000 > /sys/class/pwm/pwmchip0/pwm3/period
echo 20000000 > /sys/class/pwm/pwmchip0/pwm4/period
echo 20000000 > /sys/class/pwm/pwmchip0/pwm5/period
echo 20000000 > /sys/class/pwm/pwmchip0/pwm2/period
echo 20000000 > /sys/class/pwm/pwmchip0/pwm1/period
echo 950000 > /sys/class/pwm/pwmchip0/pwm0/duty_cycle
echo 1700000 > /sys/class/pwm/pwmchip0/pwm3/duty_cycle
echo 1700000 > /sys/class/pwm/pwmchip0/pwm4/duty_cycle
echo 1700000 > /sys/class/pwm/pwmchip0/pwm5/duty_cycle
echo 900000 > /sys/class/pwm/pwmchip0/pwm2/duty_cycle
echo 700000 > /sys/class/pwm/pwmchip0/pwm1/duty_cycle

exit 0
