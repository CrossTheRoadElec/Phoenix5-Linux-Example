/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once
#include <string>
#include "ctre/phoenix/export.h"

namespace ctre{
namespace phoenix{
namespace platform{

CTREXPORT int FRC_Report(int resource, int instanceNumber, std::string const &canbus = "", int callerIdx = 0, int context = 0, const char* feature = nullptr);
CTREXPORT int FRC_Report(std::string const &model, int instanceNumber, std::string const &canbus = "", int callerIdx = 0, int context = 0, const char* feature = nullptr);

enum FrcUsageType{
    TalonSRX,
    PigeonIMU,
    CANifier,
    VictorSPX,
    CANcoder,
    TalonFX,
    CANdle,
    CANivore,
    Pigeon2
};

} //namespace platform
} //namespace phoenix
} //namespace ctre