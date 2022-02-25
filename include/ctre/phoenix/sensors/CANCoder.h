#pragma once

#include <cstdint>
#include "ctre/phoenix/CANBusAddressable.h"
#include "ctre/phoenix/CustomParamConfiguration.h"
#include "ctre/phoenix/ErrorCode.h"
#include "ctre/phoenix/paramEnum.h"
#include "ctre/phoenix/sensors/AbsoluteSensorRange.h"
#include "ctre/phoenix/sensors/CANCoderSimCollection.h"
#include "ctre/phoenix/sensors/CANCoderStatusFrame.h"
#include "ctre/phoenix/sensors/CANCoderStickyFaults.h"
#include "ctre/phoenix/sensors/CANCoderFaults.h"
#include "ctre/phoenix/sensors/SensorVelocityMeasPeriod.h"
#include "ctre/phoenix/sensors/SensorInitializationStrategy.h"
#include "ctre/phoenix/sensors/MagnetFieldStrength.h"
#include "ctre/phoenix/sensors/SensorTimeBase.h"

namespace ctre {
	namespace phoenix {
		namespace sensors {

			/**
			 * Configurables available to CANCoder
			 */
			struct CANCoderConfiguration : CustomParamConfiguration {
				/**
				 * Velocity measurement period to use
				 */
				SensorVelocityMeasPeriod velocityMeasurementPeriod = SensorVelocityMeasPeriod::Period_100Ms;
				/**
				 * Velocity measurement window to use
				 */
				int velocityMeasurementWindow = 64;
				/**
				 * Desired Sign / Range for the absolute position register.
				 * Choose unsigned for an absolute range of[0, +1) rotations, [0, 360) deg, etc.
				 * Choose signed for an absolute range of[-0.5, +0.5) rotations, [-180, +180) deg, etc.
				 */
				ctre::phoenix::sensors::AbsoluteSensorRange absoluteSensorRange = AbsoluteSensorRange::Unsigned_0_to_360;
				/**
				 * Adjusts the zero point for the absolute position register.
				 * The absolute position of the sensor will always have a discontinuity (360 -> 0 deg) or (+180 -> -180)
				 * and a hard-limited mechanism may have such a discontinuity in its functional range.
				 * In which case use this config to move the discontinuity outside of the function range.
				 */
				double magnetOffsetDegrees = 0;
				/**
				 * Choose which direction is interpreted as positive displacement.
				 * This affects both "Position"and "Absolute Position".
				 * False(default) means positive rotation occurs when magnet
				 * is spun counter - clockwise when observer is facing the LED side of CANCoder.
				 */
				bool sensorDirection = false;
				/**
				 * The sensor initialization strategy to use.This will impact the behavior the next time CANCoder boots up.
				 *
				 * Pick the strategy on how to initialize the CANCoder's "Position" register.  Depending on the mechanism,
				 * it may be desirable to auto set the Position register to match the Absolute Position(swerve for example).
				 * Or it may be desired to zero the sensor on boot(drivetrain translation sensor or a relative servo).
				 *
				 * TIP: Tuner's self-test feature will report what the boot sensor value will be in the event the CANCoder is reset.
				 */
				ctre::phoenix::sensors::SensorInitializationStrategy initializationStrategy = ctre::phoenix::sensors::SensorInitializationStrategy::BootToZero;
				/**
				 * Scalar to multiply the CANCoder's native 12-bit resolute sensor. Defaults to 0.087890625 to produce degrees.
				 */
				double sensorCoefficient = 360.0 / 4096.0;
				/**
				 * String holding the unit to report in.  This impacts all routines(except for ConfigMagnetOffset) and the self-test in Tuner.
				 * The string value itself is arbitrary.The max number of letters will depend on firmware versioning, but generally CANCoder
				 * supports up to eight letters.However, common units such as "centimeters" are supported explicitly despite exceeding the eight-letter limit.
				 * Default is "deg"
				 */
				std::string unitString = "deg";
				/**
				 * Desired denominator to report velocity in. This impacts GetVelocityand the reported velocity in self-test in Tuner.
				 * Default is "Per Second".
				 */
				ctre::phoenix::sensors::SensorTimeBase sensorTimeBase = ctre::phoenix::sensors::SensorTimeBase::PerSecond;

