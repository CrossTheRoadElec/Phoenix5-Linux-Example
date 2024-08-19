/* Copyright (C) Cross The Road Electronics 2024 */

#pragma once

#include <string>

namespace ctre {
	namespace phoenix {
		namespace sensors {

			/**
			 * Velocity Measurement Periods
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
			enum SensorTimeBase {
				/**
				 * Legacy Mode
				 */
				Per100Ms_Legacy = 0,
				/**
				 * Per-Second Velocities
				 */
				PerSecond = 1,
				/**
				 * Per-Minute Velocities
				 */
				PerMinute = 2,
			};
			/**
			 * Class to handle routines specific to SensorTimeBase
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
			SensorTimeBaseRoutines {
			public:
				/**
				 * String representation of specified SensorTimeBase
				 * @param value SensorTimeBase to convert to a string
				 * @return string representation of SensorTimeBase
				 */
				static std::string toString(SensorTimeBase value) {
					switch (value) {
					case SensorTimeBase::Per100Ms_Legacy: return "Per 100Ms (legacy)";
					case SensorTimeBase::PerSecond: return "Per Second";
					case SensorTimeBase::PerMinute: return "Per Minute";
					default: return "InvalidValue";
					}
				}
			};
		} // namespace motorcontrol
	} // namespace phoenix
} // namespace ctre
