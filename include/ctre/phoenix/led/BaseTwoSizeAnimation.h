/* Copyright (C) Cross The Road Electronics 2024 */
#pragma once

#include "ctre/phoenix/led/Animation.h"

namespace ctre{ namespace phoenix{ namespace led{ 

/**
 * The base class for one generic type of animation.
 * These animations do allow the user to specify a color.
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
BaseTwoSizeAnimation : public Animation {
    int _r, _g, _b, _w;
    int _direction, _size;

public:

    /**
     * Constructor for the BaseStandardAnimation object
     * @param idx The animation-specific ID
     * @param r The amount of red to set, a value between [0, 255]
     * @param g The amount of green to set, a value between [0, 255]
     * @param b The amount of blue to set, a value between [0, 255]
     * @param w The amount of white to set, a value between [0, 255]
     * @param speed The rate at which the animation runs at. Higher is generally faster
     * @param numLed The number of LEDs to run the animation on
     * @param direction An animation-specific parameter for its direction
     * @param size An animation-specific parameter for its size
     * @param ledOffset Where to start the animation
     */
    BaseTwoSizeAnimation(int idx, int r, int g, int b, int w, double speed, int numLed, int direction, int size, int ledOffset);
    ~BaseTwoSizeAnimation();

    [[deprecated("This device's Phoenix 5 API is deprecated for removal in the 2027 season."
                "Users should update to Phoenix 6 firmware and migrate to the Phoenix 6 API."
                "A migration guide is available at https://v6.docs.ctr-electronics.com/en/stable/docs/migration/migration-guide/index.html")]]
    BaseStandardAnimation *GetBaseStandardAnimation();
    [[deprecated("This device's Phoenix 5 API is deprecated for removal in the 2027 season."
                "Users should update to Phoenix 6 firmware and migrate to the Phoenix 6 API."
                "A migration guide is available at https://v6.docs.ctr-electronics.com/en/stable/docs/migration/migration-guide/index.html")]]
    BaseTwoSizeAnimation *GetBaseTwoSizeAnimation();
    
    /**
     * Sets the R value of the LEDs
     * @param r The amount of red to set, a value between [0, 255]
     */
    void SetR(int r);
    /**
     * Sets the G value of the LEDs
     * @param g The amount of green to set, a value between [0, 255]
     */
    void SetG(int g);
    /**
     * Sets the B value of the LEDs
     * @param b The amount of blue to set, a value between [0, 255]
     */
    void SetB(int b);
    /**
     * Sets the W value of the LEDs
     * @param w The amount of white to set, a value between [0, 255]
     */
    void SetW(int w);
    void SetDirection(int direction);
    void SetSize(int size);

    int GetR();
    int GetG();
    int GetB();
    int GetW();
    int GetDirection();
    int GetSize();
};

} // namespace led
} // namespace phoenix
} // namespace ctre