				/**
				 * Constructor
				 */
				CANCoderConfiguration() { }

				/**
				 * @return String representation of configs
				 */
				std::string toString() {
					return toString("");
				}

				/**
				 * @param prependString
				 *              String to prepend to configs
				 * @return String representation of configs
				 */
				std::string toString(std::string prependString) {

					std::string retstr;
					retstr += prependString + ".velocityMeasurementPeriod = " + SensorVelocityMeasPeriodRoutines::toString(velocityMeasurementPeriod) + ";\n";
					retstr += prependString + ".velocityMeasurementWindow = " + std::to_string(velocityMeasurementWindow) + ";\n";
					retstr += prependString + ".absoluteSensorRange = " + std::to_string(absoluteSensorRange) + ";\n";
					retstr += prependString + ".magnetOffsetDegrees = " + std::to_string(magnetOffsetDegrees) + ";\n";
					retstr += prependString + ".sensorDirection = " + std::to_string(sensorDirection) + ";\n";
					retstr += prependString + ".initializationStrategy = " + std::to_string(initializationStrategy) + ";\n";
					retstr += prependString + ".sensorCoefficient = " + std::to_string(sensorCoefficient) + ";\n";
					retstr += prependString + ".unitString = \"" + unitString.c_str() + "\";\n";
					retstr += prependString + ".sensorTimeBase = " + std::to_string(sensorTimeBase) + ";\n";
					retstr += CustomParamConfiguration::toString(prependString);

					return retstr;
				}

			};// struct CANCoderConfiguration

			/**
			 * Util class to help with configuring CANCoder
			 */
			struct CANCoderConfigUtils : CustomParamConfigUtil {
			private:
				static CANCoderConfiguration _default;
			public:
				/**
				 * Determine if specified value is different from default
				 * @param settings settings to compare against
				 * @return if specified value is different from default
				 * @{
				 */
				static bool VelocityMeasurementPeriodDifferent(const CANCoderConfiguration& settings) { return (!(settings.velocityMeasurementPeriod == _default.velocityMeasurementPeriod)) || !settings.enableOptimizations; }
				static bool VelocityMeasurementWindowDifferent(const CANCoderConfiguration& settings) { return (!(settings.velocityMeasurementWindow == _default.velocityMeasurementWindow)) || !settings.enableOptimizations; }
				static bool AbsoluteSensorRangeDifferent(const CANCoderConfiguration& settings) { return (!(settings.absoluteSensorRange == _default.absoluteSensorRange)) || !settings.enableOptimizations; }
				static bool MagnetOffsetDegreesDifferent(const CANCoderConfiguration& settings) { return (!(settings.magnetOffsetDegrees == _default.magnetOffsetDegrees)) || !settings.enableOptimizations; }
				static bool SensorDirectionDifferent(const CANCoderConfiguration& settings) { return (!(settings.sensorDirection == _default.sensorDirection)) || !settings.enableOptimizations; }
				static bool InitializationStrategyDifferent(const CANCoderConfiguration& settings) { return (!(settings.initializationStrategy == _default.initializationStrategy)) || !settings.enableOptimizations; }
				static bool SensorCoefficientDifferent(const CANCoderConfiguration& settings) { return (!(settings.sensorCoefficient == _default.sensorCoefficient)) || !settings.enableOptimizations; }
				static bool UnitStringDifferent(const CANCoderConfiguration& settings) { return (!(settings.unitString == _default.unitString)) || !settings.enableOptimizations; }
				static bool SensorTimeBaseDifferent(const CANCoderConfiguration& settings) { return (!(settings.sensorTimeBase == _default.sensorTimeBase)) || !settings.enableOptimizations; }
				/** @} */
			};


