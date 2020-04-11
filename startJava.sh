#!/bin/sh

LD_PRELOAD="/usr/lib/libCTRE_PhoenixPlatform_socketcan.so /usr/lib/libCTRE_PhoenixCanutils.so" java -Xcomp -Xmx128M -XX:+UseG1GC -XX:MaxGCPauseMillis=10 -XX:InitiatingHeapOccupancyPercent=50 -cp ".:./lib/api-java-5.14.1.jar" Example
