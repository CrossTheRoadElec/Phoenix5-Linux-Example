/* Copyright (C) Cross The Road Electronics 2024 */
#pragma once

#include "ctre/phoenix/led/BaseStandardAnimation.h"

namespace ctre {namespace phoenix {namespace led {

/**
 * Animation that creates a rainbow throughout all the LEDs
 */
class RainbowAnimation : public BaseStandardAnimation {
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
