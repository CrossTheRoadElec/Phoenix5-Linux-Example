#!/bin/bash

sudo rm -rf bin
sudo rm -rf build
cmake -H. -Bbuild
