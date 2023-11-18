#!/bin/bash
if bspc query -T -d focused | grep -q "client"; then
    echo close
else
    echo open
fi
