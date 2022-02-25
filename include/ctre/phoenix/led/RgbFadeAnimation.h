#pragma once

#include "ctre/phoenix/led/BaseStandardAnimation.h"

namespace ctre {namespace phoenix {namespace led {

/**
 * Animation that fades all the LEDs of a strip simultaneously between Red, Green, and Blue
 */
class RgbFadeAnimation : public BaseStandardAnimation {
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
