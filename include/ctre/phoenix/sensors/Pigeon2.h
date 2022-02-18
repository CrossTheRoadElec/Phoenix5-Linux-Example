/*
 *  Software License Agreement
 *
 * Copyright (C) Cross The Road Electronics.  All rights
 * reserved.
 *
 * Cross The Road Electronics (CTRE) licenses to you the right to
 * use, publish, and distribute copies of CRF (Cross The Road) firmware files (*.crf) and Software
 * API Libraries ONLY when in use with Cross The Road Electronics hardware products.
 *
 * THE SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT
 * WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 * LIMITATION, ANY WARRANTY OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 * CROSS THE ROAD ELECTRONICS BE LIABLE FOR ANY INCIDENTAL, SPECIAL,
 * INDIRECT OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF
 * PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS
 * BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE
 * THEREOF), ANY CLAIMS FOR INDEMNITY OR CONTRIBUTION, OR OTHER
 * SIMILAR COSTS, WHETHER ASSERTED ON THE BASIS OF CONTRACT, TORT
 * (INCLUDING NEGLIGENCE), BREACH OF WARRANTY, OR OTHERWISE
 */

#pragma once

#include <string>
#include "ctre/phoenix/CANBusAddressable.h"
#include "ctre/phoenix/CustomParamConfiguration.h"
#include "ctre/phoenix/paramEnum.h"
#include "ctre/phoenix/ErrorCode.h"
#include "ctre/phoenix/sensors/PigeonIMU_ControlFrame.h"
#include "ctre/phoenix/sensors/Pigeon2_Faults.h"
#include "ctre/phoenix/sensors/PigeonIMU_StatusFrame.h"
#include "ctre/phoenix/sensors/Pigeon2_StickyFaults.h"
#include "ctre/phoenix/sensors/BasePigeonSimCollection.h"
#include "ctre/phoenix/sensors/BasePigeon.h"

/* forward prototype */
namespace ctre {
namespace phoenix {
namespace motorcontrol {
namespace can {
class TalonSRX;
}
}
}
}

namespace ctre {
namespace phoenix {
/** sensors namespace */
namespace sensors {

/**
 * Configurables available to Pigeon
 */
struct Pigeon2Configuration : CustomParamConfiguration{
    double MountPoseYaw {0};
    double MountPosePitch {0};
    double MountPoseRoll {0};
    bool EnableCompass {false};
    bool DisableTemperatureCompensation {false};
    bool DisableNoMotionCalibration {false};
	double XAxisGyroError{0};
	double YAxisGyroError{0};
	double ZAxisGyroError{0};
	Pigeon2Configuration() {}

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
        std::string retstr = CustomParamConfiguration::toString(prependString);

