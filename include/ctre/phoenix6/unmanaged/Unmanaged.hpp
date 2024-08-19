/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#include "ctre/phoenix/export.h"
#include <cstdint>

namespace ctre {
namespace phoenix {
namespace unmanaged {
	/**
	 * \brief Feed the robot enable.
	 * This function does nothing on a roborio during FRC use.
	 *
	 * \param timeoutMs Timeout before disabling
	 */
	CTREXPORT void FeedEnable(int timeoutMs);
	/**
	 * \returns true if enabled
	 */
	CTREXPORT bool GetEnableState();
	/**
	 * \brief Sets whether to enable transmitting
	 * This function does nothing on a roborio during FRC use.
	 *
	 * \param en True enables transmitting
	 */
	CTREXPORT void SetTransmitEnable(bool en);
	/**
	 * \returns true if transmitting is enabled
	 */
	CTREXPORT bool GetTransmitEnable();
	/**
	 * \returns Phoenix version
	 */
	CTREXPORT int GetPhoenixVersion();
	CTREXPORT void LoadPhoenix();

    CTREXPORT int GetApiCompliancy();
}
}
}
