/* Copyright (C) Cross The Road Electronics 2024 */
#pragma once

namespace ctre {
	namespace phoenix {
		namespace sensors {

			/**
			 * Enumerated type for status frame types.
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
			enum [[deprecated("This device's Phoenix 5 API is deprecated for removal in the 2025 season."
							"Users should update to Phoenix 6 firmware and migrate to the Phoenix 6 API."
							"A migration guide is available at https://v6.docs.ctr-electronics.com/en/stable/docs/migration/migration-guide/index.html")]]
			CANCoderStatusFrame {
				CANCoderStatusFrame_SensorData = 0x041400,
				CANCoderStatusFrame_VbatAndFaults = 0x041440,
			};

		} // namespace sensors
	} // namespace phoenix
} // namespace ctre

