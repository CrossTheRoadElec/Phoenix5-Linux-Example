#pragma once
#if defined(WIN32) || defined(_WIN32) || defined(_WIN64)
#pragma warning (push)
#pragma warning (disable : 4250)
#endif

#include "ctre/phoenix/motorcontrol/can/BaseTalon.h"
#include "ctre/phoenix/motorcontrol/IMotorControllerEnhanced.h"
#include "ctre/phoenix/motorcontrol/MotorCommutation.h"
#include "ctre/phoenix/motorcontrol/StatorCurrentLimitConfiguration.h"
#include "ctre/phoenix/CustomParamConfiguration.h"
#include "ctre/phoenix/sensors/AbsoluteSensorRange.h"
#include "ctre/phoenix/sensors/SensorInitializationStrategy.h"

namespace ctre {
	namespace phoenix {
		namespace motorcontrol {
			namespace can {

				/**
				 * Configurables available to TalonFX's PID
				 */
				struct TalonFXPIDSetConfiguration : BaseTalonPIDSetConfiguration { };

				/**
				 * Configurables available to TalonFX
				 */
				struct TalonFXConfiguration : BaseTalonConfiguration {

					/**
					 * Supply-side current limiting.  This is typically used to prevent breakers from tripping.
					 */
					SupplyCurrentLimitConfiguration supplyCurrLimit;
					/**
					 * Stator-side current limiting.  This is typically used to limit acceleration/torque and heat generation.
					 */
					StatorCurrentLimitConfiguration statorCurrLimit;

					/**
					 * Choose the type of motor commutation.
					 */
					ctre::phoenix::motorcontrol::MotorCommutation motorCommutation = ctre::phoenix::motorcontrol::MotorCommutation::Trapezoidal;

					/**
					 * Desired Sign / Range for the absolute position register.
					 * Choose unsigned for an absolute range of[0, +1) rotations, [0, 360) deg, etc.
					 * Choose signed for an absolute range of[-0.5, +0.5) rotations, [-180, +180) deg, etc.
					 */
					ctre::phoenix::sensors::AbsoluteSensorRange absoluteSensorRange = ctre::phoenix::sensors::AbsoluteSensorRange::Unsigned_0_to_360;
					/**
					 * Adjusts the zero point for the absolute position register.
					 * The absolute position of the sensor will always have a discontinuity (360 -> 0 deg) or (+180 -> -180)
					 * and a hard-limited mechanism may have such a discontinuity in its functional range.
					 * In which case use this config to move the discontinuity outside of the function range.
					 */
					double integratedSensorOffsetDegrees = 0;
					/**
					 * The sensor initialization strategy to use.This will impact the behavior the next time device boots up.
					 *
					 * Pick the strategy on how to initialize the "Position" register.  Depending on the mechanism,
					 * it may be desirable to auto set the Position register to match the Absolute Position(swerve for example).
					 * Or it may be desired to zero the sensor on boot(drivetrain translation sensor or a relative servo).
					 *
					 * TIP: Tuner's self-test feature will report what the boot sensor value will be in the event the device is reset.
					 */
					ctre::phoenix::sensors::SensorInitializationStrategy initializationStrategy = ctre::phoenix::sensors::SensorInitializationStrategy::BootToZero;


					TalonFXConfiguration() : BaseTalonConfiguration(FeedbackDevice::IntegratedSensor)
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
						retstr += prependString + ".supplyCurrLimit = " + supplyCurrLimit.ToString() + ";\n";
						retstr += prependString + ".statorCurrLimit = " + statorCurrLimit.ToString() + ";\n";
						retstr += prependString + ".motorCommutation = " + std::to_string((int)motorCommutation) + ";\n";
						retstr += prependString + ".absoluteSensorRange = " + std::to_string(absoluteSensorRange) + ";\n";
						retstr += prependString + ".integratedSensorOffsetDegrees = " + std::to_string(integratedSensorOffsetDegrees) + ";\n";
						retstr += prependString + ".initializationStrategy = " + std::to_string(initializationStrategy) + ";\n";
						retstr += BaseTalonConfiguration::toString(prependString);

						return retstr;
					}
				 };// struct TalonFXConfiguration

