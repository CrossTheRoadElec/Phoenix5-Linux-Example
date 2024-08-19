/* Copyright (C) Cross The Road Electronics 2024 */
#pragma once

#include "ctre/phoenix/led/Animation.h"

namespace ctre{ namespace phoenix{ namespace led{ 

/**
 * The base class for one generic type of animation.
 * These animations do not allow the user to specify a color.
 */
class BaseStandardAnimation : public Animation {
    double _brightness, _param4, _param5;
    bool _reverseDirection;
public:
    /**
     * Constructor for the BaseStandardAnimation object
     * @param idx The animation-specific ID
     * @param brightness The brightness to run the animation at. This is a scalar from [0, 1]
     * @param speed The rate at which the animation runs at. Higher is generally faster
     * @param numLed The number of LEDs to run the animation on
     * @param param4 Animation-specific parameter
     * @param param5 Animation-specific parameter
     * @param reverseDirection True to reverse the animation direction, so instead of going "away" from the CANdle, it will go "toward" the CANdle.
     * @param ledOffset Where to start the animation
     */
    BaseStandardAnimation(int idx, double brightness, double speed, int numLed, double param4, double param5, bool reverseDirection, int ledOffset);
    ~BaseStandardAnimation();
    
    BaseStandardAnimation *GetBaseStandardAnimation();
    BaseTwoSizeAnimation *GetBaseTwoSizeAnimation();

    /**
     * Sets the brightness of this animation
     * @param brightness The brightness to run the animation at. This is a scalar from [0, 1]
     */
    void SetBrightness(double brightness);
    void SetParam4(double param4);
    void SetParam5(double param5);
    /**
     * Set the Direction of the animation
     * @param reverseDirection True to reverse the animation direction, so instead of fire going "away" from the CANdle, it will go "toward" the CANdle.
     */
    void SetReverseDirection(bool reverseDirection);

    double GetBrightness();
    double GetParam4();
    double GetParam5();
    bool GetReverseDirection();
};

} // namespace led
} // namespace phoenix
} // namespace ctre
