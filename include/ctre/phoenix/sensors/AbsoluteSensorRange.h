#pragma once

#include <string>

namespace ctre {
	namespace phoenix {
		namespace sensors {

			/**
			 * Enum for how to range the absolute sensor position.
			 */
			enum AbsoluteSensorRange {
				/**
				 * Express the absolute position as an unsigned value.
				 * E.g. [0,+1) rotations or [0,360) deg.
				 */
				Unsigned_0_to_360 = 0,
				/**
				 * Express the absolute position as an signed value.
				 * E.g. [-0.5,+0.5) rotations or [-180,+180) deg.
				 */
				Signed_PlusMinus180 = 1,
			};

			/**
			 * Class to handle routines specific to AbsoluteSensorRange
			 */
			class AbsoluteSensorRangeRoutines {
			public:
				/**
				 * String representation of specified AbsoluteSensorRange
				 * @param value AbsoluteSensorRange to convert to a string
				 * @return string representation of AbsoluteSensorRange
				 */
				static std::string toString(AbsoluteSensorRange value) {
					switch (value) {
					case Unsigned_0_to_360: return "Unsigned: 0 to 360 deg (positive full rotation";
					case Signed_PlusMinus180: return "Signed: -180 to 180 deg (plus/minus half a rotation)";
					default: return "InvalidValue";
					}
				}
			};

		} // namespace sensors
	} // namespace phoenix
} // namespace ctre
