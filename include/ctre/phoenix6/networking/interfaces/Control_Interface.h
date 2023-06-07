/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#include "ctre/phoenix/export.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif
    CTREXPORT int c_ctre_phoenix6_requestConfigApply(const char *canbus, uint32_t ecuEncoding, double timeoutSeconds, const char *str, uint32_t strlen, bool forceApply);
CTREXPORT int c_ctre_phoenix6_RequestControlDutyCycleOut(const char *canbus, uint32_t ecuEncoding, double updateTime, bool cancelOtherRequests, double Output, bool EnableFOC, bool OverrideBrakeDurNeutral);
CTREXPORT int c_ctre_phoenix6_RequestControlTorqueCurrentFOC(const char *canbus, uint32_t ecuEncoding, double updateTime, bool cancelOtherRequests, double Output, double MaxAbsDutyCycle, double Deadband, bool OverrideCoastDurNeutral);
CTREXPORT int c_ctre_phoenix6_RequestControlVoltageOut(const char *canbus, uint32_t ecuEncoding, double updateTime, bool cancelOtherRequests, double Output, bool EnableFOC, bool OverrideBrakeDurNeutral);
CTREXPORT int c_ctre_phoenix6_RequestControlPositionDutyCycle(const char *canbus, uint32_t ecuEncoding, double updateTime, bool cancelOtherRequests, double Position, bool EnableFOC, double FeedForward, int Slot, bool OverrideBrakeDurNeutral);
CTREXPORT int c_ctre_phoenix6_RequestControlPositionVoltage(const char *canbus, uint32_t ecuEncoding, double updateTime, bool cancelOtherRequests, double Position, bool EnableFOC, double FeedForward, int Slot, bool OverrideBrakeDurNeutral);
CTREXPORT int c_ctre_phoenix6_RequestControlPositionTorqueCurrentFOC(const char *canbus, uint32_t ecuEncoding, double updateTime, bool cancelOtherRequests, double Position, double FeedForward, int Slot, bool OverrideCoastDurNeutral);
CTREXPORT int c_ctre_phoenix6_RequestControlVelocityDutyCycle(const char *canbus, uint32_t ecuEncoding, double updateTime, bool cancelOtherRequests, double Velocity, bool EnableFOC, double FeedForward, int Slot, bool OverrideBrakeDurNeutral);
CTREXPORT int c_ctre_phoenix6_RequestControlVelocityVoltage(const char *canbus, uint32_t ecuEncoding, double updateTime, bool cancelOtherRequests, double Velocity, bool EnableFOC, double FeedForward, int Slot, bool OverrideBrakeDurNeutral);
CTREXPORT int c_ctre_phoenix6_RequestControlVelocityTorqueCurrentFOC(const char *canbus, uint32_t ecuEncoding, double updateTime, bool cancelOtherRequests, double Velocity, double FeedForward, int Slot, bool OverrideCoastDurNeutral);
CTREXPORT int c_ctre_phoenix6_RequestControlMotionMagicDutyCycle(const char *canbus, uint32_t ecuEncoding, double updateTime, bool cancelOtherRequests, double Position, bool EnableFOC, double FeedForward, int Slot, bool OverrideBrakeDurNeutral);
CTREXPORT int c_ctre_phoenix6_RequestControlMotionMagicVoltage(const char *canbus, uint32_t ecuEncoding, double updateTime, bool cancelOtherRequests, double Position, bool EnableFOC, double FeedForward, int Slot, bool OverrideBrakeDurNeutral);
CTREXPORT int c_ctre_phoenix6_RequestControlMotionMagicTorqueCurrentFOC(const char *canbus, uint32_t ecuEncoding, double updateTime, bool cancelOtherRequests, double Position, double FeedForward, int Slot, bool OverrideCoastDurNeutral);
CTREXPORT int c_ctre_phoenix6_RequestControlFollower(const char *canbus, uint32_t ecuEncoding, double updateTime, bool cancelOtherRequests, int MasterID, bool OpposeMasterDirection);
CTREXPORT int c_ctre_phoenix6_RequestControlStrictFollower(const char *canbus, uint32_t ecuEncoding, double updateTime, bool cancelOtherRequests, int MasterID);
CTREXPORT int c_ctre_phoenix6_RequestControlNeutralOut(const char *canbus, uint32_t ecuEncoding, double updateTime, bool cancelOtherRequests);
CTREXPORT int c_ctre_phoenix6_RequestControlCoastOut(const char *canbus, uint32_t ecuEncoding, double updateTime, bool cancelOtherRequests);
CTREXPORT int c_ctre_phoenix6_RequestControlStaticBrake(const char *canbus, uint32_t ecuEncoding, double updateTime, bool cancelOtherRequests);
CTREXPORT int c_ctre_phoenix6_RequestControlBalanceBattery(const char *canbus, uint32_t ecuEncoding, double updateTime, bool cancelOtherRequests);
CTREXPORT int c_ctre_phoenix6_RequestControlBMSManualIsolator(const char *canbus, uint32_t ecuEncoding, double updateTime, bool cancelOtherRequests, bool Enable);
CTREXPORT int c_ctre_phoenix6_RequestControlBMSManualVboost(const char *canbus, uint32_t ecuEncoding, double updateTime, bool cancelOtherRequests, bool EnableClosedLoop, double TargetVoltage, double TargetDutyCycle);
CTREXPORT int c_ctre_phoenix6_RequestControlBMSManualPwmJunction(const char *canbus, uint32_t ecuEncoding, double updateTime, bool cancelOtherRequests, int JunctionSelect, double JunctionDutyCycle);
CTREXPORT int c_ctre_phoenix6_RequestControlBMSClearFault(const char *canbus, uint32_t ecuEncoding, double updateTime, bool cancelOtherRequests);
#ifdef __cplusplus
}
#endif
