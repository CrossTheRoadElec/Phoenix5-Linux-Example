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
	typedef struct _canframe_t {
		uint32_t arbID; //!< ArbID of the CAN frame.
		uint32_t timeStampUs; //!< Timestamp if receive event.  Zero otherwise.
		uint8_t data[64]; //!< Data bytes
		uint32_t flags; //!< Zero for now.  Can be used for detecting arbID type (29bit vs 11bit).
		uint8_t len; //!< Number of bytes in payload
	} canframe_t;

} //namespace can
} //namespace platform
} //namespace phoenix
} //namespace ctre
