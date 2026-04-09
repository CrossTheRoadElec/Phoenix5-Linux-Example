/* Copyright (C) Cross The Road Electronics 2024 */
#pragma once

namespace ctre{ namespace phoenix{ namespace led{
    /**
     * The various LED types that the CANdle can support
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
