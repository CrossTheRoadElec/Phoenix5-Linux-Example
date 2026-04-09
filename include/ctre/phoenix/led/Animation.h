/* Copyright (C) Cross The Road Electronics 2024 */
#pragma once

#include <cstddef>

namespace ctre{ namespace phoenix{ namespace led{ 

class BaseStandardAnimation;
class BaseTwoSizeAnimation;

/**
 * The base class for all animations that CANdle supports.
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
Animation {
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

    [[deprecated("This device's Phoenix 5 API is deprecated for removal in the 2027 season."
                "Users should update to Phoenix 6 firmware and migrate to the Phoenix 6 API."
                "A migration guide is available at https://v6.docs.ctr-electronics.com/en/stable/docs/migration/migration-guide/index.html")]]
    virtual BaseStandardAnimation *GetBaseStandardAnimation() = 0;
    [[deprecated("This device's Phoenix 5 API is deprecated for removal in the 2027 season."
                "Users should update to Phoenix 6 firmware and migrate to the Phoenix 6 API."
                "A migration guide is available at https://v6.docs.ctr-electronics.com/en/stable/docs/migration/migration-guide/index.html")]]
    virtual BaseTwoSizeAnimation *GetBaseTwoSizeAnimation() = 0;

    int GetAnimationIdx();
    double GetSpeed();
    int GetNumLed();
    int GetLedOffset();
};

} // namespace led
} // namespace phoenix
} // namespace ctre