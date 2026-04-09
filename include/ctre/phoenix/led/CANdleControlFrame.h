/* Copyright (C) Cross The Road Electronics 2024 */
#pragma once

namespace ctre {
namespace phoenix {
namespace led {

/**
 * Enumerated type for status frame types.
 *
 * @deprecated This device's Phoenix 5 API is deprecated for removal in the
 * 2027 season. Users should update to Phoenix 6 firmware and migrate to the
 * Phoenix 6 API. A migration guide is available at
 * https://v6.docs.ctr-electronics.com/en/stable/docs/migration/migration-guide/index.html.
 *
 * If the Phoenix 5 API must be used for this device, the device must have 22.X
 * firmware. This firmware is available in Tuner X after selecting Phoenix 5 in
 * the firmware year dropdown.
 */
enum CANdleControlFrame {
	CANdle_Control_1_General = 0x040000,
	CANdle_Control_2_ModulatedVBatOutput = 0x040040,
};

} // namespace led
} // namespace phoenix
} // namespace ctre
