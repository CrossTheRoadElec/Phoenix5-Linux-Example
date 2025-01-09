/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#include "ctre/phoenix/export.h"

#ifdef __cplusplus
extern "C"
{
#endif

CTREXPORT double c_ctre_phoenix6_get_current_time_seconds();
CTREXPORT double c_ctre_phoenix6_get_system_time_seconds();
CTREXPORT int c_ctre_phoenix6_is_simulation();
CTREXPORT int c_ctre_phoenix6_is_replay();

#ifdef __cplusplus
}
#endif
