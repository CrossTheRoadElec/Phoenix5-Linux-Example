/* Copyright (C) Cross The Road Electronics 2024 */
#pragma once
namespace ctre {
	namespace phoenix {
		namespace sensors {
			/**
			 * Indicates the magnet field strength of a magnet-based sensor
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
			MagnetFieldStrength {
				/** Magnet Field strength cannot be determined */
				Invalid_Unknown = 0,
				/** Magnet field is far too low (too far) or far too high (too close). */
				BadRange_RedLED = 1,
				/** Magnet field is adequate, sensor can be used in this range with slightly reduced accuracy. */
				Adequate_OrangeLED = 2,
				/** Magnet field is ideal */
				Good_GreenLED = 3,
			};
		} // namespace sensors
	} // namespace phoenix
} // namespace ctre
