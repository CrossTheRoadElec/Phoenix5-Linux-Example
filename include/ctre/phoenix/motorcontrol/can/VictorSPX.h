#pragma once
#if defined(WIN32) || defined(_WIN32) || defined(_WIN64)
#pragma warning (push)
#pragma warning (disable : 4250)
#endif

#include "ctre/phoenix/motorcontrol/can/BaseMotorController.h"
#include "ctre/phoenix/CustomParamConfiguration.h"

namespace ctre {
namespace phoenix {
namespace motorcontrol{
namespace can {

/**
 * Configurables available to VictorSPX's PID
 */
struct VictorSPXPIDSetConfiguration : BasePIDSetConfiguration {
    /**
     * Feedback device for a particular PID loop.
     */
	RemoteFeedbackDevice selectedFeedbackSensor;

	VictorSPXPIDSetConfiguration() :
		selectedFeedbackSensor(RemoteFeedbackDevice::None)
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

        std::string retstr = prependString + ".selectedFeedbackSensor = " + FeedbackDeviceRoutines::toString(selectedFeedbackSensor) + ";\n";
        retstr += BasePIDSetConfiguration::toString(prependString);
        return retstr;
    }
};

/**
 * Util class to help with VictorSPX's PID configs
 */
struct VictorSPXPIDSetConfigUtil {
	private:
		static VictorSPXPIDSetConfiguration _default;
	public:
		/**
		 * Determine if specified value is different from default
		 * @param settings settings to compare against
		 * @return if specified value is different from default
		 * @{
		 */
		static bool SelectedFeedbackSensorDifferent (const VictorSPXPIDSetConfiguration & settings) { return (!(settings.selectedFeedbackSensor == _default.selectedFeedbackSensor)); }
		static bool SelectedFeedbackCoefficientDifferent (const VictorSPXPIDSetConfiguration & settings) { return (!(settings.selectedFeedbackCoefficient == _default.selectedFeedbackCoefficient)); }
		/** @} */
};

/**
 * Configurables available to VictorSPX
 */
struct VictorSPXConfiguration : BaseMotorControllerConfiguration {
	/**
     * Primary PID configuration
     */
	VictorSPXPIDSetConfiguration primaryPID;	
    /**
     * Auxiliary PID configuration
     */
	VictorSPXPIDSetConfiguration auxiliaryPID;	
    /**
     * Forward Limit Switch Source
     * 
     * User can choose between the feedback connector, remote Talon SRX, CANifier, or deactivate the feature
     */
	RemoteLimitSwitchSource forwardLimitSwitchSource;
    /**
     * Reverse Limit Switch Source
     * 
     * User can choose between the feedback connector, remote Talon SRX, CANifier, or deactivate the feature
     */
	RemoteLimitSwitchSource reverseLimitSwitchSource;
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
     */
	RemoteFeedbackDevice sum0Term;
    /**
     * Feedback Device for Sum 1 Term
     */
	RemoteFeedbackDevice sum1Term;
    /**
     * Feedback Device for Diff 0 Term
     */
	RemoteFeedbackDevice diff0Term;
    /**
     * Feedback Device for Diff 1 Term
     */
	RemoteFeedbackDevice diff1Term;

