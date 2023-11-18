#!/bin/bash
if [ $1 = "0" ]; then
    governor="powersave"
elif [ $1 = "1" ]; then
    governor="schedutil"
else
    governor="performance"
fi

echo $governor
echo $(rofi -dmenu -password -p "Enter Root Password:") | sudo -S cpupower frequency-set -g $governor
pkill -x rofi