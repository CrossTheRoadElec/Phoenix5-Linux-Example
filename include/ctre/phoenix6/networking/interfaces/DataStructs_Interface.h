/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once
#include <stdint.h>

typedef struct _return_values_t
{
    double outValue;
    uint32_t unitsKey;
    char const *units;
    double hwtimestampSeconds;
    double swtimestampSeconds;
    double ecutimestampSeconds;
    int error;
} return_values_t;

typedef struct _signal_values_t
{
    uint32_t deviceHash;
    uint32_t spn;
} signal_values_t;

typedef struct _network_signal_t {
    const char *network;
    signal_values_t signal;
} network_signal_t;
