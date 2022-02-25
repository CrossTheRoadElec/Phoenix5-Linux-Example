#pragma once

#include <cstring>

constexpr size_t kCANivoreMaxStrLen = 100;

typedef struct _canivore_device_t {
	char status[kCANivoreMaxStrLen];
	char name[kCANivoreMaxStrLen];
	char serial_num[kCANivoreMaxStrLen];
	char firm_vers[16];
	char discoveryStatus[kCANivoreMaxStrLen];
} canivore_device_t;
