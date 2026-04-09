/* Copyright (C) Cross The Road Electronics 2024 */
#pragma once

#include "ctre/phoenix/led/BaseStandardAnimation.h"

namespace ctre {namespace phoenix {namespace led {

/**
 * Animation that fades all the LEDs of a strip simultaneously between Red, Green, and Blue
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
class [[deprecated("This device's Phoenix 5 API is deprecated for removal in the 2027 season."
                "Users should update to Phoenix 6 firmware and migrate to the Phoenix 6 API."
                "A migration guide is available at https://v6.docs.ctr-electronics.com/en/stable/docs/migration/migration-guide/index.html")]]
RgbFadeAnimation : public BaseStandardAnimation {
public:
    /**
     * Constructor for an RgbFadeAnimation
     * @param brightness How bright the LEDs are [0, 1]
     * @param speed How fast the LEDs fade between Red, Green, and Blue [0, 1]
     * @param numLed How many LEDs are controlled by the CANdle
     * @param ledOffset Where to start the animation
     */
    RgbFadeAnimation(double brightness = 1, double speed = 1, int numLed = -1, int ledOffset = 0);
};

} // namespace led
} // namespace phoenix
} // namespace ctre
