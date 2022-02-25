#pragma once

#include <string>
#include "ctre/phoenix/cci/CCI.h"
#include "ctre/phoenix/ErrorCode.h"


extern "C" {
	CCIEXPORT void* c_Orchestra_Create0();
	CCIEXPORT ctre::phoenix::ErrorCode c_Orchestra_Destroy(void* handle);
    
	CCIEXPORT ctre::phoenix::ErrorCode c_Orchestra_LoadMusic(void* handle, const char *filePath);
	CCIEXPORT ctre::phoenix::ErrorCode c_Orchestra_Play(void* handle);
	CCIEXPORT ctre::phoenix::ErrorCode c_Orchestra_Stop(void* handle);
	CCIEXPORT ctre::phoenix::ErrorCode c_Orchestra_Pause(void* handle);
	CCIEXPORT ctre::phoenix::ErrorCode c_Orchestra_IsPlaying(void* handle, bool &playing);
	CCIEXPORT ctre::phoenix::ErrorCode c_Orchestra_GetCurrentTime(void* handle, uint32_t &currentTime);

	CCIEXPORT ctre::phoenix::ErrorCode c_Orchestra_ClearInstruments(void* handle);
	CCIEXPORT ctre::phoenix::ErrorCode c_Orchestra_AddInstrument(void* handle, void* instrument);
	
	CCIEXPORT ctre::phoenix::ErrorCode c_Orchestra_GetDescription(void *handle, char * toFill, int toFillByteSz, size_t * numBytesFilled);
}