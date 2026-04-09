/* Copyright (C) Cross The Road Electronics 2024 */
#pragma once

#include "ctre/phoenix/CustomParamConfiguration.h"
#include "ctre/phoenix/led/CANdleLedStripType.h"
#include "ctre/phoenix/led/VBatOutputMode.h"
#include <string>

namespace ctre{ namespace phoenix{ namespace led{

/**
 * Configurables available to CANdle
 *
 * @deprecated This device's Phoenix 5 API is deprecated for removal in the
 * 2027 season. Users should update to Phoenix 6 firmware and migrate to the
 * Phoenix 6 API. A migration guide is available at
 * https://v6.docs.ctr-electronics.com/en/stable/docs/migration/migration-guide/index.html.
 *
 * If the Phoenix 5 API must be used for this device, the device must have 22.X
 * firmware. This firmware is available in Tuner X after selecting Phoenix 5 in
 * the firmware year dropdown.
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

    /**
     * Constructor
     *
     * @deprecated This device's Phoenix 5 API is deprecated for removal in the
     * 2027 season. Users should update to Phoenix 6 firmware and migrate to the
     * Phoenix 6 API. A migration guide is available at
     * https://v6.docs.ctr-electronics.com/en/stable/docs/migration/migration-guide/index.html.
     *
     * If the Phoenix 5 API must be used for this device, the device must have 22.X
     * firmware. This firmware is available in Tuner X after selecting Phoenix 5 in
     * the firmware year dropdown.
     */
    [[deprecated("This device's Phoenix 5 API is deprecated for removal in the 2027 season."
                "Users should update to Phoenix 6 firmware and migrate to the Phoenix 6 API."
                "A migration guide is available at https://v6.docs.ctr-electronics.com/en/stable/docs/migration/migration-guide/index.html")]]
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
