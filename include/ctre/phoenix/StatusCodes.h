/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#ifdef __cplusplus

namespace ctre
{
    namespace phoenix
    {

        class StatusCode
        {
            int value;

        public:
            /**
             * \brief  No Error
             */
            static constexpr int OK = 0;
            /**
             * \brief  InvalidDeviceSpec
             */
            static constexpr int InvalidDeviceSpec = -101;
            /**
             * \brief  EcuIsNotPresent
             */
            static constexpr int EcuIsNotPresent = -102;
            /**
             * \brief  CouldNotEnterBl
             */
            static constexpr int CouldNotEnterBl = -103;
            /**
             * \brief  CouldNotConfirmBl
             */
            static constexpr int CouldNotConfirmBl = -104;
            /**
             * \brief  CouldNotErase
             */
            static constexpr int CouldNotErase = -105;
            /**
             * \brief  CouldNotSendFlash
             */
            static constexpr int CouldNotSendFlash = -106;
            /**
             * \brief  CouldNotValidate
             */
            static constexpr int CouldNotValidate = -107;
            /**
             * \brief  CouldNotRunApp
             */
            static constexpr int CouldNotRunApp = -108;
            /**
             * \brief  CouldNotReqSetId
             */
            static constexpr int CouldNotReqSetId = -109;
            /**
             * \brief  CouldNotConfirmId
             */
            static constexpr int CouldNotConfirmId = -110;
            /**
             * \brief  FlashWasGood
             */
            static constexpr int FlashWasGood = -111;
            /**
             * \brief  AppTooOld
             */
            static constexpr int AppTooOld = -112;
            /**
             * \brief  CouldNotReqSetDesc
             */
            static constexpr int CouldNotReqSetDesc = -113;
            /**
             * \brief  CompileSzIsWrong
             */
            static constexpr int CompileSzIsWrong = -114;
            /**
             * \brief  GadgeteerDeviceNoSetId
             */
            static constexpr int GadgeteerDeviceNoSetId = -115;
            /**
             * \brief  InvalidTask
             */
            static constexpr int InvalidTask = -116;
            /**
             * \brief  Not Implemented, check latest installer.
             */
            static constexpr int NotImplemented = -117;
            /**
             * \brief  NoDevicesOnBus
             */
            static constexpr int NoDevicesOnBus = -118;
            /**
             * \brief  MoreThanOneFile
             */
            static constexpr int MoreThanOneFile = -119;
            /**
             * \brief  NodeIsInvalid
             */
            static constexpr int NodeIsInvalid = -120;
            /**
             * \brief  InvalidDeviceDescriptor
             */
            static constexpr int InvalidDeviceDescriptor = -121;
            /**
             * \brief  CouldNotSendCanFrame
             */
            static constexpr int CouldNotSendCanFrame = -123;
            /**
             * \brief  NormalModeMsgNotPresent
             */
            static constexpr int NormalModeMsgNotPresent = -124;
            /**
             * \brief  This feature is not supported.
             */
            static constexpr int FeatureNotSupported = -125;
            /**
             * \brief  NotUpdating
             */
            static constexpr int NotUpdating = -126;
            /**
             * \brief  CorruptedPOST
             */
            static constexpr int CorruptedPOST = -127;
            /**
             * \brief  NoConfigs
             */
            static constexpr int NoConfigs = -128;
            /**
             * \brief  ConfigFailed
             */
            static constexpr int ConfigFailed = -129;
            /**
             * \brief  CouldNotReqFactoryDefault
             */
            static constexpr int CouldNotReqFactoryDefault = -130;
            /**
             * \brief  CustomNameNotSupported
             */
            static constexpr int CustomNameNotSupported = -131;
            /**
             * \brief  ConfigReadWriteMismatch
             */
            static constexpr int ConfigReadWriteMismatch = -132;
            /**
             * \brief  CouldNotReqSetConfigs
             */
            static constexpr int CouldNotReqSetConfigs = -133;
            /**
             * \brief  InsufficientSz
             */
            static constexpr int InsufficientSz = -134;
            /**
             * \brief  InvalidModel
             */
            static constexpr int InvalidModel = -135;
            /**
             * \brief  CouldNotReqDevInfo
             */
            static constexpr int CouldNotReqDevInfo = -140;
            /**
             * \brief  NoControls
             */
            static constexpr int NoControls = -141;
            /**
             * \brief  DeviceIsNull
             */
            static constexpr int DeviceIsNull = -142;
            /**
             * \brief  DeviceDidNotRespondToDiagReq
             */
            static constexpr int DeviceDidNotRespondToDiagReq = -143;
            /**
             * \brief  OnlySupportedInTunerX
             */
            static constexpr int OnlySupportedInTunerX = -144;
            /**
             * \brief  CanivCliError
             */
            static constexpr int CanivCliError = -145;
            /**
             * \brief  InvalidCrfBadHeader
             */
            static constexpr int InvalidCrfBadHeader = -200;
            /**
             * \brief  InvalidCrfFileSzInvald
             */
            static constexpr int InvalidCrfFileSzInvald = -201;
            /**
             * \brief  InvalidCrfWrongProduct
             */
            static constexpr int InvalidCrfWrongProduct = -202;
            /**
             * \brief  InvalidCrfNoSects
             */
            static constexpr int InvalidCrfNoSects = -203;
            /**
             * \brief  InvalidCrfBadSectHeader
             */
            static constexpr int InvalidCrfBadSectHeader = -204;
            /**
             * \brief  InvalidCrfBadSectSize
             */
            static constexpr int InvalidCrfBadSectSize = -205;
            /**
             * \brief  NoCrfFile
             */
            static constexpr int NoCrfFile = -206;
            /**
             * \brief  CouldNotFindDynamicId
             */
            static constexpr int CouldNotFindDynamicId = -300;
            /**
             * \brief  DidNotGetDhcp
             */
            static constexpr int DidNotGetDhcp = -301;
            /**
             * \brief  DidNotGetFullDhcp
             */
            static constexpr int DidNotGetFullDhcp = -302;
            /**
             * \brief  InvalidLicenseResp
             */
            static constexpr int InvalidLicenseResp = -350;
            /**
             * \brief  InvalidCanivCache
             */
            static constexpr int InvalidCanivCache = -351;
            /**
             * \brief  CannotOpenSerialPort
             */
            static constexpr int CannotOpenSerialPort = -500;
            /**
             * \brief  CannotWriteSerialPort
             */
            static constexpr int CannotWriteSerialPort = -501;
            /**
             * \brief  CannotReadSerialPort
             */
            static constexpr int CannotReadSerialPort = -502;
            /**
             * \brief  CannotSerialToDevice
             */
            static constexpr int CannotSerialToDevice = -503;
            /**
             * \brief  NoSerialControlFrameResp
             */
            static constexpr int NoSerialControlFrameResp = -504;
            /**
             * \brief  CannotOpenUdpPort
             */
            static constexpr int CannotOpenUdpPort = -600;
            /**
             * \brief  CannotWriteUdpPort
             */
            static constexpr int CannotWriteUdpPort = -601;
            /**
             * \brief  CannotReadUdpPort
             */
            static constexpr int CannotReadUdpPort = -602;
            /**
             * \brief  CannotUdpToDevice
             */
            static constexpr int CannotUdpToDevice = -603;
            /**
             * \brief  NoUdpControlFrameResp
             */
            static constexpr int NoUdpControlFrameResp = -604;
            /**
             * \brief  TimeoutIso15Response
             */
            static constexpr int TimeoutIso15Response = -605;
            /**
             * \brief  InvalidJson
             */
            static constexpr int InvalidJson = -700;
            /**
             * \brief  AppIsTerminating
             */
            static constexpr int AppIsTerminating = -800;
            /**
             * \brief  CAN Message is stale.
             */
            static constexpr int CanMessageStale = 1000;
            /**
             * \brief  Buffer is full, cannot insert more data.
             */
            static constexpr int BufferFull = 1006;
            /**
             * \brief  PulseWidthSensorNotPresent
             */
            static constexpr int PulseWidthSensorNotPresent = 1010;
            /**
             * \brief  General Warning Occurred.
             */
            static constexpr int GeneralWarning = 1100;
            /**
             * \brief  Firm Vers could not be retrieved. Use Phoenix Tuner to check ID and
             *         firmware(CRF) version.
             */
            static constexpr int FirmVersionCouldNotBeRetrieved = 1103;
            /**
             * \brief  This feature will be supported in a future update.
             */
            static constexpr int FeaturesNotAvailableYet = 1104;
            /**
             * \brief  The control mode is not valid for this function.
             */
            static constexpr int ControlModeNotValid = 1105;
            /**
             * \brief  This control mode is not supported yet.  A future release will
             *         supported this soon.
             */
            static constexpr int ControlModeNotSupportedYet = 1106;
            /**
             * \brief  Motor Controller must have &gt;= 3.2 firmware for motion profile control
             *         mode.
             */
            static constexpr int MotProfFirmThreshold = 1109;
            /**
             * \brief  Motor Controller must have &gt;= 3.4 firmware for advanced PID0/PID1
             *         features.
             */
            static constexpr int MotProfFirmThreshold2 = 1110;
            /**
             * \brief  SimDeviceNotFound
             */
            static constexpr int SimDeviceNotFound = 1200;
            /**
             * \brief  SimPhysicsTypeNotSupported
             */
            static constexpr int SimPhysicsTypeNotSupported = 1201;
            /**
             * \brief  SimDeviceAlreadyExists
             */
            static constexpr int SimDeviceAlreadyExists = 1202;
            /**
             * \brief  Could not transmit CAN Frame.
             */
            static constexpr int TxFailed = -1001;
            /**
             * \brief  Incorrect argument passed into function/VI.
             */
            static constexpr int InvalidParamValue = -1002;
            /**
             * \brief  CAN frame not received/too-stale.
             */
            static constexpr int RxTimeout = -1003;
            /**
             * \brief  CAN Transmit timed out.
             */
            static constexpr int TxTimeout = -1004;
            /**
             * \brief  ArbID is incorrect.
             */
            static constexpr int UnexpectedArbId = -1005;
            /**
             * \brief  CanOverflowed
             */
            static constexpr int CanOverflowed = -1006;
            /**
             * \brief  Sensor Not Present.
             */
            static constexpr int SensorNotPresent = -1007;
            /**
             * \brief  Firmware Too Old.  Use Phoenix Tuner to field upgrade your CTRE CAN
             *         device firmware(CRF).  Then restart your robot application to clear
             *         this error.
             */
            static constexpr int FirmwareTooOld = -1008;
            /**
             * \brief  Control Frame Period could not be changed.  Most likely it is not
             *         being transmitted.
             */
            static constexpr int CouldNotChangePeriod = -1009;
            /**
             * \brief  BufferFailure
             */
            static constexpr int BufferFailure = -1010;
            /**
             * \brief  Firmware is legacy non-FRC version.  Use Phoenix Tuner to field
             *         upgrade your CTRE CAN device firmware(CRF).  Firmware greater than
             *         20.0 required.
             */
            static constexpr int FirmwareNonFRC = -1011;
            /**
             * \brief  General Error Occurred.
             */
            static constexpr int GeneralError = -1100;
            /**
             * \brief  No new response to update signal.
             */
            static constexpr int SigNotUpdated = -1200;
            /**
             * \brief  NotAllPIDValuesUpdated
             */
            static constexpr int NotAllPIDValuesUpdated = -1201;
            /**
             * \brief  GEN_PORT_ERROR
             */
            static constexpr int GEN_PORT_ERROR = -1300;
            /**
             * \brief  PORT_MODULE_TYPE_MISMATCH
             */
            static constexpr int PORT_MODULE_TYPE_MISMATCH = -1301;
            /**
             * \brief  GEN_MODULE_ERROR
             */
            static constexpr int GEN_MODULE_ERROR = -1400;
            /**
             * \brief  MODULE_NOT_INIT_SET_ERROR
             */
            static constexpr int MODULE_NOT_INIT_SET_ERROR = -1401;
            /**
             * \brief  MODULE_NOT_INIT_GET_ERROR
             */
            static constexpr int MODULE_NOT_INIT_GET_ERROR = -1402;
            /**
             * \brief  Wheel Radius is too small, cannot get distance traveled.
             */
            static constexpr int WheelRadiusTooSmall = -1500;
            /**
             * \brief  Ticks per revolution is 0, cannot get heading.
             */
            static constexpr int TicksPerRevZero = -1501;
            /**
             * \brief  Distance between wheels is too small, cannot get heading.
             */
            static constexpr int DistanceBetweenWheelsTooSmall = -1502;
            /**
             * \brief  GainsAreNotSet
             */
            static constexpr int GainsAreNotSet = -1503;
            /**
             * \brief  Use RemoteLimitSwitchSource instead of LimitSwitchSource.
             */
            static constexpr int WrongRemoteLimitSwitchSource = -1504;
            /**
             * \brief  Motor Controller Voltage Compensation should not be used with
             *         setVoltage().  This causes compensation to happen twice.  Disable
             *         Voltage Compensation by calling enableVoltageCompensation(false) in
             *         order to use setVoltage().
             */
            static constexpr int DoubleVoltageCompensatingWPI = -1505;
            /**
             * \brief  CANdleAnimSlotOutOfBounds
             */
            static constexpr int CANdleAnimSlotOutOfBounds = -1506;
            /**
             * \brief  IncompatibleMode
             */
            static constexpr int IncompatibleMode = -1600;
            /**
             * \brief  Handle passed into function is incorrect.
             */
            static constexpr int InvalidHandle = -1601;
            /**
             * \brief  Features requires newer firmware version.
             */
            static constexpr int FeatureRequiresHigherFirm = -1700;
            /**
             * \brief  Config factory default features require firmware &gt;=3.10.
             */
            static constexpr int ConfigFactoryDefaultRequiresHigherFirm = -1702;
            /**
             * \brief  Config Motion S Curve Strength features require firmware &gt;=4.16.
             */
            static constexpr int ConfigMotionSCurveRequiresHigherFirm = -1703;
            /**
             * \brief  Talon FX(Falcon 500) Firmware Too Old.  Use Phoenix Tuner to field
             *         upgrade your CTRE CAN device firmware(CRF) to &gt;=20.3. Then restart
             *         your robot application to clear this error.
             */
            static constexpr int TalonFXFirmwarePreVBatDetect = -1704;
            /**
             * \brief  CANdleAnimationsRequireHigherFirm
             */
            static constexpr int CANdleAnimationsRequireHigherFirm = -1705;
            /**
             * \brief  LibraryCouldNotBeLoaded
             */
            static constexpr int LibraryCouldNotBeLoaded = -1800;
            /**
             * \brief  MissingRoutineInLibrary
             */
            static constexpr int MissingRoutineInLibrary = -1801;
            /**
             * \brief  ResourceNotAvailable
             */
            static constexpr int ResourceNotAvailable = -1802;
            /**
             * \brief  Could not find music file specified, try specifying an absolute path.
             */
            static constexpr int MusicFileNotFound = -1900;
            /**
             * \brief  Music file size is incorrect, could not parse correctly. Ensure
             *         you're using Tuner to generate file.
             */
            static constexpr int MusicFileWrongSize = -1901;
            /**
             * \brief  Music file version is too new, update Phoenix to utilize this file.
             */
            static constexpr int MusicFileTooNew = -1902;
            /**
             * \brief  Music file is invalid. Ensure you're using Tuner to generate file.
             */
            static constexpr int MusicFileInvalid = -1903;
            /**
             * \brief  An invalid orchestra action occurred. Ensure a music file is loaded.
             */
            static constexpr int InvalidOrchestraAction = -1904;
            /**
             * \brief  This music file version is too old. Regenerate file using Tuner.
             */
            static constexpr int MusicFileTooOld = -1905;
            /**
             * \brief  Music interrupted due to one of the instruments being commanded a
             *         different control mode. Press Play to resume music.
             */
            static constexpr int MusicInterrupted = -1906;
            /**
             * \brief  This device doesn't support MusicTone control mode.
             */
            static constexpr int MusicNotSupported = -1907;
            /**
             * \brief  kInvalidInterface
             */
            static constexpr int kInvalidInterface = -2000;
            /**
             * \brief  kInvalidGuid
             */
            static constexpr int kInvalidGuid = -2001;
            /**
             * \brief  kInvalidClass
             */
            static constexpr int kInvalidClass = -2002;
            /**
             * \brief  kInvalidProtocol
             */
            static constexpr int kInvalidProtocol = -2003;
            /**
             * \brief  kInvalidPath
             */
            static constexpr int kInvalidPath = -2004;
            /**
             * \brief  kGeneralWinUsbError
             */
            static constexpr int kGeneralWinUsbError = -2005;
            /**
             * \brief  kFailedSetup
             */
            static constexpr int kFailedSetup = -2006;
            /**
             * \brief  kListenFailed
             */
            static constexpr int kListenFailed = -2007;
            /**
             * \brief  kSendFailed
             */
            static constexpr int kSendFailed = -2008;
            /**
             * \brief  kReceiveFailed
             */
            static constexpr int kReceiveFailed = -2009;
            /**
             * \brief  kInvalidRespFormat
             */
            static constexpr int kInvalidRespFormat = -2010;
            /**
             * \brief  kWinUsbInitFailed
             */
            static constexpr int kWinUsbInitFailed = -2011;
            /**
             * \brief  kWinUsbQueryFailed
             */
            static constexpr int kWinUsbQueryFailed = -2012;
            /**
             * \brief  kWinUsbGeneralError
             */
            static constexpr int kWinUsbGeneralError = -2013;
            /**
             * \brief  kAccessDenied
             */
            static constexpr int kAccessDenied = -2014;
            /**
             * \brief  kFirmwareInvalidResponse
             */
            static constexpr int kFirmwareInvalidResponse = -2015;
            /**
             * \brief  This StatusCode has not been initialized. Make sure the StatusCode is
             *         getting assigned to the return of a method.
             */
            static constexpr int StatusCodeNotInitialized = -10000;
            /**
             * \brief  WarningNotInitialized
             */
            static constexpr int WarningNotInitialized = 10000;
            /**
             * \brief  The timestamp reported by CANivore is at least 10ms older than the
             *         timestamp reported by the system, indicating it's fallen out of sync.
             *         This does not impact the data of this message, only the timing.
             */
            static constexpr int HwTimestampOutOfSync = 10001;
            /**
             * \brief  InvalidNetwork
             */
            static constexpr int InvalidNetwork = -10001;
            /**
             * \brief  MultiSignalNotSupported
             */
            static constexpr int MultiSignalNotSupported = -10002;
            /**
             * \brief  Could not cast from base value to this particular signal's type
             */
            static constexpr int CouldNotCast = -10003;
            /**
             * \brief  Could not find this value when searching for it
             */
            static constexpr int NotFound = -10004;
            /**
             * \brief  This is not supported
             */
            static constexpr int NotSupported = -10005;
            /**
             * \brief  Could not determine context from this device hash
             */
            static constexpr int MissingContext = -10006;
            /**
             * \brief  Model name in license file does not match model name of selected
             *         device.
             */
            static constexpr int ModelMismatch = -10007;
            /**
             * \brief  Serial Number in license file does not match model name of selected
             *         device.
             */
            static constexpr int SerialMismatch = -10008;
            /**
             * \brief  Could not find specified file.
             */
            static constexpr int NoFile = -10009;
            /**
             * \brief  License did not successfully download to Device.
             */
            static constexpr int LicenseDownloadFailed = -10010;
            /**
             * \brief  Self Test report does not have any values, is the firmware up to
             *         date?
             */
            static constexpr int SelfTestIsEmpty = -10011;
            /**
             * \brief  Failed to lookup signal properties.  This can happen if the fimware
             *         is too new and supports signals that older APIs do not support.
             */
            static constexpr int SignalLookupFailed = -10012;
            /**
             * \brief  The current mode of the device is invalid for getting this signal.
             */
            static constexpr int InvalidModeToGetSignal = -10013;
            /**
             * \brief  Device is not licensed. Cannot get any data from it.
             */
            static constexpr int UnlicensedDevice = -10014;
            /**
             * \brief  Size is invalid.
             */
            static constexpr int InvalidSize = -10015;
            /**
             * \brief  InvalidLicenseResponse
             */
            static constexpr int InvalidLicenseResponse = -10016;
            /**
             * \brief  InvalidContext
             */
            static constexpr int InvalidContext = -10017;
            /**
             * \brief  InternalError
             */
            static constexpr int InternalError = -10018;
            /**
             * \brief  TaskIsBusy
             */
            static constexpr int TaskIsBusy = -10019;
            /**
             * \brief  kDeviceResponseIncorrect
             */
            static constexpr int kDeviceResponseIncorrect = -10020;
            /**
             * \brief  kErrorPollingForDevices
             */
            static constexpr int kErrorPollingForDevices = -10021;
            /**
             * \brief  Device firmware could not be retrieved. Check that the device is
             *         running Pro firmware, that the device ID is correct, that the
             *         specified CAN bus is correct, and that the device is powered.
             */
            static constexpr int CouldNotRetrieveProFirmware = -10022;
            /**
             * \brief  Device firmware could not be decoded. Check that the device is
             *         running Pro firmware, that the device ID is correct, that the
             *         specified CAN bus is correct, and that the device is powered.
             */
            static constexpr int CouldNotDecodeDeviceFirmware = -10023;
            /**
             * \brief  The values specified for master are in valid.  Make sure the Device
             *         ID of master are correct.
             */
            static constexpr int InvalidIDToFollow = -10024;

