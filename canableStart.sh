#!/bin/bash

interface=can0
if [ $# -gt 0 ]; then
    interface=$1
fi

sudo ip link set $interface type can bitrate 1000000
sudo ifconfig $interface up
sudo ifconfig can0 txqueuelen 1000
