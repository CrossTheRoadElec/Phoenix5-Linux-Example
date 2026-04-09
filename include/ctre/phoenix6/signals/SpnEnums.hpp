/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#include "ctre/phoenix6/Serializable.hpp"
#include "ctre/phoenix/export.h"
#include <compare>
#include <iosfwd>

namespace ctre {
namespace phoenix6 {
namespace signals {


/**
 * \brief System state of the device.
 */
struct System_StateValue : public ISerializable {
    int value;

    static constexpr int Bootup_0 = 0;
    static constexpr int Bootup_1 = 1;
    static constexpr int Bootup_2 = 2;
    static constexpr int Bootup_3 = 3;
    static constexpr int Bootup_4 = 4;
    static constexpr int Bootup_5 = 5;
    static constexpr int Bootup_6 = 6;
    static constexpr int Bootup_7 = 7;
    static constexpr int BootBeep = 8;
    static constexpr int ControlDisabled = 9;
    static constexpr int ControlEnabled = 10;
    static constexpr int ControlEnabled_11 = 11;
    static constexpr int Fault = 12;
    static constexpr int Recover = 13;
    static constexpr int NotLicensed = 14;
    static constexpr int Production = 15;

    constexpr System_StateValue(int value) :
        value{value}
    {}

    constexpr System_StateValue() :
        value{-1}
    {}

