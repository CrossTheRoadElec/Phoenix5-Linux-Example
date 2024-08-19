/* Copyright (C) Cross The Road Electronics 2024 */
#pragma once

#include <string>
namespace ctre {
	namespace phoenix {
		namespace motorcontrol {
			/**
			 * Choose the type of motor commutation.  This is for products that support selectable commutation strategies.
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
			enum class MotorCommutation {
				Trapezoidal = 0, //!< Trapezoidal Commutation
			};
		} // namespace motorcontrol
	} // namespace phoenix
} // namespace ctre
