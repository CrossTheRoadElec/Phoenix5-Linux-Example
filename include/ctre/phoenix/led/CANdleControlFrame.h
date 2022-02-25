#pragma once

namespace ctre {
namespace phoenix {
namespace led {

/** Enumerated type for status frame types. */
enum CANdleControlFrame {
	CANdle_Control_1_General = 0x040000,
	CANdle_Control_2_ModulatedVBatOutput = 0x040040,
};

} // namespace led
} // namespace phoenix
} // namespace ctre
