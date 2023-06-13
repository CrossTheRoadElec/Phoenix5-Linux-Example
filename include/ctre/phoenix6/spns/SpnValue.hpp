/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#include <string>

namespace ctre
{
    namespace phoenix6
    {
        namespace spns
        {
            /**
             * \brief Class that holds all the SPN values used in Phoenix Pro devices.
             */
            class SpnValue
            {
            public:
                int value;

                static constexpr int TalonFX_System_State = 612;
                static constexpr int Startup_ResetFlags = 633;
                static constexpr int Version_Major = 731;
                static constexpr int Version_Minor = 732;
                static constexpr int Version_Bugfix = 733;
                static constexpr int Version_Build = 734;
                static constexpr int Version_Full = 735;
                static constexpr int Licensing_IsProLicensed = 748;
                static constexpr int CustomParam0 = 816;
                static constexpr int CustomParam1 = 817;
                static constexpr int CANcoder_SensorDirection = 821;
                static constexpr int FrcLock = 823;
                static constexpr int RobotEnabled = 824;
                static constexpr int LED1_OnColor = 826;
                static constexpr int LED1_OffColor = 827;
                static constexpr int LED2_OnColor = 828;
                static constexpr int LED2_OffColor = 829;
                static constexpr int AllFaults = 835;
                static constexpr int AllStickyFaults = 836;
                static constexpr int Pigeon2UseCompass = 910;
                static constexpr int Pigeon2DisableTemperatureCompensation = 945;
                static constexpr int Pigeon2DisableNoMotionCalibration = 947;
                static constexpr int Pigeon2MountPoseYaw = 952;
                static constexpr int Pigeon2MountPosePitch = 953;
                static constexpr int Pigeon2MountPoseRoll = 954;
                static constexpr int Pigeon2GyroScalarX = 958;
                static constexpr int Pigeon2GyroScalarY = 959;
                static constexpr int Pigeon2GyroScalarZ = 960;
                static constexpr int Pigeon2Yaw = 967;
                static constexpr int Pigeon2Pitch = 968;
                static constexpr int Pigeon2Roll = 969;
                static constexpr int Pigeon2QuatW = 970;
                static constexpr int Pigeon2QuatX = 971;
                static constexpr int Pigeon2QuatY = 972;
                static constexpr int Pigeon2QuatZ = 973;
                static constexpr int Pigeon2GravityVectorX = 974;
                static constexpr int Pigeon2GravityVectorY = 975;
                static constexpr int Pigeon2GravityVectorZ = 976;
                static constexpr int Pigeon2Temperature = 977;
                static constexpr int Pigeon2NoMotionCalEnabled = 978;
                static constexpr int Pigeon2NoMotionCount = 979;
                static constexpr int Pigeon2TempCompDisabled = 980;
                static constexpr int Pigeon2UpTime = 981;
                static constexpr int Pigeon2AccumGyroX = 982;
                static constexpr int Pigeon2AccumGyroY = 983;
                static constexpr int Pigeon2AccumGyroZ = 984;
                static constexpr int Pigeon2AngularVelocityX = 985;
                static constexpr int Pigeon2AngularVelocityY = 986;
                static constexpr int Pigeon2AngularVelocityZ = 987;
                static constexpr int Pigeon2AccelerationX = 988;
                static constexpr int Pigeon2AccelerationY = 989;
                static constexpr int Pigeon2AccelerationZ = 990;
                static constexpr int Pigeon2_SupplyVoltage = 993;
                static constexpr int Pigeon2MagneticFieldX = 997;
                static constexpr int Pigeon2MagneticFieldY = 998;
                static constexpr int Pigeon2MagneticFieldZ = 999;
                static constexpr int Pigeon2RawMagneticFieldX = 1000;
                static constexpr int Pigeon2RawMagneticFieldY = 1001;
                static constexpr int Pigeon2RawMagneticFieldZ = 1002;
                static constexpr int CANCoder_MagnetOffset = 1003;
                static constexpr int CANcoder_AbsoluteSensorRange = 1004;
                static constexpr int DeviceEnabled = 1035;
                static constexpr int ForwardLimit = 1359;
                static constexpr int ReverseLimit = 1360;
                static constexpr int PRO_MotorOutput_RotorPolarity = 1361;
                static constexpr int PRO_MotorOutput_DutyCycle = 1362;
                static constexpr int PRO_MotorOutput_TorqueCurrent = 1364;
                static constexpr int PRO_SupplyAndTemp_StatorCurrent = 1365;
                static constexpr int PRO_SupplyAndTemp_SupplyCurrent = 1366;
                static constexpr int PRO_SupplyAndTemp_SupplyVoltage = 1367;
                static constexpr int PRO_SupplyAndTemp_DeviceTemp = 1368;
                static constexpr int PRO_SupplyAndTemp_ProcessorTemp = 1369;
                static constexpr int PRO_RotorPosAndVel_Velocity = 1371;
                static constexpr int PRO_RotorPosAndVel_Position = 1372;
                static constexpr int PRO_PosAndVel_Velocity = 1375;
                static constexpr int PRO_PosAndVel_Position = 1376;
                static constexpr int PRO_PIDStateEnables_IntegratedAccum_DC = 1377;
                static constexpr int PRO_PIDStateEnables_IntegratedAccum_V = 1378;
                static constexpr int PRO_PIDStateEnables_IntegratedAccum_A = 1379;
                static constexpr int PRO_PIDStateEnables_FeedForward_DC = 1380;
                static constexpr int PRO_PIDStateEnables_FeedForward_V = 1381;
                static constexpr int PRO_PIDStateEnables_FeedForward_A = 1382;
                static constexpr int TalonFX_ControlMode = 1383;
                static constexpr int PRO_PIDStateEnables_IsMotionMagicRunning = 1385;
                static constexpr int PRO_PIDStateEnables_DeviceEnable = 1387;
                static constexpr int PRO_PIDRefPIDErr_PIDRef_Position = 1389;
                static constexpr int PRO_PIDRefPIDErr_PIDRef_Velocity = 1390;
                static constexpr int PRO_PIDRefPIDErr_PIDErr_Position = 1391;
                static constexpr int PRO_PIDRefPIDErr_PIDErr_Velocity = 1392;
                static constexpr int PRO_PIDOutput_ProportionalOutput_DC = 1394;
                static constexpr int PRO_PIDOutput_ProportionalOutput_V = 1395;
                static constexpr int PRO_PIDOutput_ProportionalOutput_A = 1396;
                static constexpr int PRO_PIDOutput_DerivativeOutput_DC = 1397;
                static constexpr int PRO_PIDOutput_DerivativeOutput_V = 1398;
                static constexpr int PRO_PIDOutput_DerivativeOutput_A = 1399;
                static constexpr int PRO_PIDOutput_Output_DC = 1400;
                static constexpr int PRO_PIDOutput_Output_V = 1401;
                static constexpr int PRO_PIDOutput_Output_A = 1402;
                static constexpr int PRO_PIDOutput_Slot = 1403;
                static constexpr int PRO_PIDRefSlopeECUTime_ReferenceSlope_Position = 1404;
                static constexpr int PRO_PIDRefSlopeECUTime_ReferenceSlope_Velocity = 1405;
                static constexpr int Slot0_kP = 1407;
                static constexpr int Slot0_kI = 1408;
                static constexpr int Slot0_kD = 1409;
                static constexpr int Slot0_kV = 1410;
                static constexpr int Slot0_kS = 1411;
                static constexpr int Slot1_kP = 1412;
                static constexpr int Slot1_kI = 1413;
                static constexpr int Slot1_kD = 1414;
                static constexpr int Slot1_kV = 1415;
                static constexpr int Slot1_kS = 1416;
                static constexpr int Slot2_kP = 1417;
                static constexpr int Slot2_kI = 1418;
                static constexpr int Slot2_kD = 1419;
                static constexpr int Slot2_kV = 1420;
                static constexpr int Slot2_kS = 1421;
                static constexpr int Config_Inverted = 1422;
                static constexpr int Config_SupplyVLowpassTau = 1423;
                static constexpr int Config_BeepOnBoot = 1424;
                static constexpr int Config_NeutralMode = 1425;
                static constexpr int Config_DutyCycleNeutralDB = 1426;
                static constexpr int Config_StatorCurrentLimit = 1427;
                static constexpr int Config_StatorCurrLimitEn = 1428;
                static constexpr int Config_SupplyCurrentLimit = 1429;
                static constexpr int Config_SupplyCurrLimitEn = 1430;
                static constexpr int Config_PeakForwardDC = 1431;
                static constexpr int Config_PeakReverseDC = 1432;
                static constexpr int Config_PeakForwardV = 1433;
                static constexpr int Config_PeakReverseV = 1434;
                static constexpr int Config_PeakForTorqCurr = 1435;
                static constexpr int Config_PeakRevTorqCurr = 1436;
                static constexpr int Config_TorqueNeutralDB = 1437;
                static constexpr int Config_FeedbackRotorOffset = 1438;
                static constexpr int Config_SensorToMechanismRatio = 1439;
                static constexpr int Config_RotorToSensorRatio = 1440;
                static constexpr int Config_FeedbackSensorSource = 1441;
                static constexpr int Config_FeedbackRemoteSensorID = 1442;
                static constexpr int Config_DutyCycleOpenLoopRampPeriod = 1443;
                static constexpr int Config_VoltageOpenLoopRampPeriod = 1444;
                static constexpr int Config_TorqueOpenLoopRampPeriod = 1445;
                static constexpr int Config_DutyCycleClosedLoopRampPeriod = 1446;
                static constexpr int Config_VoltageClosedLoopRampPeriod = 1447;
                static constexpr int Config_TorqueClosedLoopRampPeriod = 1448;
                static constexpr int Config_ForwardLimitType = 1449;
                static constexpr int Config_ForwardLimitAutosetPosEnable = 1450;
                static constexpr int Config_ForwardLimitAutosetPosValue = 1451;
                static constexpr int Config_ForwardLimitEnable = 1452;
                static constexpr int Config_ForwardLimitSource = 1453;
                static constexpr int Config_ForwardLimitRemoteSensorID = 1454;
                static constexpr int Config_ReverseLimitType = 1455;
                static constexpr int Config_ReverseLimitAutosetPosEnable = 1456;
                static constexpr int Config_ReverseLimitAutosetPosValue = 1457;
                static constexpr int Config_ReverseLimitEnable = 1458;
                static constexpr int Config_ReverseLimitSource = 1459;
                static constexpr int Config_ReverseLimitRemoteSensorID = 1460;
                static constexpr int Config_ForwardSoftLimitEnable = 1461;
                static constexpr int Config_ReverseSoftLimitEnable = 1462;
                static constexpr int Config_ForwardSoftLimitThreshold = 1463;
                static constexpr int Config_ReverseSoftLimitThreshold = 1464;
                static constexpr int Config_MotionMagicCruiseVelocity = 1465;
                static constexpr int Config_MotionMagicAcceleration = 1466;
                static constexpr int Config_MotionMagicJerk = 1467;
                static constexpr int CANcoder_Velocity = 1468;
                static constexpr int CANcoder_Position = 1469;
                static constexpr int CANcoder_AbsPosition = 1470;
                static constexpr int CANCoder_RawVel = 1471;
                static constexpr int CANCoder_RawPos = 1472;
                static constexpr int CANCoder_SupplyVoltage = 1473;
                static constexpr int CANcoder_MagHealth = 1474;
                static constexpr int PRO_MotorOutput_BridgeType_Public = 1477;
                static constexpr int Config_ContinuousWrap = 1499;
                static constexpr int Config_SupplyCurrThres = 1505;
                static constexpr int Config_SupplyTimeThres = 1506;
                static constexpr int Fault_Hardware = 10001;
                static constexpr int StickyFault_Hardware = 10002;
                static constexpr int Fault_ProcTemp = 10003;
                static constexpr int StickyFault_ProcTemp = 10004;
                static constexpr int Fault_DeviceTemp = 10005;
                static constexpr int StickyFault_DeviceTemp = 10006;
                static constexpr int Fault_Undervoltage = 10007;
                static constexpr int StickyFault_Undervoltage = 10008;
                static constexpr int Fault_BootDuringEnable = 10009;
                static constexpr int StickyFault_BootDuringEnable = 10010;
                static constexpr int Fault_UnlicensedFeatureInUse = 10011;
                static constexpr int StickyFault_UnlicensedFeatureInUse = 10012;
                static constexpr int Fault_PIGEON2_BootupAccel = 10013;
                static constexpr int StickyFault_PIGEON2_BootupAccel = 10014;
                static constexpr int Fault_PIGEON2_BootupGyros = 10015;
                static constexpr int StickyFault_PIGEON2_BootupGyros = 10016;
                static constexpr int Fault_PIGEON2_BootupMagne = 10017;
                static constexpr int StickyFault_PIGEON2_BootupMagne = 10018;
                static constexpr int Fault_PIGEON2_BootIntoMotion = 10019;
                static constexpr int StickyFault_PIGEON2_BootIntoMotion = 10020;
                static constexpr int Fault_PIGEON2_DataAcquiredLate = 10021;
                static constexpr int StickyFault_PIGEON2_DataAcquiredLate = 10022;
                static constexpr int Fault_PIGEON2_LoopTimeSlow = 10023;
                static constexpr int StickyFault_PIGEON2_LoopTimeSlow = 10024;
                static constexpr int Fault_PIGEON2_SaturatedMagne = 10025;
                static constexpr int StickyFault_PIGEON2_SaturatedMagne = 10026;
                static constexpr int Fault_PIGEON2_SaturatedAccel = 10027;
                static constexpr int StickyFault_PIGEON2_SaturatedAccel = 10028;
                static constexpr int Fault_PIGEON2_SaturatedGyros = 10029;
                static constexpr int StickyFault_PIGEON2_SaturatedGyros = 10030;
                static constexpr int Fault_CANCODER_BadMagnet = 10031;
                static constexpr int StickyFault_CANCODER_BadMagnet = 10032;
                static constexpr int Fault_TALONFX_OverSupplyV = 10033;
                static constexpr int StickyFault_TALONFX_OverSupplyV = 10034;
                static constexpr int Fault_TALONFX_UnstableSupplyV = 10035;
                static constexpr int StickyFault_TALONFX_UnstableSupplyV = 10036;
                static constexpr int Fault_TALONFX_ReverseHardLimit = 10037;
                static constexpr int StickyFault_TALONFX_ReverseHardLimit = 10038;
                static constexpr int Fault_TALONFX_ForwardHardLimit = 10039;
                static constexpr int StickyFault_TALONFX_ForwardHardLimit = 10040;
                static constexpr int Fault_TALONFX_ReverseSoftLimit = 10041;
                static constexpr int StickyFault_TALONFX_ReverseSoftLimit = 10042;
                static constexpr int Fault_TALONFX_ForwardSoftLimit = 10043;
                static constexpr int StickyFault_TALONFX_ForwardSoftLimit = 10044;
                static constexpr int Fault_TALONFX_MissingRemoteSensor = 10049;
                static constexpr int StickyFault_TALONFX_MissingRemoteSensor = 10050;
                static constexpr int Fault_TALONFX_FusedSensorOutOfSync = 10051;
                static constexpr int StickyFault_TALONFX_FusedSensorOutOfSync = 10052;
                static constexpr int Fault_TALONFX_StatorCurrLimit = 10053;
                static constexpr int StickyFault_TALONFX_StatorCurrLimit = 10054;
                static constexpr int Fault_TALONFX_SupplyCurrLimit = 10055;
                static constexpr int StickyFault_TALONFX_SupplyCurrLimit = 10056;
                static constexpr int Fault_TALONFX_UsingFusedCCWhileUnlicensed = 10057;
                static constexpr int StickyFault_TALONFX_UsingFusedCCWhileUnlicensed = 10058;

