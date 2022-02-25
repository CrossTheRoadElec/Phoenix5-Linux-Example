#pragma once

#include <cstdint>

namespace ctre {
namespace phoenix {
namespace sensors {

/**
 * Sticky faults available to Pigeon
 */
struct Pigeon2_Faults {
	/**
	 * Device detects hardware failure
	 */
	bool HardwareFault;
	/**
	 * API error detected.  Make sure API and firmware versions are compatible.
	 */
	bool APIError;
	/**
	 * Device is under 6.5V
	 */
	bool UnderVoltage;
	/**
	 * Device was powered-on or reset while robot is enabled.
	 * Check your breakers and wiring.
	 */
	bool ResetDuringEn;
	/**
	 * The device rotated at a rate that exceeded its maximum.
	 * Increase the range or slow the rate of rotation.
	 */
	bool SaturatedRotVelocity;
	/**
	 * The device saw an acceleration that exceeded its maximum.
	 * Increase the range or avoid high-g events.
	 */
	bool SaturatedAccel;
	/**
	 * The device saw a magnetic field that exceeded its maximum.
	 * Keep the device far from strong magnetic fields.
	 */
	bool SaturatedMag;
	/**
	 * The Pigeon saw motion as soon as it booted, and didn't
	 *  attempt to self-test its features.
	 * This isn't an issue, but to prevent this don't turn the
	 *  robot on while moving it.
	 */
	bool BootIntoMotion;
	/**
	 * The magnetometer failed its self-test.
	 * This is likely due to hardware damage, oftentimes from
	 *  exposing the Pigeon to a very large magnetic field.
	 */
	bool MagnetometerFault;
	/**
	 * The gyro failed its self-test.
	 * This is likely due to hardware damage.
	 */
	bool GyroFault;
	/**
	 * The Accelerometer failed its self-test.
	 * This is likely due to hardware damage, oftentimes from
	 *  exposing the Pigeon to a very large impact.
	 */
	bool AccelFault;

	/**
	 * @return true if any faults are tripped
	 */
	bool HasAnyFault() const {
		return 	HardwareFault |
				APIError |
				UnderVoltage |
				ResetDuringEn |
				SaturatedRotVelocity |
				SaturatedAccel |
				SaturatedMag |
				BootIntoMotion |
				MagnetometerFault |
				GyroFault |
				AccelFault;
	}
	/**
	 * @return Current fault list as a bit field
	 */
	uint64_t ToBitfield() const {
		uint64_t commonFaults = 0;
		commonFaults |= HardwareFault ? 1 : 0; commonFaults <<= 1;
		commonFaults |= APIError ? 1 : 0; commonFaults <<= 1;
		commonFaults |= UnderVoltage ? 1 : 0; commonFaults <<= 1;
		commonFaults |= ResetDuringEn ? 1 : 0; commonFaults <<= 1;
		
		uint64_t deviceFaults = 0;
		deviceFaults |= SaturatedRotVelocity ? 1 : 0; deviceFaults <<= 1;
		deviceFaults |= SaturatedAccel ? 1 : 0; deviceFaults <<= 1;
		deviceFaults |= SaturatedMag ? 1 : 0; deviceFaults <<= 1;
		deviceFaults <<= 1; /* Unused bitfield */
		deviceFaults <<= 1;
		deviceFaults <<= 1;
		deviceFaults |= BootIntoMotion ? 1 : 0; deviceFaults <<= 1;
		deviceFaults |= MagnetometerFault ? 1 : 0; deviceFaults <<= 1;
		deviceFaults |= GyroFault ? 1 : 0; deviceFaults <<= 1;
		deviceFaults |= AccelFault ? 1 : 0; deviceFaults <<= 1;
		
		return commonFaults | (deviceFaults << 30);
	}
	/**
	 * Updates current fault list with specified bit field of faults
	 *
	 * @param bits bit field of faults to update with
	 */
	void Update(uint64_t bits) {
		uint64_t mask = 1;
		HardwareFault = (bits & mask) ? true : false; mask <<= 1;
		APIError = 		(bits & mask) ? true : false; mask <<= 1;
		UnderVoltage = 	(bits & mask) ? true : false; mask <<= 1;
		ResetDuringEn = (bits & mask) ? true : false; mask <<= 1;
		mask <<= 30; /* 30 faults currently unused */
		AccelFault = (bits & mask) ? true : false; mask <<= 1;
		GyroFault = (bits & mask) ? true : false; mask <<= 1;
		MagnetometerFault = (bits & mask) ? true : false; mask <<= 1;
		BootIntoMotion = (bits & mask) ? true : false; mask <<= 1;
		mask <<= 1;
		mask <<= 1;
		mask <<= 1; /* unused bit field */
		SaturatedMag = (bits & mask) ? true : false; mask <<= 1;
		SaturatedAccel = (bits & mask) ? true : false; mask <<= 1;
		SaturatedRotVelocity = (bits & mask) ? true : false; mask <<= 1;
	}
	/**
	 * Creates fault list with specified bit field of faults
	 * 
	 * @param bits bit field of faults to update with
	 */
	Pigeon2_Faults(uint64_t bits) {
		Update(bits);
	}
	Pigeon2_Faults() {
		Update(0); // Default everything to false
	}
};

} // sensors
} // phoenix
} // ctre
