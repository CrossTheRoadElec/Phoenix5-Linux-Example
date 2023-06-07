/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#include "ctre/phoenix/export.h"
#include "stdint.h"

#ifdef __cplusplus
extern "C"
{
#endif

    CTREXPORT void c_ctre_phoenix_report_error(int isError, int32_t errorCode, int isLVCode, const char *details,
                                               const char *location, const char *callStack);

    CTREXPORT void c_ctre_phoenix_get_status_string(int statusCode, char *toFill, uint32_t toFillLength);

#ifdef __cplusplus
}
#endif
