#pragma once
#if defined(WIN32) || defined(_WIN32) || defined(_WIN64)
#pragma warning (push)
#pragma warning (disable : 4250)
#endif

#include "ctre/phoenix/motorcontrol/can/BaseMotorController.h"
#include "ctre/phoenix/motorcontrol/IMotorControllerEnhanced.h"
#include "ctre/phoenix/motorcontrol/SupplyCurrentLimitConfiguration.h"
#include "ctre/phoenix/CustomParamConfiguration.h"
#include "ctre/phoenix/motorcontrol/SensorCollection.h"
#include "ctre/phoenix/motorcontrol/TalonFXSensorCollection.h"
#include "ctre/phoenix/motorcontrol/TalonSRXSimCollection.h"
#include "ctre/phoenix/motorcontrol/TalonFXSimCollection.h"

/* forward proto's */
namespace ctre {
	namespace phoenix {
		namespace motorcontrol {
			class SensorCollection;
		}
	}
}

namespace ctre {
	namespace phoenix {
		namespace motorcontrol {
			namespace can {

				/**
				 * Configurables available to BaseTalon's PID
				 */
				struct BaseTalonPIDSetConfiguration : BasePIDSetConfiguration {
					/**
					 * Feedback device for a particular PID loop.
					 * Note the FeedbackDevice enum holds all possible sensor types.  Consult product documentation to confirm what is available.
					 * Alternatively the product specific enum can be used instead.
					 *	@code
					 *	configs.primaryPID.selectedFeedbackSensor = (FeedbackDevice)TalonSRXFeedbackDevice::QuadEncoder;
					 *	configs.primaryPID.selectedFeedbackSensor = (FeedbackDevice)TalonFXFeedbackDevice::IntegratedSensor;
					 *	@endcode
					 */
					FeedbackDevice selectedFeedbackSensor;

					BaseTalonPIDSetConfiguration(FeedbackDevice defaultFeedbackDevice) :
						selectedFeedbackSensor(defaultFeedbackDevice)
					{
					}

					/**
					 * @return string representation of configs
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

						std::string retstr = prependString + ".selectedFeedbackSensor = " + FeedbackDeviceRoutines::toString(selectedFeedbackSensor) + ";\n";
						retstr += BasePIDSetConfiguration::toString(prependString);
						return retstr;
					}
				};

				/**
				 * Util class to help with BaseTalon's PID configs
				 */
				struct BaseTalonPIDSetConfigUtil {
				private:
					static BaseTalonPIDSetConfiguration _default;
				public:
					/* Default feedback sensor is product specific. In order to ensure user always gets what they expect when selecting feedback sensor,
					   SelectedFeedbackSensorDifferent will always return true */

					/**
					 * Determine if specified value is different from default
					 * @param settings settings to compare against
					 * @return if specified value is different from default
					 * @{
					 */
					static bool SelectedFeedbackSensorDifferent(const BaseTalonPIDSetConfiguration& settings) { (void) settings; return true; } //{ return (!(settings.selectedFeedbackSensor == _default.selectedFeedbackSensor)); }
					static bool SelectedFeedbackCoefficientDifferent(const BaseTalonPIDSetConfiguration& settings) { return (!(settings.selectedFeedbackCoefficient == _default.selectedFeedbackCoefficient)); }
					/** @} */
				};