			/**
			 * CTRE CANCoder.
			 *
			 * <pre>
			 * {@code
			 * // Example usage of a CANCoder
			 * CANCoder cancoder{0}; // creates a new CANCoder with ID 0
			 *
			 * CANCoderConfiguration config;
			 * // set units of the CANCoder to radians, with velocity being radians per second
			 * config.sensorCoefficient = 2 * M_PI / 4096.0;
			 * config.unitString = "rad";
			 * config.sensorTimeBase = SensorTimeBase::PerSecond;
			 * cancoder.ConfigAllSettings(config);
			 *
			 * std::cout << cancoder.GetPosition() << std::endl; // prints the position of the CANCoder
			 * std::cout << cancoder.GetVelocity() << std::endl; // prints the velocity recorded by the CANCoder
			 *
			 * ErrorCode error = cancoder.GetLastError(); // gets the last error generated by the CANCoder
			 * CANCoderFaults faults;
			 * ErrorCode faultsError = cancoder.GetFaults(faults); // fills faults with the current CANCoder faults; returns the last error generated
			 *
			 * cancoder.SetStatusFramePeriod(CANCoderStatusFrame_SensorData, 10); // changes the period of the sensor data frame to 10ms
			 * }
			 * </pre>
			 */
			class CANCoder : public CANBusAddressable {
			public:
				/**
				 * Constructor.
				 * @param deviceNumber	The CAN Device ID of the CANCoder.
				 * @param canbus Name of the CANbus; can be a SocketCAN interface (on Linux),
				 *               or a CANivore device name or serial number
				 */
				CANCoder(int deviceNumber, std::string const &canbus = "");

				~CANCoder();

				/**
				 * Destructs all CANCoder objects
				 */
				static void DestroyAllCANCoders();


				/**
				 * Gets the position of the sensor.  This may be relative or absolute depending on configuration.
				 * The units are determined by the coefficient and unit-string configuration params, default is degrees.
				 * @return The position of the sensor.
				 */
				double GetPosition();
				/**
				 * Sets the position of the sensor.
				 * The units are determined by the coefficient and unit-string configuration params, default is degrees.
				 * @param newPosition
				 * @return ErrorCode generated by function. 0 indicates no error.
				 */
				double GetVelocity();
				/**
				 * Sets the position of the sensor.
				 * The units are determined by the coefficient and unit-string configuration params, default is degrees.
				 * @param newPosition
				 * @return ErrorCode generated by function. 0 indicates no error.
				 */
				ErrorCode SetPosition(double newPosition, int timeoutMs = 0);
				/**
				 * Sets the position of the sensor to match the magnet's "Absolute Sensor".
				 * The units are determined by the coefficient and unit-string configuration params, default is degrees.
				 * @return ErrorCode generated by function. 0 indicates no error.
				 */
				ErrorCode SetPositionToAbsolute(int timeoutMs = 0);

