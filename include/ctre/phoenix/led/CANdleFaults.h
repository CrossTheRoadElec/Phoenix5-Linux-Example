/* Copyright (C) Cross The Road Electronics 2024 */
#pragma once

#include <cstdint>

namespace ctre {
namespace phoenix {
namespace led{

/**
 * Faults available to CANdle (Currently has none)
 */
struct CANdleFaults {
	/**
	 * Device detects hardware failure
	 */
	bool HardwareFault;
	/**
	 * API error detected.  Make sure API and firmware versions are compatible.
	 */
	bool APIError;
    /**
     * Boot while receiving an enable frame 
     */
    bool BootDuringEnable;
    /**
     * VBat is under 5V
     */
    bool VBatTooLow;
    /**
     * VBat is over 30V
     */
    bool VBatTooHigh;
    /**
     * 5V Line is under 4 V
     */
    bool V5TooLow;
    /**
     * 5V Line is over 6V
     */
    bool V5TooHigh;
    /**
     * Exceeded output current of 6 amps
     */
    bool SoftwareFuse;
    /**
     * Device is over temperature
     */
    bool ThermalFault;
    /**
     * Output pin is shorted to something
     */
    bool ShortCircuit;

    /**
     * @return true if any faults are tripped
     */
    bool HasAnyFault() const {
        return  HardwareFault |
                APIError |
                BootDuringEnable |
                VBatTooLow |
                VBatTooHigh |
                V5TooLow |
                V5TooHigh |
                SoftwareFuse |
                ThermalFault |
                ShortCircuit;
    }
    /**
     * @return Current fault list as a bit field
     */
    int ToBitfield() const {
		uint64_t commonFaults = 0;
        commonFaults |= ShortCircuit ? 1 : 0; commonFaults <<= 1;
        commonFaults |= ThermalFault ? 1 : 0; commonFaults <<= 1;
        commonFaults |= SoftwareFuse ? 1 : 0; commonFaults <<= 1;
        commonFaults |= V5TooLow ? 1 : 0; commonFaults <<= 1;
        commonFaults |= V5TooHigh ? 1 : 0; commonFaults <<= 1;
        commonFaults |= VBatTooLow ? 1 : 0; commonFaults <<= 1;
		commonFaults |= VBatTooHigh ? 1 : 0; commonFaults <<= 1;
		commonFaults |= BootDuringEnable ? 1 : 0; commonFaults <<= 1;
		commonFaults |= APIError ? 1 : 0; commonFaults <<= 1;
		commonFaults |= HardwareFault ? 1 : 0;

        return commonFaults;
    }
    void Update(uint64_t bits) {
        uint64_t mask = 1;
        HardwareFault  =    (bits & mask) ? true : false; mask <<= 1;
        APIError =          (bits & mask) ? true : false; mask <<= 1;
        BootDuringEnable =  (bits & mask) ? true : false; mask <<= 1;
        VBatTooHigh =       (bits & mask) ? true : false; mask <<= 1;
        VBatTooLow =        (bits & mask) ? true : false; mask <<= 1;
        V5TooHigh =         (bits & mask) ? true : false; mask <<= 1;
        V5TooLow =          (bits & mask) ? true : false; mask <<= 1;
        SoftwareFuse =      (bits & mask) ? true : false; mask <<= 1;
        ThermalFault =      (bits & mask) ? true : false; mask <<= 1;
        ShortCircuit =      (bits & mask) ? true : false; mask <<= 1;
    }
    /**
     * Updates current fault list with specified bit field of faults
     * 
     * @param bits bit field of faults to update with
     */
    CANdleFaults(int bits) {
        Update(bits);
    }
    CANdleFaults() {
        Update(0);
    }
};
/**
 * Faults available to CANdle (Currently has none)
 */
struct CANdleStickyFaults {
	/**
	 * Device detects hardware failure
	 */
	bool HardwareFault;
	/**
	 * API error detected.  Make sure API and firmware versions are compatible.
	 */
	bool APIError;
    /**
     * Boot while receiving an enable frame 
     */
    bool BootDuringEnable;
    /**
     * VBat is under 5V
     */
    bool VBatTooLow;
    /**
     * VBat is over 30V
     */
    bool VBatTooHigh;
    /**
     * 5V Line is under 4 V
     */
    bool V5TooLow;
    /**
     * 5V Line is over 6V
     */
    bool V5TooHigh;
    /**
     * Exceeded output current of 6 amps
     */
    bool SoftwareFuse;
    /**
     * Device is over temperature
     */
    bool ThermalFault;
    /**
     * Output pin is shorted to something
     */
    bool ShortCircuit;

    /**
     * @return true if any faults are tripped
     */
    bool HasAnyFault() const {
        return  HardwareFault |
                APIError |
                BootDuringEnable |
                VBatTooLow |
                VBatTooHigh |
                V5TooLow |
                V5TooHigh |
                SoftwareFuse |
                ThermalFault |
                ShortCircuit;
    }
    /**
     * @return Current fault list as a bit field
     */
    int ToBitfield() const {
		uint64_t commonFaults = 0;
        commonFaults |= ShortCircuit ? 1 : 0; commonFaults <<= 1;
        commonFaults |= ThermalFault ? 1 : 0; commonFaults <<= 1;
        commonFaults |= SoftwareFuse ? 1 : 0; commonFaults <<= 1;
        commonFaults |= V5TooLow ? 1 : 0; commonFaults <<= 1;
        commonFaults |= V5TooHigh ? 1 : 0; commonFaults <<= 1;
        commonFaults |= VBatTooLow ? 1 : 0; commonFaults <<= 1;
		commonFaults |= VBatTooHigh ? 1 : 0; commonFaults <<= 1;
		commonFaults |= BootDuringEnable ? 1 : 0; commonFaults <<= 1;
		commonFaults |= APIError ? 1 : 0; commonFaults <<= 1;
		commonFaults |= HardwareFault ? 1 : 0;

        return commonFaults;
    }
    void Update(uint64_t bits) {
        uint64_t mask = 1;
        HardwareFault  =    (bits & mask) ? true : false; mask <<= 1;
        APIError =          (bits & mask) ? true : false; mask <<= 1;
        BootDuringEnable =  (bits & mask) ? true : false; mask <<= 1;
        VBatTooHigh =       (bits & mask) ? true : false; mask <<= 1;
        VBatTooLow =        (bits & mask) ? true : false; mask <<= 1;
        V5TooHigh =         (bits & mask) ? true : false; mask <<= 1;
        V5TooLow =          (bits & mask) ? true : false; mask <<= 1;
        SoftwareFuse =      (bits & mask) ? true : false; mask <<= 1;
        ThermalFault =      (bits & mask) ? true : false; mask <<= 1;
        ShortCircuit =      (bits & mask) ? true : false; mask <<= 1;
    }
    /**
     * Updates current fault list with specified bit field of faults
     * 
     * @param bits bit field of faults to update with
     */
    CANdleStickyFaults(int bits) {
        Update(bits);
    }
    CANdleStickyFaults() {
        Update(0);
    }
};

} // led
} // phoenix
} // ctre

