/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#include "ctre/phoenix/export.h"
#include "ctre/phoenix6/networking/interfaces/DeviceEncoding_Interface.h"
#include "stdint.h"

#ifdef __cplusplus
extern "C"
{
#endif
    CTREXPORT int c_ctre_phoenix6_SetUpdateFrequency(Context context, const char *network, uint32_t deviceHash, uint16_t spn, double frequencyHz, double timeoutSeconds);
#ifdef __cplusplus
}
#endif
