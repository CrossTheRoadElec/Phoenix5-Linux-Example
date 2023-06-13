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

CTREXPORT int c_ctre_phoenix6_get_signal_simplified(
        /* Inputs */
        const char *network,
        int bWaitForUpdate,
        double timeoutSeconds,
        /* Arrays */
        uint32_t num_signals,
        const uint32_t *device_hashes, // Array of Device hashes, min size of num_signals
        const uint32_t *spns, // Array of spns, min size of num_signals
        /* Outputs */
        double *values, // Array of double returns, min size of num_signals
        double *hwTimestampSeconds, // Array of timestamps, min size of num_signals
        double *swTimestampSeconds, // Array of timestamps, min size of num_signals
        double *ecuTimestampSeconds // Array of timestamps, min size of num_signals
    );

CTREXPORT int c_ctre_phoenix6_get_signal_unit(
        uint16_t spn,
        char *unit_c_string, // Array of chars that function fills
        uint16_t max_size); // Make sure labview passes at least 80 chars

#ifdef __cplusplus
}
#endif
