#pragma once

#include <stdint.h>

namespace ctre {
namespace phoenix {

enum ErrorCode
#ifdef __cplusplus
	: int32_t
#endif
{
	OK = 0,
	OKAY = 0,		//!< No Error - Function executed as expected

	//CAN-Related
	CAN_MSG_STALE = 1,
	CAN_TX_FULL = -1,
	TxFailed = -1,				//!< Could not transmit the CAN frame.
	InvalidParamValue = -2, 	//!< Caller passed an invalid param
	CAN_INVALID_PARAM = -2,
	RxTimeout = -3,	//!< CAN frame has not been received within specified period of time.
	CAN_MSG_NOT_FOUND = -3,
	TxTimeout = -4,				//!< Not used.
	CAN_NO_MORE_TX_JOBS = -4,
	UnexpectedArbId = -5,		//!< Specified CAN Id is invalid.
	CAN_NO_SESSIONS_AVAIL = -5,
	BufferFull = +6,//!< Caller attempted to insert data into a buffer that is full.
	CAN_OVERFLOW = -6,
	SensorNotPresent = -7,		//!< Sensor is not present
	FirmwareTooOld = -8,
	CouldNotChangePeriod = -9,
	BufferFailure = -10,
	FirwmwareNonFRC = -11,

	//General
	GeneralError = -100,		//!< User Specified General Error
	GENERAL_ERROR = -100,

	//Signal
	SIG_NOT_UPDATED = -200,
	SigNotUpdated = -200,	//!< Have not received an value response for signal.
	NotAllPIDValuesUpdated = -201,

	//Gadgeteer Port Error Codes
	//These include errors between ports and modules
	GEN_PORT_ERROR = -300,
	PORT_MODULE_TYPE_MISMATCH = -301,

	//Gadgeteer Module Error Codes
	//These apply only to the module units themselves
	GEN_MODULE_ERROR = -400,
	MODULE_NOT_INIT_SET_ERROR = -401,
	MODULE_NOT_INIT_GET_ERROR = -402,

	//API
	WheelRadiusTooSmall = -500,
	TicksPerRevZero = -501,
	DistanceBetweenWheelsTooSmall = -502,
	GainsAreNotSet = -503,
	WrongRemoteLimitSwitchSource = -504,
	DoubleVoltageCompensatingWPI = -505,

	//Higher Level
	IncompatibleMode = -600,
	InvalidHandle = -601,		//!< Handle does not match stored map of handles

	//Firmware Versions
	FeatureRequiresHigherFirm = -700,
    MotorControllerFeatureRequiresHigherFirm = -701,
    TalonFeatureRequiresHigherFirm = MotorControllerFeatureRequiresHigherFirm,
    ConfigFactoryDefaultRequiresHigherFirm = -702,
	ConfigMotionSCurveRequiresHigherFirm = -703,
	TalonFXFirmwarePreVBatDetect = -704,

	//Operating system centric
	LibraryCouldNotBeLoaded = -800,
	MissingRoutineInLibrary = -801,
	ResourceNotAvailable = -802,

	//MIDI and Orchestra centric
	MusicFileNotFound = -900,
	MusicFileWrongSize = -901,
	MusicFileTooNew = -902,
	MusicFileInvalid = -903,
	InvalidOrchestraAction = -904,
	MusicFileTooOld = -905,
	MusicInterrupted = -906,
	MusicNotSupported = -907,

	kInvalidInterface = -1000,
	kInvalidGuid = -1001,
	kInvalidClass = -1002,
	kInvalidProtocol = -1003,
	kInvalidPath = -1004,
	kGeneralWinUsbError = -1005,
	kFailedSetup = -1006,
	kListenFailed = -1007,
	kSendFailed = -1008,
	kReceiveFailed = -1009,
	kInvalidRespFormat = -1010,
	kWinUsbInitFailed = -1011,
	kWinUsbQueryFailed = -1012,
	kWinUsbGeneralError = -1013,
	kAccessDenied = -1014,
	kFirmwareInvalidResponse = -1015,

	//CAN Related
	PulseWidthSensorNotPresent = +10,	//!< Special Code for "isSensorPresent"

	//General
	GeneralWarning = 100,
	FeatureNotSupported = 101, // feature not implement in the API or firmware
	NotImplemented = 102, // feature not implement in the API
	FirmVersionCouldNotBeRetrieved = 103,
	FeaturesNotAvailableYet = 104, // feature will be release in an upcoming release
	ControlModeNotValid = 105, // Current control mode of motor controller not valid for this call
	ControlModeNotSupportedYet = 106,
	CascadedPIDNotSupporteYet = 107,
	AuxiliaryPIDNotSupportedYet = 107,
	RemoteSensorsNotSupportedYet = 108,
	MotProfFirmThreshold = 109,
	MotProfFirmThreshold2 = 110,

	//Simulation
	SimDeviceNotFound = 200,
	SimPhysicsTypeNotSupported = 201,
	SimDeviceAlreadyExists = 202,
};
class ErrorCollection {
public:
	ErrorCollection() {
		_firstError = OK;
	}
    void NewError(ErrorCode err) {
        _firstError = FirstOne(_firstError, err);
    }
    void NewError(int err) {
        _firstError = FirstOne(_firstError, (ErrorCode) err);
    }
	ErrorCode GetFirstNonZeroError()
	{
		return _firstError;
	}
private:

	static ErrorCode FirstOne(ErrorCode errorCode1, ErrorCode errorCode2) {
		if (errorCode1 != OK)
			return errorCode1;
		return errorCode2;
	}

	ErrorCode _firstError;
};

} // namespace phoenix
} // namespace ctre