				/**
				 * Configurables available to BaseTalon
				 */
				struct BaseTalonConfiguration : BaseMotorControllerConfiguration {
					/**
					 * Primary PID configuration
					 */
					BaseTalonPIDSetConfiguration primaryPID;
					/**
					 * Auxiliary PID configuration
					 */
					BaseTalonPIDSetConfiguration auxiliaryPID;
					/**
					 * Forward Limit Switch Source
					 *
					 * User can choose between the feedback connector, remote Talon SRX, CANifier, or deactivate the feature
					 */
					LimitSwitchSource forwardLimitSwitchSource;
					/**
					 * Reverse Limit Switch Source
					 *
					 * User can choose between the feedback connector, remote Talon SRX, CANifier, or deactivate the feature
					 */
					LimitSwitchSource reverseLimitSwitchSource;
					/**
					 * Forward limit switch device ID
					 *
					 * Limit Switch device id isn't used unless device is a remote
					 */
					int forwardLimitSwitchDeviceID;
					/**
					 * Reverse limit switch device ID
					 *
					 * Limit Switch device id isn't used unless device is a remote
					 */
					int reverseLimitSwitchDeviceID;
					/**
					 * Forward limit switch normally open/closed
					 */
					LimitSwitchNormal forwardLimitSwitchNormal;
					/**
					 * Reverse limit switch normally open/closed
					 */
					LimitSwitchNormal reverseLimitSwitchNormal;
					/**
					 * Feedback Device for Sum 0 Term
					 * Note the FeedbackDevice enum holds all possible sensor types.  Consult product documentation to confirm what is available.
					 * Alternatively the product specific enum can be used instead.
					 *	@code
					 *	configs.sum0Term = (FeedbackDevice)TalonSRXFeedbackDevice::QuadEncoder;
					 *	configs.sum0Term = (FeedbackDevice)TalonFXFeedbackDevice::IntegratedSensor;
					 *	@endcode
					 */
					FeedbackDevice sum0Term;
					/**
					 * Feedback Device for Sum 1 Term
					 * Note the FeedbackDevice enum holds all possible sensor types.  Consult product documentation to confirm what is available.
					 * Alternatively the product specific enum can be used instead.
					 *	@code
					 *	configs.sum1Term = (FeedbackDevice)TalonSRXFeedbackDevice::QuadEncoder;
					 *	configs.sum1Term = (FeedbackDevice)TalonFXFeedbackDevice::IntegratedSensor;
					 *	@endcode
					 */
					FeedbackDevice sum1Term;
					/**
					 * Feedback Device for Diff 0 Term
					 * Note the FeedbackDevice enum holds all possible sensor types.  Consult product documentation to confirm what is available.
					 * Alternatively the product specific enum can be used instead.
					 *	@code
					 *	configs.diff0Term = (FeedbackDevice)TalonSRXFeedbackDevice::QuadEncoder;
					 *	configs.diff0Term = (FeedbackDevice)TalonFXFeedbackDevice::IntegratedSensor;
					 *	@endcode
					 */
					FeedbackDevice diff0Term;
					/**
					 * Feedback Device for Diff 1 Term
					 * Note the FeedbackDevice enum holds all possible sensor types.  Consult product documentation to confirm what is available.
					 * Alternatively the product specific enum can be used instead.
					 *	@code
					 *	configs.diff1Term = (FeedbackDevice)TalonSRXFeedbackDevice::QuadEncoder;
					 *	configs.diff1Term = (FeedbackDevice)TalonFXFeedbackDevice::IntegratedSensor;
					 *	@endcode
					 */
					FeedbackDevice diff1Term;

					BaseTalonConfiguration(FeedbackDevice defaultFeedbackDevice) :
						primaryPID(defaultFeedbackDevice),
						auxiliaryPID(defaultFeedbackDevice),
						forwardLimitSwitchSource(LimitSwitchSource_FeedbackConnector),
						reverseLimitSwitchSource(LimitSwitchSource_FeedbackConnector),
						forwardLimitSwitchDeviceID(0),
						reverseLimitSwitchDeviceID(0),
						forwardLimitSwitchNormal(LimitSwitchNormal_NormallyOpen),
						reverseLimitSwitchNormal(LimitSwitchNormal_NormallyOpen),
						sum0Term(defaultFeedbackDevice),
						sum1Term(defaultFeedbackDevice),
						diff0Term(defaultFeedbackDevice),
						diff1Term(defaultFeedbackDevice)
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