				/**
				 * Util class to help with talon configs
				 */
				class TalonFXConfigUtil : BaseTalonConfigUtil { 
				private:
					static struct TalonFXConfiguration _default;
				public:
					/**
					 * Determine if specified value is different from default
					 * @param settings settings to compare against
					 * @return if specified value is different from default
					 * @{
					 */
					static bool SupplyCurrentLimitDifferent(const TalonFXConfiguration& settings) { return (!settings.supplyCurrLimit.Equals(_default.supplyCurrLimit)) || !settings.enableOptimizations; }
					static bool StatorCurrentDurationDifferent(const TalonFXConfiguration& settings) { return (!settings.statorCurrLimit.Equals(_default.statorCurrLimit)) || !settings.enableOptimizations; }
					static bool MotorCommutationDifferent(const TalonFXConfiguration& settings) { return (settings.motorCommutation != _default.motorCommutation) || !settings.enableOptimizations; }
					static bool AbsoluteSensorRangeDifferent(const TalonFXConfiguration& settings) { return (settings.absoluteSensorRange != _default.absoluteSensorRange) || !settings.enableOptimizations; }
					static bool IntegratedSensorOffsetDegreesDifferent(const TalonFXConfiguration& settings) { return (settings.integratedSensorOffsetDegrees != _default.integratedSensorOffsetDegrees) || !settings.enableOptimizations; }
					static bool InitializationStrategyDifferent(const TalonFXConfiguration& settings) { return (settings.initializationStrategy != _default.initializationStrategy) || !settings.enableOptimizations; }
					/** @} */
				};

