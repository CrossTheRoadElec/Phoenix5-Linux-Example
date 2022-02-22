#pragma once

#include <cstddef>

namespace ctre{ namespace phoenix{ namespace led{ 

class BaseStandardAnimation;
class BaseTwoSizeAnimation;

/**
 * The base class for all animations that CANdle supports.
 */
class Animation {
    int _animationIdx, _numLed, _ledOffset;
    double _speed;
public:
    /**
     * Constructor for an Animation class
     * @param idx The animation-specific ID 
     * @param speed The rate at which the animation runs at. Higher is generally faster
     * @param numLed The number of LEDs to run the animation on
     * @param ledOffset Where to start the animation
     */
    Animation(int idx, double speed, int numLed, int ledOffset);
    virtual ~Animation();
    /**
     * Sets the speed of the animation
     * @param speed The rate at which the animation runs at. Higher is generally faster
     */
    void SetSpeed(double speed);
    /**
     * Sets the number of LEDs the animation will run on
     * @param numLed The number of LEDs to run the animation on
     */
    void SetNumLed(int numLed);
    /**
     * Sets where the animation starts along the strip
     * @param ledOffset Where to start the animation along the strip
     */
    void SetLedOffset(int ledOffset);

    virtual BaseStandardAnimation *GetBaseStandardAnimation() = 0;
    virtual BaseTwoSizeAnimation *GetBaseTwoSizeAnimation() = 0;

    int GetAnimationIdx();
    double GetSpeed();
    int GetNumLed();
    int GetLedOffset();
};

} // namespace led
} // namespace phoenix
} // namespace ctre