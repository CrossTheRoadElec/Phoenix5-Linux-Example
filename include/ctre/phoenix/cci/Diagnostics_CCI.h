/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#include <stdint.h>
#include "ctre/phoenix/export.h"

#ifdef __cplusplus
extern "C" {
#endif

    /** Creates the Phoenix Diagnostic Server on the default port */
    CTREXPORT void c_Phoenix_Diagnostics_Create();
    /** Creates the Phoenix Diagnostic Server on the given port */
    CTREXPORT void c_Phoenix_Diagnostics_Create_On_Port(int port);
    /** Sets the number of seconds after which the Phoenix Diagnostic Server will start */
    CTREXPORT void c_Phoenix_Diagnostics_SetSecondsToStart(double secondsToStart);
    /** Allows the program to terminate early from a remote shutdown command (disabled by default) */
    CTREXPORT void c_Phoenix_Diagnostics_EnableEarlyShutdown();
    /** Safely disposes of the Phoenix Diagnostic Server */
    CTREXPORT void c_Phoenix_Diagnostics_Dispose();

#ifdef __cplusplus
}
#endif
