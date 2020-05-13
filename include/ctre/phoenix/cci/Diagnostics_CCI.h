#pragma once

#include <stdint.h>
#include "ctre/phoenix/cci/CCI.h"

extern "C"{
    CCIEXPORT void c_Phoenix_Diagnostics_Create();
    CCIEXPORT void c_Phoenix_Diagnostics_Create1(int port);
    CCIEXPORT void c_Phoenix_Diagnostics_SetSecondsToStart(int secondsToStart);
}