				/**
				 * Gets the absolute position of the sensor.
				 * The absolute position may be unsigned (for example: [0,360) deg), or signed (for example: [-180,+180) deg).  This is determined by a configuration.  The default selection is unsigned.
				 * The units are determined by the coefficient and unit-string configuration params, default is degrees.
				 * Note: this signal is not affected by calls to SetPosition().
				 * @return The position of the sensor.
				 */
				double GetAbsolutePosition();
				/**
				 * Configures the period of each velocity sample.
				 * Every 1ms a position value is sampled, and the delta between that sample
				 * and the position sampled kPeriod ms ago is inserted into a filter.
				 * kPeriod is configured with this function.
				 *
				 * @param period Desired period for the velocity measurement.
				 * @param timeoutMs Timeout value in ms. If nonzero, function will wait for
				 *            config success and report an error if it times out.
				 *            If zero, no blocking or checking is performed.
				 * @return Error Code generated by function. 0 indicates no error.
				 */
				ErrorCode ConfigVelocityMeasurementPeriod(SensorVelocityMeasPeriod period, int timeoutMs = 0);
				/**
				 * Sets the number of velocity samples used in the rolling average velocity
				 * measurement.
				 *
				 * @param windowSize Number of samples in the rolling average of velocity
				 *            measurement. Valid values are 1,2,4,8,16,32. If another
				 *            value is specified, it will truncate to nearest support value.
				 * @param timeoutMs Timeout value in ms. If nonzero, function will wait for
				 *            config success and report an error if it times out.
				 *            If zero, no blocking or checking is performed.
				 * @return Error Code generated by function. 0 indicates no error.
				 */
				ErrorCode ConfigVelocityMeasurementWindow(int windowSize, int timeoutMs = 0);
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
				ErrorCode ConfigAbsoluteSensorRange(ctre::phoenix::sensors::AbsoluteSensorRange absoluteSensorRange, int timeoutMs = 0);
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
				ErrorCode ConfigMagnetOffset(double offsetDegrees, int timeoutMs = 0);
				/**
				 * Pick the strategy on how to initialize the CANCoder's "Position" register.  Depending on the mechanism,
				 * it may be desirable to auto set the Position register to match the Absolute Position (swerve for example).
				 * Or it may be desired to zero the sensor on boot (drivetrain translation sensor or a relative servo).
				 *
				 * TIP: Tuner's self-test feature will report what the boot sensor value will be in the event the CANCoder is reset.
				 *
				 * @param initializationStrategy
				 *            The sensor initialization strategy to use.  This will impact the behavior the next time CANCoder boots up.
				 * @param timeoutMs
				 *            Timeout value in ms. If nonzero, function will wait for
				 *            config success and report an error if it times out.
				 *            If zero, no blocking or checking is performed.
				 * @return Error Code generated by function. 0 indicates no error.
				 */
				ErrorCode ConfigSensorInitializationStrategy(ctre::phoenix::sensors::SensorInitializationStrategy initializationStrategy, int timeoutMs = 0);
				/**
				 * Choose what units you want the API to get/set.  This also impacts the units displayed in Self-Test in Tuner.
				 * Depending on your mechanism, you may want to scale rotational units (deg, radians, rotations), or scale to a distance (inches, centimeters).
				 * @param sensorCoefficient
				 *            Scalar to multiply the CANCoder's native 12-bit resolute sensor. Defaults to 0.087890625 to produce degrees.
				 * @param unitString
				 *            String holding the unit to report in.  This impacts all routines (except for ConfigMagnetOffset) and the self-test in Tuner.
				 *            The string value itself is arbitrary.  The max number of letters will depend on firmware versioning, but generally CANCoder
				 *            supports up to eight letters.  However, common units such as "centimeters" are supported explicitly despite exceeding the eight-letter limit.
				 *			  Default is "deg"
				 * @param sensortimeBase
				 *            Desired denominator to report velocity in.  This impacts GetVelocity and the reported velocity in self-test in Tuner.
				 *            Default is "Per Second".
				 * @param timeoutMs
				 *            Timeout value in ms. If nonzero, function will wait for
				 *            config success and report an error if it times out.
				 *            If zero, no blocking or checking is performed.
				 * @return Error Code generated by function. 0 indicates no error.
				 */
				ErrorCode ConfigFeedbackCoefficient(double sensorCoefficient, const std::string& unitString, ctre::phoenix::sensors::SensorTimeBase sensortimeBase, int timeoutMs = 0);

				/**
				 * Gets the bus voltage seen by the device.
				 *
				 * @return The bus voltage value (in volts).
				 */
				double GetBusVoltage();
				/**
				 * Gets the magnet's health.
				 *
				 * @return The magnet health code (red/orange/green).
				 */
				ctre::phoenix::sensors::MagnetFieldStrength GetMagnetFieldStrength();

				/**
				 * Choose which direction is interpreted as positive displacement.
				 * This affects both "Position" and "Absolute Position".
				 * @param bSensorDirection
				 *            False (default) means positive rotation occurs when magnet
				 *            is spun counter-clockwise when observer is facing the LED side of CANCoder.
				 * @param timeoutMs
				 *            Timeout value in ms. If nonzero, function will wait for
				 *            config success and report an error if it times out.
				 *            If zero, no blocking or checking is performed.
				 * @return Error Code generated by function. 0 indicates no error.
				 */
				ErrorCode ConfigSensorDirection(bool bSensorDirection, int timeoutMs = 0);