						std::string retstr = primaryPID.toString(prependString + ".primaryPID");
						retstr += auxiliaryPID.toString(prependString + ".auxiliaryPID");
						retstr += prependString + ".forwardLimitSwitchSource = " + LimitSwitchRoutines::toString(forwardLimitSwitchSource) + ";\n";
						retstr += prependString + ".reverseLimitSwitchSource = " + LimitSwitchRoutines::toString(reverseLimitSwitchSource) + ";\n";
						retstr += prependString + ".forwardLimitSwitchDeviceID = " + std::to_string(forwardLimitSwitchDeviceID) + ";\n";
						retstr += prependString + ".reverseLimitSwitchDeviceID = " + std::to_string(reverseLimitSwitchDeviceID) + ";\n";
						retstr += prependString + ".forwardLimitSwitchNormal = " + LimitSwitchRoutines::toString(forwardLimitSwitchNormal) + ";\n";
						retstr += prependString + ".reverseLimitSwitchNormal = " + LimitSwitchRoutines::toString(reverseLimitSwitchNormal) + ";\n";
						retstr += prependString + ".sum0Term = " + FeedbackDeviceRoutines::toString(sum0Term) + ";\n";
						retstr += prependString + ".sum1Term = " + FeedbackDeviceRoutines::toString(sum1Term) + ";\n";
						retstr += prependString + ".diff0Term = " + FeedbackDeviceRoutines::toString(diff0Term) + ";\n";
						retstr += prependString + ".diff1Term = " + FeedbackDeviceRoutines::toString(diff1Term) + ";\n";
						retstr += BaseMotorControllerConfiguration::toString(prependString);

						return retstr;
					}
				};// struct BaseTalonConfiguration

				/**
				 * Util class to help with talon configs
				 */
				class BaseTalonConfigUtil {
				private:
					static struct BaseTalonConfiguration _default;
				public:
					/* Default feedback sensor is product specific. In order to ensure user always gets what they expect when selecting feedback sensor,
					   (Sum/Diff)(0/1)TermDifferent will always return true */

					/**
					 * Determine if specified value is different from default
					 * @param settings settings to compare against
					 * @return if specified value is different from default
					 * @{
					 */
					static bool ForwardLimitSwitchSourceDifferent(const BaseTalonConfiguration& settings) { return (!(settings.forwardLimitSwitchSource == _default.forwardLimitSwitchSource)) || !settings.enableOptimizations; }
					static bool ReverseLimitSwitchSourceDifferent(const BaseTalonConfiguration& settings) { return (!(settings.reverseLimitSwitchSource == _default.reverseLimitSwitchSource)) || !settings.enableOptimizations; }
					static bool ForwardLimitSwitchDeviceIDDifferent(const BaseTalonConfiguration& settings) { return (!(settings.forwardLimitSwitchDeviceID == _default.forwardLimitSwitchDeviceID)) || !settings.enableOptimizations; }
					static bool ReverseLimitSwitchDeviceIDDifferent(const BaseTalonConfiguration& settings) { return (!(settings.reverseLimitSwitchDeviceID == _default.reverseLimitSwitchDeviceID)) || !settings.enableOptimizations; }
					static bool ForwardLimitSwitchNormalDifferent(const BaseTalonConfiguration& settings) { return (!(settings.forwardLimitSwitchNormal == _default.forwardLimitSwitchNormal)) || !settings.enableOptimizations; }
					static bool ReverseLimitSwitchNormalDifferent(const BaseTalonConfiguration& settings) { return (!(settings.reverseLimitSwitchNormal == _default.reverseLimitSwitchNormal)) || !settings.enableOptimizations; }
					static bool Sum0TermDifferent(const BaseTalonConfiguration& settings) { (void) settings; return true; } //{ return (!(settings.sum0Term == _default.sum0Term)) || !settings.enableOptimizations; }
					static bool Sum1TermDifferent(const BaseTalonConfiguration& settings) { (void) settings; return true; } //{ return (!(settings.sum1Term == _default.sum1Term)) || !settings.enableOptimizations; }
					static bool Diff0TermDifferent(const BaseTalonConfiguration& settings) { (void) settings; return true; } //{ return (!(settings.diff0Term == _default.diff0Term)) || !settings.enableOptimizations; }
					static bool Diff1TermDifferent(const BaseTalonConfiguration& settings) { (void) settings; return true; } //{ return (!(settings.diff1Term == _default.diff1Term)) || !settings.enableOptimizations; }

