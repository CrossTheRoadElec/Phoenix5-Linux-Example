/* Copyright (C) Cross The Road Electronics 2024 */
#pragma once

#include <string>

namespace ctre {
	namespace phoenix {
		namespace sensors {

			/**
			 * Enum for how to range the absolute sensor position.
			 *
			 * @deprecated This device's Phoenix 5 API is deprecated for removal in the
			 * 2025 season. Users should update to Phoenix 6 firmware and migrate to the
			 * Phoenix 6 API. A migration guide is available at
			 * https://v6.docs.ctr-electronics.com/en/stable/docs/migration/migration-guide/index.html.
			 *
			 * If the Phoenix 5 API must be used for this device, the device must have 22.X
			 * firmware. This firmware is available in Tuner X after selecting Phoenix 5 in
			 * the firmware year dropdown.
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
			 *
			 * @deprecated This device's Phoenix 5 API is deprecated for removal in the
			 * 2025 season. Users should update to Phoenix 6 firmware and migrate to the
			 * Phoenix 6 API. A migration guide is available at
			 * https://v6.docs.ctr-electronics.com/en/stable/docs/migration/migration-guide/index.html.
			 *
			 * If the Phoenix 5 API must be used for this device, the device must have 22.X
			 * firmware. This firmware is available in Tuner X after selecting Phoenix 5 in
			 * the firmware year dropdown.
			 */
			class [[deprecated("This device's Phoenix 5 API is deprecated for removal in the 2025 season."
							"Users should update to Phoenix 6 firmware and migrate to the Phoenix 6 API."
							"A migration guide is available at https://v6.docs.ctr-electronics.com/en/stable/docs/migration/migration-guide/index.html")]]
			AbsoluteSensorRangeRoutines {
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