            operator int() const { return this->value; }

            bool operator==(const StatusCode &data) const
            {
                return this->value == data.value;
            }
            bool operator==(int data) const
            {
                return this->value == data;
            }
            bool operator<(const StatusCode &data) const
            {
                return this->value < data.value;
            }
            bool operator<(int data) const
            {
                return this->value < data;
            }
            StatusCode(int val) : value{val} {}
            StatusCode() : value{StatusCode::StatusCodeNotInitialized} {}

            const char *GetName() const
            {
                switch (value)
                {
                case 0: return "OK";
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
                case -10019: return "TaskIsBusy";
                case -10020: return "kDeviceResponseIncorrect";
                case -10021: return "kErrorPollingForDevices";
                case -10022: return "CouldNotRetrieveProFirmware";
                case -10023: return "CouldNotDecodeDeviceFirmware";
                case -10024: return "InvalidIDToFollow";
                default:
                    return "Could not find name";
                }
            }
            const char *GetDescription() const
            {
                switch (value)
                {
                case 0: return "No Error";
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
                case -117: return "Not Implemented, check latest installer.";
                case -118: return "NoDevicesOnBus";
                case -119: return "MoreThanOneFile";
                case -120: return "NodeIsInvalid";
                case -121: return "InvalidDeviceDescriptor";
                case -123: return "CouldNotSendCanFrame";
                case -124: return "NormalModeMsgNotPresent";
                case -125: return "This feature is not supported.";
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
                case 1000: return "CAN Message is stale.";
                case 1006: return "Buffer is full, cannot insert more data.";
                case 1010: return "PulseWidthSensorNotPresent";
                case 1100: return "General Warning Occurred.";
                case 1103: return "Firm Vers could not be retrieved. Use Phoenix Tuner to check ID and firmware(CRF) version.";
                case 1104: return "This feature will be supported in a future update.";
                case 1105: return "The control mode is not valid for this function.";
                case 1106: return "This control mode is not supported yet.  A future release will supported this soon.";
                case 1109: return "Motor Controller must have >= 3.2 firmware for motion profile control mode.";
                case 1110: return "Motor Controller must have >= 3.4 firmware for advanced PID0/PID1 features.";
                case 1200: return "SimDeviceNotFound";
                case 1201: return "SimPhysicsTypeNotSupported";
                case 1202: return "SimDeviceAlreadyExists";
                case -1001: return "Could not transmit CAN Frame.";
                case -1002: return "Incorrect argument passed into function/VI.";
                case -1003: return "CAN frame not received/too-stale.";
                case -1004: return "CAN Transmit timed out.";
                case -1005: return "ArbID is incorrect.";
                case -1006: return "CanOverflowed";
                case -1007: return "Sensor Not Present.";
                case -1008: return "Firmware Too Old.  Use Phoenix Tuner to field upgrade your CTRE CAN device firmware(CRF).  Then restart your robot application to clear this error.";
                case -1009: return "Control Frame Period could not be changed.  Most likely it is not being transmitted.";
                case -1010: return "BufferFailure";
                case -1011: return "Firmware is legacy non-FRC version.  Use Phoenix Tuner to field upgrade your CTRE CAN device firmware(CRF).  Firmware greater than 20.0 required.";
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
                case -10001: return "InvalidNetwork";
                case -10002: return "MultiSignalNotSupported";
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
                case -10019: return "TaskIsBusy";
                case -10020: return "kDeviceResponseIncorrect";
                case -10021: return "kErrorPollingForDevices";
                case -10022: return "Device firmware could not be retrieved. Check that the device is running Pro firmware, that the device ID is correct, that the specified CAN bus is correct, and that the device is powered.";
                case -10023: return "Device firmware could not be decoded. Check that the device is running Pro firmware, that the device ID is correct, that the specified CAN bus is correct, and that the device is powered.";
                case -10024: return "The values specified for master are in valid.  Make sure the Device ID of master are correct.";
                default:
                    return "Could not find description";
                }
            }
            bool IsError() const { return value < 0; }
            bool IsWarning() const { return value > 0; }
            bool IsOK() const { return value == OK; }
        };

    }
}