	VictorSPXConfiguration() :
		forwardLimitSwitchSource(RemoteLimitSwitchSource_Deactivated), 
		reverseLimitSwitchSource(RemoteLimitSwitchSource_Deactivated),
        forwardLimitSwitchDeviceID(0),
        reverseLimitSwitchDeviceID(0),
        forwardLimitSwitchNormal(LimitSwitchNormal_NormallyOpen), 
        reverseLimitSwitchNormal(LimitSwitchNormal_NormallyOpen), 
	    sum0Term (RemoteFeedbackDevice::None), 
	    sum1Term (RemoteFeedbackDevice::None),
	    diff0Term(RemoteFeedbackDevice::None),
	    diff1Term(RemoteFeedbackDevice::None)
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
};

/**
 * Util class to help with VictorSPX configs
 */
class VictorConfigUtil {
	private:
		static struct VictorSPXConfiguration _default;
	public:
		/**
		 * Determine if specified value is different from default
		 * @param settings settings to compare against
		 * @return if specified value is different from default
		 * @{
		 */
		static bool ForwardLimitSwitchSourceDifferent (const VictorSPXConfiguration & settings) { return (!(settings.forwardLimitSwitchSource == _default.forwardLimitSwitchSource)) || !settings.enableOptimizations; }
		static bool ReverseLimitSwitchSourceDifferent (const VictorSPXConfiguration & settings) { return (!(settings.reverseLimitSwitchSource == _default.reverseLimitSwitchSource)) || !settings.enableOptimizations; }
		static bool ForwardLimitSwitchDeviceIDDifferent (const VictorSPXConfiguration & settings) { return (!(settings.forwardLimitSwitchDeviceID == _default.forwardLimitSwitchDeviceID)) || !settings.enableOptimizations; }
		static bool ReverseLimitSwitchDeviceIDDifferent (const VictorSPXConfiguration & settings) { return (!(settings.reverseLimitSwitchDeviceID == _default.reverseLimitSwitchDeviceID)) || !settings.enableOptimizations; }
		static bool ForwardLimitSwitchNormalDifferent (const VictorSPXConfiguration & settings) { return (!(settings.forwardLimitSwitchNormal == _default.forwardLimitSwitchNormal)) || !settings.enableOptimizations; }
		static bool ReverseLimitSwitchNormalDifferent (const VictorSPXConfiguration & settings) { return (!(settings.reverseLimitSwitchNormal == _default.reverseLimitSwitchNormal)) || !settings.enableOptimizations; }
		static bool Sum0TermDifferent (const VictorSPXConfiguration & settings) { return (!(settings.sum0Term == _default.sum0Term)) || !settings.enableOptimizations; }
		static bool Sum1TermDifferent (const VictorSPXConfiguration & settings) { return (!(settings.sum1Term == _default.sum1Term)) || !settings.enableOptimizations; }
		static bool Diff0TermDifferent (const VictorSPXConfiguration & settings) { return (!(settings.diff0Term == _default.diff0Term)) || !settings.enableOptimizations; }
		static bool Diff1TermDifferent (const VictorSPXConfiguration & settings) { return (!(settings.diff1Term == _default.diff1Term)) || !settings.enableOptimizations; }
		
