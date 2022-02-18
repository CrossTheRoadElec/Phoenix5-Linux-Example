#pragma once

#include <stdint.h>
#include "ctre/phoenix/export.h"

extern "C"{
    CTREXPORT void c_Phoenix_Diagnostics_Create();
    CTREXPORT void c_Phoenix_Diagnostics_Create1(int port);
    CTREXPORT void c_Phoenix_Diagnostics_SetSecondsToStart(int secondsToStart);
    CTREXPORT void c_Phoenix_Diagnostics_Dispose();
}