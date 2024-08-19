/* Copyright (C) Cross The Road Electronics 2024 */
#pragma once

#include <string>
namespace ctre {
	namespace phoenix {
		namespace motorcontrol {
			/**
			 * Choose the invert type of the motor controller.
			 * None is the equivalent of SetInverted(false), where positive request yields positive voltage on M+.
			 * InvertMotorOutput is the equivelant of SetInverted(true), where positive request yields positive voltage on M-.
			 * FollowMaster/OpposeMaster will match/oppose a master Talon/Victor.  This requires device to be configured as a follower.
			 */
			enum class InvertType {
				None = 0, //!< Same as SetInverted(false)
				InvertMotorOutput = 1, //!< Same as SetInverted(true)
				FollowMaster = 2, //!< Follow the invert of the master this MC is following.
				OpposeMaster = 3, //!< Opposite of the invert of the master this MC is following.
			};
			/**
			 * Choose the invert type for a Talon FX based integrated motor controller.
			 * CCW is the equivalent of SetInverted(false), CW is the equivalent of SetInverted(true).
			 * FollowMaster/OpposeMaster will match/oppose a master Talon/Victor.  This requires device to be configured as a follower.
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
			enum class [[deprecated("This device's Phoenix 5 API is deprecated for removal in the 2025 season."
							"Users should update to Phoenix 6 firmware and migrate to the Phoenix 6 API."
							"A migration guide is available at https://v6.docs.ctr-electronics.com/en/stable/docs/migration/migration-guide/index.html")]]
			TalonFXInvertType {
				CounterClockwise = 0, //!< Same as SetInverted(false)
				Clockwise = 1, //!< Same as SetInverted(true)
				FollowMaster = 2, //!< Follow the invert of the master this MC is following.
				OpposeMaster = 3, //!< Opposite of the invert of the master this MC is following.
			};
		} // namespace motorcontrol
	} // namespace phoenix
} // namespace ctre
