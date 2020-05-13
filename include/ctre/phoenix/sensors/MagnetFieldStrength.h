#pragma once
namespace ctre {
	namespace phoenix {
		namespace sensors {
			/**
			 * Indicates the magnet field strength of a magnet-based sensor
			 */
			enum MagnetFieldStrength {
				/** Magnet Field strength cannot be determined */
				Invalid_Unknown = 0,
				/** Magnet field is far too low (too far) or far too high (too close). */
				BadRange_RedLED = 1,
				/** Magnet field is adequate, sensor can be used in this range with slightly reduced accuracy. */
				Adequate_OrangeLED = 2,
				/** Magnet field is ideal */
				Good_GreenLED = 3,
			};
		} // namespace sensors
	} // namespace phoenix
} // namespace ctre