		static bool ForwardLimitSwitchDifferent (const VictorSPXConfiguration & settings) {
			return ForwardLimitSwitchDeviceIDDifferent(settings) || ForwardLimitSwitchNormalDifferent(settings) || ForwardLimitSwitchSourceDifferent(settings);
		}
		static bool ReverseLimitSwitchDifferent (const VictorSPXConfiguration & settings) {
			return ReverseLimitSwitchDeviceIDDifferent(settings) || ReverseLimitSwitchNormalDifferent(settings) || ReverseLimitSwitchSourceDifferent(settings);
		}
		/** @} */
};

/**
 * VEX Victor SPX Motor Controller when used on CAN Bus.
 *
 * <pre>
 * {@code
 * // Example usage of a VictorSPX motor controller
 * VictorSPX motor{0}; // creates a new VictorSPX with ID 0
 *
 * motor.Set(VictorSPXControlMode::PercentOutput, 0.5); // runs the motor at 50% power
 *
 * std::cout << motor.GetMotorOutputPercent() << std::endl; // prints the percent output of the motor (0.5)
 * std::cout << motor.GetBusVoltage() << std::endl; // prints the bus voltage seen by the motor controller
 *
 * ErrorCode error = motor.GetLastError(); // gets the last error generated by the motor controller
 * Faults faults;
 * ErrorCode faultsError = motor.GetFaults(faults); // fills faults with the current motor controller faults; returns the last error generated
 * }
 * </pre>
 */
class VictorSPX: public virtual ctre::phoenix::motorcontrol::can::BaseMotorController,
                 public virtual ctre::phoenix::motorcontrol::IMotorController {

private:
	/**
	 * Gets all PID set persistant settings.
	 *
	 * @param pid               Object with all of the PID set persistant settings
	 * @param pidIdx            0 for Primary closed-loop. 1 for auxiliary closed-loop.
	 * @param timeoutMs
	 *              Timeout value in ms. If nonzero, function will wait for
	 *              config success and report an error if it times out.
	 *              If zero, no blocking or checking is performed.
	 * @param enableOptimizations Enable the optimization technique
	 */
	ctre::phoenix::ErrorCode ConfigurePID(const VictorSPXPIDSetConfiguration &pid, int pidIdx, int timeoutMs, bool enableOptimizations);
public:
	/**
	 * Constructor
	 * 
	 * @param deviceNumber
	 *            [0,62]
	 */
	VictorSPX(int deviceNumber);
	virtual ~VictorSPX() {
	}
	VictorSPX(VictorSPX const&) = delete;
	VictorSPX& operator=(VictorSPX const&) = delete;
	
	// ------ Set output routines. ----------//
	/**
	 * Sets the appropriate output on the motor controller, depending on the mode.
	 * @param mode The output mode to apply.
	 * In PercentOutput, the output is between -1.0 and 1.0, with 0.0 as stopped.
	 * In Velocity mode, output value is in position change / 100ms.
	 * In Position mode, output value is in encoder ticks or an analog value,
	 *   depending on the sensor.
	 * In Follower mode, the output value is the integer device ID of the motor controller to
	 * duplicate.
	 *
	 * @param value The setpoint value, as described above.
	 *
	 *
	 *	Standard Driving Example:
	 *	victorLeft.set(ControlMode.PercentOutput, leftJoy);
	 *	victorRght.set(ControlMode.PercentOutput, rghtJoy);
	 */
	void Set(ctre::phoenix::motorcontrol::VictorSPXControlMode mode, double value);
	/**
	 * @param mode Sets the appropriate output on the motor controller, depending on the mode.
	 * @param demand0 The output value to apply.
	 * 	such as advanced feed forward and/or auxiliary close-looping in firmware.
	 * In PercentOutput, the output is between -1.0 and 1.0, with 0.0 as stopped.
	 * In Velocity mode, output value is in position change / 100ms.
	 * In Position mode, output value is in encoder ticks or an analog value,
	 *   depending on the sensor. See
	 * In Follower mode, the output value is the integer device ID of the motor controller to
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
	 *		_victorLeft.set(ControlMode.PercentOutput, joyForward, DemandType.ArbitraryFeedForward, +joyTurn);
	 *		_victorRght.set(ControlMode.PercentOutput, joyForward, DemandType.ArbitraryFeedForward, -joyTurn);
	 *
	 *	Drive Straight Example:
	 *	Note: Selected Sensor Configuration is necessary for both PID0 and PID1.
	 *		_victorLeft.follow(_victorRght, FollwerType.AuxOutput1);
	 *		_victorRght.set(ControlMode.PercentOutput, joyForward, DemandType.AuxPID, desiredRobotHeading);
	 *
	 *	Drive Straight to a Distance Example:
	 *	Note: Other configurations (sensor selection, PID gains, etc.) need to be set.
	 *		_victorLeft.follow(_victorRght, FollwerType.AuxOutput1);
	 *		_victorRght.set(ControlMode.MotionMagic, targetDistance, DemandType.AuxPID, desiredRobotHeading);
	 */
	void Set(ctre::phoenix::motorcontrol::VictorSPXControlMode mode, double demand0, ctre::phoenix::motorcontrol::DemandType demand1Type, double demand1);

	//------ Simulation API ----------//
	/**
	 * @return object that can set simulation inputs.
	 */
	ctre::phoenix::motorcontrol::VictorSPXSimCollection& GetSimCollection();

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
	void GetPIDConfigs(VictorSPXPIDSetConfiguration &pid, int pidIdx = 0, int timeoutMs = 50);
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
	virtual ctre::phoenix::ErrorCode ConfigAllSettings(const VictorSPXConfiguration &allConfigs, int timeoutMs = 50);
    /**
     * Gets all persistant settings.
     *
	 * @param allConfigs        Object with all of the persistant settings
     * @param timeoutMs
     *              Timeout value in ms. If nonzero, function will wait for
     *              config success and report an error if it times out.
     *              If zero, no blocking or checking is performed.
     */
	virtual void GetAllConfigs(VictorSPXConfiguration &allConfigs, int timeoutMs = 50);

	/* ----- virtual re-directs ------- */
	virtual void Set(ctre::phoenix::motorcontrol::ControlMode mode, double value);
	virtual void Set(ctre::phoenix::motorcontrol::ControlMode mode, double demand0, ctre::phoenix::motorcontrol::DemandType demand1Type, double demand1);

};// class VictorSPX
} // namespace can
} // namespace motorcontrol
} // namespace phoenix
} // namespace ctre

#if defined(WIN32) || defined(_WIN32) || defined(_WIN64)
#pragma warning (pop)
#endif