        return retstr;
    }
};// struct Pigeon2

/**
 * Util class to help with Pigeon configurations
 */
struct Pigeon2ConfigUtils {
private:
	static Pigeon2Configuration _default;
public:
	/**
	 * Determine if specified value is different from default
	 * @param settings settings to compare against
	 * @return if specified value is different from default
	 * @{
	 */
    static bool MountPoseYawDifferent (const Pigeon2Configuration &  settings) { return (!(settings.MountPoseYaw == _default.MountPoseYaw)) || !settings.enableOptimizations; }
    static bool MountPosePitchDifferent (const Pigeon2Configuration &  settings) { return (!(settings.MountPosePitch == _default.MountPosePitch)) || !settings.enableOptimizations; }
    static bool MountPoseRollDifferent(const Pigeon2Configuration &  settings) { return (!(settings.MountPoseRoll == _default.MountPoseRoll)) || !settings.enableOptimizations; }
    static bool EnableCompassDifferent(const Pigeon2Configuration &  settings) { return (!(settings.EnableCompass == _default.EnableCompass)) || !settings.enableOptimizations; }
    static bool DisableTemperatureCompensationDifferent(const Pigeon2Configuration &  settings) { return (!(settings.DisableTemperatureCompensation == _default.DisableTemperatureCompensation)) || !settings.enableOptimizations; }
    static bool DisableNoMotionCalibrationDifferent(const Pigeon2Configuration &  settings) { return (!(settings.DisableNoMotionCalibration == _default.DisableNoMotionCalibration)) || !settings.enableOptimizations; }
    static bool XAxisGyroErrorDifferent(Pigeon2Configuration settings) { return (!(settings.XAxisGyroError == _default.XAxisGyroError)) || !settings.enableOptimizations; }
    static bool YAxisGyroErrorDifferent(Pigeon2Configuration settings) { return (!(settings.YAxisGyroError == _default.YAxisGyroError)) || !settings.enableOptimizations; }
    static bool ZAxisGyroErrorDifferent(Pigeon2Configuration settings) { return (!(settings.ZAxisGyroError == _default.ZAxisGyroError)) || !settings.enableOptimizations; }
	static bool CustomParam0Different (const Pigeon2Configuration & settings) { return (!(settings.customParam0 == _default.customParam0)) || !settings.enableOptimizations; }
	static bool CustomParam1Different (const Pigeon2Configuration & settings) { return (!(settings.customParam1 == _default.customParam1)) || !settings.enableOptimizations; }
	/** @} */
};

/**
 * Enumerations for what primary axis to talk about
 * Positive indicates in n the direction, negative indicates in the opposite direction
 */
enum class AxisDirection {
	PositiveZ,
	PositiveY,
	PositiveX,
	NegativeZ,
	NegativeY,
	NegativeX,
};

/**
 * Pigeon 2 Class. Class supports communicating over CANbus.
 *
 * <pre>
 * {@code
 * // Example usage of a Pigeon 2
 * Pigeon2 pigeon{0}; // creates a new Pigeon2 with ID 0
 *
 * Pigeon2Configuration config;
 * // set mount pose as rolled 90 degrees counter-clockwise
 * config.MountPoseYaw = 0;
 * config.MountPosePitch = 0;
 * config.MountPoseRoll = 90;
 * pigeon.ConfigAllSettings(config);
 *
 * std::cout << pigeon.GetYaw() << std::endl; // prints the yaw of the Pigeon
 * std::cout << pigeon.GetPitch() << std::endl; // prints the pitch of the Pigeon
 * std::cout << pigeon.GetRoll() << std::endl; // prints the roll of the Pigeon
 *
 * double gravityVec[3];
 * pigeon.GetGravityVector(gravityVec); // gets the gravity vector of the Pigeon 2
 *
 * ErrorCode error = pigeon.GetLastError(); // gets the last error generated by the Pigeon
 * Pigeon2_Faults faults;
 * ErrorCode faultsError = pigeon.GetFaults(faults); // fills faults with the current Pigeon 2 faults; returns the last error generated
 * }
 * </pre>
 */
class Pigeon2: public BasePigeon {
public:
	/**
	 * Create a Pigeon object that communicates with Pigeon on CAN Bus.
	 *
	 * @param deviceNumber
	 *            CAN Device Id of Pigeon [0,62]
	 * @param canbus Name of the CANbus; can be a SocketCAN interface (on Linux),
	 *               or a CANivore device name or serial number
	 */
	Pigeon2(int deviceNumber, std::string const &canbus = "");
	/**
	 * Gets the fault status
	 *
	 * @param toFill
	 *            Container for fault statuses.
	 * @return Error Code generated by function. 0 indicates no error.
	 */
	ErrorCode GetFaults(Pigeon2_Faults & toFill) ;
	/**
	 * Gets the sticky fault status
	 *
	 * @param toFill
	 *            Container for sticky fault statuses.
	 * @return Error Code generated by function. 0 indicates no error.
	 */
	ErrorCode GetStickyFaults(Pigeon2_StickyFaults & toFill);

	/**
	 * Configure the Mount Pose using the primary axis.
	 * This is useful if the Pigeon 2.0 is mounted straight, and you only
	 * need to describe what axis is forward and what axis is up.
	 * 
	 * @param forward Axis that points forward from the robot
	 * @param up Axis that points up from the robot
	 * @param timeoutMs Config timeout in milliseconds.
	 * @return OK if successful, InvalidParamValue if both forward and up are of the same primary axis, otherwise config return.
	 */
	ErrorCode ConfigMountPose(AxisDirection forward, AxisDirection up, int timeoutMs = 50);

