#pragma once

#include "ctre/phoenix/led/BaseTwoSizeAnimation.h"

namespace ctre {namespace phoenix {namespace led {

/**
 * Animation that gradually lights the entire LED strip one LED at a time.
 */
class ColorFlowAnimation : public BaseTwoSizeAnimation {
public:
    /**
     * What direction does the color go
     */
    enum Direction {
        /**
         * Color goes forward, away from CANdle
         */
        Forward = 0,
        /**
         * Color goes backward, toward CANdle
         */
        Backward = 1,
    };

    /**
     * Constructor for a ColorFlowAnimation
     * @param r How much red should the color have [0, 255]
     * @param g How much green should the color have [0, 255]
     * @param b How much blue should the color have [0, 255]
     * @param w How much white should the color have [0, 255]
     * @param speed How fast should the color travel the strip [0, 1]
     * @param numLed How many LEDs is the CANdle controlling
     * @param direction What direction should the color move in
     * @param ledOffset Where to start the animation
     */
    ColorFlowAnimation(int r, int g, int b, int w, double speed = 1, int numLed = -1, Direction direction = Direction::Forward, int ledOffset = 0);

    /**
     * Sets the direction the color flow moves in
     * @param direction What direction should the color move in
     */
    void SetDirection(Direction direction);
};

} // namespace led
} // namespace phoenix
} // namespace ctre
