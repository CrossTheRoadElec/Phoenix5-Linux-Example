/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#include "ctre/phoenix/StatusCodes.h"
#include "ctre/phoenix/export.h"

#ifdef __cplusplus
extern "C"
{
#endif
    CTREXPORT int c_Logger_Log(int code, const char *device, const char *func, int hierarchy, const char *stacktrace);
#ifdef __cplusplus
}
#endif
