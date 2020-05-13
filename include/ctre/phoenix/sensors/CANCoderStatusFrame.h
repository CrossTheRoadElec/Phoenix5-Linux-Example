#pragma once

namespace ctre {
	namespace phoenix {
		namespace sensors {

			/** Enumerated type for status frame types. */
			enum CANCoderStatusFrame {
				CANCoderStatusFrame_SensorData = 0x041400,
				CANCoderStatusFrame_VbatAndFaults = 0x041440,
			};

		} // namespace sensors
	} // namespace phoenix
} // namespace ctre

