#pragma once
#if defined(WIN32) || defined(_WIN32) || defined(_WIN64)
#pragma warning (push)
#pragma warning (disable : 4250)
#endif

#include "ctre/phoenix/motorcontrol/can/BaseTalon.h"
#include "ctre/phoenix/motorcontrol/IMotorControllerEnhanced.h"
#include "ctre/phoenix/CustomParamConfiguration.h"

/* forward proto's */
namespace ctre {
	namespace phoenix {
		namespace motorcontrol {
			class SensorCollection;
			class TalonSRXSimCollection;
		}
	}
}

namespace ctre {
	namespace phoenix {
		namespace motorcontrol {
			namespace can {

				/**
				 * Configurables available to TalonSRX's PID
				 */
				struct TalonSRXPIDSetConfiguration : BaseTalonPIDSetConfiguration { };
				/**
				 * Configurables available to TalonSRX
				 */
				struct TalonSRXConfiguration : BaseTalonConfiguration {

					/**
					 * Peak current in amps
					 *
					 * Current limit is activated when current exceeds the peak limit for longer
					 * than the peak duration. Then software will limit to the continuous limit.
					 * This ensures current limiting while allowing for momentary excess current
					 * events.
					 */
					int peakCurrentLimit;
					/**
					 * Peak Current duration in milliseconds
					 *
					 * Current limit is activated when current exceeds the peak limit for longer
					 * than the peak duration. Then software will limit to the continuous limit.
					 * This ensures current limiting while allowing for momentary excess current
					 * events.
					 */
					int peakCurrentDuration;
					/**
					 * Continuous current in amps
					 *
					 * Current limit is activated when current exceeds the peak limit for longer
					 * than the peak duration. Then software will limit to the continuous limit.
					 * This ensures current limiting while allowing for momentary excess current
					 * events.
					 */
					int continuousCurrentLimit;
					TalonSRXConfiguration() :
						BaseTalonConfiguration(FeedbackDevice::QuadEncoder),
						peakCurrentLimit(1),
						peakCurrentDuration(1),
						continuousCurrentLimit(1)
					{
					}

					/**
					 * @return String representation of all the configs
					 */
					std::string toString() {
						return toString("");
					}

					/**
					 * @param prependString
					 *              String to prepend to all the configs
					 * @return String representation of all the configs
					 */
					std::string toString(std::string prependString) {

						std::string retstr;
						retstr += prependString + ".peakCurrentLimit = " + std::to_string(peakCurrentLimit) + ";\n";
						retstr += prependString + ".peakCurrentDuration = " + std::to_string(peakCurrentDuration) + ";\n";
						retstr += prependString + ".continuousCurrentLimit = " + std::to_string(continuousCurrentLimit) + ";\n";
						retstr += BaseTalonConfiguration::toString(prependString);

						return retstr;
					}
				 };// struct TalonSRXConfiguration

				/**
				 * Util class to help with talon configs
				 */
				class TalonSRXConfigUtil : BaseTalonConfigUtil { 
				private:
					static struct TalonSRXConfiguration _default;
				public:
					/**
					 * Determine if specified value is different from default
					 * @param settings settings to compare against
					 * @return if specified value is different from default
					 * @{
					 */
					static bool PeakCurrentLimitDifferent(const TalonSRXConfiguration& settings) { return (!(settings.peakCurrentLimit == _default.peakCurrentLimit)) || !settings.enableOptimizations; }
					static bool PeakCurrentDurationDifferent(const TalonSRXConfiguration& settings) { return (!(settings.peakCurrentDuration == _default.peakCurrentDuration)) || !settings.enableOptimizations; }
					static bool ContinuousCurrentLimitDifferent(const TalonSRXConfiguration& settings) { return (!(settings.continuousCurrentLimit == _default.continuousCurrentLimit)) || !settings.enableOptimizations; }

					/** @} */
				};