				/**
				 * Call GetLastError() generated by this object.
				 * Not all functions return an error code but can
				 * potentially report errors.
				 *
				 * This function can be used to retrieve those error codes.
				 *
				 * @return The last ErrorCode generated.
				 */
				ErrorCode GetLastError();

				/**
				 * Get the units for the signal retrieved in the last called get routine.
				 */
				std::string GetLastUnitString();

				/**
				 *Get the timestamp of the CAN frame retrieved in the last called get routine.
				 */
				double GetLastTimestamp();

				/**
				 * Sets the value of a custom parameter. This is for arbitrary use.
				 *
				 * Sometimes it is necessary to save calibration/duty cycle/output
				 * information in the device. Particularly if the
				 * device is part of a subsystem that can be replaced.
				 *
				 * @param newValue  Value for custom parameter.
				 * @param paramIndex  Index of custom parameter. [0-1]
				 * @param timeoutMs  Timeout value in ms. If nonzero, function will wait for
				 *            config success and report an error if it times out.
				 *            If zero, no blocking or checking is performed.
				 * @return Error Code generated by function. 0 indicates no error.
				 */
				ErrorCode ConfigSetCustomParam(int newValue, int paramIndex,
					int timeoutMs = 0);
				/**
				 * Gets the value of a custom parameter. This is for arbitrary use.
				 *
				 * Sometimes it is necessary to save calibration/duty cycle/output
				 * information in the device. Particularly if the
				 * device is part of a subsystem that can be replaced.
				 *
				 * @param paramIndex Index of custom parameter. [0-1]
				 * @param timeoutMs  Timeout value in ms. If nonzero, function will wait for
				 *            config success and report an error if it times out.
				 *            If zero, no blocking or checking is performed.
				 * @return Value of the custom param.
				 */
				int ConfigGetCustomParam(int paramIndex,
					int timeoutMs = 0);
				//------ Generic Param API, typically not used ----------//
				/**
				 * Sets a parameter. Generally this is not used.
				 * This can be utilized in
				 * - Using new features without updating API installation.
				 * - Errata workarounds to circumvent API implementation.
				 * - Allows for rapid testing / unit testing of firmware.
				 *
				 * @param param Parameter enumeration.
				 * @param value Value of parameter.
				 * @param subValue  Subvalue for parameter. Maximum value of 255.
				 * @param ordinal  Ordinal of parameter.
				 * @param timeoutMs  Timeout value in ms. If nonzero, function will wait for
				 *            config success and report an error if it times out.
				 *            If zero, no blocking or checking is performed.
				 * @return Error Code generated by function. 0 indicates no error.
				 */
				ErrorCode ConfigSetParameter(ParamEnum param, double value,
					uint8_t subValue, int ordinal, int timeoutMs = 0);
				/**
				 * Gets a parameter. Generally this is not used.
				 * This can be utilized in
				 * - Using new features without updating API installation.
				 * - Errata workarounds to circumvent API implementation.
				 * - Allows for rapid testing / unit testing of firmware.
				 *
				 * @param param Parameter enumeration.
				 * @param ordinal  Ordinal of parameter.
				 * @param timeoutMs Timeout value in ms. If nonzero, function will wait for
				 *            config success and report an error if it times out.
				 *            If zero, no blocking or checking is performed.
				 * @return Value of parameter.
				 */
				double ConfigGetParameter(ParamEnum param, int ordinal, int timeoutMs = 0);

				/**
				 * Gets a parameter by passing an int by reference
				 *
				 * @param param
				 * 			  Parameter enumeration
				 * @param valueToSend
				 * 			  Value to send to parameter
				 * @param valueReceived
				 * 			  Reference to integer to receive
				 * @param subValue
				 * 			  SubValue of parameter
				 * @param ordinal
				 * 			  Ordinal of parameter
				 * @param timeoutMs
				 *            Timeout value in ms. If nonzero, function will wait for
				 *            config success and report an error if it times out.
				 *            If zero, no blocking or checking is performed.
				 * @return Error Code generated by function. 0 indicates no error.
				 */
				ErrorCode ConfigGetParameter(ParamEnum param, int32_t valueToSend,
					int32_t& valueReceived, uint8_t& subValue, int32_t ordinal,
					int32_t timeoutMs);


