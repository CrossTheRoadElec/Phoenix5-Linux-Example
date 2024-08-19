/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#include "ctre/phoenix/export.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C" {
#endif
/**
 * \brief Feed the robot enable.
 * This function does nothing on a roborio during FRC use.
 *
 * \param timeoutMs Timeout before disabling
 */
CTREXPORT void c_ctre_phoenix6_unmanaged_feed_enable(int timeoutMs);
/**
 * \returns true if enabled
 */
CTREXPORT bool c_ctre_phoenix6_unmanaged_get_enable_state(void);
/**
 * \brief Sets whether to enable transmitting
 * This function does nothing on a roborio during FRC use.
 *
 * \param en True enables transmitting
 */
CTREXPORT void c_ctre_phoenix6_unmanaged_set_transmit_enable(bool en);
/**
 * \returns true if transmitting is enabled
 */
CTREXPORT bool c_ctre_phoenix6_unmanaged_get_transmit_enable(void);
/**
 * \returns Phoenix version
 */
CTREXPORT int c_ctre_phoenix6_unmanaged_get_phoenix_version(void);
CTREXPORT void c_ctre_phoenix6_unmanaged_load_phoenix(void);
CTREXPORT int c_ctre_phoenix6_unmanaged_get_api_compliancy(void);

#ifdef __cplusplus
}
#endif