				/**
				 * CTRE Talon FX Motor Controller when used on CAN Bus.
				 *
				 * <pre>
				 * {@code
				 * // Example usage of a TalonFX motor controller
				 * TalonFX motor{0}; // creates a new TalonFX with ID 0
				 *
				 * TalonFXConfiguration config;
				 * config.supplyCurrLimit.enable = true;
				 * config.supplyCurrLimit.triggerThresholdCurrent = 40; // the peak supply current, in amps
				 * config.supplyCurrLimit.triggerThresholdTime = 1.5; // the time at the peak supply current before the limit triggers, in sec
				 * config.supplyCurrLimit.currentLimit = 30; // the current to maintain if the peak supply limit is triggered
				 * motor.ConfigAllSettings(config); // apply the config settings; this selects the quadrature encoder
				 *
				 * motor.Set(TalonFXControlMode::PercentOutput, 0.5); // runs the motor at 50% power
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
				class TalonFX : public virtual BaseTalon
				{
				private:

				public:
					/**
					 * Constructor for a Talon
					 * @param deviceNumber CAN Device ID of TalonFX
					 * @param canbus Name of the CANbus; can be a SocketCAN interface (on Linux),
					 *               or a CANivore device name or serial number
					 */
					TalonFX(int deviceNumber, std::string const &canbus = "");
					~TalonFX();
					TalonFX() = delete;
					TalonFX(TalonFX const&) = delete;
					TalonFX& operator=(TalonFX const&) = delete;
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
					void Set(TalonFXControlMode mode, double value);
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
					void Set(TalonFXControlMode mode, double demand0, DemandType demand1Type, double demand1);
					//------ Invert behavior ----------//
					/**
					 * Inverts the hbridge output of the motor controller in relation to the master if present
					 *
					 * This does not impact sensor phase and should not be used to correct sensor polarity.
					 *
					 * This will allow you to either:
					 *  - Not invert the motor
					 *  - Invert the motor
					 *  - Always follow the master regardless of master's inversion
					 *  - Always oppose the master regardless of master's inversion
					 *
					 * @param invertType
					 *            Invert state to set.
					 */
					void SetInverted(TalonFXInvertType invertType);
					//------ sensor selection ----------//
					/**
					 * Select the feedback device for the motor controller.
					 *
					 * @param feedbackDevice
					 *            Talon FX Feedback Device to select.
					 * @param pidIdx
					 *            0 for Primary closed-loop. 1 for auxiliary closed-loop.
					 * @param timeoutMs
					 *            Timeout value in ms. If nonzero, function will wait for
					 *            config success and report an error if it times out.
					 *            If zero, no blocking or checking is performed.
					 * @return Error Code generated by function. 0 indicates no error.
					 */
					ctre::phoenix::ErrorCode ConfigSelectedFeedbackSensor(TalonFXFeedbackDevice feedbackDevice, int pidIdx = 0, int timeoutMs = 0);
					//------ Current Limit ----------//
					/**
					 * Configures the supply-side current limit.
					 * @param currLimitCfg  Current limit configuration
					 * @param timeoutMs
					 *            Timeout value in ms. If nonzero, function will wait for
					 *            config success and report an error if it times out.
					 *            If zero, no blocking or checking is performed.
					 * @return Error Code generated by function. 0 indicates no error.
					 */
					ctre::phoenix::ErrorCode ConfigSupplyCurrentLimit(const ctre::phoenix::motorcontrol::SupplyCurrentLimitConfiguration& currLimitConfigs, int timeoutMs = 50);
					/**
					 * Configures the stator (output) current limit.
					 * @param currLimitCfg  Current limit configuration
					 * @param timeoutMs
					 *            Timeout value in ms. If nonzero, function will wait for
					 *            config success and report an error if it times out.
					 *            If zero, no blocking or checking is performed.
					 * @return Error Code generated by function. 0 indicates no error.
					 */
					ctre::phoenix::ErrorCode ConfigStatorCurrentLimit(const ctre::phoenix::motorcontrol::StatorCurrentLimitConfiguration& currLimitConfigs, int timeoutMs = 50);
					/**
					 * Gets the supply current limit configuration.
					 * @param currLimitConfigsToFill  Configuration object to fill with read values.
					 * @param timeoutMs
					 *            Timeout value in ms. If nonzero, function will wait for
					 *            config success and report an error if it times out.
					 * @return Error Code generated by function. 0 indicates no error.
					 */				
					ctre::phoenix::ErrorCode ConfigGetSupplyCurrentLimit(ctre::phoenix::motorcontrol::SupplyCurrentLimitConfiguration& currLimitConfigsToFill, int timeoutMs = 50);
					/**
					 * Gets the stator (output) current limit configuration.
					 * @param currLimitConfigsToFill  Configuration object to fill with read values.
					 * @param timeoutMs
					 *            Timeout value in ms. If nonzero, function will wait for
					 *            config success and report an error if it times out.
					 * @return Error Code generated by function. 0 indicates no error.
					 */
					ctre::phoenix::ErrorCode ConfigGetStatorCurrentLimit(ctre::phoenix::motorcontrol::StatorCurrentLimitConfiguration& currLimitConfigsToFill, int timeoutMs = 50);

					//------ RAW Sensor API ----------//
					/**
					 * @return object that can get/set individual RAW sensor values.
					 */
					ctre::phoenix::motorcontrol::TalonFXSensorCollection& GetSensorCollection();

					//------ Simulation API ----------//
					/**
					 * @return object that can set simulation inputs.
					 */
					ctre::phoenix::motorcontrol::TalonFXSimCollection& GetSimCollection();

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
					ctre::phoenix::ErrorCode ConfigurePID(const TalonFXPIDSetConfiguration& pid, int pidIdx = 0, int timeoutMs = 50);
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
					void GetPIDConfigs(TalonFXPIDSetConfiguration& pid, int pidIdx = 0, int timeoutMs = 50);

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
					ctre::phoenix::ErrorCode ConfigAllSettings(const TalonFXConfiguration& allConfigs, int timeoutMs = 50);
					/**
					 * Gets all persistant settings.
					 *
					 * @param allConfigs        Object with all of the persistant settings
					 * @param timeoutMs
					 *              Timeout value in ms. If nonzero, function will wait for
					 *              config success and report an error if it times out.
					 *              If zero, no blocking or checking is performed.
					 */
					void GetAllConfigs(TalonFXConfiguration& allConfigs, int timeoutMs = 50);
					/**
					 * Configure the motor commutation type.
					 *
					 * @param motorCommutation  Motor Commutation Type.
					 *
					 * @param timeoutMs
					 *            Timeout value in ms. If nonzero, function will wait for config
					 *            success and report an error if it times out. If zero, no
					 *            blocking or checking is performed.
					 */
					ctre::phoenix::ErrorCode ConfigMotorCommutation(ctre::phoenix::motorcontrol::MotorCommutation motorCommutation, int timeoutMs = 0);
					/**
					 * @param timeoutMs
					 *            Timeout value in ms. If nonzero, function will wait for config
					 *            success and report an error if it times out.
					 * @return  The motor commutation type.
					 */
					ctre::phoenix::ErrorCode ConfigGetMotorCommutation(ctre::phoenix::motorcontrol::MotorCommutation & motorCommutation, int timeoutMs = 0);

