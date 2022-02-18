#pragma once

namespace ctre{ namespace phoenix{ namespace led{
    /**
     * The various LED types that the CANdle can support
     */
    enum LEDStripType {
        /**
         * LEDs that are controlled by Green-Red-Blue values
         */
        GRB = 0,
        /**
         * LEDs that are controlled by Red-Green-Blue values
         */
        RGB = 1,
        /**
         * LEDs that are controlled by Blue-Red-Green values
         */
        BRG = 2,
        /**
         * LEDs that are controlled by Green-Red-Blue-White values
         */
        GRBW = 6,
        /**
         * LEDs that are controlled by Red-Green-Blue-White values
         */
        RGBW = 7,
        /**
         * LEDs that are controlled by Blue-Red-Green-White values
         */
        BRGW = 8,
    };
    
} // namespace led
} // namespace phoenix
} // namespace ctre
