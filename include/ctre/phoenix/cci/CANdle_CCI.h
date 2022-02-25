#pragma once

#include "ctre/phoenix/cci/CCI.h"
#include "ctre/phoenix/ErrorCode.h"
#include <set>
#include <cstddef>

extern "C"{
    CCIEXPORT void *c_CANdle_Create1(int deviceNumber, const char* canbus);
    CCIEXPORT void c_CANdle_DestroyAll();
    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_Destroy(void *handle);
    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_GetDescription(void* handle, char* toFill, int toFillByteSz, size_t* numBytesFilled);
    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_GetLastError(void* handle);
    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_GetLastTimestamp(void* handle, double* timestamp);
    CCIEXPORT void c_CANdle_SetLastError(void *handle, int error);
    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_ConfigSetParameter(void *handle, int param, double value, uint8_t subValue, int ordinal, int timeoutMs);
    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_ConfigGetParameter(void *handle, int param, double *value, int ordinal, int timeoutMs);
    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_ConfigSetCustomParam(void *handle, int newValue, int paramIndex, int timeoutMs);
    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_ConfigGetCustomParam(void *handle, int *readValue, int paramIndex, int timoutMs);
    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_ConfigFactoryDefault(void *handle, int timeoutMs);
    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_GetFaults(void *handle, int * param) ;
    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_GetStickyFaults(void *handle, int * param) ;
    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_ClearStickyFaults(void *handle, int timeoutMs) ;
    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_GetFirmwareVersion(void *handle, int *firmwareVers);
    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_HasResetOccurred(void *handle, bool * hasReset);
    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_SetStatusFramePeriod(void *handle, int frame, uint8_t periodMs, int timeoutMs);
    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_GetStatusFramePeriod(void *handle, int frame, int *periodMs, int timeoutMs);
    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_SetControlFramePeriod(void *handle, int frame,	int periodMs);

    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_BlockSet(void *handle, int r, int g, int b, int w, int startIdx, int count);
    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_SetStandardAnimation(void *handle, int idx, double brightness, double speed, int numLed, int ledOffset, double param4,  double param5, bool reverseDirection, int animSlot);
    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_SetTwoSizeAnimation(void *handle, int idx, int r, int g, int b, int w, double speed, int numLed, int ledOffset, int direction, int size, int animSlot);
    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_ClearAnimation(void *handle, int animSlot);
    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_ModulateVBatOutput(void *handle, double percentModulation);

    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_GetBusVoltage(void *handle, double *voltage);
    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_Get5VRailVoltage(void *handle, double *voltage);
    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_GetCurrent(void *handle, double *current);
    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_GetTemperature(void *handle, double *temperature);
    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_GetVBatModulation(void *handle, double *modulation);
    CCIEXPORT ctre::phoenix::ErrorCode c_CANdle_GetMaxSimultaneousAnimationCount(void *handle, int *maxAnimationCount);
}
