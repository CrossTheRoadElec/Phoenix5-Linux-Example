/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#ifdef __cplusplus

/* Make sure this is still compiled with C++ linkage
 * when included from an `extern "C"` block */
extern "C++" {

#include <ostream>

namespace ctre
{
    namespace phoenix
    {

        /**
         * \brief Status codes reported by APIs, including OK,
         * warnings, and errors.
         */
        class StatusCode
        {
            int value;

        public:
            /**
             * \brief No Error
             */
            static constexpr int OK = 0;
            /**
             * \brief Diagnostic Server is busy with another command.
             */
            static constexpr int TaskIsBusy = -100;
            /**
             * \brief InvalidDeviceSpec
             */
            static constexpr int InvalidDeviceSpec = -101;
            /**
             * \brief Device is not present. Verify the device is connected and powered, and
             *        that the CAN bus is terminated.
             */
            static constexpr int EcuIsNotPresent = -102;
            /**
             * \brief Could not put the device into bootloader mode.
             */
            static constexpr int CouldNotEnterBl = -103;
            /**
             * \brief Could not confirm the device has entered the bootloader.
             */
            static constexpr int CouldNotConfirmBl = -104;
            /**
             * \brief Could not erase flash.
             */
            static constexpr int CouldNotErase = -105;
            /**
             * \brief Could not field upgrade the device.
             */
            static constexpr int CouldNotSendFlash = -106;
            /**
             * \brief Bootloader could not verify integrity of the flashed application.
             */
            static constexpr int CouldNotValidate = -107;
            /**
             * \brief Could not run the device firmware application.
             */
            static constexpr int CouldNotRunApp = -108;
            /**
             * \brief Unable to set ID to this device.
             */
            static constexpr int CouldNotReqSetId = -109;
            /**
             * \brief Could not verify that the changed ID took effect.
             */
            static constexpr int CouldNotConfirmId = -110;
            /**
             * \brief Device field upgrade was successful.
             */
            static constexpr int FlashWasGood = -111;
            /**
             * \brief Device firmware application is too old.
             */
            static constexpr int AppTooOld = -112;
            /**
             * \brief Unable to set name to this device.
             */
            static constexpr int CouldNotReqSetDesc = -113;
            /**
             * \brief CompileSzIsWrong
             */
            static constexpr int CompileSzIsWrong = -114;
            /**
             * \brief Cannot set the ID of a gadgeteer device.
             */
            static constexpr int GadgeteerDeviceNoSetId = -115;
            /**
             * \brief This diagnostic action is not supported.
             */
            static constexpr int InvalidTask = -116;
            /**
             * \brief Not Implemented, check latest installer.
             */
            static constexpr int NotImplemented = -117;
            /**
             * \brief NoDevicesOnBus
             */
            static constexpr int NoDevicesOnBus = -118;
            /**
             * \brief MoreThanOneFile
             */
            static constexpr int MoreThanOneFile = -119;
            /**
             * \brief Specified device was not found. Verify the device is connected and
             *        powered, and that the CAN bus is terminated.
             */
            static constexpr int NodeIsInvalid = -120;
            /**
             * \brief InvalidDeviceDescriptor
             */
            static constexpr int InvalidDeviceDescriptor = -121;
            /**
             * \brief CouldNotSendCanFrame
             */
            static constexpr int CouldNotSendCanFrame = -123;
            /**
             * \brief NormalModeMsgNotPresent
             */
            static constexpr int NormalModeMsgNotPresent = -124;
            /**
             * \brief This feature is not supported.
             */
            static constexpr int FeatureNotSupported = -125;
            /**
             * \brief The diagnostic server is not field upgrading any devices.
             */
            static constexpr int NotUpdating = -126;
            /**
             * \brief CorruptedPOST
             */
            static constexpr int CorruptedPOST = -127;
            /**
             * \brief This device did not report any available configs. Verify firmware and
             *        diagnostics are up-to-date.
             */
            static constexpr int NoConfigs = -128;
            /**
             * \brief ConfigFailed
             */
            static constexpr int ConfigFailed = -129;
            /**
             * \brief Unable to factory default this device.
             */
            static constexpr int CouldNotReqFactoryDefault = -130;
            /**
             * \brief CustomNameNotSupported
             */
            static constexpr int CustomNameNotSupported = -131;
            /**
             * \brief The configs read from the device do not match the configs that were
             *        written.
             */
            static constexpr int ConfigReadWriteMismatch = -132;
            /**
             * \brief Could not apply the device configs.
             */
            static constexpr int CouldNotReqSetConfigs = -133;
            /**
             * \brief InsufficientSz
             */
            static constexpr int InsufficientSz = -134;
            /**
             * \brief This feature is not supported for this device model.
             */
            static constexpr int InvalidModel = -135;
            /**
             * \brief CouldNotReqDevInfo
             */
            static constexpr int CouldNotReqDevInfo = -140;
            /**
             * \brief This device does not support new controls.
             */
            static constexpr int NoControls = -141;
            /**
             * \brief DeviceIsNull
             */
            static constexpr int DeviceIsNull = -142;
            /**
             * \brief DeviceDidNotRespondToDiagReq
             */
            static constexpr int DeviceDidNotRespondToDiagReq = -143;
            /**
             * \brief This feature requires Tuner X.
             */
            static constexpr int OnlySupportedInTunerX = -144;
            /**
             * \brief Command-line issue with caniv.
             */
            static constexpr int CanivCliError = -145;
            /**
             * \brief InvalidCrfBadHeader
             */
            static constexpr int InvalidCrfBadHeader = -200;
            /**
             * \brief InvalidCrfFileSzInvald
             */
            static constexpr int InvalidCrfFileSzInvald = -201;
            /**
             * \brief Specified CRF is for the wrong product.
             */
            static constexpr int InvalidCrfWrongProduct = -202;
            /**
             * \brief InvalidCrfNoSects
             */
            static constexpr int InvalidCrfNoSects = -203;
            /**
             * \brief InvalidCrfBadSectHeader
             */
            static constexpr int InvalidCrfBadSectHeader = -204;
            /**
             * \brief InvalidCrfBadSectSize
             */
            static constexpr int InvalidCrfBadSectSize = -205;
            /**
             * \brief Specified CRF file could not be found.
             */
            static constexpr int NoCrfFile = -206;
            /**
             * \brief CouldNotFindDynamicId
             */
            static constexpr int CouldNotFindDynamicId = -300;
            /**
             * \brief DidNotGetDhcp
             */
            static constexpr int DidNotGetDhcp = -301;
            /**
             * \brief DidNotGetFullDhcp
             */
            static constexpr int DidNotGetFullDhcp = -302;
            /**
             * \brief InvalidLicenseResp
             */
            static constexpr int InvalidLicenseResp = -350;
            /**
             * \brief InvalidCanivCache
             */
            static constexpr int InvalidCanivCache = -351;
            /**
             * \brief CannotOpenSerialPort
             */
            static constexpr int CannotOpenSerialPort = -500;
            /**
             * \brief CannotWriteSerialPort
             */
            static constexpr int CannotWriteSerialPort = -501;
            /**
             * \brief CannotReadSerialPort
             */
            static constexpr int CannotReadSerialPort = -502;
            /**
             * \brief CannotSerialToDevice
             */
            static constexpr int CannotSerialToDevice = -503;
            /**
             * \brief NoSerialControlFrameResp
             */
            static constexpr int NoSerialControlFrameResp = -504;
            /**
             * \brief CannotOpenUdpPort
             */
            static constexpr int CannotOpenUdpPort = -600;
            /**
             * \brief CannotWriteUdpPort
             */
            static constexpr int CannotWriteUdpPort = -601;
            /**
             * \brief CannotReadUdpPort
             */
            static constexpr int CannotReadUdpPort = -602;
            /**
             * \brief CannotUdpToDevice
             */
            static constexpr int CannotUdpToDevice = -603;
            /**
             * \brief NoUdpControlFrameResp
             */
            static constexpr int NoUdpControlFrameResp = -604;
            /**
             * \brief TimeoutIso15Response
             */
            static constexpr int TimeoutIso15Response = -605;
            /**
             * \brief InvalidJson
             */
            static constexpr int InvalidJson = -700;
            /**
             * \brief The user application is shutting down.
             */
            static constexpr int AppIsTerminating = -800;
            /**
             * \brief CAN message is stale, data is valid but old. Check the CAN bus wiring,
             *        CAN bus utilization, and power to the device.
             */
            static constexpr int CanMessageStale = 1000;
            /**
             * \brief Buffer is full, cannot insert more data.
             */
            static constexpr int BufferFull = 1006;
            /**
             * \brief PulseWidthSensorNotPresent
             */
            static constexpr int PulseWidthSensorNotPresent = 1010;
            /**
             * \brief General Warning Occurred.
             */
            static constexpr int GeneralWarning = 1100;
            /**
             * \brief Firm Vers could not be retrieved. Use Phoenix Tuner X to check ID and
             *        firmware(CRF) version.
             */
            static constexpr int FirmVersionCouldNotBeRetrieved = 1103;
            /**
             * \brief This feature will be supported in a future update.
             */
            static constexpr int FeaturesNotAvailableYet = 1104;
            /**
             * \brief The control mode is not valid for this function.
             */
            static constexpr int ControlModeNotValid = 1105;
            /**
             * \brief This control mode is not supported yet.  A future release will
             *        supported this soon.
             */
            static constexpr int ControlModeNotSupportedYet = 1106;
            /**
             * \brief Motor Controller must have >= 3.2 firmware for motion profile control
             *        mode.
             */
            static constexpr int MotProfFirmThreshold = 1109;
            /**
             * \brief Motor Controller must have >= 3.4 firmware for advanced PID0/PID1
             *        features.
             */
            static constexpr int MotProfFirmThreshold2 = 1110;
            /**
             * \brief SimDeviceNotFound
             */
            static constexpr int SimDeviceNotFound = 1200;
            /**
             * \brief SimPhysicsTypeNotSupported
             */
            static constexpr int SimPhysicsTypeNotSupported = 1201;
            /**
             * \brief SimDeviceAlreadyExists
             */
            static constexpr int SimDeviceAlreadyExists = 1202;
            /**
             * \brief Could not transmit CAN Frame.
             */
            static constexpr int TxFailed = -1001;
            /**
             * \brief An invalid argument was passed into the function/VI, such as a null
             *        pointer.
             */
            static constexpr int InvalidParamValue = -1002;
            /**
             * \brief CAN frame not received/too-stale. Check the CAN bus wiring, CAN bus
             *        utilization, and power to the device.
             */
            static constexpr int RxTimeout = -1003;
            /**
             * \brief CAN Transmit timed out.
             */
            static constexpr int TxTimeout = -1004;
            /**
             * \brief ArbID is incorrect.
             */
            static constexpr int UnexpectedArbId = -1005;
            /**
             * \brief CanOverflowed
             */
            static constexpr int CanOverflowed = -1006;
            /**
             * \brief Sensor Not Present.
             */
            static constexpr int SensorNotPresent = -1007;
            /**
             * \brief Firmware Too Old.  Use Phoenix Tuner X to field upgrade your CTRE CAN
             *        device firmware(CRF).  Then restart your robot application to clear
             *        this error.
             */
            static constexpr int FirmwareTooOld = -1008;
            /**
             * \brief Control Frame Period could not be changed.  Most likely it is not
             *        being transmitted.
             */
            static constexpr int CouldNotChangePeriod = -1009;
            /**
             * \brief BufferFailure
             */
            static constexpr int BufferFailure = -1010;
            /**
             * \brief Firmware is legacy non-FRC version.  Use Phoenix Tuner X to field
             *        upgrade your CTRE CAN device firmware(CRF).  Firmware greater than
             *        20.0 required.
             */
            static constexpr int FirmwareNonFRC = -1011;
            /**
             * \brief General Error Occurred.
             */
            static constexpr int GeneralError = -1100;
            /**
             * \brief No new response to update signal.
             */
            static constexpr int SigNotUpdated = -1200;
            /**
             * \brief NotAllPIDValuesUpdated
             */
            static constexpr int NotAllPIDValuesUpdated = -1201;
            /**
             * \brief GEN_PORT_ERROR
             */
            static constexpr int GEN_PORT_ERROR = -1300;
            /**
             * \brief PORT_MODULE_TYPE_MISMATCH
             */
            static constexpr int PORT_MODULE_TYPE_MISMATCH = -1301;
            /**
             * \brief GEN_MODULE_ERROR
             */
            static constexpr int GEN_MODULE_ERROR = -1400;
            /**
             * \brief MODULE_NOT_INIT_SET_ERROR
             */
            static constexpr int MODULE_NOT_INIT_SET_ERROR = -1401;
            /**
             * \brief MODULE_NOT_INIT_GET_ERROR
             */
            static constexpr int MODULE_NOT_INIT_GET_ERROR = -1402;
            /**
             * \brief Wheel Radius is too small, cannot get distance traveled.
             */
            static constexpr int WheelRadiusTooSmall = -1500;
            /**
             * \brief Ticks per revolution is 0, cannot get heading.
             */
            static constexpr int TicksPerRevZero = -1501;
            /**
             * \brief Distance between wheels is too small, cannot get heading.
             */
            static constexpr int DistanceBetweenWheelsTooSmall = -1502;
            /**
             * \brief GainsAreNotSet
             */
            static constexpr int GainsAreNotSet = -1503;
            /**
             * \brief Use RemoteLimitSwitchSource instead of LimitSwitchSource.
             */
            static constexpr int WrongRemoteLimitSwitchSource = -1504;
            /**
             * \brief Motor Controller Voltage Compensation should not be used with
             *        setVoltage().  This causes compensation to happen twice.  Disable
             *        Voltage Compensation by calling enableVoltageCompensation(false) in
             *        order to use setVoltage().
             */
            static constexpr int DoubleVoltageCompensatingWPI = -1505;
            /**
             * \brief CANdleAnimSlotOutOfBounds
             */
            static constexpr int CANdleAnimSlotOutOfBounds = -1506;
            /**
             * \brief IncompatibleMode
             */
            static constexpr int IncompatibleMode = -1600;
            /**
             * \brief Handle passed into function is incorrect.
             */
            static constexpr int InvalidHandle = -1601;
            /**
             * \brief Features requires newer firmware version.
             */
            static constexpr int FeatureRequiresHigherFirm = -1700;
            /**
             * \brief Config factory default features require firmware >=3.10.
             */
            static constexpr int ConfigFactoryDefaultRequiresHigherFirm = -1702;
            /**
             * \brief Config Motion S Curve Strength features require firmware >=4.16.
             */
            static constexpr int ConfigMotionSCurveRequiresHigherFirm = -1703;
            /**
             * \brief Talon FX(Falcon 500) Firmware Too Old.  Use Phoenix Tuner to field
             *        upgrade your CTRE CAN device firmware(CRF) to >=20.3. Then restart
             *        your robot application to clear this error.
             */
            static constexpr int TalonFXFirmwarePreVBatDetect = -1704;
            /**
             * \brief CANdleAnimationsRequireHigherFirm
             */
            static constexpr int CANdleAnimationsRequireHigherFirm = -1705;
            /**
             * \brief LibraryCouldNotBeLoaded
             */
            static constexpr int LibraryCouldNotBeLoaded = -1800;
            /**
             * \brief MissingRoutineInLibrary
             */
            static constexpr int MissingRoutineInLibrary = -1801;
            /**
             * \brief ResourceNotAvailable
             */
            static constexpr int ResourceNotAvailable = -1802;
            /**
             * \brief Could not find music file specified, try specifying an absolute path.
             */
            static constexpr int MusicFileNotFound = -1900;
            /**
             * \brief Music file size is incorrect, could not parse correctly. Ensure you're
             *        using Tuner to generate file.
             */
            static constexpr int MusicFileWrongSize = -1901;
            /**
             * \brief Music file version is too new, update Phoenix to utilize this file.
             */
            static constexpr int MusicFileTooNew = -1902;
            /**
             * \brief Music file is invalid. Ensure you're using Tuner to generate file.
             */
            static constexpr int MusicFileInvalid = -1903;
            /**
             * \brief An invalid orchestra action occurred. Ensure a music file is loaded.
             */
            static constexpr int InvalidOrchestraAction = -1904;
            /**
             * \brief This music file version is too old. Regenerate file using Tuner.
             */
            static constexpr int MusicFileTooOld = -1905;
            /**
             * \brief Music interrupted due to one of the instruments being commanded a
             *        different control mode. Press Play to resume music.
             */
            static constexpr int MusicInterrupted = -1906;
            /**
             * \brief This device doesn't support MusicTone control mode.
             */
            static constexpr int MusicNotSupported = -1907;
            /**
             * \brief kInvalidInterface
             */
            static constexpr int kInvalidInterface = -2000;
            /**
             * \brief kInvalidGuid
             */
            static constexpr int kInvalidGuid = -2001;
            /**
             * \brief kInvalidClass
             */
            static constexpr int kInvalidClass = -2002;
            /**
             * \brief kInvalidProtocol
             */
            static constexpr int kInvalidProtocol = -2003;
            /**
             * \brief kInvalidPath
             */
            static constexpr int kInvalidPath = -2004;
            /**
             * \brief kGeneralWinUsbError
             */
            static constexpr int kGeneralWinUsbError = -2005;
            /**
             * \brief kFailedSetup
             */
            static constexpr int kFailedSetup = -2006;
            /**
             * \brief kListenFailed
             */
            static constexpr int kListenFailed = -2007;
            /**
             * \brief kSendFailed
             */
            static constexpr int kSendFailed = -2008;
            /**
             * \brief kReceiveFailed
             */
            static constexpr int kReceiveFailed = -2009;
            /**
             * \brief kInvalidRespFormat
             */
            static constexpr int kInvalidRespFormat = -2010;
            /**
             * \brief kWinUsbInitFailed
             */
            static constexpr int kWinUsbInitFailed = -2011;
            /**
             * \brief kWinUsbQueryFailed
             */
            static constexpr int kWinUsbQueryFailed = -2012;
            /**
             * \brief kWinUsbGeneralError
             */
            static constexpr int kWinUsbGeneralError = -2013;
            /**
             * \brief kAccessDenied
             */
            static constexpr int kAccessDenied = -2014;
            /**
             * \brief kFirmwareInvalidResponse
             */
            static constexpr int kFirmwareInvalidResponse = -2015;
            /**
             * \brief This StatusCode has not been initialized. Make sure the StatusCode is
             *        getting assigned to the return of a method.
             */
            static constexpr int StatusCodeNotInitialized = -10000;
            /**
             * \brief WarningNotInitialized
             */
            static constexpr int WarningNotInitialized = 10000;
            /**
             * \brief The timestamp reported by CANivore is at least 10ms older than the
             *        timestamp reported by the system, indicating it's fallen out of sync.
             *        This does not impact the data of this message, only the timing.
             */
            static constexpr int HwTimestampOutOfSync = 10001;
            /**
             * \brief Do not apply or refresh configs periodically, as configs are blocking.
             */
            static constexpr int FrequentConfigCalls = 10002;
            /**
             * \brief InvalidNetwork
             */
            static constexpr int InvalidNetwork = -10001;
            /**
             * \brief The CAN bus does not support multi-signal synchronization.
             */
            static constexpr int MultiSignalNotSupported = -10002;
            /**
             * \brief Could not cast from base value to this particular signal's type
             */
            static constexpr int CouldNotCast = -10003;
            /**
             * \brief Could not find this value when searching for it
             */
            static constexpr int NotFound = -10004;
            /**
             * \brief This is not supported
             */
            static constexpr int NotSupported = -10005;
            /**
             * \brief Could not determine context from this device hash
             */
            static constexpr int MissingContext = -10006;
            /**
             * \brief Model name in license file does not match model name of selected
             *        device.
             */
            static constexpr int ModelMismatch = -10007;
            /**
             * \brief Serial Number in license file does not match model name of selected
             *        device.
             */
            static constexpr int SerialMismatch = -10008;
            /**
             * \brief Could not find specified file.
             */
            static constexpr int NoFile = -10009;
            /**
             * \brief License did not successfully download to Device.
             */
            static constexpr int LicenseDownloadFailed = -10010;
            /**
             * \brief Self Test report does not have any values, is the firmware up to date?
             */
            static constexpr int SelfTestIsEmpty = -10011;
            /**
             * \brief Failed to lookup signal properties.  This can happen if the fimware is
             *        too new and supports signals that older APIs do not support.
             */
            static constexpr int SignalLookupFailed = -10012;
            /**
             * \brief The current mode of the device is invalid for getting this signal.
             */
            static constexpr int InvalidModeToGetSignal = -10013;
            /**
             * \brief Device is not licensed. Cannot get any data from it.
             */
            static constexpr int UnlicensedDevice = -10014;
            /**
             * \brief Size is invalid.
             */
            static constexpr int InvalidSize = -10015;
            /**
             * \brief InvalidLicenseResponse
             */
            static constexpr int InvalidLicenseResponse = -10016;
            /**
             * \brief InvalidContext
             */
            static constexpr int InvalidContext = -10017;
            /**
             * \brief InternalError
             */
            static constexpr int InternalError = -10018;
            /**
             * \brief kDeviceResponseIncorrect
             */
            static constexpr int kDeviceResponseIncorrect = -10019;
            /**
             * \brief kErrorPollingForDevices
             */
            static constexpr int kErrorPollingForDevices = -10020;
            /**
             * \brief Device firmware could not be retrieved. Check that the device is
             *        running v6 firmware, the device ID is correct, the specified CAN bus
             *        is correct, and the device is powered.
             */
            static constexpr int CouldNotRetrieveV6Firmware = -10021;
            /**
             * \brief Device firmware could not be decoded. Check that the device is running
             *        v6 firmware, the device ID is correct, the specified CAN bus is
             *        correct, and the device is powered.
             */
            static constexpr int CouldNotDecodeDeviceFirmware = -10022;
            /**
             * \brief The values specified for master are in valid.  Make sure the Device ID
             *        of master are correct.
             */
            static constexpr int InvalidIDToFollow = -10023;
            /**
             * \brief Using a Pro only feature on an unlicensed device. The device may not
             *        behave as expected if it continues to operate while unlicensed.
             */
            static constexpr int UsingProFeatureOnUnlicensedDevice = -10024;
            /**
             * \brief Firmware Too New.  Use Phoenix Tuner X to field upgrade your CTRE CAN
             *        device firmware(CRF) to a compatible version.  Then restart your robot
             *        application to clear this error.
             */
            static constexpr int FirmwareTooNew = -10025;
            /**
             * \brief The data frame could not be serialized for transmit.
             */
            static constexpr int CouldNotSerialize = -10026;
            /**
             * \brief The mechanism is disabled due to a fault in one of the devices.
             */
            static constexpr int MechanismFaulted = -10027;
            /**
             * \brief Firmware version is not compatible with this version of Phoenix. Make
             *        sure your firmware and API major versions match.
             */
            static constexpr int FirmwareVersNotCompatible = -10028;
            /**
             * \brief Could not find specified directory.
             */
            static constexpr int DirectoryMissing = -10029;
            /**
             * \brief This API version is too old for the firmware on the device. Either
             *        upgrade the API to a newer version or downgrade the device firmware to
             *        an older version for correct behavior.
             */
            static constexpr int ApiTooOld = -10030;
            /**
             * \brief The signal logger is not running. Start the signal logger before
             *        writing any signals.
             */
            static constexpr int LoggerNotRunning = -10031;
            /**
             * \brief Blocking operations, such as configs, cannot have a timeout of 0. Pass
             *        in a non-zero timeout (typically 0.050+ seconds) for normal operation.
             */
            static constexpr int TimeoutCannotBeZero = -10032;
            /**
             * \brief Device cannot be licensed while it is control enabled. Disable and
             *        neutral the device to apply the licenses.
             */
            static constexpr int CannotLicenseWhileEnabled = -10033;
            /**
             * \brief Could not open or read the given file.
             */
            static constexpr int InvalidFile = -10034;
            /**
             * \brief The given hoot log requires an older version of Phoenix API.
             */
            static constexpr int HootLogTooOld = -10035;
            /**
             * \brief The given hoot log requires a newer version of Phoenix API.
             */
            static constexpr int HootLogTooNew = -10036;
            /**
             * \brief Hoot log is not licensed. Cannot get any data from it.
             */
            static constexpr int UnlicensedHootLog = -10037;
            /**
             * \brief The simulation timing cannot be advanced by a time step while
             *        unpaused. Pause the simulator before advancing time.
             */
            static constexpr int CannotStepWhileUnpaused = -10038;
            /**
             * \brief Hoot replay does not support replaying multiple files. Ensure that
             *        only one file is loaded at a time.
             */
            static constexpr int MultipleReplayNotSupported = -10039;
            /**
             * \brief The maximum number of loggable user signals has been exceeded.
             *        Additional user signals will not be logged.
             */
            static constexpr int UserSignalLimitExceeded = -10040;
            /**
             * \brief The provided model was not a valid device type.
             */
            static constexpr int InvalidDeviceModel = -10041;

            constexpr StatusCode(int val) : value{val} {}
            constexpr StatusCode() : value{StatusCode::StatusCodeNotInitialized} {}

            constexpr operator int() const { return this->value; }

            constexpr bool operator==(StatusCode data) const
            {
                return this->value == data.value;
            }
            constexpr bool operator==(int data) const
            {
                return this->value == data;
            }
            constexpr bool operator!=(StatusCode data) const
            {
                return this->value != data.value;
            }
            constexpr bool operator!=(int data) const
            {
                return this->value != data;
            }
            constexpr bool operator<(StatusCode data) const
            {
                return this->value < data.value;
            }
            constexpr bool operator<(int data) const
            {
                return this->value < data;
            }

            /**
             * \returns true if this code is an error
             */
            constexpr bool IsError() const { return value < 0; }
            /**
             * \returns true if this code is a warning
             */
            constexpr bool IsWarning() const { return value > 0; }
            /**
             * \returns true if this code is OK
             */
            constexpr bool IsOK() const { return value == OK; }

            /**
             * Gets the name of this StatusCode
             *
             * \returns Name of this StatusCode
             */
            constexpr const char *GetName() const
            {
                switch (value)
                {
                case 0: return "OK";
                case -100: return "TaskIsBusy";
                case -101: return "InvalidDeviceSpec";
                case -102: return "EcuIsNotPresent";
                case -103: return "CouldNotEnterBl";
                case -104: return "CouldNotConfirmBl";
                case -105: return "CouldNotErase";
                case -106: return "CouldNotSendFlash";
                case -107: return "CouldNotValidate";
                case -108: return "CouldNotRunApp";
                case -109: return "CouldNotReqSetId";
                case -110: return "CouldNotConfirmId";
                case -111: return "FlashWasGood";
                case -112: return "AppTooOld";
                case -113: return "CouldNotReqSetDesc";
                case -114: return "CompileSzIsWrong";
                case -115: return "GadgeteerDeviceNoSetId";
                case -116: return "InvalidTask";
                case -117: return "NotImplemented";
                case -118: return "NoDevicesOnBus";
                case -119: return "MoreThanOneFile";
                case -120: return "NodeIsInvalid";
                case -121: return "InvalidDeviceDescriptor";
                case -123: return "CouldNotSendCanFrame";
                case -124: return "NormalModeMsgNotPresent";
                case -125: return "FeatureNotSupported";
                case -126: return "NotUpdating";
                case -127: return "CorruptedPOST";
                case -128: return "NoConfigs";
                case -129: return "ConfigFailed";
                case -130: return "CouldNotReqFactoryDefault";
                case -131: return "CustomNameNotSupported";
                case -132: return "ConfigReadWriteMismatch";
                case -133: return "CouldNotReqSetConfigs";
                case -134: return "InsufficientSz";
                case -135: return "InvalidModel";
                case -140: return "CouldNotReqDevInfo";
                case -141: return "NoControls";
                case -142: return "DeviceIsNull";
                case -143: return "DeviceDidNotRespondToDiagReq";
                case -144: return "OnlySupportedInTunerX";
                case -145: return "CanivCliError";
                case -200: return "InvalidCrfBadHeader";
                case -201: return "InvalidCrfFileSzInvald";
                case -202: return "InvalidCrfWrongProduct";
                case -203: return "InvalidCrfNoSects";
                case -204: return "InvalidCrfBadSectHeader";
                case -205: return "InvalidCrfBadSectSize";
                case -206: return "NoCrfFile";
                case -300: return "CouldNotFindDynamicId";
                case -301: return "DidNotGetDhcp";
                case -302: return "DidNotGetFullDhcp";
                case -350: return "InvalidLicenseResp";
                case -351: return "InvalidCanivCache";
                case -500: return "CannotOpenSerialPort";
                case -501: return "CannotWriteSerialPort";
                case -502: return "CannotReadSerialPort";
                case -503: return "CannotSerialToDevice";
                case -504: return "NoSerialControlFrameResp";
                case -600: return "CannotOpenUdpPort";
                case -601: return "CannotWriteUdpPort";
                case -602: return "CannotReadUdpPort";
                case -603: return "CannotUdpToDevice";
                case -604: return "NoUdpControlFrameResp";
                case -605: return "TimeoutIso15Response";
                case -700: return "InvalidJson";
                case -800: return "AppIsTerminating";
                case 1000: return "CanMessageStale";
                case 1006: return "BufferFull";
                case 1010: return "PulseWidthSensorNotPresent";
                case 1100: return "GeneralWarning";
                case 1103: return "FirmVersionCouldNotBeRetrieved";
                case 1104: return "FeaturesNotAvailableYet";
                case 1105: return "ControlModeNotValid";
                case 1106: return "ControlModeNotSupportedYet";
                case 1109: return "MotProfFirmThreshold";
                case 1110: return "MotProfFirmThreshold2";
                case 1200: return "SimDeviceNotFound";
                case 1201: return "SimPhysicsTypeNotSupported";
                case 1202: return "SimDeviceAlreadyExists";
                case -1001: return "TxFailed";
                case -1002: return "InvalidParamValue";
                case -1003: return "RxTimeout";
                case -1004: return "TxTimeout";
                case -1005: return "UnexpectedArbId";
                case -1006: return "CanOverflowed";
                case -1007: return "SensorNotPresent";
                case -1008: return "FirmwareTooOld";
                case -1009: return "CouldNotChangePeriod";
                case -1010: return "BufferFailure";
                case -1011: return "FirmwareNonFRC";
                case -1100: return "GeneralError";
                case -1200: return "SigNotUpdated";
                case -1201: return "NotAllPIDValuesUpdated";
                case -1300: return "GEN_PORT_ERROR";
                case -1301: return "PORT_MODULE_TYPE_MISMATCH";
                case -1400: return "GEN_MODULE_ERROR";
                case -1401: return "MODULE_NOT_INIT_SET_ERROR";
                case -1402: return "MODULE_NOT_INIT_GET_ERROR";
                case -1500: return "WheelRadiusTooSmall";
                case -1501: return "TicksPerRevZero";
                case -1502: return "DistanceBetweenWheelsTooSmall";
                case -1503: return "GainsAreNotSet";
                case -1504: return "WrongRemoteLimitSwitchSource";
                case -1505: return "DoubleVoltageCompensatingWPI";
                case -1506: return "CANdleAnimSlotOutOfBounds";
                case -1600: return "IncompatibleMode";
                case -1601: return "InvalidHandle";
                case -1700: return "FeatureRequiresHigherFirm";
                case -1702: return "ConfigFactoryDefaultRequiresHigherFirm";
                case -1703: return "ConfigMotionSCurveRequiresHigherFirm";
                case -1704: return "TalonFXFirmwarePreVBatDetect";
                case -1705: return "CANdleAnimationsRequireHigherFirm";
                case -1800: return "LibraryCouldNotBeLoaded";
                case -1801: return "MissingRoutineInLibrary";
                case -1802: return "ResourceNotAvailable";
                case -1900: return "MusicFileNotFound";
                case -1901: return "MusicFileWrongSize";
                case -1902: return "MusicFileTooNew";
                case -1903: return "MusicFileInvalid";
                case -1904: return "InvalidOrchestraAction";
                case -1905: return "MusicFileTooOld";
                case -1906: return "MusicInterrupted";
                case -1907: return "MusicNotSupported";
                case -2000: return "kInvalidInterface";
                case -2001: return "kInvalidGuid";
                case -2002: return "kInvalidClass";
                case -2003: return "kInvalidProtocol";
                case -2004: return "kInvalidPath";
                case -2005: return "kGeneralWinUsbError";
                case -2006: return "kFailedSetup";
                case -2007: return "kListenFailed";
                case -2008: return "kSendFailed";
                case -2009: return "kReceiveFailed";
                case -2010: return "kInvalidRespFormat";
                case -2011: return "kWinUsbInitFailed";
                case -2012: return "kWinUsbQueryFailed";
                case -2013: return "kWinUsbGeneralError";
                case -2014: return "kAccessDenied";
                case -2015: return "kFirmwareInvalidResponse";
                case -10000: return "StatusCodeNotInitialized";
                case 10000: return "WarningNotInitialized";
                case 10001: return "HwTimestampOutOfSync";
                case 10002: return "FrequentConfigCalls";
                case -10001: return "InvalidNetwork";
                case -10002: return "MultiSignalNotSupported";
                case -10003: return "CouldNotCast";
                case -10004: return "NotFound";
                case -10005: return "NotSupported";
                case -10006: return "MissingContext";
                case -10007: return "ModelMismatch";
                case -10008: return "SerialMismatch";
                case -10009: return "NoFile";
                case -10010: return "LicenseDownloadFailed";
                case -10011: return "SelfTestIsEmpty";
                case -10012: return "SignalLookupFailed";
                case -10013: return "InvalidModeToGetSignal";
                case -10014: return "UnlicensedDevice";
                case -10015: return "InvalidSize";
                case -10016: return "InvalidLicenseResponse";
                case -10017: return "InvalidContext";
                case -10018: return "InternalError";
                case -10019: return "kDeviceResponseIncorrect";
                case -10020: return "kErrorPollingForDevices";
                case -10021: return "CouldNotRetrieveV6Firmware";
                case -10022: return "CouldNotDecodeDeviceFirmware";
                case -10023: return "InvalidIDToFollow";
                case -10024: return "UsingProFeatureOnUnlicensedDevice";
                case -10025: return "FirmwareTooNew";
                case -10026: return "CouldNotSerialize";
                case -10027: return "MechanismFaulted";
                case -10028: return "FirmwareVersNotCompatible";
                case -10029: return "DirectoryMissing";
                case -10030: return "ApiTooOld";
                case -10031: return "LoggerNotRunning";
                case -10032: return "TimeoutCannotBeZero";
                case -10033: return "CannotLicenseWhileEnabled";
                case -10034: return "InvalidFile";
                case -10035: return "HootLogTooOld";
                case -10036: return "HootLogTooNew";
                case -10037: return "UnlicensedHootLog";
                case -10038: return "CannotStepWhileUnpaused";
                case -10039: return "MultipleReplayNotSupported";
                case -10040: return "UserSignalLimitExceeded";
                case -10041: return "InvalidDeviceModel";
                default:
                    /* because we return const char*, we cannot create
                     * a string with the status error code */
                    return "Could not find name for StatusCode";
                }
            }
            /**
             * Gets the description of this StatusCode
             *
             * \returns Description of this StatusCode
             */
            constexpr const char *GetDescription() const
            {
                switch (value)
                {
                case 0: return "No Error";
                case -100: return "Diagnostic Server is busy with another command.";
                case -101: return "InvalidDeviceSpec";
                case -102: return "Device is not present. Verify the device is connected and powered, and that the CAN bus is terminated.";
                case -103: return "Could not put the device into bootloader mode.";
                case -104: return "Could not confirm the device has entered the bootloader.";
                case -105: return "Could not erase flash.";
                case -106: return "Could not field upgrade the device.";
                case -107: return "Bootloader could not verify integrity of the flashed application.";
                case -108: return "Could not run the device firmware application.";
                case -109: return "Unable to set ID to this device.";
                case -110: return "Could not verify that the changed ID took effect.";
                case -111: return "Device field upgrade was successful.";
                case -112: return "Device firmware application is too old.";
                case -113: return "Unable to set name to this device.";
                case -114: return "CompileSzIsWrong";
                case -115: return "Cannot set the ID of a gadgeteer device.";
                case -116: return "This diagnostic action is not supported.";
                case -117: return "Not Implemented, check latest installer.";
                case -118: return "NoDevicesOnBus";
                case -119: return "MoreThanOneFile";
                case -120: return "Specified device was not found. Verify the device is connected and powered, and that the CAN bus is terminated.";
                case -121: return "InvalidDeviceDescriptor";
                case -123: return "CouldNotSendCanFrame";
                case -124: return "NormalModeMsgNotPresent";
                case -125: return "This feature is not supported.";
                case -126: return "The diagnostic server is not field upgrading any devices.";
                case -127: return "CorruptedPOST";
                case -128: return "This device did not report any available configs. Verify firmware and diagnostics are up-to-date.";
                case -129: return "ConfigFailed";
                case -130: return "Unable to factory default this device.";
                case -131: return "CustomNameNotSupported";
                case -132: return "The configs read from the device do not match the configs that were written.";
                case -133: return "Could not apply the device configs.";
                case -134: return "InsufficientSz";
                case -135: return "This feature is not supported for this device model.";
                case -140: return "CouldNotReqDevInfo";
                case -141: return "This device does not support new controls.";
                case -142: return "DeviceIsNull";
                case -143: return "DeviceDidNotRespondToDiagReq";
                case -144: return "This feature requires Tuner X.";
                case -145: return "Command-line issue with caniv.";
                case -200: return "InvalidCrfBadHeader";
                case -201: return "InvalidCrfFileSzInvald";
                case -202: return "Specified CRF is for the wrong product.";
                case -203: return "InvalidCrfNoSects";
                case -204: return "InvalidCrfBadSectHeader";
                case -205: return "InvalidCrfBadSectSize";
                case -206: return "Specified CRF file could not be found.";
                case -300: return "CouldNotFindDynamicId";
                case -301: return "DidNotGetDhcp";
                case -302: return "DidNotGetFullDhcp";
                case -350: return "InvalidLicenseResp";
                case -351: return "InvalidCanivCache";
                case -500: return "CannotOpenSerialPort";
                case -501: return "CannotWriteSerialPort";
                case -502: return "CannotReadSerialPort";
                case -503: return "CannotSerialToDevice";
                case -504: return "NoSerialControlFrameResp";
                case -600: return "CannotOpenUdpPort";
                case -601: return "CannotWriteUdpPort";
                case -602: return "CannotReadUdpPort";
                case -603: return "CannotUdpToDevice";
                case -604: return "NoUdpControlFrameResp";
                case -605: return "TimeoutIso15Response";
                case -700: return "InvalidJson";
                case -800: return "The user application is shutting down.";
                case 1000: return "CAN message is stale, data is valid but old. Check the CAN bus wiring, CAN bus utilization, and power to the device.";
                case 1006: return "Buffer is full, cannot insert more data.";
                case 1010: return "PulseWidthSensorNotPresent";
                case 1100: return "General Warning Occurred.";
                case 1103: return "Firm Vers could not be retrieved. Use Phoenix Tuner X to check ID and firmware(CRF) version.";
                case 1104: return "This feature will be supported in a future update.";
                case 1105: return "The control mode is not valid for this function.";
                case 1106: return "This control mode is not supported yet.  A future release will supported this soon.";
                case 1109: return "Motor Controller must have >= 3.2 firmware for motion profile control mode.";
                case 1110: return "Motor Controller must have >= 3.4 firmware for advanced PID0/PID1 features.";
                case 1200: return "SimDeviceNotFound";
                case 1201: return "SimPhysicsTypeNotSupported";
                case 1202: return "SimDeviceAlreadyExists";
                case -1001: return "Could not transmit CAN Frame.";
                case -1002: return "An invalid argument was passed into the function/VI, such as a null pointer.";
                case -1003: return "CAN frame not received/too-stale. Check the CAN bus wiring, CAN bus utilization, and power to the device.";
                case -1004: return "CAN Transmit timed out.";
                case -1005: return "ArbID is incorrect.";
                case -1006: return "CanOverflowed";
                case -1007: return "Sensor Not Present.";
                case -1008: return "Firmware Too Old.  Use Phoenix Tuner X to field upgrade your CTRE CAN device firmware(CRF).  Then restart your robot application to clear this error.";
                case -1009: return "Control Frame Period could not be changed.  Most likely it is not being transmitted.";
                case -1010: return "BufferFailure";
                case -1011: return "Firmware is legacy non-FRC version.  Use Phoenix Tuner X to field upgrade your CTRE CAN device firmware(CRF).  Firmware greater than 20.0 required.";
                case -1100: return "General Error Occurred.";
                case -1200: return "No new response to update signal.";
                case -1201: return "NotAllPIDValuesUpdated";
                case -1300: return "GEN_PORT_ERROR";
                case -1301: return "PORT_MODULE_TYPE_MISMATCH";
                case -1400: return "GEN_MODULE_ERROR";
                case -1401: return "MODULE_NOT_INIT_SET_ERROR";
                case -1402: return "MODULE_NOT_INIT_GET_ERROR";
                case -1500: return "Wheel Radius is too small, cannot get distance traveled.";
                case -1501: return "Ticks per revolution is 0, cannot get heading.";
                case -1502: return "Distance between wheels is too small, cannot get heading.";
                case -1503: return "GainsAreNotSet";
                case -1504: return "Use RemoteLimitSwitchSource instead of LimitSwitchSource.";
                case -1505: return "Motor Controller Voltage Compensation should not be used with setVoltage().  This causes compensation to happen twice.  Disable Voltage Compensation by calling enableVoltageCompensation(false) in order to use setVoltage().";
                case -1506: return "CANdleAnimSlotOutOfBounds";
                case -1600: return "IncompatibleMode";
                case -1601: return "Handle passed into function is incorrect.";
                case -1700: return "Features requires newer firmware version.";
                case -1702: return "Config factory default features require firmware >=3.10.";
                case -1703: return "Config Motion S Curve Strength features require firmware >=4.16.";
                case -1704: return "Talon FX(Falcon 500) Firmware Too Old.  Use Phoenix Tuner to field upgrade your CTRE CAN device firmware(CRF) to >=20.3. Then restart your robot application to clear this error.";
                case -1705: return "CANdleAnimationsRequireHigherFirm";
                case -1800: return "LibraryCouldNotBeLoaded";
                case -1801: return "MissingRoutineInLibrary";
                case -1802: return "ResourceNotAvailable";
                case -1900: return "Could not find music file specified, try specifying an absolute path.";
                case -1901: return "Music file size is incorrect, could not parse correctly. Ensure you're using Tuner to generate file.";
                case -1902: return "Music file version is too new, update Phoenix to utilize this file.";
                case -1903: return "Music file is invalid. Ensure you're using Tuner to generate file.";
                case -1904: return "An invalid orchestra action occurred. Ensure a music file is loaded.";
                case -1905: return "This music file version is too old. Regenerate file using Tuner.";
                case -1906: return "Music interrupted due to one of the instruments being commanded a different control mode. Press Play to resume music.";
                case -1907: return "This device doesn't support MusicTone control mode.";
                case -2000: return "kInvalidInterface";
                case -2001: return "kInvalidGuid";
                case -2002: return "kInvalidClass";
                case -2003: return "kInvalidProtocol";
                case -2004: return "kInvalidPath";
                case -2005: return "kGeneralWinUsbError";
                case -2006: return "kFailedSetup";
                case -2007: return "kListenFailed";
                case -2008: return "kSendFailed";
                case -2009: return "kReceiveFailed";
                case -2010: return "kInvalidRespFormat";
                case -2011: return "kWinUsbInitFailed";
                case -2012: return "kWinUsbQueryFailed";
                case -2013: return "kWinUsbGeneralError";
                case -2014: return "kAccessDenied";
                case -2015: return "kFirmwareInvalidResponse";
                case -10000: return "This StatusCode has not been initialized. Make sure the StatusCode is getting assigned to the return of a method.";
                case 10000: return "WarningNotInitialized";
                case 10001: return "The timestamp reported by CANivore is at least 10ms older than the timestamp reported by the system, indicating it's fallen out of sync. This does not impact the data of this message, only the timing.";
                case 10002: return "Do not apply or refresh configs periodically, as configs are blocking.";
                case -10001: return "InvalidNetwork";
                case -10002: return "The CAN bus does not support multi-signal synchronization.";
                case -10003: return "Could not cast from base value to this particular signal's type";
                case -10004: return "Could not find this value when searching for it";
                case -10005: return "This is not supported";
                case -10006: return "Could not determine context from this device hash";
                case -10007: return "Model name in license file does not match model name of selected device.";
                case -10008: return "Serial Number in license file does not match model name of selected device.";
                case -10009: return "Could not find specified file.";
                case -10010: return "License did not successfully download to Device.";
                case -10011: return "Self Test report does not have any values, is the firmware up to date?";
                case -10012: return "Failed to lookup signal properties.  This can happen if the fimware is too new and supports signals that older APIs do not support.";
                case -10013: return "The current mode of the device is invalid for getting this signal.";
                case -10014: return "Device is not licensed. Cannot get any data from it.";
                case -10015: return "Size is invalid.";
                case -10016: return "InvalidLicenseResponse";
                case -10017: return "InvalidContext";
                case -10018: return "InternalError";
                case -10019: return "kDeviceResponseIncorrect";
                case -10020: return "kErrorPollingForDevices";
                case -10021: return "Device firmware could not be retrieved. Check that the device is running v6 firmware, the device ID is correct, the specified CAN bus is correct, and the device is powered.";
                case -10022: return "Device firmware could not be decoded. Check that the device is running v6 firmware, the device ID is correct, the specified CAN bus is correct, and the device is powered.";
                case -10023: return "The values specified for master are in valid.  Make sure the Device ID of master are correct.";
                case -10024: return "Using a Pro only feature on an unlicensed device. The device may not behave as expected if it continues to operate while unlicensed.";
                case -10025: return "Firmware Too New.  Use Phoenix Tuner X to field upgrade your CTRE CAN device firmware(CRF) to a compatible version.  Then restart your robot application to clear this error.";
                case -10026: return "The data frame could not be serialized for transmit.";
                case -10027: return "The mechanism is disabled due to a fault in one of the devices.";
                case -10028: return "Firmware version is not compatible with this version of Phoenix. Make sure your firmware and API major versions match.";
                case -10029: return "Could not find specified directory.";
                case -10030: return "This API version is too old for the firmware on the device. Either upgrade the API to a newer version or downgrade the device firmware to an older version for correct behavior.";
                case -10031: return "The signal logger is not running. Start the signal logger before writing any signals.";
                case -10032: return "Blocking operations, such as configs, cannot have a timeout of 0. Pass in a non-zero timeout (typically 0.050+ seconds) for normal operation.";
                case -10033: return "Device cannot be licensed while it is control enabled. Disable and neutral the device to apply the licenses.";
                case -10034: return "Could not open or read the given file.";
                case -10035: return "The given hoot log requires an older version of Phoenix API.";
                case -10036: return "The given hoot log requires a newer version of Phoenix API.";
                case -10037: return "Hoot log is not licensed. Cannot get any data from it.";
                case -10038: return "The simulation timing cannot be advanced by a time step while unpaused. Pause the simulator before advancing time.";
                case -10039: return "Hoot replay does not support replaying multiple files. Ensure that only one file is loaded at a time.";
                case -10040: return "The maximum number of loggable user signals has been exceeded. Additional user signals will not be logged.";
                case -10041: return "The provided model was not a valid device type.";
                default:
                    /* because we return const char*, we cannot create
                     * a string with the status error code */
                    return "Could not find description for StatusCode";
                }
            }
            friend std::ostream &operator<<(std::ostream &os, StatusCode status)
            {
                os << status.GetName() << ": " << status.GetDescription();
                return os;
            }
        };

    }
}

} // extern "C++"