#else // This is straight-C, so just create a typedef enum to use

/**
 * \brief Typedef enum of the StatusCode for use in C projects
 */
typedef enum _StatusCode_t
{
    /**
     * \brief  No Error
     */
    OK = 0,
    /**
     * \brief  InvalidDeviceSpec
     */
    InvalidDeviceSpec = -101,
    /**
     * \brief  EcuIsNotPresent
     */
    EcuIsNotPresent = -102,
    /**
     * \brief  CouldNotEnterBl
     */
    CouldNotEnterBl = -103,
    /**
     * \brief  CouldNotConfirmBl
     */
    CouldNotConfirmBl = -104,
    /**
     * \brief  CouldNotErase
     */
    CouldNotErase = -105,
    /**
     * \brief  CouldNotSendFlash
     */
    CouldNotSendFlash = -106,
    /**
     * \brief  CouldNotValidate
     */
    CouldNotValidate = -107,
    /**
     * \brief  CouldNotRunApp
     */
    CouldNotRunApp = -108,
    /**
     * \brief  CouldNotReqSetId
     */
    CouldNotReqSetId = -109,
    /**
     * \brief  CouldNotConfirmId
     */
    CouldNotConfirmId = -110,
    /**
     * \brief  FlashWasGood
     */
    FlashWasGood = -111,
    /**
     * \brief  AppTooOld
     */
    AppTooOld = -112,
    /**
     * \brief  CouldNotReqSetDesc
     */
    CouldNotReqSetDesc = -113,
    /**
     * \brief  CompileSzIsWrong
     */
    CompileSzIsWrong = -114,
    /**
     * \brief  GadgeteerDeviceNoSetId
     */
    GadgeteerDeviceNoSetId = -115,
    /**
     * \brief  InvalidTask
     */
    InvalidTask = -116,
    /**
     * \brief  Not Implemented, check latest installer.
     */
    NotImplemented = -117,
    /**
     * \brief  NoDevicesOnBus
     */
    NoDevicesOnBus = -118,
    /**
     * \brief  MoreThanOneFile
     */
    MoreThanOneFile = -119,
    /**
     * \brief  NodeIsInvalid
     */
    NodeIsInvalid = -120,
    /**
     * \brief  InvalidDeviceDescriptor
     */
    InvalidDeviceDescriptor = -121,
    /**
     * \brief  CouldNotSendCanFrame
     */
    CouldNotSendCanFrame = -123,
    /**
     * \brief  NormalModeMsgNotPresent
     */
    NormalModeMsgNotPresent = -124,
    /**
     * \brief  This feature is not supported.
     */
    FeatureNotSupported = -125,
    /**
     * \brief  NotUpdating
     */
    NotUpdating = -126,
    /**
     * \brief  CorruptedPOST
     */
    CorruptedPOST = -127,
    /**
     * \brief  NoConfigs
     */
    NoConfigs = -128,
    /**
     * \brief  ConfigFailed
     */
    ConfigFailed = -129,
    /**
     * \brief  CouldNotReqFactoryDefault
     */
    CouldNotReqFactoryDefault = -130,
    /**
     * \brief  CustomNameNotSupported
     */
    CustomNameNotSupported = -131,
    /**
     * \brief  ConfigReadWriteMismatch
     */
    ConfigReadWriteMismatch = -132,
    /**
     * \brief  CouldNotReqSetConfigs
     */
    CouldNotReqSetConfigs = -133,
    /**
     * \brief  InsufficientSz
     */
    InsufficientSz = -134,
    /**
     * \brief  InvalidModel
     */
    InvalidModel = -135,
    /**
     * \brief  CouldNotReqDevInfo
     */
    CouldNotReqDevInfo = -140,
    /**
     * \brief  NoControls
     */
    NoControls = -141,
    /**
     * \brief  DeviceIsNull
     */
    DeviceIsNull = -142,
    /**
     * \brief  DeviceDidNotRespondToDiagReq
     */
    DeviceDidNotRespondToDiagReq = -143,
    /**
     * \brief  OnlySupportedInTunerX
     */
    OnlySupportedInTunerX = -144,
    /**
     * \brief  CanivCliError
     */
    CanivCliError = -145,
    /**
     * \brief  InvalidCrfBadHeader
     */
    InvalidCrfBadHeader = -200,
    /**
     * \brief  InvalidCrfFileSzInvald
     */
    InvalidCrfFileSzInvald = -201,
    /**
     * \brief  InvalidCrfWrongProduct
     */
    InvalidCrfWrongProduct = -202,
    /**
     * \brief  InvalidCrfNoSects
     */
    InvalidCrfNoSects = -203,
    /**
     * \brief  InvalidCrfBadSectHeader
     */
    InvalidCrfBadSectHeader = -204,
    /**
     * \brief  InvalidCrfBadSectSize
     */
    InvalidCrfBadSectSize = -205,
    /**
     * \brief  NoCrfFile
     */
    NoCrfFile = -206,
    /**
     * \brief  CouldNotFindDynamicId
     */
    CouldNotFindDynamicId = -300,
    /**
     * \brief  DidNotGetDhcp
     */
    DidNotGetDhcp = -301,
    /**
     * \brief  DidNotGetFullDhcp
     */
    DidNotGetFullDhcp = -302,
    /**
     * \brief  InvalidLicenseResp
     */
    InvalidLicenseResp = -350,
    /**
     * \brief  InvalidCanivCache
     */
    InvalidCanivCache = -351,
    /**
     * \brief  CannotOpenSerialPort
     */
    CannotOpenSerialPort = -500,
    /**
     * \brief  CannotWriteSerialPort
     */
    CannotWriteSerialPort = -501,
    /**
     * \brief  CannotReadSerialPort
     */
    CannotReadSerialPort = -502,
    /**
     * \brief  CannotSerialToDevice
     */
    CannotSerialToDevice = -503,
    /**
     * \brief  NoSerialControlFrameResp
     */
    NoSerialControlFrameResp = -504,
    /**
     * \brief  CannotOpenUdpPort
     */
    CannotOpenUdpPort = -600,
    /**
     * \brief  CannotWriteUdpPort
     */
    CannotWriteUdpPort = -601,
    /**
     * \brief  CannotReadUdpPort
     */
    CannotReadUdpPort = -602,
    /**
     * \brief  CannotUdpToDevice
     */
    CannotUdpToDevice = -603,
    /**
     * \brief  NoUdpControlFrameResp
     */
    NoUdpControlFrameResp = -604,
    /**
     * \brief  TimeoutIso15Response
     */
    TimeoutIso15Response = -605,
    /**
     * \brief  InvalidJson
     */
    InvalidJson = -700,
    /**
     * \brief  AppIsTerminating
     */
    AppIsTerminating = -800,
    /**
     * \brief  CAN Message is stale.
     */
    CanMessageStale = 1000,
    /**
     * \brief  Buffer is full, cannot insert more data.
     */
    BufferFull = 1006,
    /**
     * \brief  PulseWidthSensorNotPresent
     */
    PulseWidthSensorNotPresent = 1010,
    /**
     * \brief  General Warning Occurred.
     */
    GeneralWarning = 1100,
    /**
     * \brief  Firm Vers could not be retrieved. Use Phoenix Tuner to check ID and
     *         firmware(CRF) version.
     */
    FirmVersionCouldNotBeRetrieved = 1103,
    /**
     * \brief  This feature will be supported in a future update.
     */
    FeaturesNotAvailableYet = 1104,
    /**
     * \brief  The control mode is not valid for this function.
     */
    ControlModeNotValid = 1105,
    /**
     * \brief  This control mode is not supported yet.  A future release will
     *         supported this soon.
     */
    ControlModeNotSupportedYet = 1106,
    /**
     * \brief  Motor Controller must have &gt;= 3.2 firmware for motion profile control
     *         mode.
     */
    MotProfFirmThreshold = 1109,
    /**
     * \brief  Motor Controller must have &gt;= 3.4 firmware for advanced PID0/PID1
     *         features.
     */
    MotProfFirmThreshold2 = 1110,
    /**
     * \brief  SimDeviceNotFound
     */
    SimDeviceNotFound = 1200,
    /**
     * \brief  SimPhysicsTypeNotSupported
     */
    SimPhysicsTypeNotSupported = 1201,
    /**
     * \brief  SimDeviceAlreadyExists
     */
    SimDeviceAlreadyExists = 1202,
    /**
     * \brief  Could not transmit CAN Frame.
     */
    TxFailed = -1001,
    /**
     * \brief  Incorrect argument passed into function/VI.
     */
    InvalidParamValue = -1002,
    /**
     * \brief  CAN frame not received/too-stale.
     */
    RxTimeout = -1003,
    /**
     * \brief  CAN Transmit timed out.
     */
    TxTimeout = -1004,
    /**
     * \brief  ArbID is incorrect.
     */
    UnexpectedArbId = -1005,
    /**
     * \brief  CanOverflowed
     */
    CanOverflowed = -1006,
    /**
     * \brief  Sensor Not Present.
     */
    SensorNotPresent = -1007,
    /**
     * \brief  Firmware Too Old.  Use Phoenix Tuner to field upgrade your CTRE CAN
     *         device firmware(CRF).  Then restart your robot application to clear
     *         this error.
     */
    FirmwareTooOld = -1008,
    /**
     * \brief  Control Frame Period could not be changed.  Most likely it is not
     *         being transmitted.
     */
    CouldNotChangePeriod = -1009,
    /**
     * \brief  BufferFailure
     */
    BufferFailure = -1010,
    /**
     * \brief  Firmware is legacy non-FRC version.  Use Phoenix Tuner to field
     *         upgrade your CTRE CAN device firmware(CRF).  Firmware greater than
     *         20.0 required.
     */
    FirmwareNonFRC = -1011,
    /**
     * \brief  General Error Occurred.
     */
    GeneralError = -1100,
    /**
     * \brief  No new response to update signal.
     */
    SigNotUpdated = -1200,
    /**
     * \brief  NotAllPIDValuesUpdated
     */
    NotAllPIDValuesUpdated = -1201,
    /**
     * \brief  GEN_PORT_ERROR
     */
    GEN_PORT_ERROR = -1300,
    /**
     * \brief  PORT_MODULE_TYPE_MISMATCH
     */
    PORT_MODULE_TYPE_MISMATCH = -1301,
    /**
     * \brief  GEN_MODULE_ERROR
     */
    GEN_MODULE_ERROR = -1400,
    /**
     * \brief  MODULE_NOT_INIT_SET_ERROR
     */
    MODULE_NOT_INIT_SET_ERROR = -1401,
    /**
     * \brief  MODULE_NOT_INIT_GET_ERROR
     */
    MODULE_NOT_INIT_GET_ERROR = -1402,
    /**
     * \brief  Wheel Radius is too small, cannot get distance traveled.
     */
    WheelRadiusTooSmall = -1500,
    /**
     * \brief  Ticks per revolution is 0, cannot get heading.
     */
    TicksPerRevZero = -1501,
    /**
     * \brief  Distance between wheels is too small, cannot get heading.
     */
    DistanceBetweenWheelsTooSmall = -1502,
    /**
     * \brief  GainsAreNotSet
     */
    GainsAreNotSet = -1503,
    /**
     * \brief  Use RemoteLimitSwitchSource instead of LimitSwitchSource.
     */
    WrongRemoteLimitSwitchSource = -1504,
    /**
     * \brief  Motor Controller Voltage Compensation should not be used with
     *         setVoltage().  This causes compensation to happen twice.  Disable
     *         Voltage Compensation by calling enableVoltageCompensation(false) in
     *         order to use setVoltage().
     */
    DoubleVoltageCompensatingWPI = -1505,
    /**
     * \brief  CANdleAnimSlotOutOfBounds
     */
    CANdleAnimSlotOutOfBounds = -1506,
    /**
     * \brief  IncompatibleMode
     */
    IncompatibleMode = -1600,
    /**
     * \brief  Handle passed into function is incorrect.
     */
    InvalidHandle = -1601,
    /**
     * \brief  Features requires newer firmware version.
     */
    FeatureRequiresHigherFirm = -1700,
    /**
     * \brief  Config factory default features require firmware &gt;=3.10.
     */
    ConfigFactoryDefaultRequiresHigherFirm = -1702,
    /**
     * \brief  Config Motion S Curve Strength features require firmware &gt;=4.16.
     */
    ConfigMotionSCurveRequiresHigherFirm = -1703,
    /**
     * \brief  Talon FX(Falcon 500) Firmware Too Old.  Use Phoenix Tuner to field
     *         upgrade your CTRE CAN device firmware(CRF) to &gt;=20.3. Then restart
     *         your robot application to clear this error.
     */
    TalonFXFirmwarePreVBatDetect = -1704,
    /**
     * \brief  CANdleAnimationsRequireHigherFirm
     */
    CANdleAnimationsRequireHigherFirm = -1705,
    /**
     * \brief  LibraryCouldNotBeLoaded
     */
    LibraryCouldNotBeLoaded = -1800,
    /**
     * \brief  MissingRoutineInLibrary
     */
    MissingRoutineInLibrary = -1801,
    /**
     * \brief  ResourceNotAvailable
     */
    ResourceNotAvailable = -1802,
    /**
     * \brief  Could not find music file specified, try specifying an absolute path.
     */
    MusicFileNotFound = -1900,
    /**
     * \brief  Music file size is incorrect, could not parse correctly. Ensure
     *         you're using Tuner to generate file.
     */
    MusicFileWrongSize = -1901,
    /**
     * \brief  Music file version is too new, update Phoenix to utilize this file.
     */
    MusicFileTooNew = -1902,
    /**
     * \brief  Music file is invalid. Ensure you're using Tuner to generate file.
     */
    MusicFileInvalid = -1903,
    /**
     * \brief  An invalid orchestra action occurred. Ensure a music file is loaded.
     */
    InvalidOrchestraAction = -1904,
    /**
     * \brief  This music file version is too old. Regenerate file using Tuner.
     */
    MusicFileTooOld = -1905,
    /**
     * \brief  Music interrupted due to one of the instruments being commanded a
     *         different control mode. Press Play to resume music.
     */
    MusicInterrupted = -1906,
    /**
     * \brief  This device doesn't support MusicTone control mode.
     */
    MusicNotSupported = -1907,
    /**
     * \brief  kInvalidInterface
     */
    kInvalidInterface = -2000,
    /**
     * \brief  kInvalidGuid
     */
    kInvalidGuid = -2001,
    /**
     * \brief  kInvalidClass
     */
    kInvalidClass = -2002,
    /**
     * \brief  kInvalidProtocol
     */
    kInvalidProtocol = -2003,
    /**
     * \brief  kInvalidPath
     */
    kInvalidPath = -2004,
    /**
     * \brief  kGeneralWinUsbError
     */
    kGeneralWinUsbError = -2005,
    /**
     * \brief  kFailedSetup
     */
    kFailedSetup = -2006,
    /**
     * \brief  kListenFailed
     */
    kListenFailed = -2007,
    /**
     * \brief  kSendFailed
     */
    kSendFailed = -2008,
    /**
     * \brief  kReceiveFailed
     */
    kReceiveFailed = -2009,
    /**
     * \brief  kInvalidRespFormat
     */
    kInvalidRespFormat = -2010,
    /**
     * \brief  kWinUsbInitFailed
     */
    kWinUsbInitFailed = -2011,
    /**
     * \brief  kWinUsbQueryFailed
     */
    kWinUsbQueryFailed = -2012,
    /**
     * \brief  kWinUsbGeneralError
     */
    kWinUsbGeneralError = -2013,
    /**
     * \brief  kAccessDenied
     */
    kAccessDenied = -2014,
    /**
     * \brief  kFirmwareInvalidResponse
     */
    kFirmwareInvalidResponse = -2015,
    /**
     * \brief  This StatusCode has not been initialized. Make sure the StatusCode is
     *         getting assigned to the return of a method.
     */
    StatusCodeNotInitialized = -10000,
    /**
     * \brief  WarningNotInitialized
     */
    WarningNotInitialized = 10000,
    /**
     * \brief  The timestamp reported by CANivore is at least 10ms older than the
     *         timestamp reported by the system, indicating it's fallen out of sync.
     *         This does not impact the data of this message, only the timing.
     */
    HwTimestampOutOfSync = 10001,
    /**
     * \brief  InvalidNetwork
     */
    InvalidNetwork = -10001,
    /**
     * \brief  MultiSignalNotSupported
     */
    MultiSignalNotSupported = -10002,
    /**
     * \brief  Could not cast from base value to this particular signal's type
     */
    CouldNotCast = -10003,
    /**
     * \brief  Could not find this value when searching for it
     */
    NotFound = -10004,
    /**
     * \brief  This is not supported
     */
    NotSupported = -10005,
    /**
     * \brief  Could not determine context from this device hash
     */
    MissingContext = -10006,
    /**
     * \brief  Model name in license file does not match model name of selected
     *         device.
     */
    ModelMismatch = -10007,
    /**
     * \brief  Serial Number in license file does not match model name of selected
     *         device.
     */
    SerialMismatch = -10008,
    /**
     * \brief  Could not find specified file.
     */
    NoFile = -10009,
    /**
     * \brief  License did not successfully download to Device.
     */
    LicenseDownloadFailed = -10010,
    /**
     * \brief  Self Test report does not have any values, is the firmware up to
     *         date?
     */
    SelfTestIsEmpty = -10011,
    /**
     * \brief  Failed to lookup signal properties.  This can happen if the fimware
     *         is too new and supports signals that older APIs do not support.
     */
    SignalLookupFailed = -10012,
    /**
     * \brief  The current mode of the device is invalid for getting this signal.
     */
    InvalidModeToGetSignal = -10013,
    /**
     * \brief  Device is not licensed. Cannot get any data from it.
     */
    UnlicensedDevice = -10014,
    /**
     * \brief  Size is invalid.
     */
    InvalidSize = -10015,
    /**
     * \brief  InvalidLicenseResponse
     */
    InvalidLicenseResponse = -10016,
    /**
     * \brief  InvalidContext
     */
    InvalidContext = -10017,
    /**
     * \brief  InternalError
     */
    InternalError = -10018,
    /**
     * \brief  TaskIsBusy
     */
    TaskIsBusy = -10019,
    /**
     * \brief  kDeviceResponseIncorrect
     */
    kDeviceResponseIncorrect = -10020,
    /**
     * \brief  kErrorPollingForDevices
     */
    kErrorPollingForDevices = -10021,
    /**
     * \brief  Device firmware could not be retrieved. Check that the device is
     *         running Pro firmware, that the device ID is correct, that the
     *         specified CAN bus is correct, and that the device is powered.
     */
    CouldNotRetrieveProFirmware = -10022,
    /**
     * \brief  Device firmware could not be decoded. Check that the device is
     *         running Pro firmware, that the device ID is correct, that the
     *         specified CAN bus is correct, and that the device is powered.
     */
    CouldNotDecodeDeviceFirmware = -10023,
    /**
     * \brief  The values specified for master are in valid.  Make sure the Device
     *         ID of master are correct.
     */
    InvalidIDToFollow = -10024,
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