                /**
                 * \brief Gets the string representation of this enum
                 *
                 * \returns String representation of this enum
                 */
                std::string ToString() const
                {
                    switch (value)
                    {
                    case SpnValue::TalonFX_System_State: return "TalonFX_System_State";
                    case SpnValue::Startup_ResetFlags: return "Startup_ResetFlags";
                    case SpnValue::Version_Major: return "Version_Major";
                    case SpnValue::Version_Minor: return "Version_Minor";
                    case SpnValue::Version_Bugfix: return "Version_Bugfix";
                    case SpnValue::Version_Build: return "Version_Build";
                    case SpnValue::Version_Full: return "Version_Full";
                    case SpnValue::Licensing_IsProLicensed: return "Licensing_IsProLicensed";
                    case SpnValue::CustomParam0: return "CustomParam0";
                    case SpnValue::CustomParam1: return "CustomParam1";
                    case SpnValue::CANcoder_SensorDirection: return "CANcoder_SensorDirection";
                    case SpnValue::FrcLock: return "FrcLock";
                    case SpnValue::RobotEnabled: return "RobotEnabled";
                    case SpnValue::LED1_OnColor: return "LED1_OnColor";
                    case SpnValue::LED1_OffColor: return "LED1_OffColor";
                    case SpnValue::LED2_OnColor: return "LED2_OnColor";
                    case SpnValue::LED2_OffColor: return "LED2_OffColor";
                    case SpnValue::AllFaults: return "AllFaults";
                    case SpnValue::AllStickyFaults: return "AllStickyFaults";
                    case SpnValue::Pigeon2UseCompass: return "Pigeon2UseCompass";
                    case SpnValue::Pigeon2DisableTemperatureCompensation: return "Pigeon2DisableTemperatureCompensation";
                    case SpnValue::Pigeon2DisableNoMotionCalibration: return "Pigeon2DisableNoMotionCalibration";
                    case SpnValue::Pigeon2MountPoseYaw: return "Pigeon2MountPoseYaw";
                    case SpnValue::Pigeon2MountPosePitch: return "Pigeon2MountPosePitch";
                    case SpnValue::Pigeon2MountPoseRoll: return "Pigeon2MountPoseRoll";
                    case SpnValue::Pigeon2GyroScalarX: return "Pigeon2GyroScalarX";
                    case SpnValue::Pigeon2GyroScalarY: return "Pigeon2GyroScalarY";
                    case SpnValue::Pigeon2GyroScalarZ: return "Pigeon2GyroScalarZ";
                    case SpnValue::Pigeon2Yaw: return "Pigeon2Yaw";
                    case SpnValue::Pigeon2Pitch: return "Pigeon2Pitch";
                    case SpnValue::Pigeon2Roll: return "Pigeon2Roll";
                    case SpnValue::Pigeon2QuatW: return "Pigeon2QuatW";
                    case SpnValue::Pigeon2QuatX: return "Pigeon2QuatX";
                    case SpnValue::Pigeon2QuatY: return "Pigeon2QuatY";
                    case SpnValue::Pigeon2QuatZ: return "Pigeon2QuatZ";
                    case SpnValue::Pigeon2GravityVectorX: return "Pigeon2GravityVectorX";
                    case SpnValue::Pigeon2GravityVectorY: return "Pigeon2GravityVectorY";
                    case SpnValue::Pigeon2GravityVectorZ: return "Pigeon2GravityVectorZ";
                    case SpnValue::Pigeon2Temperature: return "Pigeon2Temperature";
                    case SpnValue::Pigeon2NoMotionCalEnabled: return "Pigeon2NoMotionCalEnabled";
                    case SpnValue::Pigeon2NoMotionCount: return "Pigeon2NoMotionCount";
                    case SpnValue::Pigeon2TempCompDisabled: return "Pigeon2TempCompDisabled";
                    case SpnValue::Pigeon2UpTime: return "Pigeon2UpTime";
                    case SpnValue::Pigeon2AccumGyroX: return "Pigeon2AccumGyroX";
                    case SpnValue::Pigeon2AccumGyroY: return "Pigeon2AccumGyroY";
                    case SpnValue::Pigeon2AccumGyroZ: return "Pigeon2AccumGyroZ";
                    case SpnValue::Pigeon2AngularVelocityX: return "Pigeon2AngularVelocityX";
                    case SpnValue::Pigeon2AngularVelocityY: return "Pigeon2AngularVelocityY";
                    case SpnValue::Pigeon2AngularVelocityZ: return "Pigeon2AngularVelocityZ";
                    case SpnValue::Pigeon2AccelerationX: return "Pigeon2AccelerationX";
                    case SpnValue::Pigeon2AccelerationY: return "Pigeon2AccelerationY";
                    case SpnValue::Pigeon2AccelerationZ: return "Pigeon2AccelerationZ";
                    case SpnValue::Pigeon2_SupplyVoltage: return "Pigeon2_SupplyVoltage";
                    case SpnValue::Pigeon2MagneticFieldX: return "Pigeon2MagneticFieldX";
                    case SpnValue::Pigeon2MagneticFieldY: return "Pigeon2MagneticFieldY";
                    case SpnValue::Pigeon2MagneticFieldZ: return "Pigeon2MagneticFieldZ";
                    case SpnValue::Pigeon2RawMagneticFieldX: return "Pigeon2RawMagneticFieldX";
                    case SpnValue::Pigeon2RawMagneticFieldY: return "Pigeon2RawMagneticFieldY";
                    case SpnValue::Pigeon2RawMagneticFieldZ: return "Pigeon2RawMagneticFieldZ";
                    case SpnValue::CANCoder_MagnetOffset: return "CANCoder_MagnetOffset";
                    case SpnValue::CANcoder_AbsoluteSensorRange: return "CANcoder_AbsoluteSensorRange";
                    case SpnValue::DeviceEnabled: return "DeviceEnabled";
                    case SpnValue::ForwardLimit: return "ForwardLimit";
                    case SpnValue::ReverseLimit: return "ReverseLimit";
                    case SpnValue::PRO_MotorOutput_RotorPolarity: return "PRO_MotorOutput_RotorPolarity";
                    case SpnValue::PRO_MotorOutput_DutyCycle: return "PRO_MotorOutput_DutyCycle";
                    case SpnValue::PRO_MotorOutput_TorqueCurrent: return "PRO_MotorOutput_TorqueCurrent";
                    case SpnValue::PRO_SupplyAndTemp_StatorCurrent: return "PRO_SupplyAndTemp_StatorCurrent";
                    case SpnValue::PRO_SupplyAndTemp_SupplyCurrent: return "PRO_SupplyAndTemp_SupplyCurrent";
                    case SpnValue::PRO_SupplyAndTemp_SupplyVoltage: return "PRO_SupplyAndTemp_SupplyVoltage";
                    case SpnValue::PRO_SupplyAndTemp_DeviceTemp: return "PRO_SupplyAndTemp_DeviceTemp";
                    case SpnValue::PRO_SupplyAndTemp_ProcessorTemp: return "PRO_SupplyAndTemp_ProcessorTemp";
                    case SpnValue::PRO_RotorPosAndVel_Velocity: return "PRO_RotorPosAndVel_Velocity";
                    case SpnValue::PRO_RotorPosAndVel_Position: return "PRO_RotorPosAndVel_Position";
                    case SpnValue::PRO_PosAndVel_Velocity: return "PRO_PosAndVel_Velocity";
                    case SpnValue::PRO_PosAndVel_Position: return "PRO_PosAndVel_Position";
                    case SpnValue::PRO_PIDStateEnables_IntegratedAccum_DC: return "PRO_PIDStateEnables_IntegratedAccum_DC";
                    case SpnValue::PRO_PIDStateEnables_IntegratedAccum_V: return "PRO_PIDStateEnables_IntegratedAccum_V";
                    case SpnValue::PRO_PIDStateEnables_IntegratedAccum_A: return "PRO_PIDStateEnables_IntegratedAccum_A";
                    case SpnValue::PRO_PIDStateEnables_FeedForward_DC: return "PRO_PIDStateEnables_FeedForward_DC";
                    case SpnValue::PRO_PIDStateEnables_FeedForward_V: return "PRO_PIDStateEnables_FeedForward_V";
                    case SpnValue::PRO_PIDStateEnables_FeedForward_A: return "PRO_PIDStateEnables_FeedForward_A";
                    case SpnValue::TalonFX_ControlMode: return "TalonFX_ControlMode";
                    case SpnValue::PRO_PIDStateEnables_IsMotionMagicRunning: return "PRO_PIDStateEnables_IsMotionMagicRunning";
                    case SpnValue::PRO_PIDStateEnables_DeviceEnable: return "PRO_PIDStateEnables_DeviceEnable";
                    case SpnValue::PRO_PIDRefPIDErr_PIDRef_Position: return "PRO_PIDRefPIDErr_PIDRef_Position";
                    case SpnValue::PRO_PIDRefPIDErr_PIDRef_Velocity: return "PRO_PIDRefPIDErr_PIDRef_Velocity";
                    case SpnValue::PRO_PIDRefPIDErr_PIDErr_Position: return "PRO_PIDRefPIDErr_PIDErr_Position";
                    case SpnValue::PRO_PIDRefPIDErr_PIDErr_Velocity: return "PRO_PIDRefPIDErr_PIDErr_Velocity";
                    case SpnValue::PRO_PIDOutput_ProportionalOutput_DC: return "PRO_PIDOutput_ProportionalOutput_DC";
                    case SpnValue::PRO_PIDOutput_ProportionalOutput_V: return "PRO_PIDOutput_ProportionalOutput_V";
                    case SpnValue::PRO_PIDOutput_ProportionalOutput_A: return "PRO_PIDOutput_ProportionalOutput_A";
                    case SpnValue::PRO_PIDOutput_DerivativeOutput_DC: return "PRO_PIDOutput_DerivativeOutput_DC";
                    case SpnValue::PRO_PIDOutput_DerivativeOutput_V: return "PRO_PIDOutput_DerivativeOutput_V";
                    case SpnValue::PRO_PIDOutput_DerivativeOutput_A: return "PRO_PIDOutput_DerivativeOutput_A";
                    case SpnValue::PRO_PIDOutput_Output_DC: return "PRO_PIDOutput_Output_DC";
                    case SpnValue::PRO_PIDOutput_Output_V: return "PRO_PIDOutput_Output_V";
                    case SpnValue::PRO_PIDOutput_Output_A: return "PRO_PIDOutput_Output_A";
                    case SpnValue::PRO_PIDOutput_Slot: return "PRO_PIDOutput_Slot";
                    case SpnValue::PRO_PIDRefSlopeECUTime_ReferenceSlope_Position: return "PRO_PIDRefSlopeECUTime_ReferenceSlope_Position";
                    case SpnValue::PRO_PIDRefSlopeECUTime_ReferenceSlope_Velocity: return "PRO_PIDRefSlopeECUTime_ReferenceSlope_Velocity";
                    case SpnValue::Slot0_kP: return "Slot0_kP";
                    case SpnValue::Slot0_kI: return "Slot0_kI";
                    case SpnValue::Slot0_kD: return "Slot0_kD";
                    case SpnValue::Slot0_kV: return "Slot0_kV";
                    case SpnValue::Slot0_kS: return "Slot0_kS";
                    case SpnValue::Slot1_kP: return "Slot1_kP";
                    case SpnValue::Slot1_kI: return "Slot1_kI";
                    case SpnValue::Slot1_kD: return "Slot1_kD";
                    case SpnValue::Slot1_kV: return "Slot1_kV";
                    case SpnValue::Slot1_kS: return "Slot1_kS";
                    case SpnValue::Slot2_kP: return "Slot2_kP";
                    case SpnValue::Slot2_kI: return "Slot2_kI";
                    case SpnValue::Slot2_kD: return "Slot2_kD";
                    case SpnValue::Slot2_kV: return "Slot2_kV";
                    case SpnValue::Slot2_kS: return "Slot2_kS";
                    case SpnValue::Config_Inverted: return "Config_Inverted";
                    case SpnValue::Config_SupplyVLowpassTau: return "Config_SupplyVLowpassTau";
                    case SpnValue::Config_BeepOnBoot: return "Config_BeepOnBoot";
                    case SpnValue::Config_NeutralMode: return "Config_NeutralMode";
                    case SpnValue::Config_DutyCycleNeutralDB: return "Config_DutyCycleNeutralDB";
                    case SpnValue::Config_StatorCurrentLimit: return "Config_StatorCurrentLimit";
                    case SpnValue::Config_StatorCurrLimitEn: return "Config_StatorCurrLimitEn";
                    case SpnValue::Config_SupplyCurrentLimit: return "Config_SupplyCurrentLimit";
                    case SpnValue::Config_SupplyCurrLimitEn: return "Config_SupplyCurrLimitEn";
                    case SpnValue::Config_PeakForwardDC: return "Config_PeakForwardDC";
                    case SpnValue::Config_PeakReverseDC: return "Config_PeakReverseDC";
                    case SpnValue::Config_PeakForwardV: return "Config_PeakForwardV";
                    case SpnValue::Config_PeakReverseV: return "Config_PeakReverseV";
                    case SpnValue::Config_PeakForTorqCurr: return "Config_PeakForTorqCurr";
                    case SpnValue::Config_PeakRevTorqCurr: return "Config_PeakRevTorqCurr";
                    case SpnValue::Config_TorqueNeutralDB: return "Config_TorqueNeutralDB";
                    case SpnValue::Config_FeedbackRotorOffset: return "Config_FeedbackRotorOffset";
                    case SpnValue::Config_SensorToMechanismRatio: return "Config_SensorToMechanismRatio";
                    case SpnValue::Config_RotorToSensorRatio: return "Config_RotorToSensorRatio";
                    case SpnValue::Config_FeedbackSensorSource: return "Config_FeedbackSensorSource";
                    case SpnValue::Config_FeedbackRemoteSensorID: return "Config_FeedbackRemoteSensorID";
                    case SpnValue::Config_DutyCycleOpenLoopRampPeriod: return "Config_DutyCycleOpenLoopRampPeriod";
                    case SpnValue::Config_VoltageOpenLoopRampPeriod: return "Config_VoltageOpenLoopRampPeriod";
                    case SpnValue::Config_TorqueOpenLoopRampPeriod: return "Config_TorqueOpenLoopRampPeriod";
                    case SpnValue::Config_DutyCycleClosedLoopRampPeriod: return "Config_DutyCycleClosedLoopRampPeriod";
                    case SpnValue::Config_VoltageClosedLoopRampPeriod: return "Config_VoltageClosedLoopRampPeriod";
                    case SpnValue::Config_TorqueClosedLoopRampPeriod: return "Config_TorqueClosedLoopRampPeriod";
                    case SpnValue::Config_ForwardLimitType: return "Config_ForwardLimitType";
                    case SpnValue::Config_ForwardLimitAutosetPosEnable: return "Config_ForwardLimitAutosetPosEnable";
                    case SpnValue::Config_ForwardLimitAutosetPosValue: return "Config_ForwardLimitAutosetPosValue";
                    case SpnValue::Config_ForwardLimitEnable: return "Config_ForwardLimitEnable";
                    case SpnValue::Config_ForwardLimitSource: return "Config_ForwardLimitSource";
                    case SpnValue::Config_ForwardLimitRemoteSensorID: return "Config_ForwardLimitRemoteSensorID";
                    case SpnValue::Config_ReverseLimitType: return "Config_ReverseLimitType";
                    case SpnValue::Config_ReverseLimitAutosetPosEnable: return "Config_ReverseLimitAutosetPosEnable";
                    case SpnValue::Config_ReverseLimitAutosetPosValue: return "Config_ReverseLimitAutosetPosValue";
                    case SpnValue::Config_ReverseLimitEnable: return "Config_ReverseLimitEnable";
                    case SpnValue::Config_ReverseLimitSource: return "Config_ReverseLimitSource";
                    case SpnValue::Config_ReverseLimitRemoteSensorID: return "Config_ReverseLimitRemoteSensorID";
                    case SpnValue::Config_ForwardSoftLimitEnable: return "Config_ForwardSoftLimitEnable";
                    case SpnValue::Config_ReverseSoftLimitEnable: return "Config_ReverseSoftLimitEnable";
                    case SpnValue::Config_ForwardSoftLimitThreshold: return "Config_ForwardSoftLimitThreshold";
                    case SpnValue::Config_ReverseSoftLimitThreshold: return "Config_ReverseSoftLimitThreshold";
                    case SpnValue::Config_MotionMagicCruiseVelocity: return "Config_MotionMagicCruiseVelocity";
                    case SpnValue::Config_MotionMagicAcceleration: return "Config_MotionMagicAcceleration";
                    case SpnValue::Config_MotionMagicJerk: return "Config_MotionMagicJerk";
                    case SpnValue::CANcoder_Velocity: return "CANcoder_Velocity";
                    case SpnValue::CANcoder_Position: return "CANcoder_Position";
                    case SpnValue::CANcoder_AbsPosition: return "CANcoder_AbsPosition";
                    case SpnValue::CANCoder_RawVel: return "CANCoder_RawVel";
                    case SpnValue::CANCoder_RawPos: return "CANCoder_RawPos";
                    case SpnValue::CANCoder_SupplyVoltage: return "CANCoder_SupplyVoltage";
                    case SpnValue::CANcoder_MagHealth: return "CANcoder_MagHealth";
                    case SpnValue::PRO_MotorOutput_BridgeType_Public: return "PRO_MotorOutput_BridgeType_Public";
                    case SpnValue::Config_ContinuousWrap: return "Config_ContinuousWrap";
                    case SpnValue::Config_SupplyCurrThres: return "Config_SupplyCurrThres";
                    case SpnValue::Config_SupplyTimeThres: return "Config_SupplyTimeThres";
                    case SpnValue::Fault_Hardware: return "Fault_Hardware";
                    case SpnValue::StickyFault_Hardware: return "StickyFault_Hardware";
                    case SpnValue::Fault_ProcTemp: return "Fault_ProcTemp";
                    case SpnValue::StickyFault_ProcTemp: return "StickyFault_ProcTemp";
                    case SpnValue::Fault_DeviceTemp: return "Fault_DeviceTemp";
                    case SpnValue::StickyFault_DeviceTemp: return "StickyFault_DeviceTemp";
                    case SpnValue::Fault_Undervoltage: return "Fault_Undervoltage";
                    case SpnValue::StickyFault_Undervoltage: return "StickyFault_Undervoltage";
                    case SpnValue::Fault_BootDuringEnable: return "Fault_BootDuringEnable";
                    case SpnValue::StickyFault_BootDuringEnable: return "StickyFault_BootDuringEnable";
                    case SpnValue::Fault_UnlicensedFeatureInUse: return "Fault_UnlicensedFeatureInUse";
                    case SpnValue::StickyFault_UnlicensedFeatureInUse: return "StickyFault_UnlicensedFeatureInUse";
                    case SpnValue::Fault_PIGEON2_BootupAccel: return "Fault_PIGEON2_BootupAccel";
                    case SpnValue::StickyFault_PIGEON2_BootupAccel: return "StickyFault_PIGEON2_BootupAccel";
                    case SpnValue::Fault_PIGEON2_BootupGyros: return "Fault_PIGEON2_BootupGyros";
                    case SpnValue::StickyFault_PIGEON2_BootupGyros: return "StickyFault_PIGEON2_BootupGyros";
                    case SpnValue::Fault_PIGEON2_BootupMagne: return "Fault_PIGEON2_BootupMagne";
                    case SpnValue::StickyFault_PIGEON2_BootupMagne: return "StickyFault_PIGEON2_BootupMagne";
                    case SpnValue::Fault_PIGEON2_BootIntoMotion: return "Fault_PIGEON2_BootIntoMotion";
                    case SpnValue::StickyFault_PIGEON2_BootIntoMotion: return "StickyFault_PIGEON2_BootIntoMotion";
                    case SpnValue::Fault_PIGEON2_DataAcquiredLate: return "Fault_PIGEON2_DataAcquiredLate";
                    case SpnValue::StickyFault_PIGEON2_DataAcquiredLate: return "StickyFault_PIGEON2_DataAcquiredLate";
                    case SpnValue::Fault_PIGEON2_LoopTimeSlow: return "Fault_PIGEON2_LoopTimeSlow";
                    case SpnValue::StickyFault_PIGEON2_LoopTimeSlow: return "StickyFault_PIGEON2_LoopTimeSlow";
                    case SpnValue::Fault_PIGEON2_SaturatedMagne: return "Fault_PIGEON2_SaturatedMagne";
                    case SpnValue::StickyFault_PIGEON2_SaturatedMagne: return "StickyFault_PIGEON2_SaturatedMagne";
                    case SpnValue::Fault_PIGEON2_SaturatedAccel: return "Fault_PIGEON2_SaturatedAccel";
                    case SpnValue::StickyFault_PIGEON2_SaturatedAccel: return "StickyFault_PIGEON2_SaturatedAccel";
                    case SpnValue::Fault_PIGEON2_SaturatedGyros: return "Fault_PIGEON2_SaturatedGyros";
                    case SpnValue::StickyFault_PIGEON2_SaturatedGyros: return "StickyFault_PIGEON2_SaturatedGyros";
                    case SpnValue::Fault_CANCODER_BadMagnet: return "Fault_CANCODER_BadMagnet";
                    case SpnValue::StickyFault_CANCODER_BadMagnet: return "StickyFault_CANCODER_BadMagnet";
                    case SpnValue::Fault_TALONFX_OverSupplyV: return "Fault_TALONFX_OverSupplyV";
                    case SpnValue::StickyFault_TALONFX_OverSupplyV: return "StickyFault_TALONFX_OverSupplyV";
                    case SpnValue::Fault_TALONFX_UnstableSupplyV: return "Fault_TALONFX_UnstableSupplyV";
                    case SpnValue::StickyFault_TALONFX_UnstableSupplyV: return "StickyFault_TALONFX_UnstableSupplyV";
                    case SpnValue::Fault_TALONFX_ReverseHardLimit: return "Fault_TALONFX_ReverseHardLimit";
                    case SpnValue::StickyFault_TALONFX_ReverseHardLimit: return "StickyFault_TALONFX_ReverseHardLimit";
                    case SpnValue::Fault_TALONFX_ForwardHardLimit: return "Fault_TALONFX_ForwardHardLimit";
                    case SpnValue::StickyFault_TALONFX_ForwardHardLimit: return "StickyFault_TALONFX_ForwardHardLimit";
                    case SpnValue::Fault_TALONFX_ReverseSoftLimit: return "Fault_TALONFX_ReverseSoftLimit";
                    case SpnValue::StickyFault_TALONFX_ReverseSoftLimit: return "StickyFault_TALONFX_ReverseSoftLimit";
                    case SpnValue::Fault_TALONFX_ForwardSoftLimit: return "Fault_TALONFX_ForwardSoftLimit";
                    case SpnValue::StickyFault_TALONFX_ForwardSoftLimit: return "StickyFault_TALONFX_ForwardSoftLimit";
                    case SpnValue::Fault_TALONFX_MissingRemoteSensor: return "Fault_TALONFX_MissingRemoteSensor";
                    case SpnValue::StickyFault_TALONFX_MissingRemoteSensor: return "StickyFault_TALONFX_MissingRemoteSensor";
                    case SpnValue::Fault_TALONFX_FusedSensorOutOfSync: return "Fault_TALONFX_FusedSensorOutOfSync";
                    case SpnValue::StickyFault_TALONFX_FusedSensorOutOfSync: return "StickyFault_TALONFX_FusedSensorOutOfSync";
                    case SpnValue::Fault_TALONFX_StatorCurrLimit: return "Fault_TALONFX_StatorCurrLimit";
                    case SpnValue::StickyFault_TALONFX_StatorCurrLimit: return "StickyFault_TALONFX_StatorCurrLimit";
                    case SpnValue::Fault_TALONFX_SupplyCurrLimit: return "Fault_TALONFX_SupplyCurrLimit";
                    case SpnValue::StickyFault_TALONFX_SupplyCurrLimit: return "StickyFault_TALONFX_SupplyCurrLimit";
                    case SpnValue::Fault_TALONFX_UsingFusedCCWhileUnlicensed: return "Fault_TALONFX_UsingFusedCCWhileUnlicensed";
                    case SpnValue::StickyFault_TALONFX_UsingFusedCCWhileUnlicensed: return "StickyFault_TALONFX_UsingFusedCCWhileUnlicensed";
                    default:
                        return "Invalid Value";
                    }
                }

                friend std::ostream &operator<<(std::ostream &os, const SpnValue &data)
                {
                    os << data.ToString();
                    return os;
                }
                bool operator==(const SpnValue &data) const
                {
                    return this->value == data.value;
                }
                bool operator==(int data) const
                {
                    return this->value == data;
                }
                bool operator<(const SpnValue &data) const
                {
                    return this->value < data.value;
                }
                bool operator<(int data) const
                {
                    return this->value < data;
                }
            };
        }
    }
}
