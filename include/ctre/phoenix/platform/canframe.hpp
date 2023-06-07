/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#include <stdint.h>

namespace ctre {
namespace phoenix {
namespace platform {
namespace can {

	/**
	 * "plain old data" container for holding a CAN Frame Event.
	 * Assignment of this type resolves to a copy-by-value.
	 */
	struct canframe_t {
		uint32_t arbID; //!< ArbID of the CAN frame.
		uint64_t hwTimestampUs; //!< Hardware timestamp if receive event. Zero otherwise.
		uint64_t swTimestampUs; //!< Software timestamp if receive event. Zero otherwise.
		uint64_t ecuTimestampUs; //!< ECU timestamp if receive event. Zero otherwise.
		uint8_t data[64]; //!< Data bytes
		uint32_t flags; //!< CAN flags, such as FD and BRS
		uint8_t len; //!< Number of bytes in payload
	};

} //namespace can
} //namespace platform
} //namespace phoenix
} //namespace ctre
