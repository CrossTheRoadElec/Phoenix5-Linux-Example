/* Copyright (C) Cross The Road Electronics 2024 */
#pragma once

#include "ctre/phoenix/led/BaseStandardAnimation.h"

namespace ctre {namespace phoenix {namespace led {

/**
 * Animation that creates a rainbow throughout all the LEDs
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
RainbowAnimation : public BaseStandardAnimation {
public:
    /**
     * Constructor for a RainbowAnimation
     * @param brightness The brightness of the LEDs [0, 1]
     * @param speed How fast the rainbow travels through the leds [0, 1]
     * @param numLed How many LEDs are controlled by the CANdle
     * @param reverseDirection True to reverse the animation direction, so instead of going "toward" the CANdle, it will go "away" from the CANdle.
     * @param ledOffset Where to start the animation
     */
    RainbowAnimation(double brightness = 1, double speed = 1, int numLed = -1, bool reverseDirection = false, int ledOffset = 0);
};

} // namespace led
} // namespace phoenix
} // namespace ctre
