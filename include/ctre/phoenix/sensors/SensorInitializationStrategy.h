/* Copyright (C) Cross The Road Electronics 2024 */
#pragma once

#include <string>

namespace ctre {
	namespace phoenix {
		namespace sensors {

			/**
			 * Enum for how CANCoder should initialize its position register on boot.
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
			enum SensorInitializationStrategy {
				/**
				 * On boot up, set position to zero.
				 */
				BootToZero = 0,
				/**
				 * On boot up, sync to the Absolute Position signal.  The Absolute position signal will be signed according to the selected Absolute Sensor Range.
				 */
				BootToAbsolutePosition = 1,
			};

			/**
			 * Class to handle routines specific to VelocityMeasPeriod
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
			SensorInitializationStrategyRoutines {
			public:
				/**
				 * String representation of specified SensorInitializationStrategy
				 * @param value CANCoderVelocityMeasPeriod to convert to a string
				 * @return string representation of SensorInitializationStrategy
				 */
				static std::string toString(SensorInitializationStrategy value) {
					switch (value) {
					case BootToZero: return "On boot up, set position to zero.";
					case BootToAbsolutePosition: return " On boot up, sync to the Absolute Position signal.";
					default: return "InvalidValue";
					}
				}
			};

		} // namespace sensors
	} // namespace phoenix
} // namespace ctre
