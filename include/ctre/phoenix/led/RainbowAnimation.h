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
     */
    RainbowAnimation(double brightness = 1, double speed = 1, int numLed = -1);
};

} // namespace led
} // namespace phoenix
} // namespace ctre
