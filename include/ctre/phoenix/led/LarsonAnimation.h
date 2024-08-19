/* Copyright (C) Cross The Road Electronics 2024 */
#pragma once

#include "ctre/phoenix/led/BaseTwoSizeAnimation.h"

namespace ctre {namespace phoenix {namespace led {

/**
 * Animation that sends a pocket of light across the LED strip.
 */
class LarsonAnimation : public BaseTwoSizeAnimation {
public:
    /**
     * How the pocket of light behaves when it reaches the end of the strip
     */
    enum BounceMode {
        /**
         * Bounce the pocket as soon as the first LED reaches the end of the strip
         */
        Front = 0,
        /**
         * Bounce the pocket once it is midway through the end of the strip
         */
        Center = 1,
        /**
         * Bounce the pocket once all the LEDs are off the strip
         */
        Back = 2,
    };
    /**
     * Constructor for a LarsonAnimation
     * @param r How much red should the color have [0, 255]
     * @param g How much green should the color have [0, 255]
     * @param b How much blue should the color have [0, 255]
     * @param w How much white should the color have [0, 255]
     * @param speed How fast should the color travel the strip [0, 1]
     * @param numLed The number of LEDs the CANdle will control
     * @param mode How the pocket of LEDs will behave once it reaches the end of the strip
     * @param size How large the pocket of LEDs are [0, 7]
     * @param ledOffset Where to start the animation
     */
    LarsonAnimation(int r, int g, int b, int w = 0, double speed = 1, int numLed = -1, BounceMode mode = BounceMode::Front, int size = 2, int ledOffset = 0);

    /**
     * Sets the bounce mode of the animation.
     * @param mode How the pocket of LEDs will behave once it reaches the end of the strip
     */
    void SetBounceMode(BounceMode mode);
    
    /**
     * Sets the size of the pocket of LEDs
     * @param size The size of the pocket [0, 7]
     */
    void SetSize(int size);
};

} // namespace led
} // namespace phoenix
} // namespace ctre
