/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#include "ctre/phoenix/export.h"
#include "ctre/phoenix6/networking/interfaces/DataStructs_Interface.h"
#include "ctre/phoenix6/networking/interfaces/DeviceEncoding_Interface.h"
#include "stddef.h"

#ifdef __cplusplus
extern "C"
{
#endif

    CTREXPORT int c_ctre_phoenix6_SetUpdateFrequency(Context context, const char *network, uint32_t deviceHash, uint16_t spn, double frequencyHz, double timeoutSeconds);
    CTREXPORT int c_ctre_phoenix6_SetUpdateFrequencyForAll(Context context, const network_signal_t *signals_list, size_t num_signals, double frequencyHz, double timeoutSeconds);
    CTREXPORT double c_ctre_phoenix6_GetUpdateFrequency(const char *network, uint32_t deviceHash, uint16_t spn);
    CTREXPORT int c_ctre_phoenix6_OptimizeUpdateFrequencies(Context context, const char *network, uint32_t deviceHash, double optimizedFreqHz, double timeoutSeconds);
    CTREXPORT int c_ctre_phoenix6_ResetUpdateFrequencies(Context context, const char *network, uint32_t deviceHash, double timeoutSeconds);
    CTREXPORT int c_ctre_phoenix6_ResendUpdateFrequencies(Context context, const char *network, uint32_t deviceHash, double timeoutSeconds);

#ifdef __cplusplus
}
#endif