					/**
				 * Sets the signage and range of the "Absolute Position" signal.
				 * Choose unsigned for an absolute range of [0,+1) rotations, [0,360) deg, etc...
				 * Choose signed for an absolute range of [-0.5,+0.5) rotations, [-180,+180) deg, etc...
				 * @param absoluteSensorRange
				 *            Desired Sign/Range for the absolute position register.
				 * @param timeoutMs
				 *            Timeout value in ms. If nonzero, function will wait for
				 *            config success and report an error if it times out.
				 *            If zero, no blocking or checking is performed.
				 * @return Error Code generated by function. 0 indicates no error.
				 */
					ErrorCode ConfigIntegratedSensorAbsoluteRange(ctre::phoenix::sensors::AbsoluteSensorRange absoluteSensorRange, int timeoutMs = 0);
					/**
					 * Adjusts the zero point for the absolute position register.
					 * The absolute position of the sensor will always have a discontinuity (360 -> 0 deg) or (+180 -> -180)
					 * and a hard-limited mechanism may have such a discontinuity in its functional range.
					 * In which case use this config to move the discontinuity outside of the function range.
					 * @param offsetDegrees
					 *            Offset in degrees (unit string and coefficient DO NOT apply for this config).
					 * @param timeoutMs
					 *            Timeout value in ms. If nonzero, function will wait for
					 *            config success and report an error if it times out.
					 *            If zero, no blocking or checking is performed.
					 * @return Error Code generated by function. 0 indicates no error.
					 */
					ErrorCode ConfigIntegratedSensorOffset(double offsetDegrees, int timeoutMs = 0);
					/**
					 * Pick the strategy on how to initialize the integrated sensor absolute position register.  Depending on the mechanism,
					 * it may be desirable to auto set the Position register to match the Absolute Position (swerve for example).
					 * Or it may be desired to zero the sensor on boot (drivetrain translation sensor or a relative servo).
					 *
					 * TIP: Tuner's self-test feature will report what the boot sensor value will be in the event the product is reset.
					 *
					 * @param initializationStrategy
					 *            The sensor initialization strategy to use.  This will impact the behavior the next time product boots up.
					 * @param timeoutMs
					 *            Timeout value in ms. If nonzero, function will wait for
					 *            config success and report an error if it times out.
					 *            If zero, no blocking or checking is performed.
					 * @return Error Code generated by function. 0 indicates no error.
					 */
					ErrorCode ConfigIntegratedSensorInitializationStrategy(ctre::phoenix::sensors::SensorInitializationStrategy initializationStrategy, int timeoutMs = 0);

					/* ----- virtual re-directs ------- */
					virtual void Set(ControlMode mode, double value);
					virtual void Set(ControlMode mode, double demand0, DemandType demand1Type, double demand1);
					virtual void SetInverted(InvertType invertType);
					virtual void SetInverted(bool bInvert);
					virtual ctre::phoenix::ErrorCode ConfigSelectedFeedbackSensor(FeedbackDevice feedbackDevice, int pidIdx = 0, int timeoutMs = 0);
					virtual ctre::phoenix::ErrorCode ConfigSelectedFeedbackSensor(RemoteFeedbackDevice feedbackDevice, int pidIdx = 0, int timeoutMs = 0);

				};// class TalonFX

			} // namespace can
		} // namespace motorcontrol
	} // namespace phoenix
} // namespace ctre

#if defined(WIN32) || defined(_WIN32) || defined(_WIN64)
#pragma warning (pop)
#endif
