/* Copyright (C) Cross The Road Electronics 2024 */
#pragma once

namespace ctre{ namespace phoenix{ namespace led{
    
    /**
     * The various methods of managing the VBat output behavior
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
    enum VBatOutputMode {
        /**
         * VBat output is on at full power, no modulation
         */
        On = 0,
        /**
         * VBat output is off, no modulation
         */
        Off = 1,
        /**
         * VBat output is on at the specified modulation
         */
        Modulated = 2,
    };
} // namespace led
} // namespace phoenix
} // namespace ctre
