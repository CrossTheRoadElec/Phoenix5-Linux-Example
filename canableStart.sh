#!/bin/sh

sudo ip link set can0 type can bitrate 1000000
sudo ifconfig can0 up
