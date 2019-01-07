#!/bin/bash

sudo modprobe vcan

interface=vcan0
if [ $# -gt 0 ]; then
    interface=$1
fi

sudo ip link add dev $interface type vcan
sudo ip link set up $interface
