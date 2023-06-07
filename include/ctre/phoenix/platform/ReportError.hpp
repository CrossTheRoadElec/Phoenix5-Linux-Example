/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#include "ctre/phoenix/export.h"
#include <stdint.h>

namespace ctre
{
    namespace phoenix
    {
        namespace platform
        {

            CTREXPORT void ReportError(int isError, int32_t errorCode, int isLVCode, const char *details,
                                       const char *location, const char *callStack);

        } // namespace platform
    } // namespace phoenix
} // namespace ctre
