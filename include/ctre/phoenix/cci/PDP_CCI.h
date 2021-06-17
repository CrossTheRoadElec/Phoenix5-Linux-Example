#pragma once

#include "ctre/phoenix/cci/CCI.h"
#include "ctre/phoenix/ErrorCode.h"

CCIEXPORT ctre::phoenix::ErrorCode c_PDP_GetValues(int deviceID, double *voltage, double currents[], int currentCapacity, int *currentsFilled);