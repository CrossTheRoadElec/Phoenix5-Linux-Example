#pragma once

#include "ctre/phoenix/ErrorCode.h"
#include <string>

namespace ctre {
	namespace phoenix {
		namespace motorcontrol {
			/**
			 * Choose the feedback device for a motor controller.
			 * Consult product specific documentation to determine what is available/supported.
			 */
			enum class FeedbackDevice {
				/**
				 * Quadrature encoder
				 */
				QuadEncoder = 0,
				/**
				 * TalonFX supports an integrated sensor.
				 */
				IntegratedSensor = 1,
				/**
				 * Analog potentiometer/encoder
				 */
				Analog = 2,
				//3
				/**
				 * Tachometer
				 */
				Tachometer = 4,
				/**
				 * CTRE Mag Encoder in Absolute mode or
				 * any other device that uses PWM to encode its output
				 */
				PulseWidthEncodedPosition = 8,
				/**
				 * Sum0 + Sum1
				 */
				SensorSum = 9,
				/**
				 * Diff0 - Diff1
				 */
				SensorDifference = 10,
				/**
				 * Sensor configured in RemoteFilter0
				 */
				RemoteSensor0 = 11,
				/**
				 * Sensor configured in RemoteFilter1
				 */
				RemoteSensor1 = 12,
				//13
				/**
				 * Position and velocity will read 0.
				 */
				None = 14,
				/**
				 * Motor Controller will fake a sensor based on applied motor output.
				 */
				SoftwareEmulatedSensor = 15,
				/**
				 * CTR mag encoder configured in absolute, is the same
				 * as a PWM sensor.
				 */
				CTRE_MagEncoder_Absolute = PulseWidthEncodedPosition,
				/**
				 * CTR mag encoder configured in relative, is the same
				 * as an quadrature encoder sensor.
				 */
				CTRE_MagEncoder_Relative = QuadEncoder,
			};
			/**
			 * Choose the feedback device for a Talon SRX
			 */
			enum class TalonSRXFeedbackDevice {
				/**
				 * Quadrature encoder
				 */
				QuadEncoder = 0,
				//1
				/**
				 * Analog potentiometer/encoder
				 */
				Analog = 2,
				//3
				/**
				 * Tachometer
				 */
				Tachometer = 4,
				/**
				 * CTRE Mag Encoder in Absolute mode or
				 * any other device that uses PWM to encode its output
				 */
				PulseWidthEncodedPosition = 8,
				/**
				 * Sum0 + Sum1
				 */
				SensorSum = 9,
				/**
				 * Diff0 - Diff1
				 */
				SensorDifference = 10,
				/**
				 * Sensor configured in RemoteFilter0
				 */
				RemoteSensor0 = 11,
				/**
				 * Sensor configured in RemoteFilter1
				 */
				RemoteSensor1 = 12,
				//13
				/**
				 * Position and velocity will read 0.
				 */
				None = 14,
				/**
				 * Motor Controller will fake a sensor based on applied motor output.
				 */
				SoftwareEmulatedSensor = 15,
				/**
				 * CTR mag encoder configured in absolute, is the same
				 * as a PWM sensor.
				 */
				CTRE_MagEncoder_Absolute = PulseWidthEncodedPosition,
				/**
				 * CTR mag encoder configured in relative, is the same
				 * as an quadrature encoder sensor.
				 */
				CTRE_MagEncoder_Relative = QuadEncoder,
			};
			/**
			 * Choose the feedback device for a Talon FX/Falcon 500.
			 */
			enum class TalonFXFeedbackDevice {
				//0
				/**
				 * TalonFX supports an integrated sensor.
				 */
				IntegratedSensor = 1,
				/**
				 * Sum0 + Sum1
				 */
				SensorSum = 9,
				/**
				 * Diff0 - Diff1
				 */
				SensorDifference = 10,
				/**
				 * Sensor configured in RemoteFilter0
				 */
				RemoteSensor0 = 11,
				/**
				 * Sensor configured in RemoteFilter1
				 */
				RemoteSensor1 = 12,
				//13
				/**
				 * Position and velocity will read 0.
				 */
				None = 14,
				/**
				 * Motor Controller will fake a sensor based on applied motor output.
				 */
				SoftwareEmulatedSensor = 15,
			};
			/**
			 * Choose the remote feedback device for a motor controller.
			 */
			enum class RemoteFeedbackDevice {
				/**
				 * [[deprecated("Use None instead.")]]
				 * Factory default setting for non-enhanced motor controllers
				 */
				RemoteFeedbackDevice_FactoryDefaultOff = 0,
				/**
				 * [[deprecated("Use None instead.")]]
				 * Factory default setting for non-enhanced motor controllers
				 */
				FactoryDefaultOff = RemoteFeedbackDevice_FactoryDefaultOff,
				/**
				 * [[deprecated("Use SensorSum instead.")]]
				 * Use Sum0 + Sum1
				 */
				RemoteFeedbackDevice_SensorSum = 9,
				/**
				 * Use Sum0 + Sum1
				 */
				SensorSum = RemoteFeedbackDevice_SensorSum,
				/**
				 * [[deprecated("Use SensorDifference instead.")]]
				 * Use Diff0 - Diff1
				 */
				RemoteFeedbackDevice_SensorDifference = 10,
				/**
				 * Use Diff0 - Diff1
				 */
				SensorDifference = RemoteFeedbackDevice_SensorDifference,
				/**
				 * [[deprecated("Use RemoteSensor0 instead.")]]
				 * Use the sensor configured
				 * in filter0
				 */
				RemoteFeedbackDevice_RemoteSensor0 = 11,
				/**
				 * Use the sensor configured
				 * in filter0
				 */
				RemoteSensor0 = RemoteFeedbackDevice_RemoteSensor0,
				/**
				 * [[deprecated("Use RemoteSensor1 instead.")]]
				 * Use the sensor configured
				 * in filter1
				 */
				RemoteFeedbackDevice_RemoteSensor1 = 12,
				/**
				 * Use the sensor configured
				 * in filter1
				 */
				RemoteSensor1 = RemoteFeedbackDevice_RemoteSensor1,
				//13
				/**
				 * [[deprecated("Use None instead.")]]
				 * Position and velocity will read 0.
				 */
				RemoteFeedbackDevice_None = 14,
				/**
				 * Position and velocity will read 0.
				 */
				None = RemoteFeedbackDevice_None,
				/**
				 * [[deprecated("Use SoftwareEmulatedSensor instead.")]]
				 * Motor Controller will fake a sensor based on applied motor output.
				 */
				RemoteFeedbackDevice_SoftwareEmulatedSensor = 15,
				/**
				 * Motor Controller will fake a sensor based on applied motor output.
				 */
				SoftwareEmulatedSensor = RemoteFeedbackDevice_SoftwareEmulatedSensor,
			};
			/**
			 * Class to handle feedback device routines
			 */
			class FeedbackDeviceRoutines {
			public:
				/**
				 * Gets the string representation of selected feedback device
				 * @param value feedback device to get string representation of
				 * @return String representation of selected feedback device
				 */
				static std::string toString(FeedbackDevice value) {
					switch (value) {
						case FeedbackDevice::QuadEncoder: return "QuadEncoder";
						case FeedbackDevice::IntegratedSensor: return "Integrated Sensor";
						case FeedbackDevice::Analog: return "Analog";
						case FeedbackDevice::Tachometer: return "Tachometer";
						case FeedbackDevice::PulseWidthEncodedPosition: return "PulseWidthEncodedPosition";
						case FeedbackDevice::SensorSum: return "SensorSum";
						case FeedbackDevice::SensorDifference: return "SensorDifference";
						case FeedbackDevice::RemoteSensor0: return "RemoteSensor0";
						case FeedbackDevice::RemoteSensor1: return "RemoteSensor1";
						case FeedbackDevice::None: return "None";
						case FeedbackDevice::SoftwareEmulatedSensor: return "SoftwareEmulatedSensor";
						default: return "InvalidValue";
					}
				}
				/**
				 * Gets the string representation of selected feedback device
				 * @param value feedback device to get string representation of
				 * @return String representation of selected feedback device
				 */
				static std::string toString(TalonSRXFeedbackDevice value) {
					switch (value) {
						case TalonSRXFeedbackDevice::QuadEncoder: return "QuadEncoder";
						case TalonSRXFeedbackDevice::Analog: return "Analog";
						case TalonSRXFeedbackDevice::Tachometer: return "Tachometer";
						case TalonSRXFeedbackDevice::PulseWidthEncodedPosition: return "PulseWidthEncodedPosition";
						case TalonSRXFeedbackDevice::SensorSum: return "SensorSum";
						case TalonSRXFeedbackDevice::SensorDifference: return "SensorDifference";
						case TalonSRXFeedbackDevice::RemoteSensor0: return "RemoteSensor0";
						case TalonSRXFeedbackDevice::RemoteSensor1: return "RemoteSensor1";
						case TalonSRXFeedbackDevice::None: return "None";
						case TalonSRXFeedbackDevice::SoftwareEmulatedSensor: return "SoftwareEmulatedSensor";
						default: return "InvalidValue";
					}
				}
				/**
				 * Gets the string representation of selected feedback device
				 * @param value feedback device to get string representation of
				 * @return String representation of selected feedback device
				 */
				static std::string toString(TalonFXFeedbackDevice value) {
					switch (value) {
						case TalonFXFeedbackDevice::IntegratedSensor: return "Integrated Sensor";
						case TalonFXFeedbackDevice::SensorSum: return "SensorSum";
						case TalonFXFeedbackDevice::SensorDifference: return "SensorDifference";
						case TalonFXFeedbackDevice::RemoteSensor0: return "RemoteSensor0";
						case TalonFXFeedbackDevice::RemoteSensor1: return "RemoteSensor1";
						case TalonFXFeedbackDevice::None: return "None";
						case TalonFXFeedbackDevice::SoftwareEmulatedSensor: return "SoftwareEmulatedSensor";
						default: return "InvalidValue";
					}
				}
				/**
				 * Gets the string representation of selected remote feedback device
				 * @param value remote feedback device to get string representation of
				 * @return String representation of selected remote feedback device
				 */
				static std::string toString(RemoteFeedbackDevice value) {
					switch (value) {
						case RemoteFeedbackDevice::FactoryDefaultOff: return "None (factory default value)";
						case RemoteFeedbackDevice::None: return "None";
						case RemoteFeedbackDevice::SensorSum: return "SensorSum";
						case RemoteFeedbackDevice::SensorDifference: return "SensorDifference";
						case RemoteFeedbackDevice::RemoteSensor0: return "RemoteSensor0";
						case RemoteFeedbackDevice::RemoteSensor1: return "RemoteSensor1";
						case RemoteFeedbackDevice::SoftwareEmulatedSensor: return "SoftwareEmulatedSensor";
						default: return "InvalidValue";
					}
				}
			};
		} // namespace motorcontrol
	} // namespace phoenix
} // namespace ctre