    constexpr bool operator==(System_StateValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(System_StateValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case System_StateValue::Bootup_0: return "Bootup_0";
            case System_StateValue::Bootup_1: return "Bootup_1";
            case System_StateValue::Bootup_2: return "Bootup_2";
            case System_StateValue::Bootup_3: return "Bootup_3";
            case System_StateValue::Bootup_4: return "Bootup_4";
            case System_StateValue::Bootup_5: return "Bootup_5";
            case System_StateValue::Bootup_6: return "Bootup_6";
            case System_StateValue::Bootup_7: return "Bootup_7";
            case System_StateValue::BootBeep: return "BootBeep";
            case System_StateValue::ControlDisabled: return "ControlDisabled";
            case System_StateValue::ControlEnabled: return "ControlEnabled";
            case System_StateValue::ControlEnabled_11: return "ControlEnabled_11";
            case System_StateValue::Fault: return "Fault";
            case System_StateValue::Recover: return "Recover";
            case System_StateValue::NotLicensed: return "NotLicensed";
            case System_StateValue::Production: return "Production";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, System_StateValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Whether the device is Pro licensed.
 */
struct IsPROLicensedValue : public ISerializable {
    int value;

    static constexpr int NotLicensed = 0;
    static constexpr int Licensed = 1;

    constexpr IsPROLicensedValue(int value) :
        value{value}
    {}

    constexpr IsPROLicensedValue() :
        value{-1}
    {}

    constexpr bool operator==(IsPROLicensedValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(IsPROLicensedValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case IsPROLicensedValue::NotLicensed: return "Not Licensed";
            case IsPROLicensedValue::Licensed: return "Licensed";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, IsPROLicensedValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Whether the device is Season Pass licensed.
 */
struct Licensing_IsSeasonPassedValue : public ISerializable {
    int value;

    static constexpr int NotLicensed = 0;
    static constexpr int Licensed = 1;

    constexpr Licensing_IsSeasonPassedValue(int value) :
        value{value}
    {}

    constexpr Licensing_IsSeasonPassedValue() :
        value{-1}
    {}

    constexpr bool operator==(Licensing_IsSeasonPassedValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(Licensing_IsSeasonPassedValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case Licensing_IsSeasonPassedValue::NotLicensed: return "Not Licensed";
            case Licensing_IsSeasonPassedValue::Licensed: return "Licensed";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, Licensing_IsSeasonPassedValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Direction of the sensor to determine positive rotation, as seen facing
 *        the LED side of the CANcoder.
 */
struct SensorDirectionValue : public ISerializable {
    int value;

    /**
     * \brief Counter-clockwise motion reports positive rotation.
     */
    static constexpr int CounterClockwise_Positive = 0;
    /**
     * \brief Clockwise motion reports positive rotation.
     */
    static constexpr int Clockwise_Positive = 1;

    constexpr SensorDirectionValue(int value) :
        value{value}
    {}

    constexpr SensorDirectionValue() :
        value{-1}
    {}

    constexpr bool operator==(SensorDirectionValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(SensorDirectionValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case SensorDirectionValue::CounterClockwise_Positive: return "CounterClockwise_Positive";
            case SensorDirectionValue::Clockwise_Positive: return "Clockwise_Positive";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, SensorDirectionValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Whether device is locked by FRC.
 */
struct FrcLockValue : public ISerializable {
    int value;

    static constexpr int Frc_Locked = 1;
    static constexpr int Frc_Unlocked = 0;

    constexpr FrcLockValue(int value) :
        value{value}
    {}

    constexpr FrcLockValue() :
        value{-1}
    {}

    constexpr bool operator==(FrcLockValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(FrcLockValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case FrcLockValue::Frc_Locked: return "Frc_Locked";
            case FrcLockValue::Frc_Unlocked: return "Frc_Unlocked";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, FrcLockValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Whether the robot is enabled.
 */
struct RobotEnableValue : public ISerializable {
    int value;

    static constexpr int Enabled = 1;
    static constexpr int Disabled = 0;

    constexpr RobotEnableValue(int value) :
        value{value}
    {}

    constexpr RobotEnableValue() :
        value{-1}
    {}

    constexpr bool operator==(RobotEnableValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(RobotEnableValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case RobotEnableValue::Enabled: return "Enabled";
            case RobotEnableValue::Disabled: return "Disabled";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, RobotEnableValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The Color of LED1 when it's "On".
 */
struct Led1OnColorValue : public ISerializable {
    int value;

    static constexpr int Off = 0;
    static constexpr int Red = 1;
    static constexpr int Green = 2;
    static constexpr int Orange = 3;
    static constexpr int Blue = 4;
    static constexpr int Pink = 5;
    static constexpr int Cyan = 6;
    static constexpr int White = 7;

    constexpr Led1OnColorValue(int value) :
        value{value}
    {}

    constexpr Led1OnColorValue() :
        value{-1}
    {}

    constexpr bool operator==(Led1OnColorValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(Led1OnColorValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case Led1OnColorValue::Off: return "Off";
            case Led1OnColorValue::Red: return "Red";
            case Led1OnColorValue::Green: return "Green";
            case Led1OnColorValue::Orange: return "Orange";
            case Led1OnColorValue::Blue: return "Blue";
            case Led1OnColorValue::Pink: return "Pink";
            case Led1OnColorValue::Cyan: return "Cyan";
            case Led1OnColorValue::White: return "White";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, Led1OnColorValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The Color of LED1 when it's "Off".
 */
struct Led1OffColorValue : public ISerializable {
    int value;

    static constexpr int Off = 0;
    static constexpr int Red = 1;
    static constexpr int Green = 2;
    static constexpr int Orange = 3;
    static constexpr int Blue = 4;
    static constexpr int Pink = 5;
    static constexpr int Cyan = 6;
    static constexpr int White = 7;

    constexpr Led1OffColorValue(int value) :
        value{value}
    {}

    constexpr Led1OffColorValue() :
        value{-1}
    {}

    constexpr bool operator==(Led1OffColorValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(Led1OffColorValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case Led1OffColorValue::Off: return "Off";
            case Led1OffColorValue::Red: return "Red";
            case Led1OffColorValue::Green: return "Green";
            case Led1OffColorValue::Orange: return "Orange";
            case Led1OffColorValue::Blue: return "Blue";
            case Led1OffColorValue::Pink: return "Pink";
            case Led1OffColorValue::Cyan: return "Cyan";
            case Led1OffColorValue::White: return "White";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, Led1OffColorValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The Color of LED2 when it's "On".
 */
struct Led2OnColorValue : public ISerializable {
    int value;

    static constexpr int Off = 0;
    static constexpr int Red = 1;
    static constexpr int Green = 2;
    static constexpr int Orange = 3;
    static constexpr int Blue = 4;
    static constexpr int Pink = 5;
    static constexpr int Cyan = 6;
    static constexpr int White = 7;

    constexpr Led2OnColorValue(int value) :
        value{value}
    {}

    constexpr Led2OnColorValue() :
        value{-1}
    {}

    constexpr bool operator==(Led2OnColorValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(Led2OnColorValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case Led2OnColorValue::Off: return "Off";
            case Led2OnColorValue::Red: return "Red";
            case Led2OnColorValue::Green: return "Green";
            case Led2OnColorValue::Orange: return "Orange";
            case Led2OnColorValue::Blue: return "Blue";
            case Led2OnColorValue::Pink: return "Pink";
            case Led2OnColorValue::Cyan: return "Cyan";
            case Led2OnColorValue::White: return "White";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, Led2OnColorValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The Color of LED2 when it's "Off".
 */
struct Led2OffColorValue : public ISerializable {
    int value;

    static constexpr int Off = 0;
    static constexpr int Red = 1;
    static constexpr int Green = 2;
    static constexpr int Orange = 3;
    static constexpr int Blue = 4;
    static constexpr int Pink = 5;
    static constexpr int Cyan = 6;
    static constexpr int White = 7;

    constexpr Led2OffColorValue(int value) :
        value{value}
    {}

    constexpr Led2OffColorValue() :
        value{-1}
    {}

    constexpr bool operator==(Led2OffColorValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(Led2OffColorValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case Led2OffColorValue::Off: return "Off";
            case Led2OffColorValue::Red: return "Red";
            case Led2OffColorValue::Green: return "Green";
            case Led2OffColorValue::Orange: return "Orange";
            case Led2OffColorValue::Blue: return "Blue";
            case Led2OffColorValue::Pink: return "Pink";
            case Led2OffColorValue::Cyan: return "Cyan";
            case Led2OffColorValue::White: return "White";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, Led2OffColorValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Whether the device is enabled.
 */
struct DeviceEnableValue : public ISerializable {
    int value;

    static constexpr int Enabled = 1;
    static constexpr int Disabled = 0;

    constexpr DeviceEnableValue(int value) :
        value{value}
    {}

    constexpr DeviceEnableValue() :
        value{-1}
    {}

    constexpr bool operator==(DeviceEnableValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(DeviceEnableValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case DeviceEnableValue::Enabled: return "Enabled";
            case DeviceEnableValue::Disabled: return "Disabled";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, DeviceEnableValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Forward Limit Pin.
 */
struct ForwardLimitValue : public ISerializable {
    int value;

    static constexpr int ClosedToGround = 0;
    static constexpr int Open = 1;

    constexpr ForwardLimitValue(int value) :
        value{value}
    {}

    constexpr ForwardLimitValue() :
        value{-1}
    {}

    constexpr bool operator==(ForwardLimitValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(ForwardLimitValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case ForwardLimitValue::ClosedToGround: return "Closed To Ground";
            case ForwardLimitValue::Open: return "Open";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, ForwardLimitValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Reverse Limit Pin.
 */
struct ReverseLimitValue : public ISerializable {
    int value;

    static constexpr int ClosedToGround = 0;
    static constexpr int Open = 1;

    constexpr ReverseLimitValue(int value) :
        value{value}
    {}

    constexpr ReverseLimitValue() :
        value{-1}
    {}

    constexpr bool operator==(ReverseLimitValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(ReverseLimitValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case ReverseLimitValue::ClosedToGround: return "Closed To Ground";
            case ReverseLimitValue::Open: return "Open";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, ReverseLimitValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The applied rotor polarity as seen from the front of the motor.  This
 *        typically is determined by the Inverted config, but can be overridden
 *        if using Follower features.
 */
struct AppliedRotorPolarityValue : public ISerializable {
    int value;

    /**
     * \brief Positive motor output results in counter-clockwise motion.
     */
    static constexpr int PositiveIsCounterClockwise = 0;
    /**
     * \brief Positive motor output results in clockwise motion.
     */
    static constexpr int PositiveIsClockwise = 1;

    constexpr AppliedRotorPolarityValue(int value) :
        value{value}
    {}

    constexpr AppliedRotorPolarityValue() :
        value{-1}
    {}

    constexpr bool operator==(AppliedRotorPolarityValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(AppliedRotorPolarityValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case AppliedRotorPolarityValue::PositiveIsCounterClockwise: return "PositiveIsCounterClockwise";
            case AppliedRotorPolarityValue::PositiveIsClockwise: return "PositiveIsClockwise";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, AppliedRotorPolarityValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The active control mode of the motor controller.
 */
struct ControlModeValue : public ISerializable {
    int value;

    static constexpr int DisabledOutput = 0;
    static constexpr int NeutralOut = 1;
    static constexpr int StaticBrake = 2;
    static constexpr int DutyCycleOut = 3;
    static constexpr int PositionDutyCycle = 4;
    static constexpr int VelocityDutyCycle = 5;
    static constexpr int MotionMagicDutyCycle = 6;
    static constexpr int DutyCycleFOC = 7;
    static constexpr int PositionDutyCycleFOC = 8;
    static constexpr int VelocityDutyCycleFOC = 9;
    static constexpr int MotionMagicDutyCycleFOC = 10;
    static constexpr int VoltageOut = 11;
    static constexpr int PositionVoltage = 12;
    static constexpr int VelocityVoltage = 13;
    static constexpr int MotionMagicVoltage = 14;
    static constexpr int VoltageFOC = 15;
    static constexpr int PositionVoltageFOC = 16;
    static constexpr int VelocityVoltageFOC = 17;
    static constexpr int MotionMagicVoltageFOC = 18;
    static constexpr int TorqueCurrentFOC = 19;
    static constexpr int PositionTorqueCurrentFOC = 20;
    static constexpr int VelocityTorqueCurrentFOC = 21;
    static constexpr int MotionMagicTorqueCurrentFOC = 22;
    static constexpr int Follower = 23;
    static constexpr int Reserved = 24;
    static constexpr int CoastOut = 25;
    static constexpr int UnauthorizedDevice = 26;
    static constexpr int MusicTone = 27;
    static constexpr int MotionMagicVelocityDutyCycle = 28;
    static constexpr int MotionMagicVelocityDutyCycleFOC = 29;
    static constexpr int MotionMagicVelocityVoltage = 30;
    static constexpr int MotionMagicVelocityVoltageFOC = 31;
    static constexpr int MotionMagicVelocityTorqueCurrentFOC = 32;
    static constexpr int MotionMagicExpoDutyCycle = 33;
    static constexpr int MotionMagicExpoDutyCycleFOC = 34;
    static constexpr int MotionMagicExpoVoltage = 35;
    static constexpr int MotionMagicExpoVoltageFOC = 36;
    static constexpr int MotionMagicExpoTorqueCurrentFOC = 37;

    constexpr ControlModeValue(int value) :
        value{value}
    {}

    constexpr ControlModeValue() :
        value{-1}
    {}

    constexpr bool operator==(ControlModeValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(ControlModeValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case ControlModeValue::DisabledOutput: return "DisabledOutput";
            case ControlModeValue::NeutralOut: return "NeutralOut";
            case ControlModeValue::StaticBrake: return "StaticBrake";
            case ControlModeValue::DutyCycleOut: return "DutyCycleOut";
            case ControlModeValue::PositionDutyCycle: return "PositionDutyCycle";
            case ControlModeValue::VelocityDutyCycle: return "VelocityDutyCycle";
            case ControlModeValue::MotionMagicDutyCycle: return "MotionMagicDutyCycle";
            case ControlModeValue::DutyCycleFOC: return "DutyCycleFOC";
            case ControlModeValue::PositionDutyCycleFOC: return "PositionDutyCycleFOC";
            case ControlModeValue::VelocityDutyCycleFOC: return "VelocityDutyCycleFOC";
            case ControlModeValue::MotionMagicDutyCycleFOC: return "MotionMagicDutyCycleFOC";
            case ControlModeValue::VoltageOut: return "VoltageOut";
            case ControlModeValue::PositionVoltage: return "PositionVoltage";
            case ControlModeValue::VelocityVoltage: return "VelocityVoltage";
            case ControlModeValue::MotionMagicVoltage: return "MotionMagicVoltage";
            case ControlModeValue::VoltageFOC: return "VoltageFOC";
            case ControlModeValue::PositionVoltageFOC: return "PositionVoltageFOC";
            case ControlModeValue::VelocityVoltageFOC: return "VelocityVoltageFOC";
            case ControlModeValue::MotionMagicVoltageFOC: return "MotionMagicVoltageFOC";
            case ControlModeValue::TorqueCurrentFOC: return "TorqueCurrentFOC";
            case ControlModeValue::PositionTorqueCurrentFOC: return "PositionTorqueCurrentFOC";
            case ControlModeValue::VelocityTorqueCurrentFOC: return "VelocityTorqueCurrentFOC";
            case ControlModeValue::MotionMagicTorqueCurrentFOC: return "MotionMagicTorqueCurrentFOC";
            case ControlModeValue::Follower: return "Follower";
            case ControlModeValue::Reserved: return "Reserved";
            case ControlModeValue::CoastOut: return "CoastOut";
            case ControlModeValue::UnauthorizedDevice: return "UnauthorizedDevice";
            case ControlModeValue::MusicTone: return "MusicTone";
            case ControlModeValue::MotionMagicVelocityDutyCycle: return "MotionMagicVelocityDutyCycle";
            case ControlModeValue::MotionMagicVelocityDutyCycleFOC: return "MotionMagicVelocityDutyCycleFOC";
            case ControlModeValue::MotionMagicVelocityVoltage: return "MotionMagicVelocityVoltage";
            case ControlModeValue::MotionMagicVelocityVoltageFOC: return "MotionMagicVelocityVoltageFOC";
            case ControlModeValue::MotionMagicVelocityTorqueCurrentFOC: return "MotionMagicVelocityTorqueCurrentFOC";
            case ControlModeValue::MotionMagicExpoDutyCycle: return "MotionMagicExpoDutyCycle";
            case ControlModeValue::MotionMagicExpoDutyCycleFOC: return "MotionMagicExpoDutyCycleFOC";
            case ControlModeValue::MotionMagicExpoVoltage: return "MotionMagicExpoVoltage";
            case ControlModeValue::MotionMagicExpoVoltageFOC: return "MotionMagicExpoVoltageFOC";
            case ControlModeValue::MotionMagicExpoTorqueCurrentFOC: return "MotionMagicExpoTorqueCurrentFOC";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, ControlModeValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Status of the temperature sensor of the external motor.
 */
struct ExternalMotorTempStatusValue : public ISerializable {
    int value;

    /**
     * \brief Talon is collecting information on the sensor.
     */
    static constexpr int Collecting = 0;
    /**
     * \brief Temperature sensor appears to be disconnected.
     */
    static constexpr int Disconnected = 1;
    /**
     * \brief Temperature sensor is too hot to allow motor operation.
     */
    static constexpr int TooHot = 2;
    /**
     * \brief Temperature sensor is normal.
     */
    static constexpr int Normal = 3;
    /**
     * \brief Temperature sensor is present but is not used.  Most likely the motor
     *        arrangement is brushed or disabled.
     */
    static constexpr int NotUsed = 4;
    /**
     * \brief Temperature sensor appears to be for the wrong motor arrangement, or
     *        signals are shorted.
     */
    static constexpr int WrongMotorOrShorted = 5;

    constexpr ExternalMotorTempStatusValue(int value) :
        value{value}
    {}

    constexpr ExternalMotorTempStatusValue() :
        value{-1}
    {}

    constexpr bool operator==(ExternalMotorTempStatusValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(ExternalMotorTempStatusValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case ExternalMotorTempStatusValue::Collecting: return "Collecting";
            case ExternalMotorTempStatusValue::Disconnected: return "Disconnected";
            case ExternalMotorTempStatusValue::TooHot: return "Too Hot";
            case ExternalMotorTempStatusValue::Normal: return "Normal";
            case ExternalMotorTempStatusValue::NotUsed: return "Not Used";
            case ExternalMotorTempStatusValue::WrongMotorOrShorted: return "Wrong Motor Or Shorted";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, ExternalMotorTempStatusValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Whether the closed-loop is running on position or velocity.
 */
struct PIDRefPIDErr_ClosedLoopModeValue : public ISerializable {
    int value;

    static constexpr int Position = 0;
    static constexpr int Velocity = 1;

    constexpr PIDRefPIDErr_ClosedLoopModeValue(int value) :
        value{value}
    {}

    constexpr PIDRefPIDErr_ClosedLoopModeValue() :
        value{-1}
    {}

    constexpr bool operator==(PIDRefPIDErr_ClosedLoopModeValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(PIDRefPIDErr_ClosedLoopModeValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case PIDRefPIDErr_ClosedLoopModeValue::Position: return "Position";
            case PIDRefPIDErr_ClosedLoopModeValue::Velocity: return "Velocity";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, PIDRefPIDErr_ClosedLoopModeValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The output mode of the PID controller.
 */
struct PIDOutput_PIDOutputModeValue : public ISerializable {
    int value;

    static constexpr int DutyCycle = 0;
    static constexpr int Voltage = 1;
    static constexpr int TorqueCurrentFOC = 2;

    constexpr PIDOutput_PIDOutputModeValue(int value) :
        value{value}
    {}

    constexpr PIDOutput_PIDOutputModeValue() :
        value{-1}
    {}

    constexpr bool operator==(PIDOutput_PIDOutputModeValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(PIDOutput_PIDOutputModeValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case PIDOutput_PIDOutputModeValue::DutyCycle: return "DutyCycle";
            case PIDOutput_PIDOutputModeValue::Voltage: return "Voltage";
            case PIDOutput_PIDOutputModeValue::TorqueCurrentFOC: return "TorqueCurrentFOC";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, PIDOutput_PIDOutputModeValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Whether the closed-loop is running on position or velocity.
 */
struct PIDRefSlopeECUTime_ClosedLoopModeValue : public ISerializable {
    int value;

    static constexpr int Position = 0;
    static constexpr int Velocity = 1;

    constexpr PIDRefSlopeECUTime_ClosedLoopModeValue(int value) :
        value{value}
    {}

    constexpr PIDRefSlopeECUTime_ClosedLoopModeValue() :
        value{-1}
    {}

    constexpr bool operator==(PIDRefSlopeECUTime_ClosedLoopModeValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(PIDRefSlopeECUTime_ClosedLoopModeValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case PIDRefSlopeECUTime_ClosedLoopModeValue::Position: return "Position";
            case PIDRefSlopeECUTime_ClosedLoopModeValue::Velocity: return "Velocity";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, PIDRefSlopeECUTime_ClosedLoopModeValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Assess the status of the motor output with respect to load and supply.
 * 
 * \details This routine can be used to determine the general status of motor
 *          commutation.
 */
struct MotorOutputStatusValue : public ISerializable {
    int value;

    /**
     * \brief The status of motor output could not be determined.
     */
    static constexpr int Unknown = 0;
    /**
     * \brief Motor output is disabled.
     */
    static constexpr int Off = 1;
    /**
     * \brief The motor is in neutral-brake.
     */
    static constexpr int StaticBraking = 2;
    /**
     * \brief The motor is loaded in a typical fashion, drawing current from the
     *        supply, and successfully turning the rotor in the direction of applied
     *        voltage.
     */
    static constexpr int Motoring = 3;
    /**
     * \brief The same as Motoring, except the rotor is being backdriven as the
     *        motor output is not enough to defeat load forces.
     */
    static constexpr int DiscordantMotoring = 4;
    /**
     * \brief The motor is braking in such a way where motor current is traveling
     *        back to the supply (typically a battery).
     */
    static constexpr int RegenBraking = 5;

    constexpr MotorOutputStatusValue(int value) :
        value{value}
    {}

    constexpr MotorOutputStatusValue() :
        value{-1}
    {}

    constexpr bool operator==(MotorOutputStatusValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(MotorOutputStatusValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case MotorOutputStatusValue::Unknown: return "Unknown";
            case MotorOutputStatusValue::Off: return "Off";
            case MotorOutputStatusValue::StaticBraking: return "StaticBraking";
            case MotorOutputStatusValue::Motoring: return "Motoring";
            case MotorOutputStatusValue::DiscordantMotoring: return "DiscordantMotoring";
            case MotorOutputStatusValue::RegenBraking: return "RegenBraking";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, MotorOutputStatusValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The active control mode of the differential controller.
 */
struct DifferentialControlModeValue : public ISerializable {
    int value;

    static constexpr int DisabledOutput = 0;
    static constexpr int NeutralOut = 1;
    static constexpr int StaticBrake = 2;
    static constexpr int DutyCycleOut = 3;
    static constexpr int PositionDutyCycle = 4;
    static constexpr int VelocityDutyCycle = 5;
    static constexpr int MotionMagicDutyCycle = 6;
    static constexpr int DutyCycleFOC = 7;
    static constexpr int PositionDutyCycleFOC = 8;
    static constexpr int VelocityDutyCycleFOC = 9;
    static constexpr int MotionMagicDutyCycleFOC = 10;
    static constexpr int VoltageOut = 11;
    static constexpr int PositionVoltage = 12;
    static constexpr int VelocityVoltage = 13;
    static constexpr int MotionMagicVoltage = 14;
    static constexpr int VoltageFOC = 15;
    static constexpr int PositionVoltageFOC = 16;
    static constexpr int VelocityVoltageFOC = 17;
    static constexpr int MotionMagicVoltageFOC = 18;
    static constexpr int TorqueCurrentFOC = 19;
    static constexpr int PositionTorqueCurrentFOC = 20;
    static constexpr int VelocityTorqueCurrentFOC = 21;
    static constexpr int MotionMagicTorqueCurrentFOC = 22;
    static constexpr int Follower = 23;
    static constexpr int Reserved = 24;
    static constexpr int CoastOut = 25;
    static constexpr int UnauthorizedDevice = 26;
    static constexpr int MusicTone = 27;
    static constexpr int MotionMagicVelocityDutyCycle = 28;
    static constexpr int MotionMagicVelocityDutyCycleFOC = 29;
    static constexpr int MotionMagicVelocityVoltage = 30;
    static constexpr int MotionMagicVelocityVoltageFOC = 31;
    static constexpr int MotionMagicVelocityTorqueCurrentFOC = 32;
    static constexpr int MotionMagicExpoDutyCycle = 33;
    static constexpr int MotionMagicExpoDutyCycleFOC = 34;
    static constexpr int MotionMagicExpoVoltage = 35;
    static constexpr int MotionMagicExpoVoltageFOC = 36;
    static constexpr int MotionMagicExpoTorqueCurrentFOC = 37;

    constexpr DifferentialControlModeValue(int value) :
        value{value}
    {}

    constexpr DifferentialControlModeValue() :
        value{-1}
    {}

    constexpr bool operator==(DifferentialControlModeValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(DifferentialControlModeValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case DifferentialControlModeValue::DisabledOutput: return "DisabledOutput";
            case DifferentialControlModeValue::NeutralOut: return "NeutralOut";
            case DifferentialControlModeValue::StaticBrake: return "StaticBrake";
            case DifferentialControlModeValue::DutyCycleOut: return "DutyCycleOut";
            case DifferentialControlModeValue::PositionDutyCycle: return "PositionDutyCycle";
            case DifferentialControlModeValue::VelocityDutyCycle: return "VelocityDutyCycle";
            case DifferentialControlModeValue::MotionMagicDutyCycle: return "MotionMagicDutyCycle";
            case DifferentialControlModeValue::DutyCycleFOC: return "DutyCycleFOC";
            case DifferentialControlModeValue::PositionDutyCycleFOC: return "PositionDutyCycleFOC";
            case DifferentialControlModeValue::VelocityDutyCycleFOC: return "VelocityDutyCycleFOC";
            case DifferentialControlModeValue::MotionMagicDutyCycleFOC: return "MotionMagicDutyCycleFOC";
            case DifferentialControlModeValue::VoltageOut: return "VoltageOut";
            case DifferentialControlModeValue::PositionVoltage: return "PositionVoltage";
            case DifferentialControlModeValue::VelocityVoltage: return "VelocityVoltage";
            case DifferentialControlModeValue::MotionMagicVoltage: return "MotionMagicVoltage";
            case DifferentialControlModeValue::VoltageFOC: return "VoltageFOC";
            case DifferentialControlModeValue::PositionVoltageFOC: return "PositionVoltageFOC";
            case DifferentialControlModeValue::VelocityVoltageFOC: return "VelocityVoltageFOC";
            case DifferentialControlModeValue::MotionMagicVoltageFOC: return "MotionMagicVoltageFOC";
            case DifferentialControlModeValue::TorqueCurrentFOC: return "TorqueCurrentFOC";
            case DifferentialControlModeValue::PositionTorqueCurrentFOC: return "PositionTorqueCurrentFOC";
            case DifferentialControlModeValue::VelocityTorqueCurrentFOC: return "VelocityTorqueCurrentFOC";
            case DifferentialControlModeValue::MotionMagicTorqueCurrentFOC: return "MotionMagicTorqueCurrentFOC";
            case DifferentialControlModeValue::Follower: return "Follower";
            case DifferentialControlModeValue::Reserved: return "Reserved";
            case DifferentialControlModeValue::CoastOut: return "CoastOut";
            case DifferentialControlModeValue::UnauthorizedDevice: return "UnauthorizedDevice";
            case DifferentialControlModeValue::MusicTone: return "MusicTone";
            case DifferentialControlModeValue::MotionMagicVelocityDutyCycle: return "MotionMagicVelocityDutyCycle";
            case DifferentialControlModeValue::MotionMagicVelocityDutyCycleFOC: return "MotionMagicVelocityDutyCycleFOC";
            case DifferentialControlModeValue::MotionMagicVelocityVoltage: return "MotionMagicVelocityVoltage";
            case DifferentialControlModeValue::MotionMagicVelocityVoltageFOC: return "MotionMagicVelocityVoltageFOC";
            case DifferentialControlModeValue::MotionMagicVelocityTorqueCurrentFOC: return "MotionMagicVelocityTorqueCurrentFOC";
            case DifferentialControlModeValue::MotionMagicExpoDutyCycle: return "MotionMagicExpoDutyCycle";
            case DifferentialControlModeValue::MotionMagicExpoDutyCycleFOC: return "MotionMagicExpoDutyCycleFOC";
            case DifferentialControlModeValue::MotionMagicExpoVoltage: return "MotionMagicExpoVoltage";
            case DifferentialControlModeValue::MotionMagicExpoVoltageFOC: return "MotionMagicExpoVoltageFOC";
            case DifferentialControlModeValue::MotionMagicExpoTorqueCurrentFOC: return "MotionMagicExpoTorqueCurrentFOC";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, DifferentialControlModeValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Whether the closed-loop is running on position or velocity.
 */
struct DiffPIDRefPIDErr_ClosedLoopModeValue : public ISerializable {
    int value;

    static constexpr int Position = 0;
    static constexpr int Velocity = 1;

    constexpr DiffPIDRefPIDErr_ClosedLoopModeValue(int value) :
        value{value}
    {}

    constexpr DiffPIDRefPIDErr_ClosedLoopModeValue() :
        value{-1}
    {}

    constexpr bool operator==(DiffPIDRefPIDErr_ClosedLoopModeValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(DiffPIDRefPIDErr_ClosedLoopModeValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case DiffPIDRefPIDErr_ClosedLoopModeValue::Position: return "Position";
            case DiffPIDRefPIDErr_ClosedLoopModeValue::Velocity: return "Velocity";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, DiffPIDRefPIDErr_ClosedLoopModeValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The output mode of the differential PID controller.
 */
struct DiffPIDOutput_PIDOutputModeValue : public ISerializable {
    int value;

    static constexpr int DutyCycle = 0;
    static constexpr int Voltage = 1;
    static constexpr int TorqueCurrentFOC = 2;

    constexpr DiffPIDOutput_PIDOutputModeValue(int value) :
        value{value}
    {}

    constexpr DiffPIDOutput_PIDOutputModeValue() :
        value{-1}
    {}

    constexpr bool operator==(DiffPIDOutput_PIDOutputModeValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(DiffPIDOutput_PIDOutputModeValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case DiffPIDOutput_PIDOutputModeValue::DutyCycle: return "DutyCycle";
            case DiffPIDOutput_PIDOutputModeValue::Voltage: return "Voltage";
            case DiffPIDOutput_PIDOutputModeValue::TorqueCurrentFOC: return "TorqueCurrentFOC";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, DiffPIDOutput_PIDOutputModeValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Whether the closed-loop is running on position or velocity.
 */
struct DiffPIDRefSlopeECUTime_ClosedLoopModeValue : public ISerializable {
    int value;

    static constexpr int Position = 0;
    static constexpr int Velocity = 1;

    constexpr DiffPIDRefSlopeECUTime_ClosedLoopModeValue(int value) :
        value{value}
    {}

    constexpr DiffPIDRefSlopeECUTime_ClosedLoopModeValue() :
        value{-1}
    {}

    constexpr bool operator==(DiffPIDRefSlopeECUTime_ClosedLoopModeValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(DiffPIDRefSlopeECUTime_ClosedLoopModeValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case DiffPIDRefSlopeECUTime_ClosedLoopModeValue::Position: return "Position";
            case DiffPIDRefSlopeECUTime_ClosedLoopModeValue::Velocity: return "Velocity";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, DiffPIDRefSlopeECUTime_ClosedLoopModeValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Gravity feedforward/feedback type.
 *        
 *        This determines the type of the gravity feedforward/feedback.
 *        
 *        Choose Elevator_Static for systems where the gravity feedforward is
 *        constant, such as an elevator. The gravity feedforward output will
 *        always have the same sign.
 *        
 *        Choose Arm_Cosine for systems where the gravity feedback is dependent
 *        on the angular position of the mechanism, such as an arm. The gravity
 *        feedback output will vary depending on the mechanism angular position.
 *        Note that the sensor offset and ratios must be configured so that the
 *        sensor reports a position of 0 when the mechanism is horizonal
 *        (parallel to the ground), and the reported sensor position is 1:1 with
 *        the mechanism.
 */
struct GravityTypeValue : public ISerializable {
    int value;

    /**
     * \brief The system's gravity feedforward is constant, such as an elevator. The
     *        gravity feedforward output will always have the same sign.
     */
    static constexpr int Elevator_Static = 0;
    /**
     * \brief The system's gravity feedback is dependent on the angular position of
     *        the mechanism, such as an arm. The gravity feedback output will vary
     *        depending on the mechanism angular position. Note that the sensor
     *        offset and ratios must be configured so that the sensor reports a
     *        position of 0 when the mechanism is horizonal (parallel to the
     *        ground), and the reported sensor position is 1:1 with the mechanism.
     */
    static constexpr int Arm_Cosine = 1;

    constexpr GravityTypeValue(int value) :
        value{value}
    {}

    constexpr GravityTypeValue() :
        value{-1}
    {}

    constexpr bool operator==(GravityTypeValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(GravityTypeValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case GravityTypeValue::Elevator_Static: return "Elevator_Static";
            case GravityTypeValue::Arm_Cosine: return "Arm_Cosine";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, GravityTypeValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Invert state of the device as seen from the front of the motor.
 */
struct InvertedValue : public ISerializable {
    int value;

    /**
     * \brief Positive motor output results in counter-clockwise motion.
     */
    static constexpr int CounterClockwise_Positive = 0;
    /**
     * \brief Positive motor output results in clockwise motion.
     */
    static constexpr int Clockwise_Positive = 1;

    constexpr InvertedValue(int value) :
        value{value}
    {}

    constexpr InvertedValue() :
        value{-1}
    {}

    constexpr bool operator==(InvertedValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(InvertedValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case InvertedValue::CounterClockwise_Positive: return "CounterClockwise_Positive";
            case InvertedValue::Clockwise_Positive: return "Clockwise_Positive";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, InvertedValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The state of the motor controller bridge when output is neutral or
 *        disabled.
 */
struct NeutralModeValue : public ISerializable {
    int value;

    static constexpr int Coast = 0;
    static constexpr int Brake = 1;

    constexpr NeutralModeValue(int value) :
        value{value}
    {}

    constexpr NeutralModeValue() :
        value{-1}
    {}

    constexpr bool operator==(NeutralModeValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(NeutralModeValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case NeutralModeValue::Coast: return "Coast";
            case NeutralModeValue::Brake: return "Brake";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, NeutralModeValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Choose what sensor source is reported via API and used by closed-loop
 *        and limit features.  The default is RotorSensor, which uses the
 *        internal rotor sensor in the Talon.
 *        
 *        Choose Remote* to use another sensor on the same CAN bus (this also
 *        requires setting FeedbackRemoteSensorID).  Talon will update its
 *        position and velocity whenever the remote sensor publishes its
 *        information on CAN bus, and the Talon internal rotor will not be used.
 *        
 *        Choose Fused* (requires Phoenix Pro) and Talon will fuse another
 *        sensor's information with the internal rotor, which provides the best
 *        possible position and velocity for accuracy and bandwidth (this also
 *        requires setting FeedbackRemoteSensorID).  This was developed for
 *        applications such as swerve-azimuth.
 *        
 *        Choose Sync* (requires Phoenix Pro) and Talon will synchronize its
 *        internal rotor position against another sensor, then continue to use
 *        the rotor sensor for closed loop control (this also requires setting
 *        FeedbackRemoteSensorID).  The Talon will report if its internal
 *        position differs significantly from the reported remote sensor
 *        position.  This was developed for mechanisms where there is a risk of
 *        the sensor failing in such a way that it reports a position that does
 *        not match the mechanism, such as the sensor mounting assembly breaking
 *        off.
 *        
 *        Choose RemotePigeon2Yaw, RemotePigeon2Pitch, and RemotePigeon2Roll to
 *        use another Pigeon2 on the same CAN bus (this also requires setting
 *        FeedbackRemoteSensorID).  Talon will update its position to match the
 *        selected value whenever Pigeon2 publishes its information on CAN bus.
 *        Note that the Talon position will be in rotations and not degrees.
 * 
 * \details Note: When the feedback source is changed to Fused* or Sync*, the
 *          Talon needs a period of time to fuse before sensor-based
 *          (soft-limit, closed loop, etc.) features are used. This period of
 *          time is determined by the update frequency of the remote sensor's
 *          Position signal.
 */
struct FeedbackSensorSourceValue : public ISerializable {
    int value;

    /**
     * \brief Use the internal rotor sensor in the Talon.
     */
    static constexpr int RotorSensor = 0;
    /**
     * \brief Use another CANcoder on the same CAN bus (this also requires setting
     *        FeedbackRemoteSensorID).  Talon will update its position and velocity
     *        whenever CANcoder publishes its information on CAN bus, and the Talon
     *        internal rotor will not be used.
     */
    static constexpr int RemoteCANcoder = 1;
    /**
     * \brief Use another Pigeon2 on the same CAN bus (this also requires setting
     *        FeedbackRemoteSensorID).  Talon will update its position to match the
     *        Pigeon2 yaw whenever Pigeon2 publishes its information on CAN bus.
     *        Note that the Talon position will be in rotations and not degrees.
     */
    static constexpr int RemotePigeon2Yaw = 2;
    /**
     * \brief Use another Pigeon2 on the same CAN bus (this also requires setting
     *        FeedbackRemoteSensorID).  Talon will update its position to match the
     *        Pigeon2 pitch whenever Pigeon2 publishes its information on CAN bus.
     *        Note that the Talon position will be in rotations and not degrees.
     */
    static constexpr int RemotePigeon2Pitch = 3;
    /**
     * \brief Use another Pigeon2 on the same CAN bus (this also requires setting
     *        FeedbackRemoteSensorID).  Talon will update its position to match the
     *        Pigeon2 roll whenever Pigeon2 publishes its information on CAN bus.
     *        Note that the Talon position will be in rotations and not degrees.
     */
    static constexpr int RemotePigeon2Roll = 4;
    /**
     * \brief Requires Phoenix Pro; Talon will fuse another CANcoder's information
     *        with the internal rotor, which provides the best possible position and
     *        velocity for accuracy and bandwidth (this also requires setting
     *        FeedbackRemoteSensorID).  FusedCANcoder was developed for applications
     *        such as swerve-azimuth.
     */
    static constexpr int FusedCANcoder = 5;
    /**
     * \brief Requires Phoenix Pro; Talon will synchronize its internal rotor
     *        position against another CANcoder, then continue to use the rotor
     *        sensor for closed loop control (this also requires setting
     *        FeedbackRemoteSensorID).  The Talon will report if its internal
     *        position differs significantly from the reported CANcoder position. 
     *        SyncCANcoder was developed for mechanisms where there is a risk of the
     *        CANcoder failing in such a way that it reports a position that does
     *        not match the mechanism, such as the sensor mounting assembly breaking
     *        off.
     */
    static constexpr int SyncCANcoder = 6;
    /**
     * \brief Use a pulse-width encoder remotely attached to the Sensor Input 1
     *        (S1IN) on the CTR Electronics' CANdi™ (this also requires setting
     *        FeedbackRemoteSensorID). Talon will update its position and velocity
     *        whenever the CTR Electronics' CANdi™ publishes its information on CAN
     *        bus, and the Talon internal rotor will not be used.
     */
    static constexpr int RemoteCANdiPWM1 = 9;
    /**
     * \brief Use a pulse-width encoder remotely attached to the Sensor Input 2
     *        (S2IN) on the CTR Electronics' CANdi™ (this also requires setting
     *        FeedbackRemoteSensorID). Talon will update its position and velocity
     *        whenever the CTR Electronics' CANdi™ publishes its information on CAN
     *        bus, and the Talon internal rotor will not be used.
     */
    static constexpr int RemoteCANdiPWM2 = 10;
    /**
     * \brief Use a quadrature encoder remotely attached to the two Sensor Inputs on
     *        the CTR Electronics' CANdi™ (this also requires setting
     *        FeedbackRemoteSensorID). Talon will update its position and velocity
     *        whenever the CTR Electronics' CANdi™ publishes its information on CAN
     *        bus, and the Talon internal rotor will not be used.
     */
    static constexpr int RemoteCANdiQuadrature = 11;
    /**
     * \brief Requires Phoenix Pro; Talon will fuse a pulse-width encoder remotely
     *        attached to the Sensor Input 1 (S1IN) on the CTR Electronics' CANdi™,
     *        which provides the best possible position and velocity for accuracy
     *        and bandwidth (this also requires setting FeedbackRemoteSensorID). 
     *        FusedCANdi was developed for applications such as swerve-azimuth.
     */
    static constexpr int FusedCANdiPWM1 = 12;
    /**
     * \brief Requires Phoenix Pro; Talon will fuse a pulse-width encoder remotely
     *        attached to the Sensor Input 2 (S2IN) on the CTR Electronics' CANdi™,
     *        which provides the best possible position and velocity for accuracy
     *        and bandwidth (this also requires setting FeedbackRemoteSensorID). 
     *        FusedCANdi was developed for applications such as swerve-azimuth.
     */
    static constexpr int FusedCANdiPWM2 = 13;
    /**
     * \brief Requires Phoenix Pro; Talon will fuse a qaudrature encoder remotely
     *        attached to the two Sensor Inputs on the CTR Electronics' CANdi™. This
     *        provides velocity and relative position measurements. This also
     *        requires setting FeedbackRemoteSensorID.
     */
    static constexpr int FusedCANdiQuadrature = 14;
    /**
     * \brief Requires Phoenix Pro; Talon will synchronize its internal rotor
     *        position against the pulse-width encoder attached to Sensor Input 1
     *        (S1IN), then continue to use the rotor sensor for closed loop control
     *        (this also requires setting FeedbackRemoteSensorID).  The Talon will
     *        report if its internal position differs significantly from the
     *        reported PWM position.  SyncCANdi was developed for mechanisms where
     *        there is a risk of the CTR Electronics' CANdi™ failing in such a way
     *        that it reports a position that does not match the mechanism, such as
     *        the sensor mounting assembly breaking off.
     */
    static constexpr int SyncCANdiPWM1 = 15;
    /**
     * \brief Requires Phoenix Pro; Talon will synchronize its internal rotor
     *        position against the pulse-width encoder attached to Sensor Input 1
     *        (S1IN), then continue to use the rotor sensor for closed loop control
     *        (this also requires setting FeedbackRemoteSensorID).  The Talon will
     *        report if its internal position differs significantly from the
     *        reported PWM position.  SyncCANdi was developed for mechanisms where
     *        there is a risk of the CTR Electronics' CANdi™ failing in such a way
     *        that it reports a position that does not match the mechanism, such as
     *        the sensor mounting assembly breaking off.
     */
    static constexpr int SyncCANdiPWM2 = 16;

    constexpr FeedbackSensorSourceValue(int value) :
        value{value}
    {}

    constexpr FeedbackSensorSourceValue() :
        value{-1}
    {}

    constexpr bool operator==(FeedbackSensorSourceValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(FeedbackSensorSourceValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case FeedbackSensorSourceValue::RotorSensor: return "RotorSensor";
            case FeedbackSensorSourceValue::RemoteCANcoder: return "RemoteCANcoder";
            case FeedbackSensorSourceValue::RemotePigeon2Yaw: return "RemotePigeon2Yaw";
            case FeedbackSensorSourceValue::RemotePigeon2Pitch: return "RemotePigeon2Pitch";
            case FeedbackSensorSourceValue::RemotePigeon2Roll: return "RemotePigeon2Roll";
            case FeedbackSensorSourceValue::FusedCANcoder: return "FusedCANcoder";
            case FeedbackSensorSourceValue::SyncCANcoder: return "SyncCANcoder";
            case FeedbackSensorSourceValue::RemoteCANdiPWM1: return "RemoteCANdiPWM1";
            case FeedbackSensorSourceValue::RemoteCANdiPWM2: return "RemoteCANdiPWM2";
            case FeedbackSensorSourceValue::RemoteCANdiQuadrature: return "RemoteCANdiQuadrature";
            case FeedbackSensorSourceValue::FusedCANdiPWM1: return "FusedCANdiPWM1";
            case FeedbackSensorSourceValue::FusedCANdiPWM2: return "FusedCANdiPWM2";
            case FeedbackSensorSourceValue::FusedCANdiQuadrature: return "FusedCANdiQuadrature";
            case FeedbackSensorSourceValue::SyncCANdiPWM1: return "SyncCANdiPWM1";
            case FeedbackSensorSourceValue::SyncCANdiPWM2: return "SyncCANdiPWM2";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, FeedbackSensorSourceValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Determines if the forward limit switch is normally-open (default) or
 *        normally-closed.
 */
struct ForwardLimitTypeValue : public ISerializable {
    int value;

    static constexpr int NormallyOpen = 0;
    static constexpr int NormallyClosed = 1;

    constexpr ForwardLimitTypeValue(int value) :
        value{value}
    {}

    constexpr ForwardLimitTypeValue() :
        value{-1}
    {}

    constexpr bool operator==(ForwardLimitTypeValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(ForwardLimitTypeValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case ForwardLimitTypeValue::NormallyOpen: return "NormallyOpen";
            case ForwardLimitTypeValue::NormallyClosed: return "NormallyClosed";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, ForwardLimitTypeValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Determines where to poll the forward limit switch.  This defaults to
 *        the forward limit switch pin on the limit switch connector.
 *        
 *        Choose RemoteTalonFX to use the forward limit switch attached to
 *        another Talon FX on the same CAN bus (this also requires setting
 *        ForwardLimitRemoteSensorID).
 *        
 *        Choose RemoteCANifier to use the forward limit switch attached to
 *        another CANifier on the same CAN bus (this also requires setting
 *        ForwardLimitRemoteSensorID).
 *        
 *        Choose RemoteCANcoder to use another CANcoder on the same CAN bus
 *        (this also requires setting ForwardLimitRemoteSensorID).  The forward
 *        limit will assert when the CANcoder magnet strength changes from BAD
 *        (red) to ADEQUATE (orange) or GOOD (green).
 */
struct ForwardLimitSourceValue : public ISerializable {
    int value;

    /**
     * \brief Use the forward limit switch pin on the limit switch connector.
     */
    static constexpr int LimitSwitchPin = 0;
    /**
     * \brief Use the forward limit switch attached to another Talon FX on the same
     *        CAN bus (this also requires setting ForwardLimitRemoteSensorID).
     */
    static constexpr int RemoteTalonFX = 1;
    /**
     * \brief Use the forward limit switch attached to another CANifier on the same
     *        CAN bus (this also requires setting ForwardLimitRemoteSensorID).
     */
    static constexpr int RemoteCANifier = 2;
    /**
     * \brief Use another CANcoder on the same CAN bus (this also requires setting
     *        ForwardLimitRemoteSensorID).  The forward limit will assert when the
     *        CANcoder magnet strength changes from BAD (red) to ADEQUATE (orange)
     *        or GOOD (green).
     */
    static constexpr int RemoteCANcoder = 4;
    /**
     * \brief Use another CANrange on the same CAN bus (this also requires setting
     *        ForwardLimitRemoteSensorID).  The forward limit will assert when the
     *        CANrange proximity detect is tripped.
     */
    static constexpr int RemoteCANrange = 6;
    /**
     * \brief Use another CTR Electronics' CANdi™ on the same CAN bus (this also
     *        requires setting ForwardLimitRemoteSensorID).  The forward limit will
     *        assert when the CTR Electronics' CANdi™ Signal 1 Input (S1IN) pin
     *        matches the configured closed state.
     */
    static constexpr int RemoteCANdiS1 = 7;
    /**
     * \brief Use another CTR Electronics' CANdi™ on the same CAN bus (this also
     *        requires setting ForwardLimitRemoteSensorID).  The forward limit will
     *        assert when the CTR Electronics' CANdi™ Signal 2 Input (S2IN) pin
     *        matches the configured closed state.
     */
    static constexpr int RemoteCANdiS2 = 8;
    /**
     * \brief Disable the forward limit switch.
     */
    static constexpr int Disabled = 3;

    constexpr ForwardLimitSourceValue(int value) :
        value{value}
    {}

    constexpr ForwardLimitSourceValue() :
        value{-1}
    {}

    constexpr bool operator==(ForwardLimitSourceValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(ForwardLimitSourceValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case ForwardLimitSourceValue::LimitSwitchPin: return "LimitSwitchPin";
            case ForwardLimitSourceValue::RemoteTalonFX: return "RemoteTalonFX";
            case ForwardLimitSourceValue::RemoteCANifier: return "RemoteCANifier";
            case ForwardLimitSourceValue::RemoteCANcoder: return "RemoteCANcoder";
            case ForwardLimitSourceValue::RemoteCANrange: return "RemoteCANrange";
            case ForwardLimitSourceValue::RemoteCANdiS1: return "RemoteCANdiS1";
            case ForwardLimitSourceValue::RemoteCANdiS2: return "RemoteCANdiS2";
            case ForwardLimitSourceValue::Disabled: return "Disabled";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, ForwardLimitSourceValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Determines if the reverse limit switch is normally-open (default) or
 *        normally-closed.
 */
struct ReverseLimitTypeValue : public ISerializable {
    int value;

    static constexpr int NormallyOpen = 0;
    static constexpr int NormallyClosed = 1;

    constexpr ReverseLimitTypeValue(int value) :
        value{value}
    {}

    constexpr ReverseLimitTypeValue() :
        value{-1}
    {}

    constexpr bool operator==(ReverseLimitTypeValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(ReverseLimitTypeValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case ReverseLimitTypeValue::NormallyOpen: return "NormallyOpen";
            case ReverseLimitTypeValue::NormallyClosed: return "NormallyClosed";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, ReverseLimitTypeValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Determines where to poll the reverse limit switch.  This defaults to
 *        the reverse limit switch pin on the limit switch connector.
 *        
 *        Choose RemoteTalonFX to use the reverse limit switch attached to
 *        another Talon FX on the same CAN bus (this also requires setting
 *        ReverseLimitRemoteSensorID).
 *        
 *        Choose RemoteCANifier to use the reverse limit switch attached to
 *        another CANifier on the same CAN bus (this also requires setting
 *        ReverseLimitRemoteSensorID).
 *        
 *        Choose RemoteCANcoder to use another CANcoder on the same CAN bus
 *        (this also requires setting ReverseLimitRemoteSensorID).  The reverse
 *        limit will assert when the CANcoder magnet strength changes from BAD
 *        (red) to ADEQUATE (orange) or GOOD (green).
 */
struct ReverseLimitSourceValue : public ISerializable {
    int value;

    /**
     * \brief Use the reverse limit switch pin on the limit switch connector.
     */
    static constexpr int LimitSwitchPin = 0;
    /**
     * \brief Use the reverse limit switch attached to another Talon FX on the same
     *        CAN bus (this also requires setting ReverseLimitRemoteSensorID).
     */
    static constexpr int RemoteTalonFX = 1;
    /**
     * \brief Use the reverse limit switch attached to another CANifier on the same
     *        CAN bus (this also requires setting ReverseLimitRemoteSensorID).
     */
    static constexpr int RemoteCANifier = 2;
    /**
     * \brief Use another CANcoder on the same CAN bus (this also requires setting
     *        ReverseLimitRemoteSensorID).  The reverse limit will assert when the
     *        CANcoder magnet strength changes from BAD (red) to ADEQUATE (orange)
     *        or GOOD (green).
     */
    static constexpr int RemoteCANcoder = 4;
    /**
     * \brief Use another CANrange on the same CAN bus (this also requires setting
     *        ReverseLimitRemoteSensorID).  The reverse limit will assert when the
     *        CANrange proximity detect is tripped.
     */
    static constexpr int RemoteCANrange = 6;
    /**
     * \brief Use another CTR Electronics' CANdi™ on the same CAN bus (this also
     *        requires setting ForwardLimitRemoteSensorID).  The forward limit will
     *        assert when the CTR Electronics' CANdi™ Signal 1 Input (S1IN) pin
     *        matches the configured closed state.
     */
    static constexpr int RemoteCANdiS1 = 7;
    /**
     * \brief Use another CTR Electronics' CANdi™ on the same CAN bus (this also
     *        requires setting ForwardLimitRemoteSensorID).  The forward limit will
     *        assert when CANdi™ Signal 2 Input (S2IN) pin matches the configured
     *        closed state.
     */
    static constexpr int RemoteCANdiS2 = 8;
    /**
     * \brief Disable the reverse limit switch.
     */
    static constexpr int Disabled = 3;

    constexpr ReverseLimitSourceValue(int value) :
        value{value}
    {}

    constexpr ReverseLimitSourceValue() :
        value{-1}
    {}

    constexpr bool operator==(ReverseLimitSourceValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(ReverseLimitSourceValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case ReverseLimitSourceValue::LimitSwitchPin: return "LimitSwitchPin";
            case ReverseLimitSourceValue::RemoteTalonFX: return "RemoteTalonFX";
            case ReverseLimitSourceValue::RemoteCANifier: return "RemoteCANifier";
            case ReverseLimitSourceValue::RemoteCANcoder: return "RemoteCANcoder";
            case ReverseLimitSourceValue::RemoteCANrange: return "RemoteCANrange";
            case ReverseLimitSourceValue::RemoteCANdiS1: return "RemoteCANdiS1";
            case ReverseLimitSourceValue::RemoteCANdiS2: return "RemoteCANdiS2";
            case ReverseLimitSourceValue::Disabled: return "Disabled";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, ReverseLimitSourceValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Magnet health as measured by CANcoder.
 *        
 *        Red indicates too close or too far, Orange is adequate but with
 *        reduced accuracy, green is ideal. Invalid means the accuracy cannot be
 *        determined.
 */
struct MagnetHealthValue : public ISerializable {
    int value;

    /**
     * \brief The magnet is too close or too far from the CANcoder.
     */
    static constexpr int Magnet_Red = 1;
    /**
     * \brief Magnet health is adequate but with reduced accuracy.
     */
    static constexpr int Magnet_Orange = 2;
    /**
     * \brief Magnet health is ideal.
     */
    static constexpr int Magnet_Green = 3;
    /**
     * \brief The accuracy cannot be determined.
     */
    static constexpr int Magnet_Invalid = 0;

    constexpr MagnetHealthValue(int value) :
        value{value}
    {}

    constexpr MagnetHealthValue() :
        value{-1}
    {}

    constexpr bool operator==(MagnetHealthValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(MagnetHealthValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case MagnetHealthValue::Magnet_Red: return "Magnet_Red";
            case MagnetHealthValue::Magnet_Orange: return "Magnet_Orange";
            case MagnetHealthValue::Magnet_Green: return "Magnet_Green";
            case MagnetHealthValue::Magnet_Invalid: return "Magnet_Invalid";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, MagnetHealthValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The applied output of the bridge.
 */
struct BridgeOutputValue : public ISerializable {
    int value;

    static constexpr int BridgeReq_Coast = 0;
    static constexpr int BridgeReq_Brake = 1;
    static constexpr int BridgeReq_Trapez = 6;
    static constexpr int BridgeReq_FOCTorque = 7;
    static constexpr int BridgeReq_MusicTone = 8;
    static constexpr int BridgeReq_FOCEasy = 9;
    static constexpr int BridgeReq_FaultBrake = 12;
    static constexpr int BridgeReq_FaultCoast = 13;
    static constexpr int BridgeReq_ActiveBrake = 14;
    static constexpr int BridgeReq_VariableBrake = 15;

    constexpr BridgeOutputValue(int value) :
        value{value}
    {}

    constexpr BridgeOutputValue() :
        value{-1}
    {}

    constexpr bool operator==(BridgeOutputValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(BridgeOutputValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case BridgeOutputValue::BridgeReq_Coast: return "BridgeReq_Coast";
            case BridgeOutputValue::BridgeReq_Brake: return "BridgeReq_Brake";
            case BridgeOutputValue::BridgeReq_Trapez: return "BridgeReq_Trapez";
            case BridgeOutputValue::BridgeReq_FOCTorque: return "BridgeReq_FOCTorque";
            case BridgeOutputValue::BridgeReq_MusicTone: return "BridgeReq_MusicTone";
            case BridgeOutputValue::BridgeReq_FOCEasy: return "BridgeReq_FOCEasy";
            case BridgeOutputValue::BridgeReq_FaultBrake: return "BridgeReq_FaultBrake";
            case BridgeOutputValue::BridgeReq_FaultCoast: return "BridgeReq_FaultCoast";
            case BridgeOutputValue::BridgeReq_ActiveBrake: return "BridgeReq_ActiveBrake";
            case BridgeOutputValue::BridgeReq_VariableBrake: return "BridgeReq_VariableBrake";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, BridgeOutputValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Choose what sensor source is used for differential control of a
 *        mechanism.  The default is Disabled.  All other options require
 *        setting the DifferentialTalonFXSensorID, as the average of this Talon
 *        FX's sensor and the remote TalonFX's sensor is used for the
 *        differential controller's primary targets.
 *        
 *        Choose RemoteTalonFX_HalfDiff to use another TalonFX on the same CAN
 *        bus.  Talon FX will update its differential position and velocity
 *        whenever the remote TalonFX publishes its information on CAN bus.  The
 *        differential controller will use half of the difference between this
 *        TalonFX's sensor and the remote Talon FX's sensor for the differential
 *        component of the output.
 *        
 *        Choose RemotePigeon2Yaw, RemotePigeon2Pitch, and RemotePigeon2Roll to
 *        use another Pigeon2 on the same CAN bus (this also requires setting
 *        DifferentialRemoteSensorID).  Talon FX will update its differential
 *        position to match the selected value whenever Pigeon2 publishes its
 *        information on CAN bus. Note that the Talon FX differential position
 *        will be in rotations and not degrees.
 *        
 *        Choose RemoteCANcoder to use another CANcoder on the same CAN bus
 *        (this also requires setting DifferentialRemoteSensorID).  Talon FX
 *        will update its differential position and velocity to match the
 *        CANcoder whenever CANcoder publishes its information on CAN bus.
 */
struct DifferentialSensorSourceValue : public ISerializable {
    int value;

    /**
     * \brief Disable differential control.
     */
    static constexpr int Disabled = 0;
    /**
     * \brief Use another TalonFX on the same CAN bus.  Talon FX will update its
     *        differential position and velocity whenever the remote TalonFX
     *        publishes its information on CAN bus.  The differential controller
     *        will use half of the difference between this TalonFX's sensor and the
     *        remote Talon FX's sensor for the differential component of the output.
     */
    static constexpr int RemoteTalonFX_HalfDiff = 1;
    /**
     * \brief Use another Pigeon2 on the same CAN bus (this also requires setting
     *        DifferentialRemoteSensorID).  Talon FX will update its differential
     *        position to match the Pigeon2 yaw whenever Pigeon2 publishes its
     *        information on CAN bus. Note that the Talon FX differential position
     *        will be in rotations and not degrees.
     */
    static constexpr int RemotePigeon2Yaw = 2;
    /**
     * \brief Use another Pigeon2 on the same CAN bus (this also requires setting
     *        DifferentialRemoteSensorID).  Talon FX will update its differential
     *        position to match the Pigeon2 pitch whenever Pigeon2 publishes its
     *        information on CAN bus. Note that the Talon FX differential position
     *        will be in rotations and not degrees.
     */
    static constexpr int RemotePigeon2Pitch = 3;
    /**
     * \brief Use another Pigeon2 on the same CAN bus (this also requires setting
     *        DifferentialRemoteSensorID).  Talon FX will update its differential
     *        position to match the Pigeon2 roll whenever Pigeon2 publishes its
     *        information on CAN bus. Note that the Talon FX differential position
     *        will be in rotations and not degrees.
     */
    static constexpr int RemotePigeon2Roll = 4;
    /**
     * \brief Use another CANcoder on the same CAN bus (this also requires setting
     *        DifferentialRemoteSensorID).  Talon FX will update its differential
     *        position and velocity to match the CANcoder whenever CANcoder
     *        publishes its information on CAN bus.
     */
    static constexpr int RemoteCANcoder = 5;
    /**
     * \brief Use a pulse-width encoder remotely attached to the Sensor Input 1
     *        (S1IN) on the CTR Electronics' CANdi™ (this also requires setting the
     *        DifferentialRemoteSensorID).  Talon FX will update its differential
     *        position and velocity to match the CTR Electronics' CANdi™ whenever
     *        the CTR Electronics' CANdi™ publishes its information on CAN bus.
     */
    static constexpr int RemoteCANdiPWM1 = 6;
    /**
     * \brief Use a pulse-width encoder remotely attached to the Sensor Input 2
     *        (S2IN) on the CTR Electronics' CANdi™ (this also requires setting the
     *        DifferentialRemoteSensorID).  Talon FX will update its differential
     *        position and velocity to match the CTR Electronics' CANdi™ whenever
     *        the CTR Electronics' CANdi™ publishes its information on CAN bus.
     */
    static constexpr int RemoteCANdiPWM2 = 7;
    /**
     * \brief Use a quadrature encoder remotely attached to the two Sensor Inputs on
     *        the CTR Electronics' CANdi™ (this also requires setting the
     *        DifferentialRemoteSensorID).  Talon FX will update its differential
     *        position and velocity to match the CTR Electronics' CANdi™ whenever
     *        the CTR Electronics' CANdi™ publishes its information on CAN bus.
     */
    static constexpr int RemoteCANdiQuadrature = 8;

    constexpr DifferentialSensorSourceValue(int value) :
        value{value}
    {}

    constexpr DifferentialSensorSourceValue() :
        value{-1}
    {}

    constexpr bool operator==(DifferentialSensorSourceValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(DifferentialSensorSourceValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case DifferentialSensorSourceValue::Disabled: return "Disabled";
            case DifferentialSensorSourceValue::RemoteTalonFX_HalfDiff: return "RemoteTalonFX_HalfDiff";
            case DifferentialSensorSourceValue::RemotePigeon2Yaw: return "RemotePigeon2Yaw";
            case DifferentialSensorSourceValue::RemotePigeon2Pitch: return "RemotePigeon2Pitch";
            case DifferentialSensorSourceValue::RemotePigeon2Roll: return "RemotePigeon2Roll";
            case DifferentialSensorSourceValue::RemoteCANcoder: return "RemoteCANcoder";
            case DifferentialSensorSourceValue::RemoteCANdiPWM1: return "RemoteCANdiPWM1";
            case DifferentialSensorSourceValue::RemoteCANdiPWM2: return "RemoteCANdiPWM2";
            case DifferentialSensorSourceValue::RemoteCANdiQuadrature: return "RemoteCANdiQuadrature";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, DifferentialSensorSourceValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Static feedforward sign during position closed loop.
 *        
 *        This determines the sign of the applied kS during position closed-loop
 *        modes. The default behavior uses the velocity reference sign. This
 *        works well with velocity closed loop, Motion Magic® controls, and
 *        position closed loop when velocity reference is specified (motion
 *        profiling).
 *        
 *        However, when using position closed loop with zero velocity reference
 *        (no motion profiling), the application may want to apply static
 *        feedforward based on the sign of closed loop error instead. When doing
 *        so, we recommend using the minimal amount of kS, otherwise the motor
 *        output may dither when closed loop error is near zero.
 */
struct StaticFeedforwardSignValue : public ISerializable {
    int value;

    /**
     * \brief Use the velocity reference sign. This works well with velocity closed
     *        loop, Motion Magic® controls, and position closed loop when velocity
     *        reference is specified (motion profiling).
     */
    static constexpr int UseVelocitySign = 0;
    /**
     * \brief Use the sign of closed loop error. This is useful when using position
     *        closed loop with zero velocity reference (no motion profiling). We
     *        recommend the minimal amount of kS, otherwise the motor output may
     *        dither when closed loop error is near zero.
     */
    static constexpr int UseClosedLoopSign = 1;

    constexpr StaticFeedforwardSignValue(int value) :
        value{value}
    {}

    constexpr StaticFeedforwardSignValue() :
        value{-1}
    {}

    constexpr bool operator==(StaticFeedforwardSignValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(StaticFeedforwardSignValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case StaticFeedforwardSignValue::UseVelocitySign: return "UseVelocitySign";
            case StaticFeedforwardSignValue::UseClosedLoopSign: return "UseClosedLoopSign";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, StaticFeedforwardSignValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The type of motor attached to the Talon.
 * 
 * \details This can be used to determine what motor is attached to the Talon
 *          FX.  Return will be "Unknown" if firmware is too old or device is
 *          not present.
 */
struct ConnectedMotorValue : public ISerializable {
    int value;

    /**
     * \brief Talon could not determine the type of motor attached.
     */
    static constexpr int Unknown = 0;
    /**
     * \brief Talon is attached to an integrated Falcon motor.
     */
    static constexpr int Falcon500_Integrated = 1;
    /**
     * \brief Talon is attached to an integrated Kraken X60 motor.
     */
    static constexpr int KrakenX60_Integrated = 2;
    /**
     * \brief Talon is attached to an integrated Kraken X44 motor.
     */
    static constexpr int KrakenX44_Integrated = 3;
    /**
     * \brief Talon is connected to a CTR Electronics Minion® brushless three phase
     *        motor.
     */
    static constexpr int Minion_JST = 4;
    /**
     * \brief Talon is connected to a third party brushed DC motor with leads A and
     *        B.
     */
    static constexpr int Brushed_AB = 5;
    /**
     * \brief Talon is connected to a third party brushed DC motor with leads A and
     *        C.
     */
    static constexpr int Brushed_AC = 6;
    /**
     * \brief Talon is connected to a third party brushed DC motor with leads B and
     *        C.
     */
    static constexpr int Brushed_BC = 7;
    /**
     * \brief Talon is connected to a third party NEO brushless three phase motor.
     */
    static constexpr int NEO_JST = 8;
    /**
     * \brief Talon is connected to a third party NEO550 brushless three phase
     *        motor.
     */
    static constexpr int NEO550_JST = 9;
    /**
     * \brief Talon is connected to a third party VORTEX brushless three phase
     *        motor.
     */
    static constexpr int VORTEX_JST = 10;
    /**
     * \brief Talon is connected to a custom brushless three phase motor. This
     *        requires that the device is not FRC-Locked.
     */
    static constexpr int CustomBrushless = 11;

    constexpr ConnectedMotorValue(int value) :
        value{value}
    {}

    constexpr ConnectedMotorValue() :
        value{-1}
    {}

    constexpr bool operator==(ConnectedMotorValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(ConnectedMotorValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case ConnectedMotorValue::Unknown: return "Unknown";
            case ConnectedMotorValue::Falcon500_Integrated: return "Falcon500_Integrated";
            case ConnectedMotorValue::KrakenX60_Integrated: return "KrakenX60_Integrated";
            case ConnectedMotorValue::KrakenX44_Integrated: return "KrakenX44_Integrated";
            case ConnectedMotorValue::Minion_JST: return "Minion_JST";
            case ConnectedMotorValue::Brushed_AB: return "Brushed_AB";
            case ConnectedMotorValue::Brushed_AC: return "Brushed_AC";
            case ConnectedMotorValue::Brushed_BC: return "Brushed_BC";
            case ConnectedMotorValue::NEO_JST: return "NEO_JST";
            case ConnectedMotorValue::NEO550_JST: return "NEO550_JST";
            case ConnectedMotorValue::VORTEX_JST: return "VORTEX_JST";
            case ConnectedMotorValue::CustomBrushless: return "Custom Brushless";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, ConnectedMotorValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Health of the distance measurement.
 */
struct MeasurementHealthValue : public ISerializable {
    int value;

    /**
     * \brief Measurement is good.
     */
    static constexpr int Good = 0;
    /**
     * \brief Measurement is likely okay, but the target is either very far away or
     *        moving very quickly.
     */
    static constexpr int Limited = 1;
    /**
     * \brief Measurement is compromised.
     */
    static constexpr int Bad = 2;

    constexpr MeasurementHealthValue(int value) :
        value{value}
    {}

    constexpr MeasurementHealthValue() :
        value{-1}
    {}

    constexpr bool operator==(MeasurementHealthValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(MeasurementHealthValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case MeasurementHealthValue::Good: return "Good";
            case MeasurementHealthValue::Limited: return "Limited";
            case MeasurementHealthValue::Bad: return "Bad";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, MeasurementHealthValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Update mode of the CANrange. The CANrange supports short-range and
 *        long-range detection at various update frequencies.
 */
struct UpdateModeValue : public ISerializable {
    int value;

    /**
     * \brief Updates distance/proximity at 100hz using short-range detection mode.
     */
    static constexpr int ShortRange100Hz = 0;
    /**
     * \brief Uses short-range detection mode for improved detection under high
     *        ambient infrared light conditions. Uses user-specified update
     *        frequency.
     */
    static constexpr int ShortRangeUserFreq = 1;
    /**
     * \brief Uses long-range detection mode and user-specified update frequency.
     */
    static constexpr int LongRangeUserFreq = 2;

    constexpr UpdateModeValue(int value) :
        value{value}
    {}

    constexpr UpdateModeValue() :
        value{-1}
    {}

    constexpr bool operator==(UpdateModeValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(UpdateModeValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case UpdateModeValue::ShortRange100Hz: return "ShortRange100Hz";
            case UpdateModeValue::ShortRangeUserFreq: return "ShortRangeUserFreq";
            case UpdateModeValue::LongRangeUserFreq: return "LongRangeUserFreq";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, UpdateModeValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Requires Phoenix Pro; Improves commutation and velocity measurement
 *        for motors with hall sensors.  Talon can use advanced features to
 *        improve commutation and velocity measurement when using a motor with
 *        hall sensors.  This can improve peak efficiency by as high as 2% and
 *        reduce noise in the measured velocity.
 */
struct AdvancedHallSupportValue : public ISerializable {
    int value;

    /**
     * \brief Talon will utilize hall sensors without advanced features.
     */
    static constexpr int Disabled = 0;
    /**
     * \brief Requires Phoenix Pro; Talon uses advanced features to improve
     *        commutation and velocity measurement when using hall sensors.  This
     *        can improve peak efficiency by as high as 2% and reduce noise in the
     *        measured velocity.
     */
    static constexpr int Enabled = 1;

    constexpr AdvancedHallSupportValue(int value) :
        value{value}
    {}

    constexpr AdvancedHallSupportValue() :
        value{-1}
    {}

    constexpr bool operator==(AdvancedHallSupportValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(AdvancedHallSupportValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case AdvancedHallSupportValue::Disabled: return "Disabled";
            case AdvancedHallSupportValue::Enabled: return "Enabled";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, AdvancedHallSupportValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Selects the motor and motor connections used with Talon.
 *        
 *        This setting determines what kind of motor and sensors are used with
 *        the Talon.  This also determines what signals are used on the JST and
 *        Gadgeteer port.
 *        
 *        Motor drive will not function correctly if this setting does not match
 *        the physical setup.
 */
struct MotorArrangementValue : public ISerializable {
    int value;

    /**
     * \brief Motor is not selected.  This is the default setting to ensure the user
     *        has an opportunity to select the correct motor arrangement before
     *        attempting to drive motor.
     */
    static constexpr int Disabled = 0;
    /**
     * \brief CTR Electronics Minion® brushless three phase motor.
     *        Motor leads: red(terminal A), black (terminal B), and white (terminal
     *        C).
     *        JST Connector: hall [A, B, C] is on pins [4, 3, 2] and temperature is
     *        on pin [5]. Motor JST cable can be plugged directly into the JST
     *        connector.
     *        Gadgeteer Connector: quadrature [A, B] are on pins [7, 5], limit
     *        [forward, reverse] are on pins [4, 8], and pulse width position is on
     *        pin [9].
     */
    static constexpr int Minion_JST = 1;
    /**
     * \brief Third party brushed DC motor with two leads.
     *        Use the Brushed Motor Wiring config to determine which leads to use on
     *        the Talon (motor leads may be flipped to correct for clockwise vs
     *        counterclockwise).
     *        Note that the invert configuration can still be used to invert rotor
     *        orientation.
     *        Gadgeteer Connector: quadrature [A, B] are on pins [7, 5], limit
     *        [forward, reverse] are on pins [4, 8], and pulse width position is on
     *        pin [9].
     */
    static constexpr int Brushed_DC = 2;
    /**
     * \brief Third party NEO brushless three phase motor (~6000 RPM at 12V).
     *        Motor leads: red(terminal A), black (terminal B), and white (terminal
     *        C).
     *        JST Connector: hall [A, B, C] is on pins [4, 3, 2] and temperature is
     *        on pin [5]. Motor JST cable can be plugged directly into the JST
     *        connector.
     *        Gadgeteer Connector: quadrature [A, B] are on pins [7, 5], limit
     *        [forward, reverse] are on pins [4, 8], and pulse width position is on
     *        pin [9].
     */
    static constexpr int NEO_JST = 5;
    /**
     * \brief Third party NEO550 brushless three phase motor (~11000 RPM at 12V).
     *        Motor leads: red(terminal A), black (terminal B), and white (terminal
     *        C).
     *        JST Connector: hall [A, B, C] is on pins [4, 3, 2] and temperature is
     *        on pin [5]. Motor JST cable can be plugged directly into the JST
     *        connector.
     *        Gadgeteer Connector: quadrature [A, B] are on pins [7, 5], limit
     *        [forward, reverse] are on pins [4, 8], and pulse width position is on
     *        pin [9].
     */
    static constexpr int NEO550_JST = 6;
    /**
     * \brief Third party VORTEX brushless three phase motor.
     *        Motor leads: red(terminal A), black (terminal B), and white (terminal
     *        C).
     *        JST Connector: hall [A, B, C] is on pins [4, 3, 2] and temperature is
     *        on pin [5]. Motor JST cable can be plugged directly into the JST
     *        connector.
     *        Gadgeteer Connector: quadrature [A, B] are on pins [7, 5], limit
     *        [forward, reverse] are on pins [4, 8], and pulse width position is on
     *        pin [9].
     */
    static constexpr int VORTEX_JST = 7;
    /**
     * \brief Third party custom brushless three phase motor.
     *        This setting allows use of TalonFXS with motors that are not
     *        explicitly supported above.  Note that this requires user to set the
     *        Custom Motor configuration parameters.
     *        This setting will only work outside of the FRC use case.  If selected
     *        during FRC use, motor output will be neutral.
     *        Motor leads: red(terminal A), black (terminal B), and white (terminal
     *        C).
     *        JST Connector: hall [A, B, C] is on pins [4, 3, 2] and temperature is
     *        on pin [5]. Motor JST cable can be plugged directly into the JST
     *        connector.
     *        Gadgeteer Connector: quadrature [A, B] are on pins [7, 5], limit
     *        [forward, reverse] are on pins [4, 8], and pulse width position is on
     *        pin [9].
     */
    static constexpr int CustomBrushless = 8;

    constexpr MotorArrangementValue(int value) :
        value{value}
    {}

    constexpr MotorArrangementValue() :
        value{-1}
    {}

    constexpr bool operator==(MotorArrangementValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(MotorArrangementValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case MotorArrangementValue::Disabled: return "Disabled";
            case MotorArrangementValue::Minion_JST: return "Minion_JST";
            case MotorArrangementValue::Brushed_DC: return "Brushed_DC";
            case MotorArrangementValue::NEO_JST: return "NEO_JST";
            case MotorArrangementValue::NEO550_JST: return "NEO550_JST";
            case MotorArrangementValue::VORTEX_JST: return "VORTEX_JST";
            case MotorArrangementValue::CustomBrushless: return "Custom Brushless";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, MotorArrangementValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief State of the Signal 1 input (S1IN).
 */
struct S1StateValue : public ISerializable {
    int value;

    /**
     * \brief Input is not driven high or low, it is disconnected from load.
     */
    static constexpr int Floating = 0;
    /**
     * \brief Input is driven low (below 0.5V).
     */
    static constexpr int Low = 1;
    /**
     * \brief Input is driven high (above 3V).
     */
    static constexpr int High = 2;

    constexpr S1StateValue(int value) :
        value{value}
    {}

    constexpr S1StateValue() :
        value{-1}
    {}

    constexpr bool operator==(S1StateValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(S1StateValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case S1StateValue::Floating: return "Floating";
            case S1StateValue::Low: return "Low";
            case S1StateValue::High: return "High";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, S1StateValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief State of the Signal 2 input (S2IN).
 */
struct S2StateValue : public ISerializable {
    int value;

    /**
     * \brief Input is not driven high or low, it is disconnected from load.
     */
    static constexpr int Floating = 0;
    /**
     * \brief Input is driven low (below 0.5V).
     */
    static constexpr int Low = 1;
    /**
     * \brief Input is driven high (above 3V).
     */
    static constexpr int High = 2;

    constexpr S2StateValue(int value) :
        value{value}
    {}

    constexpr S2StateValue() :
        value{-1}
    {}

    constexpr bool operator==(S2StateValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(S2StateValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case S2StateValue::Floating: return "Floating";
            case S2StateValue::Low: return "Low";
            case S2StateValue::High: return "High";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, S2StateValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The floating state of the Signal 1 input (S1IN).
 */
struct S1FloatStateValue : public ISerializable {
    int value;

    /**
     * \brief The input will attempt to detect when it is floating. This is enabled
     *        by default.
     */
    static constexpr int FloatDetect = 0;
    /**
     * \brief The input will be pulled high when not loaded by an outside device.
     *        This is useful for NPN-style devices.
     */
    static constexpr int PullHigh = 1;
    /**
     * \brief The input will be pulled low when not loaded by an outside device.
     *        This is useful for PNP-style devices.
     */
    static constexpr int PullLow = 2;
    /**
     * \brief The input will pull in the direction of the last measured state. This
     *        may be useful for devices that can enter into a high-Z tri-state.
     */
    static constexpr int BusKeeper = 3;

    constexpr S1FloatStateValue(int value) :
        value{value}
    {}

    constexpr S1FloatStateValue() :
        value{-1}
    {}

    constexpr bool operator==(S1FloatStateValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(S1FloatStateValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case S1FloatStateValue::FloatDetect: return "Float Detect";
            case S1FloatStateValue::PullHigh: return "Pull High";
            case S1FloatStateValue::PullLow: return "Pull Low";
            case S1FloatStateValue::BusKeeper: return "Bus Keeper";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, S1FloatStateValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The floating state of the Signal 2 input (S2IN).
 */
struct S2FloatStateValue : public ISerializable {
    int value;

    /**
     * \brief The input will attempt to detect when it is floating. This is enabled
     *        by default.
     */
    static constexpr int FloatDetect = 0;
    /**
     * \brief The input will be pulled high when not loaded by an outside device.
     *        This is useful for NPN-style devices.
     */
    static constexpr int PullHigh = 1;
    /**
     * \brief The input will be pulled low when not loaded by an outside device.
     *        This is useful for PNP-style devices.
     */
    static constexpr int PullLow = 2;
    /**
     * \brief The input will pull in the direction of the last measured state. This
     *        may be useful for devices that can enter into a high-Z tri-state.
     */
    static constexpr int BusKeeper = 3;

    constexpr S2FloatStateValue(int value) :
        value{value}
    {}

    constexpr S2FloatStateValue() :
        value{-1}
    {}

    constexpr bool operator==(S2FloatStateValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(S2FloatStateValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case S2FloatStateValue::FloatDetect: return "Float Detect";
            case S2FloatStateValue::PullHigh: return "Pull High";
            case S2FloatStateValue::PullLow: return "Pull Low";
            case S2FloatStateValue::BusKeeper: return "Bus Keeper";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, S2FloatStateValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Choose what sensor source is reported via API and used by closed-loop
 *        and limit features.  The default is Commutation, which uses the
 *        external sensor used for motor commutation.
 *        
 *        Choose Remote* to use another sensor on the same CAN bus (this also
 *        requires setting FeedbackRemoteSensorID).  Talon will update its
 *        position and velocity whenever the remote sensor publishes its
 *        information on CAN bus, and the Talon commutation sensor will not be
 *        used.
 *        
 *        Choose Fused* (requires Phoenix Pro) and Talon will fuse another
 *        sensor's information with the commutation sensor, which provides the
 *        best possible position and velocity for accuracy and bandwidth (this
 *        also requires setting FeedbackRemoteSensorID).  This was developed for
 *        applications such as swerve-azimuth.
 *        
 *        Choose Sync* (requires Phoenix Pro) and Talon will synchronize its
 *        commutation sensor position against another sensor, then continue to
 *        use the rotor sensor for closed loop control (this also requires
 *        setting FeedbackRemoteSensorID).  The Talon will report if its
 *        internal position differs significantly from the reported remote
 *        sensor position.  This was developed for mechanisms where there is a
 *        risk of the sensor failing in such a way that it reports a position
 *        that does not match the mechanism, such as the sensor mounting
 *        assembly breaking off.
 *        
 *        Choose RemotePigeon2Yaw, RemotePigeon2Pitch, and RemotePigeon2Roll to
 *        use another Pigeon2 on the same CAN bus (this also requires setting
 *        FeedbackRemoteSensorID).  Talon will update its position to match the
 *        selected value whenever Pigeon2 publishes its information on CAN bus.
 *        Note that the Talon position will be in rotations and not degrees.
 *        
 *        Choose Quadrature to use a quadrature encoder directly attached to the
 *        Talon data port. This provides velocity and relative position
 *        measurements.
 *        
 *        Choose PulseWidth to use a pulse-width encoder directly attached to
 *        the Talon data port. This provides velocity and absolute position
 *        measurements.
 * 
 * \details Note: When the feedback source is changed to Fused* or Sync*, the
 *          Talon needs a period of time to fuse before sensor-based
 *          (soft-limit, closed loop, etc.) features are used. This period of
 *          time is determined by the update frequency of the remote sensor's
 *          Position signal.
 */
struct ExternalFeedbackSensorSourceValue : public ISerializable {
    int value;

    /**
     * \brief Use the external sensor used for motor commutation.
     */
    static constexpr int Commutation = 0;
    /**
     * \brief Use another CANcoder on the same CAN bus (this also requires setting
     *        FeedbackRemoteSensorID).  Talon will update its position and velocity
     *        whenever CANcoder publishes its information on CAN bus, and the Talon
     *        commutation sensor will not be used.
     */
    static constexpr int RemoteCANcoder = 1;
    /**
     * \brief Use another Pigeon2 on the same CAN bus (this also requires setting
     *        FeedbackRemoteSensorID).  Talon will update its position to match the
     *        Pigeon2 yaw whenever Pigeon2 publishes its information on CAN bus.
     *        Note that the Talon position will be in rotations and not degrees.
     */
    static constexpr int RemotePigeon2Yaw = 2;
    /**
     * \brief Use another Pigeon2 on the same CAN bus (this also requires setting
     *        FeedbackRemoteSensorID).  Talon will update its position to match the
     *        Pigeon2 pitch whenever Pigeon2 publishes its information on CAN bus.
     *        Note that the Talon position will be in rotations and not degrees.
     */
    static constexpr int RemotePigeon2Pitch = 3;
    /**
     * \brief Use another Pigeon2 on the same CAN bus (this also requires setting
     *        FeedbackRemoteSensorID).  Talon will update its position to match the
     *        Pigeon2 roll whenever Pigeon2 publishes its information on CAN bus.
     *        Note that the Talon position will be in rotations and not degrees.
     */
    static constexpr int RemotePigeon2Roll = 4;
    /**
     * \brief Requires Phoenix Pro; Talon will fuse another CANcoder's information
     *        with the commutation sensor, which provides the best possible position
     *        and velocity for accuracy and bandwidth (this also requires setting
     *        FeedbackRemoteSensorID).  FusedCANcoder was developed for applications
     *        such as swerve-azimuth.
     */
    static constexpr int FusedCANcoder = 5;
    /**
     * \brief Requires Phoenix Pro; Talon will synchronize its commutation sensor
     *        position against another CANcoder, then continue to use the rotor
     *        sensor for closed loop control (this also requires setting
     *        FeedbackRemoteSensorID).  The Talon will report if its internal
     *        position differs significantly from the reported CANcoder position. 
     *        SyncCANcoder was developed for mechanisms where there is a risk of the
     *        CANcoder failing in such a way that it reports a position that does
     *        not match the mechanism, such as the sensor mounting assembly breaking
     *        off.
     */
    static constexpr int SyncCANcoder = 6;
    /**
     * \brief Use a quadrature encoder directly attached to the Talon data port.
     *        This provides velocity and relative position measurements.
     */
    static constexpr int Quadrature = 7;
    /**
     * \brief Use a pulse-width encoder directly attached to the Talon data port.
     *        This provides velocity and absolute position measurements.
     */
    static constexpr int PulseWidth = 8;
    /**
     * \brief Use a pulse-width encoder remotely attached to the Sensor Input 1
     *        (S1IN) on CANdi™ (this also requires setting FeedbackRemoteSensorID).
     *        Talon will update its position and velocity whenever CANdi™ publishes
     *        its information on CAN bus, and the Talon internal rotor will not be
     *        used.
     */
    static constexpr int RemoteCANdiPWM1 = 9;
    /**
     * \brief Use a pulse-width encoder remotely attached to the Sensor Input 2
     *        (S2IN) on CANdi™ (this also requires setting FeedbackRemoteSensorID).
     *        Talon will update its position and velocity whenever CANdi™ publishes
     *        its information on CAN bus, and the Talon internal rotor will not be
     *        used.
     */
    static constexpr int RemoteCANdiPWM2 = 10;
    /**
     * \brief Use a quadrature encoder remotely attached to the two Sensor Inputs on
     *        CANdi™ (this also requires setting FeedbackRemoteSensorID). Talon will
     *        update its position and velocity whenever CANdi™ publishes its
     *        information on CAN bus, and the Talon internal rotor will not be used.
     */
    static constexpr int RemoteCANdiQuadrature = 11;
    /**
     * \brief Requires Phoenix Pro; Talon will fuse a pulse-width encoder remotely
     *        attached to the Sensor Input 1 (S1IN) on CANdi™, which provides the
     *        best possible position and velocity for accuracy and bandwidth (this
     *        also requires setting FeedbackRemoteSensorID).  FusedCANdi was
     *        developed for applications such as swerve-azimuth.
     */
    static constexpr int FusedCANdiPWM1 = 12;
    /**
     * \brief Requires Phoenix Pro; Talon will fuse a pulse-width encoder remotely
     *        attached to the Sensor Input 2 (S2IN) on CANdi™, which provides the
     *        best possible position and velocity for accuracy and bandwidth (this
     *        also requires setting FeedbackRemoteSensorID).  FusedCANdi was
     *        developed for applications such as swerve-azimuth.
     */
    static constexpr int FusedCANdiPWM2 = 13;
    /**
     * \brief Requires Phoenix Pro; Talon will fuse a qaudrature encoder remotely
     *        attached to the two Sensor Inputs on CANdi™. This provides velocity
     *        and relative position measurements. This also requires setting
     *        FeedbackRemoteSensorID.
     */
    static constexpr int FusedCANdiQuadrature = 14;
    /**
     * \brief Requires Phoenix Pro; Talon will synchronize its internal rotor
     *        position against the pulse-width encoder attached to Sensor Input 1
     *        (S1IN), then continue to use the rotor sensor for closed loop control
     *        (this also requires setting FeedbackRemoteSensorID).  The Talon will
     *        report if its internal position differs significantly from the
     *        reported PWM position.  SyncCANdi was developed for mechanisms where
     *        there is a risk of the CTR Electronics' CANdi™ failing in such a way
     *        that it reports a position that does not match the mechanism, such as
     *        the sensor mounting assembly breaking off.
     */
    static constexpr int SyncCANdiPWM1 = 15;
    /**
     * \brief Requires Phoenix Pro; Talon will synchronize its internal rotor
     *        position against the pulse-width encoder attached to Sensor Input 1
     *        (S1IN), then continue to use the rotor sensor for closed loop control
     *        (this also requires setting FeedbackRemoteSensorID).  The Talon will
     *        report if its internal position differs significantly from the
     *        reported PWM position.  SyncCANdi was developed for mechanisms where
     *        there is a risk of the CTR Electronics' CANdi™ failing in such a way
     *        that it reports a position that does not match the mechanism, such as
     *        the sensor mounting assembly breaking off.
     */
    static constexpr int SyncCANdiPWM2 = 16;

    constexpr ExternalFeedbackSensorSourceValue(int value) :
        value{value}
    {}

    constexpr ExternalFeedbackSensorSourceValue() :
        value{-1}
    {}

    constexpr bool operator==(ExternalFeedbackSensorSourceValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(ExternalFeedbackSensorSourceValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case ExternalFeedbackSensorSourceValue::Commutation: return "Commutation";
            case ExternalFeedbackSensorSourceValue::RemoteCANcoder: return "RemoteCANcoder";
            case ExternalFeedbackSensorSourceValue::RemotePigeon2Yaw: return "RemotePigeon2Yaw";
            case ExternalFeedbackSensorSourceValue::RemotePigeon2Pitch: return "RemotePigeon2Pitch";
            case ExternalFeedbackSensorSourceValue::RemotePigeon2Roll: return "RemotePigeon2Roll";
            case ExternalFeedbackSensorSourceValue::FusedCANcoder: return "FusedCANcoder";
            case ExternalFeedbackSensorSourceValue::SyncCANcoder: return "SyncCANcoder";
            case ExternalFeedbackSensorSourceValue::Quadrature: return "Quadrature";
            case ExternalFeedbackSensorSourceValue::PulseWidth: return "PulseWidth";
            case ExternalFeedbackSensorSourceValue::RemoteCANdiPWM1: return "RemoteCANdiPWM1";
            case ExternalFeedbackSensorSourceValue::RemoteCANdiPWM2: return "RemoteCANdiPWM2";
            case ExternalFeedbackSensorSourceValue::RemoteCANdiQuadrature: return "RemoteCANdiQuadrature";
            case ExternalFeedbackSensorSourceValue::FusedCANdiPWM1: return "FusedCANdiPWM1";
            case ExternalFeedbackSensorSourceValue::FusedCANdiPWM2: return "FusedCANdiPWM2";
            case ExternalFeedbackSensorSourceValue::FusedCANdiQuadrature: return "FusedCANdiQuadrature";
            case ExternalFeedbackSensorSourceValue::SyncCANdiPWM1: return "SyncCANdiPWM1";
            case ExternalFeedbackSensorSourceValue::SyncCANdiPWM2: return "SyncCANdiPWM2";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, ExternalFeedbackSensorSourceValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The relationship between the motor controlled by a Talon and the
 *        external sensor connected to the data port. This does not affect the
 *        commutation sensor or remote sensors.
 *        
 *        To determine the sensor phase, set this config to Aligned and drive
 *        the motor with positive output. If the reported sensor velocity is
 *        positive, then the phase is Aligned. If the reported sensor velocity
 *        is negative, then the phase is Opposed.
 *        
 *        The sensor direction is automatically inverted along with motor
 *        invert, so the sensor phase does not need to be changed when motor
 *        invert changes.
 */
struct SensorPhaseValue : public ISerializable {
    int value;

    /**
     * \brief The sensor direction is normally aligned with the motor.
     */
    static constexpr int Aligned = 0;
    /**
     * \brief The sensor direction is normally opposed to the motor.
     */
    static constexpr int Opposed = 1;

    constexpr SensorPhaseValue(int value) :
        value{value}
    {}

    constexpr SensorPhaseValue() :
        value{-1}
    {}

    constexpr bool operator==(SensorPhaseValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(SensorPhaseValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case SensorPhaseValue::Aligned: return "Aligned";
            case SensorPhaseValue::Opposed: return "Opposed";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, SensorPhaseValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief What value the Signal 1 input (S1IN) needs to be for the CTR
 *        Electronics' CANdi™ to detect as Closed.
 * 
 * \details Devices using the S1 input as a remote limit switch will treat the
 *          switch as closed when the S1 input is this state.
 */
struct S1CloseStateValue : public ISerializable {
    int value;

    /**
     * \brief The S1 input will be treated as closed when it is not floating.
     */
    static constexpr int CloseWhenNotFloating = 0;
    /**
     * \brief The S1 input will be treated as closed when it is floating.
     */
    static constexpr int CloseWhenFloating = 1;
    /**
     * \brief The S1 input will be treated as closed when it is not High.
     */
    static constexpr int CloseWhenNotHigh = 2;
    /**
     * \brief The S1 input will be treated as closed when it is High.
     */
    static constexpr int CloseWhenHigh = 3;
    /**
     * \brief The S1 input will be treated as closed when it is not Low.
     */
    static constexpr int CloseWhenNotLow = 4;
    /**
     * \brief The S1 input will be treated as closed when it is Low.
     */
    static constexpr int CloseWhenLow = 5;

    constexpr S1CloseStateValue(int value) :
        value{value}
    {}

    constexpr S1CloseStateValue() :
        value{-1}
    {}

    constexpr bool operator==(S1CloseStateValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(S1CloseStateValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case S1CloseStateValue::CloseWhenNotFloating: return "CloseWhenNotFloating";
            case S1CloseStateValue::CloseWhenFloating: return "CloseWhenFloating";
            case S1CloseStateValue::CloseWhenNotHigh: return "CloseWhenNotHigh";
            case S1CloseStateValue::CloseWhenHigh: return "CloseWhenHigh";
            case S1CloseStateValue::CloseWhenNotLow: return "CloseWhenNotLow";
            case S1CloseStateValue::CloseWhenLow: return "CloseWhenLow";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, S1CloseStateValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief What value the Signal 2 input (S2IN) needs to be for the CTR
 *        Electronics' CANdi™ to detect as Closed.
 * 
 * \details Devices using the S2 input as a remote limit switch will treat the
 *          switch as closed when the S2 input is this state.
 */
struct S2CloseStateValue : public ISerializable {
    int value;

    /**
     * \brief The S2 input will be treated as closed when it is not floating.
     */
    static constexpr int CloseWhenNotFloating = 0;
    /**
     * \brief The S2 input will be treated as closed when it is floating.
     */
    static constexpr int CloseWhenFloating = 1;
    /**
     * \brief The S2 input will be treated as closed when it is not High.
     */
    static constexpr int CloseWhenNotHigh = 2;
    /**
     * \brief The S2 input will be treated as closed when it is High.
     */
    static constexpr int CloseWhenHigh = 3;
    /**
     * \brief The S2 input will be treated as closed when it is not Low.
     */
    static constexpr int CloseWhenNotLow = 4;
    /**
     * \brief The S2 input will be treated as closed when it is Low.
     */
    static constexpr int CloseWhenLow = 5;

    constexpr S2CloseStateValue(int value) :
        value{value}
    {}

    constexpr S2CloseStateValue() :
        value{-1}
    {}

    constexpr bool operator==(S2CloseStateValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(S2CloseStateValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case S2CloseStateValue::CloseWhenNotFloating: return "CloseWhenNotFloating";
            case S2CloseStateValue::CloseWhenFloating: return "CloseWhenFloating";
            case S2CloseStateValue::CloseWhenNotHigh: return "CloseWhenNotHigh";
            case S2CloseStateValue::CloseWhenHigh: return "CloseWhenHigh";
            case S2CloseStateValue::CloseWhenNotLow: return "CloseWhenNotLow";
            case S2CloseStateValue::CloseWhenLow: return "CloseWhenLow";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, S2CloseStateValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief If a brushed motor is selected with Motor Arrangement, this config
 *        determines which of three leads to use.
 */
struct BrushedMotorWiringValue : public ISerializable {
    int value;

    /**
     * \brief Third party brushed DC motor with two leads.
     *        Motor leads: Use terminal A for the motor red lead and terminal B for
     *        the motor black lead (motor leads may be flipped to correct for
     *        clockwise vs counterclockwise).
     *        Note that the invert configuration can still be used to invert rotor
     *        orientation.
     *        Gadgeteer Connector: quadrature [A, B] are on pins [7, 5], limit
     *        [forward, reverse] are on pins [4, 8], and pulse width position is on
     *        pin [9].
     */
    static constexpr int Leads_A_and_B = 0;
    /**
     * \brief Third party brushed DC motor with two leads.
     *        Motor leads: Use terminal A for the motor red lead and terminal C for
     *        the motor black lead (motor leads may be flipped to correct for
     *        clockwise vs counterclockwise).
     *        Note that the invert configuration can still be used to reverse rotor
     *        orientation.
     *        Gadgeteer Connector: quadrature [A, B] are on pins [7, 5], limit
     *        [forward, reverse] are on pins [4, 8], and pulse width position is on
     *        pin [9].
     */
    static constexpr int Leads_A_and_C = 1;
    /**
     * \brief Third party brushed DC motor with two leads.
     *        Motor leads: Use terminal B for the motor red lead and terminal C for
     *        the motor black lead (motor leads may be flipped to correct for
     *        clockwise vs counterclockwise).
     *        Note that the invert configuration can still be used to reverse rotor
     *        orientation.
     *        Gadgeteer Connector: quadrature [A, B] are on pins [7, 5], limit
     *        [forward, reverse] are on pins [4, 8], and pulse width position is on
     *        pin [9].
     */
    static constexpr int Leads_B_and_C = 2;

    constexpr BrushedMotorWiringValue(int value) :
        value{value}
    {}

    constexpr BrushedMotorWiringValue() :
        value{-1}
    {}

    constexpr bool operator==(BrushedMotorWiringValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(BrushedMotorWiringValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case BrushedMotorWiringValue::Leads_A_and_B: return "Leads_A_and_B";
            case BrushedMotorWiringValue::Leads_A_and_C: return "Leads_A_and_C";
            case BrushedMotorWiringValue::Leads_B_and_C: return "Leads_B_and_C";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, BrushedMotorWiringValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The type of LEDs that are being controlled.
 */
struct StripTypeValue : public ISerializable {
    int value;

    /**
     * \brief LEDs that are controlled by Green-Red-Blue values.
     */
    static constexpr int GRB = 0;
    /**
     * \brief LEDs that are controlled by Red-Green-Blue values.
     */
    static constexpr int RGB = 1;
    /**
     * \brief LEDs that are controlled by Blue-Red-Green values.
     */
    static constexpr int BRG = 2;
    /**
     * \brief LEDs that are controlled by Green-Red-Blue-White values.
     */
    static constexpr int GRBW = 6;
    /**
     * \brief LEDs that are controlled by Red-Green-Blue-White values.
     */
    static constexpr int RGBW = 7;
    /**
     * \brief LEDs that are controlled by Blue-Red-Green-White values.
     */
    static constexpr int BRGW = 8;

    constexpr StripTypeValue(int value) :
        value{value}
    {}

    constexpr StripTypeValue() :
        value{-1}
    {}

    constexpr bool operator==(StripTypeValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(StripTypeValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case StripTypeValue::GRB: return "GRB";
            case StripTypeValue::RGB: return "RGB";
            case StripTypeValue::BRG: return "BRG";
            case StripTypeValue::GRBW: return "GRBW";
            case StripTypeValue::RGBW: return "RGBW";
            case StripTypeValue::BRGW: return "BRGW";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, StripTypeValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The behavior of the LEDs when the control signal is lost.
 */
struct LossOfSignalBehaviorValue : public ISerializable {
    int value;

    /**
     * \brief LEDs remain enabled, and animations continue to run.
     */
    static constexpr int KeepRunning = 0;
    /**
     * \brief LEDs and animations are disabled after the control signal is lost.
     */
    static constexpr int DisableLEDs = 1;

    constexpr LossOfSignalBehaviorValue(int value) :
        value{value}
    {}

    constexpr LossOfSignalBehaviorValue() :
        value{-1}
    {}

    constexpr bool operator==(LossOfSignalBehaviorValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(LossOfSignalBehaviorValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case LossOfSignalBehaviorValue::KeepRunning: return "KeepRunning";
            case LossOfSignalBehaviorValue::DisableLEDs: return "DisableLEDs";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, LossOfSignalBehaviorValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Whether the 5V rail is enabled. Disabling the 5V rail will also turn
 *        off the onboard LEDs.
 */
struct Enable5VRailValue : public ISerializable {
    int value;

    /**
     * \brief The 5V rail is enabled, allowing for LED control.
     */
    static constexpr int Enabled = 0;
    /**
     * \brief The 5V rail is disabled. This will also turn off the onboard LEDs.
     */
    static constexpr int Disabled = 1;

    constexpr Enable5VRailValue(int value) :
        value{value}
    {}

    constexpr Enable5VRailValue() :
        value{-1}
    {}

    constexpr bool operator==(Enable5VRailValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(Enable5VRailValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case Enable5VRailValue::Enabled: return "Enabled";
            case Enable5VRailValue::Disabled: return "Disabled";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, Enable5VRailValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The behavior of the VBat output. CANdle supports modulating VBat
 *        output for single-color LED strips.
 */
struct VBatOutputModeValue : public ISerializable {
    int value;

    /**
     * \brief VBat output is on at full power.
     */
    static constexpr int On = 0;
    /**
     * \brief VBat output is off.
     */
    static constexpr int Off = 1;
    /**
     * \brief VBat output is on at the specified modulation.
     */
    static constexpr int Modulated = 2;

    constexpr VBatOutputModeValue(int value) :
        value{value}
    {}

    constexpr VBatOutputModeValue() :
        value{-1}
    {}

    constexpr bool operator==(VBatOutputModeValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(VBatOutputModeValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case VBatOutputModeValue::On: return "On";
            case VBatOutputModeValue::Off: return "Off";
            case VBatOutputModeValue::Modulated: return "Modulated";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, VBatOutputModeValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Whether the Status LED is enabled when the CANdle is actively being
 *        controlled.
 */
struct StatusLedWhenActiveValue : public ISerializable {
    int value;

    /**
     * \brief The status LED is enabled during control.
     */
    static constexpr int Enabled = 0;
    /**
     * \brief The status LED is disabled during control.
     */
    static constexpr int Disabled = 1;

    constexpr StatusLedWhenActiveValue(int value) :
        value{value}
    {}

    constexpr StatusLedWhenActiveValue() :
        value{-1}
    {}

    constexpr bool operator==(StatusLedWhenActiveValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(StatusLedWhenActiveValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case StatusLedWhenActiveValue::Enabled: return "Enabled";
            case StatusLedWhenActiveValue::Disabled: return "Disabled";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, StatusLedWhenActiveValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The type of animation running in slot 0 of the CANdle.
 */
struct Animation0TypeValue : public ISerializable {
    int value;

    /**
     * \brief No animation.
     */
    static constexpr int Empty = 0;
    /**
     * \brief Color flow animation.
     */
    static constexpr int ColorFlow = 1;
    /**
     * \brief Fire animation.
     */
    static constexpr int Fire = 2;
    /**
     * \brief Larson animation.
     */
    static constexpr int Larson = 3;
    /**
     * \brief Rainbow animation.
     */
    static constexpr int Rainbow = 4;
    /**
     * \brief RGB Fade animation.
     */
    static constexpr int RgbFade = 5;
    /**
     * \brief Single fade animation.
     */
    static constexpr int SingleFade = 6;
    /**
     * \brief Strobe animation.
     */
    static constexpr int Strobe = 7;
    /**
     * \brief Twinkle animation.
     */
    static constexpr int Twinkle = 8;
    /**
     * \brief Twinkle off animation.
     */
    static constexpr int TwinkleOff = 9;

    constexpr Animation0TypeValue(int value) :
        value{value}
    {}

    constexpr Animation0TypeValue() :
        value{-1}
    {}

    constexpr bool operator==(Animation0TypeValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(Animation0TypeValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case Animation0TypeValue::Empty: return "Empty";
            case Animation0TypeValue::ColorFlow: return "ColorFlow";
            case Animation0TypeValue::Fire: return "Fire";
            case Animation0TypeValue::Larson: return "Larson";
            case Animation0TypeValue::Rainbow: return "Rainbow";
            case Animation0TypeValue::RgbFade: return "RgbFade";
            case Animation0TypeValue::SingleFade: return "SingleFade";
            case Animation0TypeValue::Strobe: return "Strobe";
            case Animation0TypeValue::Twinkle: return "Twinkle";
            case Animation0TypeValue::TwinkleOff: return "TwinkleOff";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, Animation0TypeValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The type of animation running in slot 1 of the CANdle.
 */
struct Animation1TypeValue : public ISerializable {
    int value;

    /**
     * \brief No animation.
     */
    static constexpr int Empty = 0;
    /**
     * \brief Color flow animation.
     */
    static constexpr int ColorFlow = 1;
    /**
     * \brief Fire animation.
     */
    static constexpr int Fire = 2;
    /**
     * \brief Larson animation.
     */
    static constexpr int Larson = 3;
    /**
     * \brief Rainbow animation.
     */
    static constexpr int Rainbow = 4;
    /**
     * \brief RGB Fade animation.
     */
    static constexpr int RgbFade = 5;
    /**
     * \brief Single fade animation.
     */
    static constexpr int SingleFade = 6;
    /**
     * \brief Strobe animation.
     */
    static constexpr int Strobe = 7;
    /**
     * \brief Twinkle animation.
     */
    static constexpr int Twinkle = 8;
    /**
     * \brief Twinkle off animation.
     */
    static constexpr int TwinkleOff = 9;

    constexpr Animation1TypeValue(int value) :
        value{value}
    {}

    constexpr Animation1TypeValue() :
        value{-1}
    {}

    constexpr bool operator==(Animation1TypeValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(Animation1TypeValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case Animation1TypeValue::Empty: return "Empty";
            case Animation1TypeValue::ColorFlow: return "ColorFlow";
            case Animation1TypeValue::Fire: return "Fire";
            case Animation1TypeValue::Larson: return "Larson";
            case Animation1TypeValue::Rainbow: return "Rainbow";
            case Animation1TypeValue::RgbFade: return "RgbFade";
            case Animation1TypeValue::SingleFade: return "SingleFade";
            case Animation1TypeValue::Strobe: return "Strobe";
            case Animation1TypeValue::Twinkle: return "Twinkle";
            case Animation1TypeValue::TwinkleOff: return "TwinkleOff";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, Animation1TypeValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The type of animation running in slot 2 of the CANdle.
 */
struct Animation2TypeValue : public ISerializable {
    int value;

    /**
     * \brief No animation.
     */
    static constexpr int Empty = 0;
    /**
     * \brief Color flow animation.
     */
    static constexpr int ColorFlow = 1;
    /**
     * \brief Fire animation.
     */
    static constexpr int Fire = 2;
    /**
     * \brief Larson animation.
     */
    static constexpr int Larson = 3;
    /**
     * \brief Rainbow animation.
     */
    static constexpr int Rainbow = 4;
    /**
     * \brief RGB Fade animation.
     */
    static constexpr int RgbFade = 5;
    /**
     * \brief Single fade animation.
     */
    static constexpr int SingleFade = 6;
    /**
     * \brief Strobe animation.
     */
    static constexpr int Strobe = 7;
    /**
     * \brief Twinkle animation.
     */
    static constexpr int Twinkle = 8;
    /**
     * \brief Twinkle off animation.
     */
    static constexpr int TwinkleOff = 9;

    constexpr Animation2TypeValue(int value) :
        value{value}
    {}

    constexpr Animation2TypeValue() :
        value{-1}
    {}

    constexpr bool operator==(Animation2TypeValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(Animation2TypeValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case Animation2TypeValue::Empty: return "Empty";
            case Animation2TypeValue::ColorFlow: return "ColorFlow";
            case Animation2TypeValue::Fire: return "Fire";
            case Animation2TypeValue::Larson: return "Larson";
            case Animation2TypeValue::Rainbow: return "Rainbow";
            case Animation2TypeValue::RgbFade: return "RgbFade";
            case Animation2TypeValue::SingleFade: return "SingleFade";
            case Animation2TypeValue::Strobe: return "Strobe";
            case Animation2TypeValue::Twinkle: return "Twinkle";
            case Animation2TypeValue::TwinkleOff: return "TwinkleOff";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, Animation2TypeValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The type of animation running in slot 3 of the CANdle.
 */
struct Animation3TypeValue : public ISerializable {
    int value;

    /**
     * \brief No animation.
     */
    static constexpr int Empty = 0;
    /**
     * \brief Color flow animation.
     */
    static constexpr int ColorFlow = 1;
    /**
     * \brief Fire animation.
     */
    static constexpr int Fire = 2;
    /**
     * \brief Larson animation.
     */
    static constexpr int Larson = 3;
    /**
     * \brief Rainbow animation.
     */
    static constexpr int Rainbow = 4;
    /**
     * \brief RGB Fade animation.
     */
    static constexpr int RgbFade = 5;
    /**
     * \brief Single fade animation.
     */
    static constexpr int SingleFade = 6;
    /**
     * \brief Strobe animation.
     */
    static constexpr int Strobe = 7;
    /**
     * \brief Twinkle animation.
     */
    static constexpr int Twinkle = 8;
    /**
     * \brief Twinkle off animation.
     */
    static constexpr int TwinkleOff = 9;

    constexpr Animation3TypeValue(int value) :
        value{value}
    {}

    constexpr Animation3TypeValue() :
        value{-1}
    {}

    constexpr bool operator==(Animation3TypeValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(Animation3TypeValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case Animation3TypeValue::Empty: return "Empty";
            case Animation3TypeValue::ColorFlow: return "ColorFlow";
            case Animation3TypeValue::Fire: return "Fire";
            case Animation3TypeValue::Larson: return "Larson";
            case Animation3TypeValue::Rainbow: return "Rainbow";
            case Animation3TypeValue::RgbFade: return "RgbFade";
            case Animation3TypeValue::SingleFade: return "SingleFade";
            case Animation3TypeValue::Strobe: return "Strobe";
            case Animation3TypeValue::Twinkle: return "Twinkle";
            case Animation3TypeValue::TwinkleOff: return "TwinkleOff";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, Animation3TypeValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The type of animation running in slot 4 of the CANdle.
 */
struct Animation4TypeValue : public ISerializable {
    int value;

    /**
     * \brief No animation.
     */
    static constexpr int Empty = 0;
    /**
     * \brief Color flow animation.
     */
    static constexpr int ColorFlow = 1;
    /**
     * \brief Fire animation.
     */
    static constexpr int Fire = 2;
    /**
     * \brief Larson animation.
     */
    static constexpr int Larson = 3;
    /**
     * \brief Rainbow animation.
     */
    static constexpr int Rainbow = 4;
    /**
     * \brief RGB Fade animation.
     */
    static constexpr int RgbFade = 5;
    /**
     * \brief Single fade animation.
     */
    static constexpr int SingleFade = 6;
    /**
     * \brief Strobe animation.
     */
    static constexpr int Strobe = 7;
    /**
     * \brief Twinkle animation.
     */
    static constexpr int Twinkle = 8;
    /**
     * \brief Twinkle off animation.
     */
    static constexpr int TwinkleOff = 9;

    constexpr Animation4TypeValue(int value) :
        value{value}
    {}

    constexpr Animation4TypeValue() :
        value{-1}
    {}

    constexpr bool operator==(Animation4TypeValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(Animation4TypeValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case Animation4TypeValue::Empty: return "Empty";
            case Animation4TypeValue::ColorFlow: return "ColorFlow";
            case Animation4TypeValue::Fire: return "Fire";
            case Animation4TypeValue::Larson: return "Larson";
            case Animation4TypeValue::Rainbow: return "Rainbow";
            case Animation4TypeValue::RgbFade: return "RgbFade";
            case Animation4TypeValue::SingleFade: return "SingleFade";
            case Animation4TypeValue::Strobe: return "Strobe";
            case Animation4TypeValue::Twinkle: return "Twinkle";
            case Animation4TypeValue::TwinkleOff: return "TwinkleOff";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, Animation4TypeValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The type of animation running in slot 5 of the CANdle.
 */
struct Animation5TypeValue : public ISerializable {
    int value;

    /**
     * \brief No animation.
     */
    static constexpr int Empty = 0;
    /**
     * \brief Color flow animation.
     */
    static constexpr int ColorFlow = 1;
    /**
     * \brief Fire animation.
     */
    static constexpr int Fire = 2;
    /**
     * \brief Larson animation.
     */
    static constexpr int Larson = 3;
    /**
     * \brief Rainbow animation.
     */
    static constexpr int Rainbow = 4;
    /**
     * \brief RGB Fade animation.
     */
    static constexpr int RgbFade = 5;
    /**
     * \brief Single fade animation.
     */
    static constexpr int SingleFade = 6;
    /**
     * \brief Strobe animation.
     */
    static constexpr int Strobe = 7;
    /**
     * \brief Twinkle animation.
     */
    static constexpr int Twinkle = 8;
    /**
     * \brief Twinkle off animation.
     */
    static constexpr int TwinkleOff = 9;

    constexpr Animation5TypeValue(int value) :
        value{value}
    {}

    constexpr Animation5TypeValue() :
        value{-1}
    {}

    constexpr bool operator==(Animation5TypeValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(Animation5TypeValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case Animation5TypeValue::Empty: return "Empty";
            case Animation5TypeValue::ColorFlow: return "ColorFlow";
            case Animation5TypeValue::Fire: return "Fire";
            case Animation5TypeValue::Larson: return "Larson";
            case Animation5TypeValue::Rainbow: return "Rainbow";
            case Animation5TypeValue::RgbFade: return "RgbFade";
            case Animation5TypeValue::SingleFade: return "SingleFade";
            case Animation5TypeValue::Strobe: return "Strobe";
            case Animation5TypeValue::Twinkle: return "Twinkle";
            case Animation5TypeValue::TwinkleOff: return "TwinkleOff";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, Animation5TypeValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The type of animation running in slot 6 of the CANdle.
 */
struct Animation6TypeValue : public ISerializable {
    int value;

    /**
     * \brief No animation.
     */
    static constexpr int Empty = 0;
    /**
     * \brief Color flow animation.
     */
    static constexpr int ColorFlow = 1;
    /**
     * \brief Fire animation.
     */
    static constexpr int Fire = 2;
    /**
     * \brief Larson animation.
     */
    static constexpr int Larson = 3;
    /**
     * \brief Rainbow animation.
     */
    static constexpr int Rainbow = 4;
    /**
     * \brief RGB Fade animation.
     */
    static constexpr int RgbFade = 5;
    /**
     * \brief Single fade animation.
     */
    static constexpr int SingleFade = 6;
    /**
     * \brief Strobe animation.
     */
    static constexpr int Strobe = 7;
    /**
     * \brief Twinkle animation.
     */
    static constexpr int Twinkle = 8;
    /**
     * \brief Twinkle off animation.
     */
    static constexpr int TwinkleOff = 9;

    constexpr Animation6TypeValue(int value) :
        value{value}
    {}

    constexpr Animation6TypeValue() :
        value{-1}
    {}

    constexpr bool operator==(Animation6TypeValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(Animation6TypeValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case Animation6TypeValue::Empty: return "Empty";
            case Animation6TypeValue::ColorFlow: return "ColorFlow";
            case Animation6TypeValue::Fire: return "Fire";
            case Animation6TypeValue::Larson: return "Larson";
            case Animation6TypeValue::Rainbow: return "Rainbow";
            case Animation6TypeValue::RgbFade: return "RgbFade";
            case Animation6TypeValue::SingleFade: return "SingleFade";
            case Animation6TypeValue::Strobe: return "Strobe";
            case Animation6TypeValue::Twinkle: return "Twinkle";
            case Animation6TypeValue::TwinkleOff: return "TwinkleOff";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, Animation6TypeValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The type of animation running in slot 7 of the CANdle.
 */
struct Animation7TypeValue : public ISerializable {
    int value;

    /**
     * \brief No animation.
     */
    static constexpr int Empty = 0;
    /**
     * \brief Color flow animation.
     */
    static constexpr int ColorFlow = 1;
    /**
     * \brief Fire animation.
     */
    static constexpr int Fire = 2;
    /**
     * \brief Larson animation.
     */
    static constexpr int Larson = 3;
    /**
     * \brief Rainbow animation.
     */
    static constexpr int Rainbow = 4;
    /**
     * \brief RGB Fade animation.
     */
    static constexpr int RgbFade = 5;
    /**
     * \brief Single fade animation.
     */
    static constexpr int SingleFade = 6;
    /**
     * \brief Strobe animation.
     */
    static constexpr int Strobe = 7;
    /**
     * \brief Twinkle animation.
     */
    static constexpr int Twinkle = 8;
    /**
     * \brief Twinkle off animation.
     */
    static constexpr int TwinkleOff = 9;

    constexpr Animation7TypeValue(int value) :
        value{value}
    {}

    constexpr Animation7TypeValue() :
        value{-1}
    {}

    constexpr bool operator==(Animation7TypeValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(Animation7TypeValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case Animation7TypeValue::Empty: return "Empty";
            case Animation7TypeValue::ColorFlow: return "ColorFlow";
            case Animation7TypeValue::Fire: return "Fire";
            case Animation7TypeValue::Larson: return "Larson";
            case Animation7TypeValue::Rainbow: return "Rainbow";
            case Animation7TypeValue::RgbFade: return "RgbFade";
            case Animation7TypeValue::SingleFade: return "SingleFade";
            case Animation7TypeValue::Strobe: return "Strobe";
            case Animation7TypeValue::Twinkle: return "Twinkle";
            case Animation7TypeValue::TwinkleOff: return "TwinkleOff";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, Animation7TypeValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Direction of the animation.
 */
struct AnimationDirectionValue : public ISerializable {
    int value;

    /**
     * \brief The animation starts at the specified LED start index and moves
     *        towards the LED end index.
     */
    static constexpr int Forward = 0;
    /**
     * \brief The animation starts at the specified LED end index and moves towards
     *        the LED start index.
     */
    static constexpr int Backward = 1;

    constexpr AnimationDirectionValue(int value) :
        value{value}
    {}

    constexpr AnimationDirectionValue() :
        value{-1}
    {}

    constexpr bool operator==(AnimationDirectionValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(AnimationDirectionValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case AnimationDirectionValue::Forward: return "Forward";
            case AnimationDirectionValue::Backward: return "Backward";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, AnimationDirectionValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The behavior of the larson animation pocket of light when it reaches
 *        the end of the strip.
 */
struct LarsonBounceValue : public ISerializable {
    int value;

    /**
     * \brief The animation bounces as soon as the first LED reaches the end of the
     *        strip.
     */
    static constexpr int Front = 0;
    /**
     * \brief The animation bounces once it is midway through the end of the strip.
     */
    static constexpr int Center = 1;
    /**
     * \brief The animation bounces once all LEDs are off the strip.
     */
    static constexpr int Back = 2;

    constexpr LarsonBounceValue(int value) :
        value{value}
    {}

    constexpr LarsonBounceValue() :
        value{-1}
    {}

    constexpr bool operator==(LarsonBounceValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(LarsonBounceValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case LarsonBounceValue::Front: return "Front";
            case LarsonBounceValue::Center: return "Center";
            case LarsonBounceValue::Back: return "Back";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, LarsonBounceValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief Whether a temperature sensor should be required for motor control.
 *        This configuration is ignored in FRC environments and defaults to
 *        Required.
 */
struct TempSensorRequiredValue : public ISerializable {
    int value;

    /**
     * \brief Temperature sensor is required for motor control.
     */
    static constexpr int Required = 0;
    /**
     * \brief Temperature sensor is not required for motor control.
     */
    static constexpr int Not_Required = 1;

    constexpr TempSensorRequiredValue(int value) :
        value{value}
    {}

    constexpr TempSensorRequiredValue() :
        value{-1}
    {}

    constexpr bool operator==(TempSensorRequiredValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(TempSensorRequiredValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case TempSensorRequiredValue::Required: return "Required";
            case TempSensorRequiredValue::Not_Required: return "Not_Required";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, TempSensorRequiredValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The behavior of kP output as the error crosses the
 *        GainSchedErrorThreshold during gain scheduling. The output of kP can
 *        be adjusted to maintain continuity in output, or it can be left
 *        discontinuous.
 */
struct GainSchedKpBehaviorValue : public ISerializable {
    int value;

    /**
     * \brief The gain scheduler will maintain continuity in the kP output as the
     *        error crosses the gain threshold. This results in the best system
     *        stability, but it may result in output that does not match pOut = kP *
     *        error.
     */
    static constexpr int Continuous = 0;
    /**
     * \brief The gain scheduler will allow for a discontinuity in the kP output.
     *        This ensures that pOut = kP * error, but it may result in instability
     *        as the system's error crosses the gain threshold.
     */
    static constexpr int Discontinuous = 1;

    constexpr GainSchedKpBehaviorValue(int value) :
        value{value}
    {}

    constexpr GainSchedKpBehaviorValue() :
        value{-1}
    {}

    constexpr bool operator==(GainSchedKpBehaviorValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(GainSchedKpBehaviorValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case GainSchedKpBehaviorValue::Continuous: return "Continuous";
            case GainSchedKpBehaviorValue::Discontinuous: return "Discontinuous";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, GainSchedKpBehaviorValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The behavior of the gain scheduler on this slot. This specifies which
 *        gains to use while within the configured GainSchedErrorThreshold. The
 *        default is to continue using the specified slot.
 * 
 * \details Gain scheduling will not take effect when running velocity
 *          closed-loop controls.
 */
struct GainSchedBehaviorValue : public ISerializable {
    int value;

    /**
     * \brief No gain scheduling will occur.
     */
    static constexpr int Inactive = 0;
    /**
     * \brief The output of the PID controller will be completely zeroed, except for
     *        kG and the user FeedForward control request parameter.
     */
    static constexpr int ZeroOutput = 1;
    /**
     * \brief Switch to Slot 0 while within the configured GainSchedErrorThreshold.
     */
    static constexpr int UseSlot0 = 2;
    /**
     * \brief Switch to Slot 1 while within the configured GainSchedErrorThreshold.
     */
    static constexpr int UseSlot1 = 3;
    /**
     * \brief Switch to Slot 2 while within the configured GainSchedErrorThreshold.
     */
    static constexpr int UseSlot2 = 4;

    constexpr GainSchedBehaviorValue(int value) :
        value{value}
    {}

    constexpr GainSchedBehaviorValue() :
        value{-1}
    {}

    constexpr bool operator==(GainSchedBehaviorValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(GainSchedBehaviorValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case GainSchedBehaviorValue::Inactive: return "Inactive";
            case GainSchedBehaviorValue::ZeroOutput: return "ZeroOutput";
            case GainSchedBehaviorValue::UseSlot0: return "UseSlot0";
            case GainSchedBehaviorValue::UseSlot1: return "UseSlot1";
            case GainSchedBehaviorValue::UseSlot2: return "UseSlot2";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, GainSchedBehaviorValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};

/**
 * \brief The relationship between two motors in a mechanism. Depending on
 *        hardware setup, one motor may be inverted relative to the other motor.
 */
struct MotorAlignmentValue : public ISerializable {
    int value;

    /**
     * \brief The two motor directions are aligned. Positive output on both motors
     *        moves the mechanism forward/backward.
     */
    static constexpr int Aligned = 0;
    /**
     * \brief The two motor directions are opposed. To move forward/backward, one
     *        motor needs positive output, and the other needs negative output.
     */
    static constexpr int Opposed = 1;

    constexpr MotorAlignmentValue(int value) :
        value{value}
    {}

    constexpr MotorAlignmentValue() :
        value{-1}
    {}

    constexpr bool operator==(MotorAlignmentValue other) const
    {
        return value == other.value;
    }
    constexpr auto operator<=>(MotorAlignmentValue other) const
    {
        return value <=> other.value;
    }

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    constexpr std::string_view ToString() const
    {
        switch (value) {
            case MotorAlignmentValue::Aligned: return "Aligned";
            case MotorAlignmentValue::Opposed: return "Opposed";
            default: return "Invalid Value";
        }
    }

    CTREXPORT friend std::ostream &operator<<(std::ostream &os, MotorAlignmentValue data);

    std::string Serialize() const override
    {
        return "u_" + std::to_string(this->value);
    }
};


}
}
}
