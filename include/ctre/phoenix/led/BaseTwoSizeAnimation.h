#pragma once

#include "ctre/phoenix/led/Animation.h"

namespace ctre{ namespace phoenix{ namespace led{ 

/**
 * The base class for one generic type of animation.
 * These animations do allow the user to specify a color.
 */
class BaseTwoSizeAnimation : public Animation {
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

    BaseStandardAnimation *GetBaseStandardAnimation();
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