	/**
	 * Configure the mounting pose of the Pigeon2.<p>
	 * This is the Yaw-Pitch-Roll the Pigeon2 underwent to get to its current
	 *  orientation, referenced from the robot's point of view.<p>
	 * This is only necessary if the Pigeon2 is mounted at an exotic angle
	 *  near the gimbal lock point or not forward. <p>
	 * If the pigeon is relatively flat and pointed forward, this is not needed.<p>
	 * <p>
	 * Examples:<p>
	 * If the Pigeon2 is pointed directly right, that corresponds to a -90 yaw,
	 *  0 pitch, and 0 roll, as it yaw'd 90 degrees clockwise.<p>
	 * If the Pigeon2 points upwards, that's a 0 yaw, -90 pitch, 0 roll, as it
	 *  pitched 90 degrees clockwise. <p>
	 * @param yaw Yaw angle needed to reach the current orientation in degrees.
	 * @param pitch Pitch angle needed to reach the current orientation in degrees.
	 * @param roll Roll angle needed to reach the current orientation in degrees.
	 * @param timeoutMs Config timeout in milliseconds.
	 * @return Worst error code of all config sets.
	 */
	ErrorCode ConfigMountPose(double yaw, double pitch, double roll, int timeoutMs = 0);
	/**
	 * Configure the mounting pose Yaw of the Pigeon2.
	 * See {@link #configMountPose(double, double, double, int)}
	 * 
	 * @param yaw Yaw angle needed to reach the current orientation in degrees.
	 * @param timeoutMs Config timeout in milliseconds.
	 * @return ErrorCode of configSet
	 */
	ErrorCode ConfigMountPoseYaw(double yaw, int timeoutMs = 0);
	/**
	 * Configure the mounting pose Pitch of the Pigeon2.
	 * See {@link #configMountPose(double, double, double, int)}
	 * 
	 * @param pitch Pitch angle needed to reach the current orientation in degrees.
	 * @param timeoutMs Config timeout in milliseconds.
	 * @return ErrorCode of configSet
	 */
	ErrorCode ConfigMountPosePitch(double pitch, int timeoutMs = 0);
	/**
	 * Configure the mounting pose Roll of the Pigeon2.
	 * See {@link #configMountPose(double, double, double, int)}
	 * 
	 * @param roll Roll angle needed to reach the current orientation in degrees.
	 * @param timeoutMs Config timeout in milliseconds.
	 * @return ErrorCode of configSet
	 */
	ErrorCode ConfigMountPoseRoll(double roll, int timeoutMs = 0);
	/**
	 * Configures the X Axis Gyroscope Error for 1 rotation
	 * @param err Degrees that Pigeon 2.0 overshot after 1 rotation (i.e. overshot 1 degree is 1; undershot by 3 degrees is -3)
	 * @param timeoutMs Config timeout in milliseconds.
	 * @return ErrorCode fo configSet
	 */
	ErrorCode ConfigXAxisGyroError(double err, int timeoutMs = 0);
	/**
	 * Configures the Y Axis Gyroscope Error for 1 rotation
	 * @param err Degrees that Pigeon 2.0 overshot after 1 rotation (i.e. overshot 1 degree is 1; undershot by 3 degrees is -3)
	 * @param timeoutMs Config timeout in milliseconds.
	 * @return ErrorCode fo configSet
	 */
	ErrorCode ConfigYAxisGyroError(double err, int timeoutMs = 0);
	/**
	 * Configures the Z Axis Gyroscope Error for 1 rotation
	 * @param err Degrees that Pigeon 2.0 overshot after 1 rotation (i.e. overshot 1 degree is 1; undershot by 3 degrees is -3)
	 * @param timeoutMs Config timeout in milliseconds.
	 * @return ErrorCode fo configSet
	 */
	ErrorCode ConfigZAxisGyroError(double err, int timeoutMs = 0);

	/**
	 * Enables the magnetometer fusion for Pigeon2. This is **not** recommended for FRC use
	 * 
	 * @param enable Boolean to enable/disable magnetometer fusion
	 * @param timeoutMs 
     *            Timeout value in ms. If nonzero, function will wait for
     *            config success and report an error if it times out.
     *            If zero, no blocking or checking is performed.
	 * @return ErrorCode Status of the config response
	 */
	ErrorCode ConfigEnableCompass(bool enable, int timeoutMs = 0);
	/**
	 * Disables temperature compensation from Pigeon2.
	 * 
	 * @param disable Boolean to disable/enable temperature compensation
	 * @param timeoutMs 
     *            Timeout value in ms. If nonzero, function will wait for
     *            config success and report an error if it times out.
     *            If zero, no blocking or checking is performed.
	 * @return ErrorCode Status of the config response
	 */
	ErrorCode ConfigDisableTemperatureCompensation(bool disable, int timeoutMs = 0);
	/**
	 * Disables the no-motion calibration from Pigeon2
	 * 
	 * @param disable Boolean to disable/enable no-motion calibration
	 * @param timeoutMs 
     *            Timeout value in ms. If nonzero, function will wait for
     *            config success and report an error if it times out.
     *            If zero, no blocking or checking is performed.
	 * @return ErrorCode Status of the config response
	 */
	ErrorCode ConfigDisableNoMotionCalibration(bool disable, int timeoutMs = 0);

	/**
	 * Performs an offset calibration on gyro bias
	 * 
	 * @param timeoutMs 
     *            Timeout value in ms. If nonzero, function will wait for
     *            config success and report an error if it times out.
     *            If zero, no blocking or checking is performed.
	 * @return ErrorCode Status of the config response
	 */
	ErrorCode ZeroGyroBiasNow(int timeoutMs = 0);

	/**
	 * Get the Gravity Vector.
	 * 
	 * This provides a vector that points toward ground. This is useful for applications like
	 *  an arm, where the z-value of the gravity vector corresponds to the feed-forward needed
	 *  to hold the arm steady.
	 * The gravity vector is calculated after the mount pose, so if the pigeon is where it was
	 *  mounted, the gravity vector is {0, 0, 1}.
	 * @param gravVector Pass in a double array of size 3 to get the gravity vector
	 * @return Errorcode of getter
	 */
	ErrorCode GetGravityVector(double gravVector[3]) const;

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
	ErrorCode ConfigAllSettings(Pigeon2Configuration& settings, int timeoutMs = 50);
	/**
	 * Gets all persistant settings.
	 *
	 * @param allConfigs        Object with all of the persistant settings
	 * @param timeoutMs
	 *              Timeout value in ms. If nonzero, function will wait for
	 *              config success and report an error if it times out.
	 *              If zero, no blocking or checking is performed.
	 */
	void GetAllConfigs(Pigeon2Configuration& allConfigs, int timeoutMs = 50);

};// class Pigeon2
} // namespace signals
} // namespace phoenix
} // namespace ctre
