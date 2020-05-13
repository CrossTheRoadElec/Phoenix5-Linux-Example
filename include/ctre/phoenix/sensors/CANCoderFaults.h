#pragma once

namespace ctre {
	namespace phoenix {
		namespace sensors {

			/**
			 * Faults available to CANCoderFaults
			 */
			struct CANCoderFaults {
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
				 * Magnet strength is too weak to provide reliable results
				 * Make sure CANCoder is close to the magnet being used
				 */
				bool MagnetTooWeak;
				/**
				 * @return true if any faults are tripped
				 */
				bool HasAnyFault() const {
					return 	HardwareFault |
							APIError |
							UnderVoltage |
							ResetDuringEn |
							MagnetTooWeak;
				}
				/**
				 * @return Current fault list as a bit field
				 */
				int ToBitfield() const {
					int retval = 0;
					int mask = 1;
					retval |= HardwareFault ? mask : 0; mask <<= 1;
					retval |= APIError		? mask : 0; mask <<= 1;
					retval |= UnderVoltage 	? mask : 0; mask <<= 1;
					retval |= ResetDuringEn ? mask : 0; mask <<= 1; 
					mask <<= 3; /* 3 faults currently unused */
					retval |= MagnetTooWeak ? mask : 0; mask <<= 1;
					return retval;
				}
				/**
				 * Updates current fault list with specified bit field of faults
				 *
				 * @param bits bit field of faults to update with
				 */
				void Update(int bits) {
					int mask = 1;
					HardwareFault = (bits & mask) ? true : false; mask <<= 1;
					APIError = 		(bits & mask) ? true : false; mask <<= 1;
					UnderVoltage = 	(bits & mask) ? true : false; mask <<= 1;
					ResetDuringEn = (bits & mask) ? true : false; mask <<= 1;
					mask <<= 3; /* 3 faults currently unused */
					MagnetTooWeak = (bits & mask) ? true : false; mask <<= 1;
				}
				/**
				 * Updates current fault list with specified bit field of faults
				 *
				 * @param bits bit field of faults to update with
				 */
				CANCoderFaults(int bits) {
					Update(bits);
				}
				CANCoderFaults() {
					HardwareFault = false;
					APIError = false;
					UnderVoltage = false;
					ResetDuringEn = false;
					MagnetTooWeak = false;
				}
			};

		} // namespace sensors
	} // namespace phoenix
} // namespace ctre

