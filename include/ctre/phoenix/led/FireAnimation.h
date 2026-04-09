/* Copyright (C) Cross The Road Electronics 2024 */
#pragma once

#include "ctre/phoenix/led/BaseStandardAnimation.h"

namespace ctre {namespace phoenix {namespace led {

/**
 * Animation that looks similarly to a flame flickering
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
FireAnimation : public BaseStandardAnimation {
public:
    /**
     * Constructor for a FireAnimation
     * @param brightness How bright should the animation be [0, 1]
     * @param speed How fast will the flame be processed at [0, 1]
     * @param numLed How many LEDs is the CANdle controlling
     * @param sparking The rate at which the Fire "Sparks" [0, 1]
     * @param cooling The rate at which the Fire "Cools" along the travel [0, 1]
     * @param reverseDirection True to reverse the animation direction, so instead of fire going "away" from the CANdle, it will go "toward" the CANdle.
     * @param ledOffset Where to start the animation
     */
    FireAnimation(double brightness = 1, double speed = 1, int numLed = -1, double sparking = 1, double cooling = 1, bool reverseDirection = false, int ledOffset = 0);
    /**
     * Sets the sparking value of the FireAnimation
     * @param sparking The rate at which the Fire "Sparks" [0, 1]
     */
    void SetSparking(double sparking);
    /**
     * Sets the cooling value of the FireAnimation
     * @param cooling The rate at which the Fire "Cools" [0, 1]
     */
    void SetCooling(double cooling);
};

} // namespace led
} // namespace phoenix
} // namespace ctre