				/**
				 * CTRE Talon SRX Motor Controller when used on CAN Bus.
				 *
				 * <pre>
				 * {@code
				 * // Example usage of a TalonSRX motor controller
				 * TalonSRX motor{0}; // creates a new TalonSRX with ID 0
				 *
				 * TalonSRXConfiguration config;
				 * config.peakCurrentLimit = 40; // the peak current, in amps
				 * config.peakCurrentDuration = 1500; // the time at the peak current before the limit triggers, in ms
				 * config.continuousCurrentLimit = 30; // the current to maintain if the peak limit is triggered
				 * motor.ConfigAllSettings(config); // apply the config settings; this selects the quadrature encoder
				 *
				 * motor.Set(TalonSRXControlMode::PercentOutput, 0.5); // runs the motor at 50% power
				 *
				 * std::cout << motor.GetSelectedSensorPosition() << std::endl; // prints the position of the selected sensor
				 * std::cout << motor.GetSelectedSensorVelocity() << std::endl; // prints the velocity recorded by the selected sensor
				 * std::cout << motor.GetMotorOutputPercent() << std::endl; // prints the percent output of the motor (0.5)
				 * std::cout << motor.GetStatorCurrent() << std::endl; // prints the output current of the motor
				 *
				 * ErrorCode error = motor.GetLastError(); // gets the last error generated by the motor controller
				 * Faults faults;
				 * ErrorCode faultsError = motor.GetFaults(faults); // fills faults with the current motor controller faults; returns the last error generated
				 *
				 * motor.SetStatusFramePeriod(StatusFrameEnhanced::Status_2_Feedback0, 10); // changes the period of the Status 2 frame (GetSelectedSensor*()) to 10ms
				 * }
				 * </pre>
				 */
				class TalonSRX : public virtual BaseTalon
				{
				private:

				public:
					/**
					 * Constructor for a Talon
					 * @param deviceNumber CAN Device ID of TalonSRX
					 */
					TalonSRX(int deviceNumber);
					~TalonSRX();
					TalonSRX() = delete;
					TalonSRX(TalonSRX const&) = delete;
					TalonSRX& operator=(TalonSRX const&) = delete;
					// ------ Set output routines. ----------//
					/**
					 * Sets the appropriate output on the talon, depending on the mode.
					 * @param mode The output mode to apply.
					 * In PercentOutput, the output is between -1.0 and 1.0, with 0.0 as stopped.
					 * In Current mode, output value is in amperes.
					 * In Velocity mode, output value is in position change / 100ms.
					 * In Position mode, output value is in encoder ticks or an analog value,
					 *   depending on the sensor.
					 * In Follower mode, the output value is the integer device ID of the talon to
					 * duplicate.
					 *
					 * @param value The setpoint value, as described above.
					 *
					 *
					 *	Standard Driving Example:
					 *	_talonLeft.set(ControlMode.PercentOutput, leftJoy);
					 *	_talonRght.set(ControlMode.PercentOutput, rghtJoy);
					 */
					void Set(TalonSRXControlMode mode, double value);
					/**
					 * @param mode Sets the appropriate output on the talon, depending on the mode.
					 * @param demand0 The output value to apply.
					 * 	such as advanced feed forward and/or auxiliary close-looping in firmware.
					 * In PercentOutput, the output is between -1.0 and 1.0, with 0.0 as stopped.
					 * In Current mode, output value is in amperes.
					 * In Velocity mode, output value is in position change / 100ms.
					 * In Position mode, output value is in encoder ticks or an analog value,
					 *   depending on the sensor. See
					 * In Follower mode, the output value is the integer device ID of the talon to
					 * duplicate.
					 *
					 * @param demand1Type The demand type for demand1.
					 * Neutral: Ignore demand1 and apply no change to the demand0 output.
					 * AuxPID: Use demand1 to set the target for the auxiliary PID 1.  Auxiliary
					 *   PID is always executed as standard Position PID control.
					 * ArbitraryFeedForward: Use demand1 as an arbitrary additive value to the
					 *	 demand0 output.  In PercentOutput the demand0 output is the motor output,
					 *   and in closed-loop modes the demand0 output is the output of PID0.
					 * @param demand1 Supplmental output value.
					 * AuxPID: Target position in Sensor Units
					 * ArbitraryFeedForward: Percent Output between -1.0 and 1.0
					 *
					 *
					 *  Arcade Drive Example:
					 *		_talonLeft.set(ControlMode.PercentOutput, joyForward, DemandType.ArbitraryFeedForward, +joyTurn);
					 *		_talonRght.set(ControlMode.PercentOutput, joyForward, DemandType.ArbitraryFeedForward, -joyTurn);
					 *
					 *	Drive Straight Example:
					 *	Note: Selected Sensor Configuration is necessary for both PID0 and PID1.
					 *		_talonLeft.follow(_talonRght, FollwerType.AuxOutput1);
					 *		_talonRght.set(ControlMode.PercentOutput, joyForward, DemandType.AuxPID, desiredRobotHeading);
					 *
					 *	Drive Straight to a Distance Example:
					 *	Note: Other configurations (sensor selection, PID gains, etc.) need to be set.
					 *		_talonLeft.follow(_talonRght, FollwerType.AuxOutput1);
					 *		_talonRght.set(ControlMode.MotionMagic, targetDistance, DemandType.AuxPID, desiredRobotHeading);
					 */
					void Set(TalonSRXControlMode mode, double demand0, DemandType demand1Type, double demand1);
					//------ sensor selection ----------//
					/**
					 * Select the feedback device for the motor controller.
					 *
					 * @param feedbackDevice
					 *            Talon SRX Feedback Device to select.
					 * @param pidIdx
					 *            0 for Primary closed-loop. 1 for auxiliary closed-loop.
					 * @param timeoutMs
					 *            Timeout value in ms. If nonzero, function will wait for
					 *            config success and report an error if it times out.
					 *            If zero, no blocking or checking is performed.
					 * @return Error Code generated by function. 0 indicates no error.
					 */
					ctre::phoenix::ErrorCode ConfigSelectedFeedbackSensor(TalonSRXFeedbackDevice feedbackDevice, int pidIdx = 0, int timeoutMs = 0);
					/**
					 * Select the feedback device for the motor controller.
					 *
					 * @param feedbackDevice
					 *            Feedback Device to select.
					 * @param pidIdx
					 *            0 for Primary closed-loop. 1 for auxiliary closed-loop.
					 * @param timeoutMs
					 *            Timeout value in ms. If nonzero, function will wait for
					 *            config success and report an error if it times out.
					 *            If zero, no blocking or checking is performed.
					 * @return Error Code generated by function. 0 indicates no error.
					 */
					ctre::phoenix::ErrorCode ConfigSelectedFeedbackSensor(FeedbackDevice feedbackDevice, int pidIdx, int timeoutMs = 0);