				/**
				 * Sets the period of the given status frame.
				 *
				 * @param statusFrame  Frame whose period is to be changed.
				 * @param periodMs Period in ms for the given frame.
				 * @param timeoutMs Timeout value in ms. If nonzero, function will wait for
				 *            config success and report an error if it times out.
				 *            If zero, no blocking or checking is performed.
				 * @return Error Code generated by function. 0 indicates no error.
				 */
				ErrorCode SetStatusFramePeriod(CANCoderStatusFrame statusFrame,
					uint8_t periodMs, int timeoutMs = 0);
				/**
				 * Gets the period of the given status frame.
				 *
				 * @param frame  Frame to get the period of.
				 * @param timeoutMs  Timeout value in ms. If nonzero, function will wait for
				 *            config success and report an error if it times out.
				 *            If zero, no blocking or checking is performed.
				 * @return Period of the given status frame.
				 */
				int GetStatusFramePeriod(CANCoderStatusFrame frame, int timeoutMs = 0);
				/**
				 * Gets the firmware version of the device.
				 *
				 * @return Firmware version of device.
				 */
				int GetFirmwareVersion();
				/**
				 * Returns true if the device has reset since last call.
				 *
				 * @return Has a Device Reset Occurred?
				 */
				bool HasResetOccurred();
				/**
				 * Gets the CANCoder fault status
				 *
				 * @param toFill
				 *            Container for fault statuses.
				 * @return Error Code generated by function. 0 indicates no error.
				 */
				ErrorCode GetFaults(CANCoderFaults& toFill);
				/**
				 * Gets the CANCoder sticky fault status
				 *
				 * @param toFill
				 *            Container for sticky fault statuses.
				 * @return Error Code generated by function. 0 indicates no error.
				 */
				ErrorCode GetStickyFaults(CANCoderStickyFaults& toFill);
				/**
				 * Clears the Sticky Faults
				 *
				 * @param timeoutMs Timeout value in ms. If nonzero, function will wait for
				 *            config success and report an error if it times out.
				 *            If zero, no blocking or checking is performed.
				 *
				 * @return Error Code generated by function. 0 indicates no error.
				 */
				ErrorCode ClearStickyFaults(int timeoutMs = 0);

				//------ All Configs ----------//
				/**
				 * Configures all persistent settings.
				 *
				 * @param allConfigs        Object with all of the persistant settings
				 * @param timeoutMs Timeout value in ms. If nonzero, function will wait for
				 *              config success and report an error if it times out.
				 *              If zero, no blocking or checking is performed.
				 *
				 * @return Error Code generated by function. 0 indicates no error.
				 */
				ctre::phoenix::ErrorCode ConfigAllSettings(const CANCoderConfiguration& allConfigs, int timeoutMs = 50);
				/**
				 * Gets all persistant settings.
				 *
				 * @param allConfigs        Object with all of the persistant settings
				 * @param timeoutMs Timeout value in ms. If nonzero, function will wait for
				 *              config success and report an error if it times out.
				 *              If zero, no blocking or checking is performed.
				 * @return Error Code generated by function. 0 indicates no error.
				 */
				ErrorCode GetAllConfigs(CANCoderConfiguration& allConfigs, int timeoutMs = 50);
				/**
				 * Configures all persistent settings to defaults (overloaded so timeoutMs is 50 ms).
				 *
				 * @param timeoutMs Timeout value in ms. If nonzero, function will wait for
				 *            config success and report an error if it times out.
				 *            If zero, no blocking or checking is performed.
				 *
				 * @return Error Code generated by function. 0 indicates no error.
				 */
				ErrorCode ConfigFactoryDefault(int timeoutMs = 50);

				/**
				 * @return object that can set simulation inputs.
				 */
				CANCoderSimCollection& GetSimCollection();

			private:
				void* m_handle;
				CANCoderSimCollection* _simCollection;

			};// class CANCoder

		} // namespace sensor
	} // namespace phoenix
} // namespace ctre