					static bool ForwardLimitSwitchDifferent(const BaseTalonConfiguration& settings) {
						return ForwardLimitSwitchDeviceIDDifferent(settings) || ForwardLimitSwitchNormalDifferent(settings) || ForwardLimitSwitchSourceDifferent(settings);
					}
					static bool ReverseLimitSwitchDifferent(const BaseTalonConfiguration& settings) {
						return ReverseLimitSwitchDeviceIDDifferent(settings) || ReverseLimitSwitchNormalDifferent(settings) || ReverseLimitSwitchSourceDifferent(settings);
					}
					/** @} */
				};

				/**
				 * CTRE Talon SRX Motor Controller when used on CAN Bus.
				 */
				class BaseTalon : public virtual BaseMotorController, public virtual IMotorControllerEnhanced
				{
				private:
					ctre::phoenix::motorcontrol::SensorCollection* _sensorCollSrx;
					ctre::phoenix::motorcontrol::TalonFXSensorCollection* _sensorCollFx;

					ctre::phoenix::motorcontrol::TalonSRXSimCollection* _simCollSrx;
					ctre::phoenix::motorcontrol::TalonFXSimCollection* _simCollFx;

				protected:
					ctre::phoenix::motorcontrol::SensorCollection& GetTalonSRXSensorCollection() { return *_sensorCollSrx; }
					ctre::phoenix::motorcontrol::TalonFXSensorCollection& GetTalonFXSensorCollection() { return *_sensorCollFx; }

					ctre::phoenix::motorcontrol::TalonSRXSimCollection& GetTalonSRXSimCollection() { return *_simCollSrx; }
					ctre::phoenix::motorcontrol::TalonFXSimCollection& GetTalonFXSimCollection() { return *_simCollFx; }

					ctre::phoenix::ErrorCode ConfigurePID(const BaseTalonPIDSetConfiguration& pid, int pidIdx, int timeoutMs, bool enableOptimizations);


					//------ All Configs ----------//
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
					void GetPIDConfigs(BaseTalonPIDSetConfiguration& pid, int pidIdx = 0, int timeoutMs = 50);
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
					ctre::phoenix::ErrorCode BaseTalonConfigAllSettings(const BaseTalonConfiguration& allConfigs, int timeoutMs = 50);
					/**
					 * Gets all persistant settings.
					 *
					 * @param allConfigs        Object with all of the persistant settings
					 * @param timeoutMs
					 *              Timeout value in ms. If nonzero, function will wait for
					 *              config success and report an error if it times out.
					 *              If zero, no blocking or checking is performed.
					 */
					void BaseTalonGetAllConfigs(BaseTalonConfiguration& allConfigs, int timeoutMs = 50);
				public:
					/**
					 * Constructor for a Talon
					 * @param deviceNumber CAN Device ID of BaseTalon
					 * @param canbus Name of the CANbus; can be a SocketCAN interface (on Linux),
					 *               or a CANivore device name or serial number
					 */
					BaseTalon(int deviceNumber, const char* model, std::string const &canbus = "");
					virtual ~BaseTalon();
					BaseTalon() = delete;
					BaseTalon(BaseTalon const&) = delete;
					BaseTalon& operator=(BaseTalon const&) = delete;

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
					virtual ctre::phoenix::ErrorCode ConfigSelectedFeedbackSensor(FeedbackDevice feedbackDevice, int pidIdx = 0, int timeoutMs = 0);
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
					virtual ctre::phoenix::ErrorCode ConfigSelectedFeedbackSensor(RemoteFeedbackDevice feedbackDevice, int pidIdx = 0, int timeoutMs = 0);