					/**
					 * Select the remote feedback device for the motor controller.
					 * Most CTRE CAN motor controllers will support remote sensors over CAN.
					 *
					 * @param feedbackDevice
					 *            Remote Feedback Device to select.
					 * @param pidIdx
					 *            0 for Primary closed-loop. 1 for auxiliary closed-loop.
					 * @param timeoutMs
					 *            Timeout value in ms. If nonzero, function will wait for
					 *            config success and report an error if it times out.
					 *            If zero, no blocking or checking is performed.
					 * @return Error Code generated by function. 0 indicates no error.
					 */
					ctre::phoenix::ErrorCode ConfigSelectedFeedbackSensor(RemoteFeedbackDevice feedbackDevice, int pidIdx, int timeoutMs);

					//------ Current Limit ----------//
					/**
					 * Configures the supply (input) current limit.
					 * @param currLimitConfigs  Current limit configuration
					 * @param timeoutMs
					 *            Timeout value in ms. If nonzero, function will wait for
					 *            config success and report an error if it times out.
					 *            If zero, no blocking or checking is performed.
					 * @return Error Code generated by function. 0 indicates no error.
					 */
					virtual ctre::phoenix::ErrorCode ConfigSupplyCurrentLimit(const SupplyCurrentLimitConfiguration& currLimitConfigs, int timeoutMs = 50);
					/**
					 * Configure the peak allowable current (when current limit is enabled).
 					 *
 					 * Supply current limiting is also available via ConfigSupplyCurrentLimit(),
 					 * which is a common routine with Talon FX.
					 *
					 * Current limit is activated when current exceeds the peak limit for longer
					 * than the peak duration. Then software will limit to the continuous limit.
					 * This ensures current limiting while allowing for momentary excess current
					 * events.
					 *
					 * For simpler current-limiting (single threshold) use
					 * ConfigContinuousCurrentLimit() and set the peak to zero:
					 * ConfigPeakCurrentLimit(0).
					 *
					 * @param amps
					 *            Amperes to limit.
					 * @param timeoutMs
					 *            Timeout value in ms. If nonzero, function will wait for config
					 *            success and report an error if it times out. If zero, no
					 *            blocking or checking is performed.
					 */
					ctre::phoenix::ErrorCode ConfigPeakCurrentLimit(int amps, int timeoutMs = 0);
					/**
					 * Configure the peak allowable duration (when current limit is enabled).
 					 *
 					 * Supply current limiting is also available via ConfigSupplyCurrentLimit(),
 					 * which is a common routine with Talon FX.
					 *
					 * Current limit is activated when current exceeds the peak limit for longer
					 * than the peak duration. Then software will limit to the continuous limit.
					 * This ensures current limiting while allowing for momentary excess current
					 * events.
					 *
					 * For simpler current-limiting (single threshold) use
					 * ConfigContinuousCurrentLimit() and set the peak to zero:
					 * ConfigPeakCurrentLimit(0).
					 *
					 * @param milliseconds
					 *            How long to allow current-draw past peak limit.
					 * @param timeoutMs
					 *            Timeout value in ms. If nonzero, function will wait for config
					 *            success and report an error if it times out. If zero, no
					 *            blocking or checking is performed.
					 */
					ctre::phoenix::ErrorCode ConfigPeakCurrentDuration(int milliseconds,
						int timeoutMs = 0);
					/**
					 * Configure the continuous allowable current-draw (when current limit is
					 * enabled).
 					 *
 					 * Supply current limiting is also available via ConfigSupplyCurrentLimit(),
 					 * which is a common routine with Talon FX.
					 *
					 * Current limit is activated when current exceeds the peak limit for longer
					 * than the peak duration. Then software will limit to the continuous limit.
					 * This ensures current limiting while allowing for momentary excess current
					 * events.
					 *
					 * For simpler current-limiting (single threshold) use
					 * ConfigContinuousCurrentLimit() and set the peak to zero:
					 * ConfigPeakCurrentLimit(0).
					 *
					 * @param amps
					 *            Amperes to limit.
					 * @param timeoutMs
					 *            Timeout value in ms. If nonzero, function will wait for config
					 *            success and report an error if it times out. If zero, no
					 *            blocking or checking is performed.
					 */
					ctre::phoenix::ErrorCode ConfigContinuousCurrentLimit(int amps, int timeoutMs = 0);

