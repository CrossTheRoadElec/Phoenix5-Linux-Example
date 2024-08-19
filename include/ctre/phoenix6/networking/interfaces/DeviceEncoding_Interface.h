/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#include "ctre/phoenix/Context.h"
#include "ctre/phoenix/export.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif
    CTREXPORT int c_ctre_phoenix6_encode_device(int deviceId, const char *model, const char *canbus, uint32_t *deviceEncoding);
#ifdef __cplusplus
}
#endif
