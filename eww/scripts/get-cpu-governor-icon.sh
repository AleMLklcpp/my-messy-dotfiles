#!/bin/bash
output=$(cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor)

if [ "$output" = "powersave" ]; then
    echo 󰾆
elif [ "$output" = "schedutil" ]; then
    echo 󰾅
else
    echo 󰓅
fi