#else // This is straight-C, so just create a typedef enum to use

/**
 * \brief Typedef enum of the StatusCode for use in C projects
 */
typedef enum _StatusCode_t
{
    /**
     * \brief No Error
     */
    OK = 0,
    /**
     * \brief Diagnostic Server is busy with another command.
     */
    TaskIsBusy = -100,
    /**
     * \brief InvalidDeviceSpec
     */
    InvalidDeviceSpec = -101,
    /**
     * \brief Device is not present. Verify the device is connected and powered, and
     *        that the CAN bus is terminated.
     */
    EcuIsNotPresent = -102,
    /**
     * \brief Could not put the device into bootloader mode.
     */
    CouldNotEnterBl = -103,
    /**
     * \brief Could not confirm the device has entered the bootloader.
     */
    CouldNotConfirmBl = -104,
    /**
     * \brief Could not erase flash.
     */
    CouldNotErase = -105,
    /**
     * \brief Could not field upgrade the device.
     */
    CouldNotSendFlash = -106,
    /**
     * \brief Bootloader could not verify integrity of the flashed application.
     */
    CouldNotValidate = -107,
    /**
     * \brief Could not run the device firmware application.
     */
    CouldNotRunApp = -108,
    /**
     * \brief Unable to set ID to this device.
     */
    CouldNotReqSetId = -109,
    /**
     * \brief Could not verify that the changed ID took effect.
     */
    CouldNotConfirmId = -110,
    /**
     * \brief Device field upgrade was successful.
     */
    FlashWasGood = -111,
    /**
     * \brief Device firmware application is too old.
     */
    AppTooOld = -112,
    /**
     * \brief Unable to set name to this device.
     */
    CouldNotReqSetDesc = -113,
    /**
     * \brief CompileSzIsWrong
     */
    CompileSzIsWrong = -114,
    /**
     * \brief Cannot set the ID of a gadgeteer device.
     */
    GadgeteerDeviceNoSetId = -115,
    /**
     * \brief This diagnostic action is not supported.
     */
    InvalidTask = -116,
    /**
     * \brief Not Implemented, check latest installer.
     */
    NotImplemented = -117,
    /**
     * \brief NoDevicesOnBus
     */
    NoDevicesOnBus = -118,
    /**
     * \brief MoreThanOneFile
     */
    MoreThanOneFile = -119,
    /**
     * \brief Specified device was not found. Verify the device is connected and
     *        powered, and that the CAN bus is terminated.
     */
    NodeIsInvalid = -120,
    /**
     * \brief InvalidDeviceDescriptor
     */
    InvalidDeviceDescriptor = -121,
    /**
     * \brief CouldNotSendCanFrame
     */
    CouldNotSendCanFrame = -123,
    /**
     * \brief NormalModeMsgNotPresent
     */
    NormalModeMsgNotPresent = -124,
    /**
     * \brief This feature is not supported.
     */
    FeatureNotSupported = -125,
    /**
     * \brief The diagnostic server is not field upgrading any devices.
     */
    NotUpdating = -126,
    /**
     * \brief CorruptedPOST
     */
    CorruptedPOST = -127,
    /**
     * \brief This device did not report any available configs. Verify firmware and
     *        diagnostics are up-to-date.
     */
    NoConfigs = -128,
    /**
     * \brief ConfigFailed
     */
    ConfigFailed = -129,
    /**
     * \brief Unable to factory default this device.
     */
    CouldNotReqFactoryDefault = -130,
    /**
     * \brief CustomNameNotSupported
     */
    CustomNameNotSupported = -131,
    /**
     * \brief The configs read from the device do not match the configs that were
     *        written.
     */
    ConfigReadWriteMismatch = -132,
    /**
     * \brief Could not apply the device configs.
     */
    CouldNotReqSetConfigs = -133,
    /**
     * \brief InsufficientSz
     */
    InsufficientSz = -134,
    /**
     * \brief This feature is not supported for this device model.
     */
    InvalidModel = -135,
    /**
     * \brief CouldNotReqDevInfo
     */
    CouldNotReqDevInfo = -140,
    /**
     * \brief This device does not support new controls.
     */
    NoControls = -141,
    /**
     * \brief DeviceIsNull
     */
    DeviceIsNull = -142,
    /**
     * \brief DeviceDidNotRespondToDiagReq
     */
    DeviceDidNotRespondToDiagReq = -143,
    /**
     * \brief This feature requires Tuner X.
     */
    OnlySupportedInTunerX = -144,
    /**
     * \brief Command-line issue with caniv.
     */
    CanivCliError = -145,
    /**
     * \brief InvalidCrfBadHeader
     */
    InvalidCrfBadHeader = -200,
    /**
     * \brief InvalidCrfFileSzInvald
     */
    InvalidCrfFileSzInvald = -201,
    /**
     * \brief Specified CRF is for the wrong product.
     */
    InvalidCrfWrongProduct = -202,
    /**
     * \brief InvalidCrfNoSects
     */
    InvalidCrfNoSects = -203,
    /**
     * \brief InvalidCrfBadSectHeader
     */
    InvalidCrfBadSectHeader = -204,
    /**
     * \brief InvalidCrfBadSectSize
     */
    InvalidCrfBadSectSize = -205,
    /**
     * \brief Specified CRF file could not be found.
     */
    NoCrfFile = -206,
    /**
     * \brief CouldNotFindDynamicId
     */
    CouldNotFindDynamicId = -300,
    /**
     * \brief DidNotGetDhcp
     */
    DidNotGetDhcp = -301,
    /**
     * \brief DidNotGetFullDhcp
     */
    DidNotGetFullDhcp = -302,
    /**
     * \brief InvalidLicenseResp
     */
    InvalidLicenseResp = -350,
    /**
     * \brief InvalidCanivCache
     */
    InvalidCanivCache = -351,
    /**
     * \brief CannotOpenSerialPort
     */
    CannotOpenSerialPort = -500,
    /**
     * \brief CannotWriteSerialPort
     */
    CannotWriteSerialPort = -501,
    /**
     * \brief CannotReadSerialPort
     */
    CannotReadSerialPort = -502,
    /**
     * \brief CannotSerialToDevice
     */
    CannotSerialToDevice = -503,
    /**
     * \brief NoSerialControlFrameResp
     */
    NoSerialControlFrameResp = -504,
    /**
     * \brief CannotOpenUdpPort
     */
    CannotOpenUdpPort = -600,
    /**
     * \brief CannotWriteUdpPort
     */
    CannotWriteUdpPort = -601,
    /**
     * \brief CannotReadUdpPort
     */
    CannotReadUdpPort = -602,
    /**
     * \brief CannotUdpToDevice
     */
    CannotUdpToDevice = -603,
    /**
     * \brief NoUdpControlFrameResp
     */
    NoUdpControlFrameResp = -604,
    /**
     * \brief TimeoutIso15Response
     */
    TimeoutIso15Response = -605,
    /**
     * \brief InvalidJson
     */
    InvalidJson = -700,
    /**
     * \brief The user application is shutting down.
     */
    AppIsTerminating = -800,
    /**
     * \brief CAN message is stale, data is valid but old. Check the CAN bus wiring,
     *        CAN bus utilization, and power to the device.
     */
    CanMessageStale = 1000,
    /**
     * \brief Buffer is full, cannot insert more data.
     */
    BufferFull = 1006,
    /**
     * \brief PulseWidthSensorNotPresent
     */
    PulseWidthSensorNotPresent = 1010,
    /**
     * \brief General Warning Occurred.
     */
    GeneralWarning = 1100,
    /**
     * \brief Firm Vers could not be retrieved. Use Phoenix Tuner X to check ID and
     *        firmware(CRF) version.
     */
    FirmVersionCouldNotBeRetrieved = 1103,
    /**
     * \brief This feature will be supported in a future update.
     */
    FeaturesNotAvailableYet = 1104,
    /**
     * \brief The control mode is not valid for this function.
     */
    ControlModeNotValid = 1105,
    /**
     * \brief This control mode is not supported yet.  A future release will
     *        supported this soon.
     */
    ControlModeNotSupportedYet = 1106,
    /**
     * \brief Motor Controller must have &gt;= 3.2 firmware for motion profile
     *        control mode.
     */
    MotProfFirmThreshold = 1109,
    /**
     * \brief Motor Controller must have &gt;= 3.4 firmware for advanced PID0/PID1
     *        features.
     */
    MotProfFirmThreshold2 = 1110,
    /**
     * \brief SimDeviceNotFound
     */
    SimDeviceNotFound = 1200,
    /**
     * \brief SimPhysicsTypeNotSupported
     */
    SimPhysicsTypeNotSupported = 1201,
    /**
     * \brief SimDeviceAlreadyExists
     */
    SimDeviceAlreadyExists = 1202,
    /**
     * \brief Could not transmit CAN Frame.
     */
    TxFailed = -1001,
    /**
     * \brief An invalid argument was passed into the function/VI, such as a null
     *        pointer.
     */
    InvalidParamValue = -1002,
    /**
     * \brief CAN frame not received/too-stale. Check the CAN bus wiring, CAN bus
     *        utilization, and power to the device.
     */
    RxTimeout = -1003,
    /**
     * \brief CAN Transmit timed out.
     */
    TxTimeout = -1004,
    /**
     * \brief ArbID is incorrect.
     */
    UnexpectedArbId = -1005,
    /**
     * \brief CanOverflowed
     */
    CanOverflowed = -1006,
    /**
     * \brief Sensor Not Present.
     */
    SensorNotPresent = -1007,
    /**
     * \brief Firmware Too Old.  Use Phoenix Tuner X to field upgrade your CTRE CAN
     *        device firmware(CRF).  Then restart your robot application to clear
     *        this error.
     */
    FirmwareTooOld = -1008,
    /**
     * \brief Control Frame Period could not be changed.  Most likely it is not
     *        being transmitted.
     */
    CouldNotChangePeriod = -1009,
    /**
     * \brief BufferFailure
     */
    BufferFailure = -1010,
    /**
     * \brief Firmware is legacy non-FRC version.  Use Phoenix Tuner X to field
     *        upgrade your CTRE CAN device firmware(CRF).  Firmware greater than
     *        20.0 required.
     */
    FirmwareNonFRC = -1011,
    /**
     * \brief General Error Occurred.
     */
    GeneralError = -1100,
    /**
     * \brief No new response to update signal.
     */
    SigNotUpdated = -1200,
    /**
     * \brief NotAllPIDValuesUpdated
     */
    NotAllPIDValuesUpdated = -1201,
    /**
     * \brief GEN_PORT_ERROR
     */
    GEN_PORT_ERROR = -1300,
    /**
     * \brief PORT_MODULE_TYPE_MISMATCH
     */
    PORT_MODULE_TYPE_MISMATCH = -1301,
    /**
     * \brief GEN_MODULE_ERROR
     */
    GEN_MODULE_ERROR = -1400,
    /**
     * \brief MODULE_NOT_INIT_SET_ERROR
     */
    MODULE_NOT_INIT_SET_ERROR = -1401,
    /**
     * \brief MODULE_NOT_INIT_GET_ERROR
     */
    MODULE_NOT_INIT_GET_ERROR = -1402,
    /**
     * \brief Wheel Radius is too small, cannot get distance traveled.
     */
    WheelRadiusTooSmall = -1500,
    /**
     * \brief Ticks per revolution is 0, cannot get heading.
     */
    TicksPerRevZero = -1501,
    /**
     * \brief Distance between wheels is too small, cannot get heading.
     */
    DistanceBetweenWheelsTooSmall = -1502,
    /**
     * \brief GainsAreNotSet
     */
    GainsAreNotSet = -1503,
    /**
     * \brief Use RemoteLimitSwitchSource instead of LimitSwitchSource.
     */
    WrongRemoteLimitSwitchSource = -1504,
    /**
     * \brief Motor Controller Voltage Compensation should not be used with
     *        setVoltage().  This causes compensation to happen twice.  Disable
     *        Voltage Compensation by calling enableVoltageCompensation(false) in
     *        order to use setVoltage().
     */
    DoubleVoltageCompensatingWPI = -1505,
    /**
     * \brief CANdleAnimSlotOutOfBounds
     */
    CANdleAnimSlotOutOfBounds = -1506,
    /**
     * \brief IncompatibleMode
     */
    IncompatibleMode = -1600,
    /**
     * \brief Handle passed into function is incorrect.
     */
    InvalidHandle = -1601,
    /**
     * \brief Features requires newer firmware version.
     */
    FeatureRequiresHigherFirm = -1700,
    /**
     * \brief Config factory default features require firmware &gt;=3.10.
     */
    ConfigFactoryDefaultRequiresHigherFirm = -1702,
    /**
     * \brief Config Motion S Curve Strength features require firmware &gt;=4.16.
     */
    ConfigMotionSCurveRequiresHigherFirm = -1703,
    /**
     * \brief Talon FX(Falcon 500) Firmware Too Old.  Use Phoenix Tuner to field
     *        upgrade your CTRE CAN device firmware(CRF) to &gt;=20.3. Then restart
     *        your robot application to clear this error.
     */
    TalonFXFirmwarePreVBatDetect = -1704,
    /**
     * \brief CANdleAnimationsRequireHigherFirm
     */
    CANdleAnimationsRequireHigherFirm = -1705,
    /**
     * \brief LibraryCouldNotBeLoaded
     */
    LibraryCouldNotBeLoaded = -1800,
    /**
     * \brief MissingRoutineInLibrary
     */
    MissingRoutineInLibrary = -1801,
    /**
     * \brief ResourceNotAvailable
     */
    ResourceNotAvailable = -1802,
    /**
     * \brief Could not find music file specified, try specifying an absolute path.
     */
    MusicFileNotFound = -1900,
    /**
     * \brief Music file size is incorrect, could not parse correctly. Ensure you're
     *        using Tuner to generate file.
     */
    MusicFileWrongSize = -1901,
    /**
     * \brief Music file version is too new, update Phoenix to utilize this file.
     */
    MusicFileTooNew = -1902,
    /**
     * \brief Music file is invalid. Ensure you're using Tuner to generate file.
     */
    MusicFileInvalid = -1903,
    /**
     * \brief An invalid orchestra action occurred. Ensure a music file is loaded.
     */
    InvalidOrchestraAction = -1904,
    /**
     * \brief This music file version is too old. Regenerate file using Tuner.
     */
    MusicFileTooOld = -1905,
    /**
     * \brief Music interrupted due to one of the instruments being commanded a
     *        different control mode. Press Play to resume music.
     */
    MusicInterrupted = -1906,
    /**
     * \brief This device doesn't support MusicTone control mode.
     */
    MusicNotSupported = -1907,
    /**
     * \brief kInvalidInterface
     */
    kInvalidInterface = -2000,
    /**
     * \brief kInvalidGuid
     */
    kInvalidGuid = -2001,
    /**
     * \brief kInvalidClass
     */
    kInvalidClass = -2002,
    /**
     * \brief kInvalidProtocol
     */
    kInvalidProtocol = -2003,
    /**
     * \brief kInvalidPath
     */
    kInvalidPath = -2004,
    /**
     * \brief kGeneralWinUsbError
     */
    kGeneralWinUsbError = -2005,
    /**
     * \brief kFailedSetup
     */
    kFailedSetup = -2006,
    /**
     * \brief kListenFailed
     */
    kListenFailed = -2007,
    /**
     * \brief kSendFailed
     */
    kSendFailed = -2008,
    /**
     * \brief kReceiveFailed
     */
    kReceiveFailed = -2009,
    /**
     * \brief kInvalidRespFormat
     */
    kInvalidRespFormat = -2010,
    /**
     * \brief kWinUsbInitFailed
     */
    kWinUsbInitFailed = -2011,
    /**
     * \brief kWinUsbQueryFailed
     */
    kWinUsbQueryFailed = -2012,
    /**
     * \brief kWinUsbGeneralError
     */
    kWinUsbGeneralError = -2013,
    /**
     * \brief kAccessDenied
     */
    kAccessDenied = -2014,
    /**
     * \brief kFirmwareInvalidResponse
     */
    kFirmwareInvalidResponse = -2015,
    /**
     * \brief This StatusCode has not been initialized. Make sure the StatusCode is
     *        getting assigned to the return of a method.
     */
    StatusCodeNotInitialized = -10000,
    /**
     * \brief WarningNotInitialized
     */
    WarningNotInitialized = 10000,
    /**
     * \brief The timestamp reported by CANivore is at least 10ms older than the
     *        timestamp reported by the system, indicating it's fallen out of sync.
     *        This does not impact the data of this message, only the timing.
     */
    HwTimestampOutOfSync = 10001,
    /**
     * \brief Do not apply or refresh configs periodically, as configs are blocking.
     */
    FrequentConfigCalls = 10002,
    /**
     * \brief InvalidNetwork
     */
    InvalidNetwork = -10001,
    /**
     * \brief The CAN bus does not support multi-signal synchronization.
     */
    MultiSignalNotSupported = -10002,
    /**
     * \brief Could not cast from base value to this particular signal's type
     */
    CouldNotCast = -10003,
    /**
     * \brief Could not find this value when searching for it
     */
    NotFound = -10004,
    /**
     * \brief This is not supported
     */
    NotSupported = -10005,
    /**
     * \brief Could not determine context from this device hash
     */
    MissingContext = -10006,
    /**
     * \brief Model name in license file does not match model name of selected
     *        device.
     */
    ModelMismatch = -10007,
    /**
     * \brief Serial Number in license file does not match model name of selected
     *        device.
     */
    SerialMismatch = -10008,
    /**
     * \brief Could not find specified file.
     */
    NoFile = -10009,
    /**
     * \brief License did not successfully download to Device.
     */
    LicenseDownloadFailed = -10010,
    /**
     * \brief Self Test report does not have any values, is the firmware up to date?
     */
    SelfTestIsEmpty = -10011,
    /**
     * \brief Failed to lookup signal properties.  This can happen if the fimware is
     *        too new and supports signals that older APIs do not support.
     */
    SignalLookupFailed = -10012,
    /**
     * \brief The current mode of the device is invalid for getting this signal.
     */
    InvalidModeToGetSignal = -10013,
    /**
     * \brief Device is not licensed. Cannot get any data from it.
     */
    UnlicensedDevice = -10014,
    /**
     * \brief Size is invalid.
     */
    InvalidSize = -10015,
    /**
     * \brief InvalidLicenseResponse
     */
    InvalidLicenseResponse = -10016,
    /**
     * \brief InvalidContext
     */
    InvalidContext = -10017,
    /**
     * \brief InternalError
     */
    InternalError = -10018,
    /**
     * \brief kDeviceResponseIncorrect
     */
    kDeviceResponseIncorrect = -10019,
    /**
     * \brief kErrorPollingForDevices
     */
    kErrorPollingForDevices = -10020,
    /**
     * \brief Device firmware could not be retrieved. Check that the device is
     *        running v6 firmware, the device ID is correct, the specified CAN bus
     *        is correct, and the device is powered.
     */
    CouldNotRetrieveV6Firmware = -10021,
    /**
     * \brief Device firmware could not be decoded. Check that the device is running
     *        v6 firmware, the device ID is correct, the specified CAN bus is
     *        correct, and the device is powered.
     */
    CouldNotDecodeDeviceFirmware = -10022,
    /**
     * \brief The values specified for master are in valid.  Make sure the Device ID
     *        of master are correct.
     */
    InvalidIDToFollow = -10023,
    /**
     * \brief Using a Pro only feature on an unlicensed device. The device may not
     *        behave as expected if it continues to operate while unlicensed.
     */
    UsingProFeatureOnUnlicensedDevice = -10024,
    /**
     * \brief Firmware Too New.  Use Phoenix Tuner X to field upgrade your CTRE CAN
     *        device firmware(CRF) to a compatible version.  Then restart your robot
     *        application to clear this error.
     */
    FirmwareTooNew = -10025,
    /**
     * \brief The data frame could not be serialized for transmit.
     */
    CouldNotSerialize = -10026,
    /**
     * \brief The mechanism is disabled due to a fault in one of the devices.
     */
    MechanismFaulted = -10027,
    /**
     * \brief Firmware version is not compatible with this version of Phoenix. Make
     *        sure your firmware and API major versions match.
     */
    FirmwareVersNotCompatible = -10028,
    /**
     * \brief Could not find specified directory.
     */
    DirectoryMissing = -10029,
    /**
     * \brief This API version is too old for the firmware on the device. Either
     *        upgrade the API to a newer version or downgrade the device firmware to
     *        an older version for correct behavior.
     */
    ApiTooOld = -10030,
    /**
     * \brief The signal logger is not running. Start the signal logger before
     *        writing any signals.
     */
    LoggerNotRunning = -10031,
    /**
     * \brief Blocking operations, such as configs, cannot have a timeout of 0. Pass
     *        in a non-zero timeout (typically 0.050+ seconds) for normal operation.
     */
    TimeoutCannotBeZero = -10032,
    /**
     * \brief Device cannot be licensed while it is control enabled. Disable and
     *        neutral the device to apply the licenses.
     */
    CannotLicenseWhileEnabled = -10033,
    /**
     * \brief Could not open or read the given file.
     */
    InvalidFile = -10034,
    /**
     * \brief The given hoot log requires an older version of Phoenix API.
     */
    HootLogTooOld = -10035,
    /**
     * \brief The given hoot log requires a newer version of Phoenix API.
     */
    HootLogTooNew = -10036,
    /**
     * \brief Hoot log is not licensed. Cannot get any data from it.
     */
    UnlicensedHootLog = -10037,
    /**
     * \brief The simulation timing cannot be advanced by a time step while
     *        unpaused. Pause the simulator before advancing time.
     */
    CannotStepWhileUnpaused = -10038,
    /**
     * \brief Hoot replay does not support replaying multiple files. Ensure that
     *        only one file is loaded at a time.
     */
    MultipleReplayNotSupported = -10039,
    /**
     * \brief The maximum number of loggable user signals has been exceeded.
     *        Additional user signals will not be logged.
     */
    UserSignalLimitExceeded = -10040,
    /**
     * \brief The provided model was not a valid device type.
     */
    InvalidDeviceModel = -10041,
} StatusCode_t;

/**
 * \brief Get the name of the StatusCode passed
 *
 * \param value StatusCode to get name of
 * \returns const char* Name of StatusCode
 */
const char *GetStatusCodeName(StatusCode_t value);
/**
 * \brief Get the description of the StatusCode passed
 *
 * \param value StatusCode to get description of
 * \returns const char* Description of StatusCode
 */
const char *GetStatusCodeDescription(StatusCode_t value);

#endif
