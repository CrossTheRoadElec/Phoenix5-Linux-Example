#pragma once

#include "ctre/phoenix/CustomParamConfiguration.h"
#include "ctre/phoenix/led/CANdleLedStripType.h"
#include "ctre/phoenix/led/VBatOutputMode.h"
#include <string>

namespace ctre{ namespace phoenix{ namespace led{

/**
 * Configurables available to CANifier
 */
struct CANdleConfiguration : public CustomParamConfiguration {
    /** 
     * What type of LEDs the CANdle controls
     */
    LEDStripType stripType {LEDStripType::RGB};
    /**
     * Brightness scalar for all LEDs controlled
     */
    double brightnessScalar {1.0};
    /**
     * True to turn off LEDs when Loss of Signal occurrs
     */
    bool disableWhenLOS {false};
    /**
     * True to turn off Status LED when CANdle is actively being controlled
     */
    bool statusLedOffWhenActive {false};
    /**
     * The behavior of VBat output
     */
    VBatOutputMode vBatOutputMode {VBatOutputMode::On};
    /**
     * True to turn off the 5V rail. This turns off the on-board LEDs as well.
     */
    bool v5Enabled {false};

    CANdleConfiguration();

    /**
     * @param prependString
     *              String to prepend to configs
     * @return String representation of configs
     */
    std::string toString(std::string prependString = "");

};

} // namespace led
} // namespace phoenix
} // namespace ctre
