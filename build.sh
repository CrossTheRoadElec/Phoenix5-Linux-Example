#!/bin/bash

cmake -H. -Bbuild

sudo cmake --build build -- -j3
