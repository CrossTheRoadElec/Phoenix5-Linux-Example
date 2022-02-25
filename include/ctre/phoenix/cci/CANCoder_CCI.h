#pragma once

#include "ctre/phoenix/cci/CCI.h"
#include "ctre/phoenix/ErrorCode.h"
#include "ctre/phoenix/sensors/AbsoluteSensorRange.h"
#include "ctre/phoenix/sensors/CANCoderStatusFrame.h"
#include "ctre/phoenix/sensors/CANCoderStickyFaults.h"
#include "ctre/phoenix/sensors/CANCoderFaults.h"
#include "ctre/phoenix/sensors/SensorVelocityMeasPeriod.h"
#include "ctre/phoenix/sensors/SensorInitializationStrategy.h"
#include "ctre/phoenix/sensors/MagnetFieldStrength.h"
#include "ctre/phoenix/sensors/SensorTimeBase.h"
#include <set>
#include <cstddef>


extern "C" {
	CCIEXPORT void* c_CANCoder_Create1(int deviceNumber, const char* canbus);
	CCIEXPORT void c_CANCoder_DestroyAll();
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_Destroy(void* handle);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_GetDescription(void* handle, char* toFill, int toFillByteSz, size_t* numBytesFilled);

	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_GetLastError(void* handle);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_GetLastUnitString(void* handle, char* toFill, int toFillByteSz, int* numBytesFilled);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_GetLastTimestamp(void* handle, double* timestamp);

	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_GetBusVoltage(void* handle, double* batteryVoltage);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_GetMagnetFieldStrength(void* handle, ctre::phoenix::sensors::MagnetFieldStrength* magnetFieldStrength);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_GetPosition(void* handle, double* pos);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_SetPosition(void* handle, double pos, int timeoutMs);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_SetPositionToAbsolute(void* handle, int timeoutMs);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_ConfigSensorDirection(void* handle, int bDirection, int timeoutMs);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_GetVelocity(void* handle, double* vel);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_GetAbsolutePosition(void* handle, double* pos);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_ConfigVelocityMeasurementPeriod(void* handle, int period, int timeoutMs);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_ConfigVelocityMeasurementWindow(void* handle, int window, int timeoutMs);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_ConfigAbsoluteSensorRange(void* handle, ctre::phoenix::sensors::AbsoluteSensorRange absoluteSensorRange, int timeoutMs);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_ConfigMagnetOffset(void* handle, double offsetDegrees, int timeoutMs);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_ConfigSensorInitializationStrategy(void* handle, ctre::phoenix::sensors::SensorInitializationStrategy initializationStrategy, int timeoutMs);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_ConfigFeedbackCoefficient(void* handle, double sensorCoefficient, const char* unitString, ctre::phoenix::sensors::SensorTimeBase sensortimeBase, int timeoutMs);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_ConfigSetParameter(void* handle, int param, double value, uint8_t subValue, int ordinal, int timeoutMs);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_ConfigGetParameter(void* handle, int param, double* value, int ordinal, int timeoutMs);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_ConfigGetParameter_6(void* handle, int32_t param, int32_t valueToSend, int32_t* valueRecieved, uint8_t* subValue, int32_t ordinal, int32_t timeoutMs);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_ConfigSetCustomParam(void* handle, int newValue, int paramIndex, int timeoutMs);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_ConfigGetCustomParam(void* handle, int* readValue, int paramIndex, int timoutMs);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_ConfigFactoryDefault(void* handle, int timeoutMs);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_GetFaults(void* handle, int* param);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_GetStickyFaults(void* handle, int* param);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_ClearStickyFaults(void* handle, int timeoutMs);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_GetFirmwareVersion(void* handle, int* firmwareVers);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_HasResetOccurred(void* handle, bool* hasReset);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_SetStatusFramePeriod(void* handle, int frame, uint8_t periodMs, int timeoutMs);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_GetStatusFramePeriod(void* handle, int frame, int* periodMs, int timeoutMs);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_ConfigGetVelocityMeasurementPeriod(void* handle, ctre::phoenix::sensors::SensorVelocityMeasPeriod* period, int timeoutMs);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_ConfigGetVelocityMeasurementWindow(void* handle, int* window, int timeoutMs);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_ConfigGetAbsoluteSensorRange(void* handle, ctre::phoenix::sensors::AbsoluteSensorRange* absoluteSensorRange, int timeoutMs);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_ConfigGetMagnetOffset(void* handle, double* offsetDegrees, int timeoutMs);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_ConfigGetSensorDirection(void* handle, int* bDirection, int timeoutMs);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_ConfigGetSensorInitializationStrategy(void* handle, ctre::phoenix::sensors::SensorInitializationStrategy* initializationStrategy, int timeoutMs);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_ConfigGetFeedbackCoefficient(void* handle, double* sensorCoefficient, int timeoutMs);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_ConfigGetFeedbackUnitString(void* handle, char* unitStringToFill, int toFillByteSz, int* numBytesFilled, int timeoutMs);
	CCIEXPORT ctre::phoenix::ErrorCode c_CANCoder_ConfigGetFeedbackTimeBase(void* handle, ctre::phoenix::sensors::SensorTimeBase* sensortimeBase, int timeoutMs);
}
