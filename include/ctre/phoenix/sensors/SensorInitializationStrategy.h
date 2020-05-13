#pragma once

#include <string>

namespace ctre {
	namespace phoenix {
		namespace sensors {

			/**
			 * Enum for how CANCoder should initialize its position register on boot.
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
			 */
			class SensorInitializationStrategyRoutines {
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
