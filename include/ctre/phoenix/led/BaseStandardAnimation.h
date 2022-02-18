#pragma once

#include "ctre/phoenix/led/Animation.h"

namespace ctre{ namespace phoenix{ namespace led{ 

/**
 * The base class for one generic type of animation.
 * These animations do not allow the user to specify a color.
 */
class BaseStandardAnimation : public Animation {
    double _brightness, _param4, _param5;
public:
    /**
     * Constructor for the BaseStandardAnimation object
     * @param idx The animation-specific ID
     * @param brightness The brightness to run the animation at. This is a scalar from [0, 1]
     * @param speed The rate at which the animation runs at. Higher is generally faster
     * @param numLed The number of LEDs to run the animation on
     * @param param4 Animation-specific parameter
     * @param param5 Animation-specific parameter
     */
    BaseStandardAnimation(int idx, double brightness, double speed, int numLed, double param4, double param5);
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

    double GetBrightness();
    double GetParam4();
    double GetParam5();
};

} // namespace led
} // namespace phoenix
} // namespace ctre
