#pragma once

namespace ctre {
	namespace phoenix {
		namespace motorcontrol {
			/**
			 * Choose the control mode for a motor controller.
			 * Consult product specific documentation to determine what is available/supported.
			 */
			enum class ControlMode {
				/**
				 * Percent output [-1,1]
				 */
				PercentOutput = 0,
				/**
				 * Position closed loop
				 */
				Position = 1,
				/**
				 * Velocity closed loop
				 */
				Velocity = 2,
				/**
				 * Input current closed loop
				 */
				Current = 3,
				/**
				 * Follow other motor controller
				 */
				Follower = 5,
				/**
				 * Motion Profile
				 */
				MotionProfile = 6,
				/**
				 * Motion Magic
				 */
				MotionMagic = 7,
				/**
				 * Motion Profile with auxiliary output
				 */
				MotionProfileArc = 10,
				/**
				 * Plays a single tone.  Frequency (hz) is passed into set.
				 */
				MusicTone = 13,
				/**
				 * Disable Motor Controller
				 */
				Disabled = 15,
			};
			/**
			 * Choose the control mode for a TalonFX / Falcon 500.
			 */
			enum class TalonFXControlMode {
				/**
				 * Percent output [-1,1]
				 */
				PercentOutput = 0,
				/**
				 * Position closed loop
				 */
				Position = 1,
				/**
				 * Velocity closed loop
				 */
				Velocity = 2,
				/**
				 * Input current closed loop
				 */
				Current = 3,
				/**
				 * Follow other motor controller
				 */
				Follower = 5,
				/**
				 * Motion Profile
				 */
				MotionProfile = 6,
				/**
				 * Motion Magic
				 */
				MotionMagic = 7,
				/**
				 * Motion Profile with auxiliary output
				 */
				MotionProfileArc = 10,
				/**
				 * Plays a single tone.  Frequency (hz) is passed into set.
				 */
				MusicTone = 13,
				/**
				 * Disable Motor Controller
				 */
				Disabled = 15,
			};

			/**
			 * Choose the control mode for a Talon SRX.
			 */
			enum class TalonSRXControlMode {
				/**
				 * Percent output [-1,1]
				 */
				PercentOutput = 0,
				/**
				 * Position closed loop
				 */
				Position = 1,
				/**
				 * Velocity closed loop
				 */
				Velocity = 2,
				/**
				 * Input current closed loop
				 */
				Current = 3,
				/**
				 * Follow other motor controller
				 */
				Follower = 5,
				/**
				 * Motion Profile
				 */
				MotionProfile = 6,
				/**
				 * Motion Magic
				 */
				MotionMagic = 7,
				/**
				 * Motion Profile with auxiliary output
				 */
				MotionProfileArc = 10,
				/**
				 * Disable Motor Controller
				 */
				Disabled = 15,
			};

			/**
			 * Choose the control mode for a Victor SPX.
			 */
			enum class VictorSPXControlMode {
				/**
				 * Percent output [-1,1]
				 */
				PercentOutput = 0,
				/**
				 * Position closed loop
				 */
				Position = 1,
				/**
				 * Velocity closed loop
				 */
				Velocity = 2,
				/**
				 * Follow other motor controller
				 */
				Follower = 5,
				/**
				 * Motion Profile
				 */
				MotionProfile = 6,
				/**
				 * Motion Magic
				 */
				MotionMagic = 7,
				/**
				 * Motion Profile with auxiliary output
				 */
				MotionProfileArc = 10,
				/**
				 * Disable Motor Controller
				 */
				Disabled = 15,
			};
		}
	}
}