					/**
					 * Sets the period of the given status frame.
					 *
					 * User ensure CAN Bus utilization is not high.
					 *
					 * This setting is not persistent and is lost when device is reset.
					 * If this is a concern, calling application can use HasResetOccurred()
					 * to determine if the status frame needs to be reconfigured.
					 *
					 * @param frame
					 *            Frame whose period is to be changed.
					 * @param periodMs
					 *            Period in ms for the given frame.
					 * @param timeoutMs
					 *            Timeout value in ms. If nonzero, function will wait for
					 *            config success and report an error if it times out.
					 *            If zero, no blocking or checking is performed.
					 * @return Error Code generated by function. 0 indicates no error.
					 */
					virtual ctre::phoenix::ErrorCode SetStatusFramePeriod(StatusFrameEnhanced frame, uint8_t periodMs, int timeoutMs = 0);
					/**
					 * Sets the period of the given status frame.
					 *
					 * User ensure CAN Bus utilization is not high.
					 *
					 * This setting is not persistent and is lost when device is reset.
					 * If this is a concern, calling application can use HasResetOccurred()
					 * to determine if the status frame needs to be reconfigured.
					 *
					 * @param frame
					 *            Frame whose period is to be changed.
					 * @param periodMs
					 *            Period in ms for the given frame.
					 * @param timeoutMs
					 *            Timeout value in ms. If nonzero, function will wait for
					 *            config success and report an error if it times out.
					 *            If zero, no blocking or checking is performed.
					 * @return Error Code generated by function. 0 indicates no error.
					 */
					virtual ctre::phoenix::ErrorCode SetStatusFramePeriod(StatusFrame frame, uint8_t periodMs, int timeoutMs = 0);

					/**
					 * Gets the period of the given status frame.
					 *
					 * @param frame
					 *            Frame to get the period of.
					 * @param timeoutMs
					 *            Timeout value in ms. If nonzero, function will wait for
					 *            config success and report an error if it times out.
					 *            If zero, no blocking or checking is performed.
					 * @return Period of the given status frame.
					 */
					virtual int GetStatusFramePeriod(StatusFrameEnhanced frame, int timeoutMs = 0);
					/**
					 * Gets the period of the given status frame.
					 *
					 * @param frame
					 *            Frame to get the period of.
					 * @param timeoutMs
					 *            Timeout value in ms. If nonzero, function will wait for
					 *            config success and report an error if it times out.
					 *            If zero, no blocking or checking is performed.
					 * @return Period of the given status frame.
					 */
					virtual int GetStatusFramePeriod(StatusFrame frame, int timeoutMs = 0);

					//------ General Status ----------//
					/**
					 * Gets the output current of the motor controller.
					 * In the case of TalonSRX class, this routine returns supply current for legacy reasons.  In order to get the "true" output current, call GetStatorCurrent().
					 * In the case of TalonFX class, this routine returns the true output stator current.
					 *
					 * [[deprecated("Use GetStatorCurrent/GetSupplyCurrent instead.")]]
					 *
					 * @return The output current (in amps).
					 */
					virtual double GetOutputCurrent();

					/**
					 * Gets the stator/output current of the motor controller.
					 *
					 * @return The stator/output current (in amps).
					 */
					double GetStatorCurrent();

					/**
					 * Gets the supply/input current of the motor controller.
					 *
					 * @return The supply/input current (in amps).
					 */
					double GetSupplyCurrent();

