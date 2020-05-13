
#pragma once

#include <string>

namespace ctre {
	namespace phoenix {
		namespace sensors {

			/**
			 * Velocity Measurement Periods
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
			 */
			class SensorTimeBaseRoutines {
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
