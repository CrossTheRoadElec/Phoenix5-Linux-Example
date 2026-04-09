/* Copyright (C) Cross The Road Electronics 2024 */
#pragma once

#include "ctre/phoenix/led/Animation.h"

namespace ctre{ namespace phoenix{ namespace led{ 

/**
 * The base class for one generic type of animation.
 * These animations do not allow the user to specify a color.
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
BaseStandardAnimation : public Animation {
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
    
    [[deprecated("This device's Phoenix 5 API is deprecated for removal in the 2027 season."
                "Users should update to Phoenix 6 firmware and migrate to the Phoenix 6 API."
                "A migration guide is available at https://v6.docs.ctr-electronics.com/en/stable/docs/migration/migration-guide/index.html")]]
    BaseStandardAnimation *GetBaseStandardAnimation();
    [[deprecated("This device's Phoenix 5 API is deprecated for removal in the 2027 season."
                "Users should update to Phoenix 6 firmware and migrate to the Phoenix 6 API."
                "A migration guide is available at https://v6.docs.ctr-electronics.com/en/stable/docs/migration/migration-guide/index.html")]]
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
