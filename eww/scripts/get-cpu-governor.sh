#!/bin/bash
output=$(cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor)

if [ "$output" = "powersave" ]; then
    echo 0
elif [ "$output" = "schedutil" ]; then
    echo 1
else
    echo 2
fi