					/**
					 * Enable or disable Current Limit.
 					 *
 					 * Supply current limiting is also available via ConfigSupplyCurrentLimit(),
 					 * which is a common routine with Talon FX.
					 *
					 * @param enable
					 *            Enable state of current limit.
					 * @see configPeakCurrentLimit()
					 * @see configPeakCurrentDuration()
					 * @see configContinuousCurrentLimit()
					 */
					void EnableCurrentLimit(bool enable);
					//------ RAW Sensor API ----------//
					/**
					 * @return object that can get/set individual RAW sensor values.
					 */
					ctre::phoenix::motorcontrol::SensorCollection& GetSensorCollection();

					//------ Simulation API ----------//
					/**
					 * @return object that can set simulation inputs.
					 */
					ctre::phoenix::motorcontrol::TalonSRXSimCollection& GetSimCollection();

					//------ All Configs ----------//

					/**
					 * Sets all PID persistant settings.
					 *
					 * @param pid               Object with all of the PID set persistant settings
					 * @param pidIdx            0 for Primary closed-loop. 1 for auxiliary closed-loop.
					 * @param timeoutMs
					 *              Timeout value in ms. If nonzero, function will wait for
					 *              config success and report an error if it times out.
					 *              If zero, no blocking or checking is performed.
					 */
					ctre::phoenix::ErrorCode ConfigurePID(const TalonSRXPIDSetConfiguration& pid, int pidIdx = 0, int timeoutMs = 50);
					/**
					* Gets all PID set persistant settings.
					*
					* @param pid               Object with all of the PID set persistant settings
					* @param pidIdx            0 for Primary closed-loop. 1 for auxiliary closed-loop.
					* @param timeoutMs
					*              Timeout value in ms. If nonzero, function will wait for
					*              config success and report an error if it times out.
					*              If zero, no blocking or checking is performed.
					*/
					void GetPIDConfigs(TalonSRXPIDSetConfiguration& pid, int pidIdx = 0, int timeoutMs = 50);
					/**
					 * Configures all persistent settings.
					 *
					 * @param allConfigs        Object with all of the persistant settings
					 * @param timeoutMs
					 *              Timeout value in ms. If nonzero, function will wait for
					 *              config success and report an error if it times out.
					 *              If zero, no blocking or checking is performed.
					 *
					 * @return Error Code generated by function. 0 indicates no error.
					 */
					ctre::phoenix::ErrorCode ConfigAllSettings(const TalonSRXConfiguration& allConfigs, int timeoutMs = 50);
					/**
					 * Gets all persistant settings.
					 *
					 * @param allConfigs        Object with all of the persistant settings
					 * @param timeoutMs
					 *              Timeout value in ms. If nonzero, function will wait for
					 *              config success and report an error if it times out.
					 *              If zero, no blocking or checking is performed.
					 */
					void GetAllConfigs(TalonSRXConfiguration& allConfigs, int timeoutMs = 50);

					/* ----- virtual re-directs ------- */
					virtual void Set(ControlMode mode, double value);
					virtual void Set(ControlMode mode, double demand0, DemandType demand1Type, double demand1);
				};// class TalonSRX

			} // namespace can
		} // namespace motorcontrol
	} // namespace phoenix
} // namespace ctre

#if defined(WIN32) || defined(_WIN32) || defined(_WIN64)
#pragma warning (pop)
#endif