					//------ Velocity measurement ----------//
					/**
					 * Configures the period of each velocity sample.
					 * Every 1ms a position value is sampled, and the delta between that sample
					 * and the position sampled kPeriod ms ago is inserted into a filter.
					 * kPeriod is configured with this function.
					 *
					 * @param period
					 *            Desired period for the velocity measurement. @see
					 *            #SensorVelocityMeasPeriod
					 * @param timeoutMs
					 *            Timeout value in ms. If nonzero, function will wait for
					 *            config success and report an error if it times out.
					 *            If zero, no blocking or checking is performed.
					 * @return Error Code generated by function. 0 indicates no error.
					 */
					virtual ctre::phoenix::ErrorCode ConfigVelocityMeasurementPeriod(ctre::phoenix::sensors::SensorVelocityMeasPeriod period,
						int timeoutMs = 0);

					[[deprecated("Use the overload with SensorVelocityMeasPeriod instead.")]]
					virtual ctre::phoenix::ErrorCode ConfigVelocityMeasurementPeriod(VelocityMeasPeriod period,
						int timeoutMs = 0);
					/**
					 * Sets the number of velocity samples used in the rolling average velocity
					 * measurement.
					 *
					 * @param windowSize
					 *            Number of samples in the rolling average of velocity
					 *            measurement. Valid values are 1,2,4,8,16,32. If another
					 *            value is specified, it will truncate to nearest support value.
					 * @param timeoutMs
					 *            Timeout value in ms. If nonzero, function will wait for
					 *            config success and report an error if it times out.
					 *            If zero, no blocking or checking is performed.
					 * @return Error Code generated by function. 0 indicates no error.
					 */
					virtual ctre::phoenix::ErrorCode ConfigVelocityMeasurementWindow(int windowSize,
						int timeoutMs = 0);

