#pragma once

namespace ctre{ namespace phoenix{ namespace led{
    
    /**
     * The various methods of managing the VBat output behavior
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
