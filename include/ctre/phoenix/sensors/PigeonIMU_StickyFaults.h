/* Copyright (C) Cross The Road Electronics 2024 */
#pragma once

#include <cstdint>

namespace ctre {
namespace phoenix {
namespace sensors {

/**
 * Sticky faults available to Pigeon
 */
struct PigeonIMU_StickyFaults {

	/**
	 * @return true if any faults are tripped
	 */
	bool HasAnyFault() const {
		return 	false;
	}
	/**
	 * @return Current fault list as a bit field
	 */
	uint64_t ToBitfield() const {
        return 0;
	}
	/**
	 * Updates current fault list with specified bit field of faults
	 *
	 * @param bits bit field of faults to update with
	 */
	void Update(uint64_t bits) {
	}
	/**
	 * Creates fault list with specified bit field of faults
	 * 
	 * @param bits bit field of faults to update with
	 */
	PigeonIMU_StickyFaults(uint64_t bits) {
		Update(bits);
	}
	PigeonIMU_StickyFaults() {
		Update(0); // Default everything to false
	}
};

} // sensors
} // phoenix
} // ctre