					//------ limit switch ----------//
					/**
					 * Configures a limit switch for a local/remote source.
					 *
					 * For example, a CAN motor controller may need to monitor the Limit-R pin
					 * of another Talon, CANifier, or local Gadgeteer feedback connector.
					 *
					 * If the sensor is remote, a device ID of zero is assumed.
					 * If that's not desired, use the four parameter version of this function.
					 *
					 * @param limitSwitchSource
					 *            Limit switch source.
					 *            User can choose between the feedback connector, remote Talon SRX, CANifier, or deactivate the feature.
					 * @param normalOpenOrClose
					 *            Setting for normally open, normally closed, or disabled. This setting
					 *            matches the Phoenix Tuner drop down.
					 * @param timeoutMs
					 *            Timeout value in ms. If nonzero, function will wait for
					 *            config success and report an error if it times out.
					 *            If zero, no blocking or checking is performed.
					 * @return Error Code generated by function. 0 indicates no error.
					 */
					virtual ctre::phoenix::ErrorCode ConfigForwardLimitSwitchSource(
						LimitSwitchSource limitSwitchSource,
						LimitSwitchNormal normalOpenOrClose, int timeoutMs = 0);
					/**
					 * Configures a limit switch for a local/remote source.
					 *
					 * For example, a CAN motor controller may need to monitor the Limit-R pin
					 * of another Talon, CANifier, or local Gadgeteer feedback connector.
					 *
					 * If the sensor is remote, a device ID of zero is assumed.
					 * If that's not desired, use the four parameter version of this function.
					 *
					 * @param limitSwitchSource
					 *            Limit switch source.
					 *            User can choose between the feedback connector, remote Talon SRX, CANifier, or deactivate the feature.
					 * @param normalOpenOrClose
					 *            Setting for normally open, normally closed, or disabled. This setting
					 *            matches the Phoenix Tuner drop down.
					 * @param deviceID
					 *            Device ID of remote source (Talon SRX or CANifier device ID).
					 * @param timeoutMs
					 *            Timeout value in ms. If nonzero, function will wait for
					 *            config success and report an error if it times out.
					 *            If zero, no blocking or checking is performed.
					 * @return Error Code generated by function. 0 indicates no error.
					 */
					virtual ctre::phoenix::ErrorCode ConfigForwardLimitSwitchSource(
						RemoteLimitSwitchSource limitSwitchSource,
						LimitSwitchNormal normalOpenOrClose, int deviceID, int timeoutMs = 0);
					/**
					 * Configures a limit switch for a local/remote source.
					 *
					 * For example, a CAN motor controller may need to monitor the Limit-R pin
					 * of another Talon, CANifier, or local Gadgeteer feedback connector.
					 *
					 * If the sensor is remote, a device ID of zero is assumed. If that's not
					 * desired, use the four parameter version of this function.
					 *
					 * @param limitSwitchSource
					 *            Limit switch source. @see #LimitSwitchSource User can choose
					 *            between the feedback connector, remote Talon SRX, CANifier, or
					 *            deactivate the feature.
					 * @param normalOpenOrClose
					 *            Setting for normally open, normally closed, or disabled. This
					 *            setting matches the Phoenix Tuner drop down.
					 * @param timeoutMs
					 *            Timeout value in ms. If nonzero, function will wait for config
					 *            success and report an error if it times out. If zero, no
					 *            blocking or checking is performed.
					 * @return Error Code generated by function. 0 indicates no error.
					 */
					virtual ctre::phoenix::ErrorCode ConfigReverseLimitSwitchSource(
						LimitSwitchSource limitSwitchSource,
						LimitSwitchNormal normalOpenOrClose, int timeoutMs = 0);
					/**
					 * Configures a limit switch for a local/remote source.
					 *
					 * For example, a CAN motor controller may need to monitor the Limit-R pin
					 * of another Talon, CANifier, or local Gadgeteer feedback connector.
					 *
					 * If the sensor is remote, a device ID of zero is assumed. If that's not
					 * desired, use the four parameter version of this function.
					 *
					 * @param limitSwitchSource
					 *            Limit switch source. @see #LimitSwitchSource User can choose
					 *            between the feedback connector, remote Talon SRX, CANifier, or
					 *            deactivate the feature.
					 * @param normalOpenOrClose
					 *            Setting for normally open, normally closed, or disabled. This
					 *            setting matches the Phoenix Tuner drop down.
					 * @param deviceID
					 *            Device ID of remote source (Talon SRX or CANifier device ID).
					 * @param timeoutMs
					 *            Timeout value in ms. If nonzero, function will wait for config
					 *            success and report an error if it times out. If zero, no
					 *            blocking or checking is performed.
					 * @return Error Code generated by function. 0 indicates no error.
					 */
					virtual ctre::phoenix::ErrorCode ConfigReverseLimitSwitchSource(
						RemoteLimitSwitchSource limitSwitchSource,
						LimitSwitchNormal normalOpenOrClose, int deviceID, int timeoutMs = 0);

					//------ Current Limit ----------//
					virtual ctre::phoenix::ErrorCode ConfigSupplyCurrentLimit(const SupplyCurrentLimitConfiguration& currLimitConfigs, int timeoutMs = 50);

					//------ RAW Sensor API ----------//
					/**
					 * Is forward limit switch closed.
					 *
					 * @return  '1' iff forward limit switch is closed, 0 iff switch is open. This function works
					 *          regardless if limit switch feature is enabled.  Remote limit features do not impact this routine.
					 */

					int IsFwdLimitSwitchClosed();

					/**
					 * Is reverse limit switch closed.
					 *
					 * @return  '1' iff reverse limit switch is closed, 0 iff switch is open. This function works
					 *          regardless if limit switch feature is enabled.  Remote limit features do not impact this routine.
					 */

					int IsRevLimitSwitchClosed();
				};// class BaseTalon

			} // namespace can
		} // namespace motorcontrol
	} // namespace phoenix
} // namespace ctre

#if defined(WIN32) || defined(_WIN32) || defined(_WIN64)
#pragma warning (pop)
#endif
