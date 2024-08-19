/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#include "ctre/phoenix/StatusCodes.h"
#include "ctre/phoenix/export.h"
#include "ctre/phoenix6/networking/interfaces/DeviceEncoding_Interface.h"
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

    CTREXPORT int c_ctre_phoenix6_set_configs(
        int context,
        const char *network,
        int deviceHash,
        double timeoutSeconds,
        const char *values,
        uint32_t value_len,
        bool futureProofConfigs,
        bool overrideIfDuplicate,
        bool useDid);

    CTREXPORT int c_ctre_phoenix6_get_configs(
        int context,
        const char *network,
        int deviceHash,
        double timeoutSeconds,
        char **str,
        bool useDid);

    CTREXPORT int c_ctre_phoenix6_get_configs_no_malloc(
        Context context,
        const char *network,
        int deviceHash,
        double timeoutSeconds,
        char *str,
        uint32_t str_len,
        bool useDid);

#ifdef __cplusplus
}
#endif
