#pragma once

#include <string>

namespace ctre {
	namespace phoenix {
		namespace sensors {

			/**
			* Enumerate filter periods for any sensor that measures velocity.
			*/
			enum SensorVelocityMeasPeriod {
				/**
				 * 1ms velocity measurement period
				 */
				Period_1Ms = 1,
				/**
				 * 2ms velocity measurement period
				 */
				Period_2Ms = 2,
				/**
				 * 5ms velocity measurement period
				 */
				Period_5Ms = 5,
				/**
				 * 10ms velocity measurement period
				 */
				Period_10Ms = 10,
				/**
				 * 20ms velocity measurement period
				 */
				Period_20Ms = 20,
				/**
				 * 25ms velocity measurement period
				 */
				Period_25Ms = 25,
				/**
				 * 50ms velocity measurement period
				 */
				Period_50Ms = 50,
				/**
				 * 100ms velocity measurement period
				 */
				Period_100Ms = 100,
			};

			/**
			 * Class to handle routines specific to VelocityMeasPeriod
			 */
			class SensorVelocityMeasPeriodRoutines {
			public:
				/**
				 * String representation of specified CANCoderVelocityMeasPeriod
				 * @param value CANCoderVelocityMeasPeriod to convert to a string
				 * @return string representation of CANCoderVelocityMeasPeriod
				 */
				static std::string toString(SensorVelocityMeasPeriod value) {
					switch (value) {
					case Period_1Ms: return "Period_1Ms";
					case Period_2Ms: return "Period_2Ms";
					case Period_5Ms: return "Period_5Ms";
					case Period_10Ms: return "Period_10Ms";
					case Period_20Ms: return "Period_20Ms";
					case Period_25Ms: return "Period_25Ms";
					case Period_50Ms: return "Period_50Ms";
					case Period_100Ms: return "Period_100Ms";
					default: return "InvalidValue";
					}
				}
			};

		} // namespace sensors
	} // namespace phoenix
} // namespace ctre
