/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

#include "ctre/phoenix6/Serializable.hpp"
#include <sstream>
#include <string>

namespace ctre {
namespace phoenix6 {
namespace signals {


/**
 * \brief  System state of the device
 */
class System_StateValue : public ISerializable
{
public:
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
    static constexpr int Fault = 11;
    static constexpr int Recover = 12;
    static constexpr int NotLicensed = 13;

    System_StateValue(int value) :
        value{value}
    {}

    System_StateValue() :
        value{-1}
    {}

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    std::string ToString() const
    {
        switch(value)
        {
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
        case System_StateValue::Fault: return "Fault";
        case System_StateValue::Recover: return "Recover";
        case System_StateValue::NotLicensed: return "NotLicensed";
        default: return "Invalid Value";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const System_StateValue& data)
    {
        os << data.ToString();
        return os;
    }

    std::string Serialize() const
    {
        std::stringstream ss;
        ss << "u_" << this->value;
        return ss.str();
    }

    bool operator==(const System_StateValue& data) const
    {
        return this->value == data.value;
    }
    bool operator==(int data) const
    {
        return this->value == data;
    }
    bool operator<(const System_StateValue& data) const
    {
        return this->value < data.value;
    }
    bool operator<(int data) const
    {
        return this->value < data;
    }
};

/**
 * \brief  Whether the device is pro licensed or not
 */
class IsPROLicensedValue : public ISerializable
{
public:
    int value;

    static constexpr int NotLicensed = 0;
    static constexpr int Licensed = 1;

    IsPROLicensedValue(int value) :
        value{value}
    {}

    IsPROLicensedValue() :
        value{-1}
    {}

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    std::string ToString() const
    {
        switch(value)
        {
        case IsPROLicensedValue::NotLicensed: return "Not Licensed";
        case IsPROLicensedValue::Licensed: return "Licensed";
        default: return "Invalid Value";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const IsPROLicensedValue& data)
    {
        os << data.ToString();
        return os;
    }

    std::string Serialize() const
    {
        std::stringstream ss;
        ss << "u_" << this->value;
        return ss.str();
    }

    bool operator==(const IsPROLicensedValue& data) const
    {
        return this->value == data.value;
    }
    bool operator==(int data) const
    {
        return this->value == data;
    }
    bool operator<(const IsPROLicensedValue& data) const
    {
        return this->value < data.value;
    }
    bool operator<(int data) const
    {
        return this->value < data;
    }
};

/**
 * \brief  Direction of the sensor to determine positive facing the LED side of
 *         the CANcoder.
 */
class SensorDirectionValue : public ISerializable
{
public:
    int value;

    static constexpr int CounterClockwise_Positive = 0;
    static constexpr int Clockwise_Positive = 1;

    SensorDirectionValue(int value) :
        value{value}
    {}

    SensorDirectionValue() :
        value{-1}
    {}

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    std::string ToString() const
    {
        switch(value)
        {
        case SensorDirectionValue::CounterClockwise_Positive: return "CounterClockwise_Positive";
        case SensorDirectionValue::Clockwise_Positive: return "Clockwise_Positive";
        default: return "Invalid Value";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const SensorDirectionValue& data)
    {
        os << data.ToString();
        return os;
    }

    std::string Serialize() const
    {
        std::stringstream ss;
        ss << "u_" << this->value;
        return ss.str();
    }

    bool operator==(const SensorDirectionValue& data) const
    {
        return this->value == data.value;
    }
    bool operator==(int data) const
    {
        return this->value == data;
    }
    bool operator<(const SensorDirectionValue& data) const
    {
        return this->value < data.value;
    }
    bool operator<(int data) const
    {
        return this->value < data;
    }
};

/**
 * \brief  True if device is locked by FRC.
 */
class FrcLockValue : public ISerializable
{
public:
    int value;

    static constexpr int Frc_Locked = 1;
    static constexpr int Frc_Unlocked = 0;

    FrcLockValue(int value) :
        value{value}
    {}

    FrcLockValue() :
        value{-1}
    {}

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    std::string ToString() const
    {
        switch(value)
        {
        case FrcLockValue::Frc_Locked: return "Frc_Locked";
        case FrcLockValue::Frc_Unlocked: return "Frc_Unlocked";
        default: return "Invalid Value";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const FrcLockValue& data)
    {
        os << data.ToString();
        return os;
    }

    std::string Serialize() const
    {
        std::stringstream ss;
        ss << "u_" << this->value;
        return ss.str();
    }

    bool operator==(const FrcLockValue& data) const
    {
        return this->value == data.value;
    }
    bool operator==(int data) const
    {
        return this->value == data;
    }
    bool operator<(const FrcLockValue& data) const
    {
        return this->value < data.value;
    }
    bool operator<(int data) const
    {
        return this->value < data;
    }
};

/**
 * \brief  True if the robot is enabled.
 */
class RobotEnableValue : public ISerializable
{
public:
    int value;

    static constexpr int Enabled = 1;
    static constexpr int Disabled = 0;

    RobotEnableValue(int value) :
        value{value}
    {}

    RobotEnableValue() :
        value{-1}
    {}

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    std::string ToString() const
    {
        switch(value)
        {
        case RobotEnableValue::Enabled: return "Enabled";
        case RobotEnableValue::Disabled: return "Disabled";
        default: return "Invalid Value";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const RobotEnableValue& data)
    {
        os << data.ToString();
        return os;
    }

    std::string Serialize() const
    {
        std::stringstream ss;
        ss << "u_" << this->value;
        return ss.str();
    }

    bool operator==(const RobotEnableValue& data) const
    {
        return this->value == data.value;
    }
    bool operator==(int data) const
    {
        return this->value == data;
    }
    bool operator<(const RobotEnableValue& data) const
    {
        return this->value < data.value;
    }
    bool operator<(int data) const
    {
        return this->value < data;
    }
};

/**
 * \brief  The Color of LED1 when it's "On".
 */
class Led1OnColorValue : public ISerializable
{
public:
    int value;

    static constexpr int Off = 0;
    static constexpr int Red = 1;
    static constexpr int Green = 2;
    static constexpr int Orange = 3;
    static constexpr int Blue = 4;
    static constexpr int Pink = 5;
    static constexpr int Cyan = 6;
    static constexpr int White = 7;

    Led1OnColorValue(int value) :
        value{value}
    {}

    Led1OnColorValue() :
        value{-1}
    {}

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    std::string ToString() const
    {
        switch(value)
        {
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

    friend std::ostream& operator<<(std::ostream& os, const Led1OnColorValue& data)
    {
        os << data.ToString();
        return os;
    }

    std::string Serialize() const
    {
        std::stringstream ss;
        ss << "u_" << this->value;
        return ss.str();
    }

    bool operator==(const Led1OnColorValue& data) const
    {
        return this->value == data.value;
    }
    bool operator==(int data) const
    {
        return this->value == data;
    }
    bool operator<(const Led1OnColorValue& data) const
    {
        return this->value < data.value;
    }
    bool operator<(int data) const
    {
        return this->value < data;
    }
};

/**
 * \brief  The Color of LED1 when it's "Off".
 */
class Led1OffColorValue : public ISerializable
{
public:
    int value;

    static constexpr int Off = 0;
    static constexpr int Red = 1;
    static constexpr int Green = 2;
    static constexpr int Orange = 3;
    static constexpr int Blue = 4;
    static constexpr int Pink = 5;
    static constexpr int Cyan = 6;
    static constexpr int White = 7;

    Led1OffColorValue(int value) :
        value{value}
    {}

    Led1OffColorValue() :
        value{-1}
    {}

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    std::string ToString() const
    {
        switch(value)
        {
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

    friend std::ostream& operator<<(std::ostream& os, const Led1OffColorValue& data)
    {
        os << data.ToString();
        return os;
    }

    std::string Serialize() const
    {
        std::stringstream ss;
        ss << "u_" << this->value;
        return ss.str();
    }

    bool operator==(const Led1OffColorValue& data) const
    {
        return this->value == data.value;
    }
    bool operator==(int data) const
    {
        return this->value == data;
    }
    bool operator<(const Led1OffColorValue& data) const
    {
        return this->value < data.value;
    }
    bool operator<(int data) const
    {
        return this->value < data;
    }
};

/**
 * \brief  The Color of LED2 when it's "On".
 */
class Led2OnColorValue : public ISerializable
{
public:
    int value;

    static constexpr int Off = 0;
    static constexpr int Red = 1;
    static constexpr int Green = 2;
    static constexpr int Orange = 3;
    static constexpr int Blue = 4;
    static constexpr int Pink = 5;
    static constexpr int Cyan = 6;
    static constexpr int White = 7;

    Led2OnColorValue(int value) :
        value{value}
    {}

    Led2OnColorValue() :
        value{-1}
    {}

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    std::string ToString() const
    {
        switch(value)
        {
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

    friend std::ostream& operator<<(std::ostream& os, const Led2OnColorValue& data)
    {
        os << data.ToString();
        return os;
    }

    std::string Serialize() const
    {
        std::stringstream ss;
        ss << "u_" << this->value;
        return ss.str();
    }

    bool operator==(const Led2OnColorValue& data) const
    {
        return this->value == data.value;
    }
    bool operator==(int data) const
    {
        return this->value == data;
    }
    bool operator<(const Led2OnColorValue& data) const
    {
        return this->value < data.value;
    }
    bool operator<(int data) const
    {
        return this->value < data;
    }
};

/**
 * \brief  The Color of LED2 when it's "Off".
 */
class Led2OffColorValue : public ISerializable
{
public:
    int value;

    static constexpr int Off = 0;
    static constexpr int Red = 1;
    static constexpr int Green = 2;
    static constexpr int Orange = 3;
    static constexpr int Blue = 4;
    static constexpr int Pink = 5;
    static constexpr int Cyan = 6;
    static constexpr int White = 7;

    Led2OffColorValue(int value) :
        value{value}
    {}

    Led2OffColorValue() :
        value{-1}
    {}

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    std::string ToString() const
    {
        switch(value)
        {
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

    friend std::ostream& operator<<(std::ostream& os, const Led2OffColorValue& data)
    {
        os << data.ToString();
        return os;
    }

    std::string Serialize() const
    {
        std::stringstream ss;
        ss << "u_" << this->value;
        return ss.str();
    }

    bool operator==(const Led2OffColorValue& data) const
    {
        return this->value == data.value;
    }
    bool operator==(int data) const
    {
        return this->value == data;
    }
    bool operator<(const Led2OffColorValue& data) const
    {
        return this->value < data.value;
    }
    bool operator<(int data) const
    {
        return this->value < data;
    }
};

/**
 * \brief  The range of the absolute sensor, either [0, 1) or [-0.5, 0.5).
 */
class AbsoluteSensorRangeValue : public ISerializable
{
public:
    int value;

    static constexpr int Unsigned_0To1 = 0;
    static constexpr int Signed_PlusMinusHalf = 1;

    AbsoluteSensorRangeValue(int value) :
        value{value}
    {}

    AbsoluteSensorRangeValue() :
        value{-1}
    {}

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    std::string ToString() const
    {
        switch(value)
        {
        case AbsoluteSensorRangeValue::Unsigned_0To1: return "Unsigned_0To1";
        case AbsoluteSensorRangeValue::Signed_PlusMinusHalf: return "Signed_PlusMinusHalf";
        default: return "Invalid Value";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const AbsoluteSensorRangeValue& data)
    {
        os << data.ToString();
        return os;
    }

    std::string Serialize() const
    {
        std::stringstream ss;
        ss << "u_" << this->value;
        return ss.str();
    }

    bool operator==(const AbsoluteSensorRangeValue& data) const
    {
        return this->value == data.value;
    }
    bool operator==(int data) const
    {
        return this->value == data;
    }
    bool operator<(const AbsoluteSensorRangeValue& data) const
    {
        return this->value < data.value;
    }
    bool operator<(int data) const
    {
        return this->value < data;
    }
};

/**
 * \brief  True if the device is enabled.
 */
class DeviceEnableValue : public ISerializable
{
public:
    int value;

    static constexpr int Enabled = 1;
    static constexpr int Disabled = 0;

    DeviceEnableValue(int value) :
        value{value}
    {}

    DeviceEnableValue() :
        value{-1}
    {}

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    std::string ToString() const
    {
        switch(value)
        {
        case DeviceEnableValue::Enabled: return "Enabled";
        case DeviceEnableValue::Disabled: return "Disabled";
        default: return "Invalid Value";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const DeviceEnableValue& data)
    {
        os << data.ToString();
        return os;
    }

    std::string Serialize() const
    {
        std::stringstream ss;
        ss << "u_" << this->value;
        return ss.str();
    }

    bool operator==(const DeviceEnableValue& data) const
    {
        return this->value == data.value;
    }
    bool operator==(int data) const
    {
        return this->value == data;
    }
    bool operator<(const DeviceEnableValue& data) const
    {
        return this->value < data.value;
    }
    bool operator<(int data) const
    {
        return this->value < data;
    }
};

/**
 * \brief  Forward Limit Pin.
 */
class ForwardLimitValue : public ISerializable
{
public:
    int value;

    static constexpr int ClosedToGround = 0;
    static constexpr int Open = 1;

    ForwardLimitValue(int value) :
        value{value}
    {}

    ForwardLimitValue() :
        value{-1}
    {}

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    std::string ToString() const
    {
        switch(value)
        {
        case ForwardLimitValue::ClosedToGround: return "Closed To Ground";
        case ForwardLimitValue::Open: return "Open";
        default: return "Invalid Value";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const ForwardLimitValue& data)
    {
        os << data.ToString();
        return os;
    }

    std::string Serialize() const
    {
        std::stringstream ss;
        ss << "u_" << this->value;
        return ss.str();
    }

    bool operator==(const ForwardLimitValue& data) const
    {
        return this->value == data.value;
    }
    bool operator==(int data) const
    {
        return this->value == data;
    }
    bool operator<(const ForwardLimitValue& data) const
    {
        return this->value < data.value;
    }
    bool operator<(int data) const
    {
        return this->value < data;
    }
};

/**
 * \brief  Reverse Limit Pin.
 */
class ReverseLimitValue : public ISerializable
{
public:
    int value;

    static constexpr int ClosedToGround = 0;
    static constexpr int Open = 1;

    ReverseLimitValue(int value) :
        value{value}
    {}

    ReverseLimitValue() :
        value{-1}
    {}

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    std::string ToString() const
    {
        switch(value)
        {
        case ReverseLimitValue::ClosedToGround: return "Closed To Ground";
        case ReverseLimitValue::Open: return "Open";
        default: return "Invalid Value";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const ReverseLimitValue& data)
    {
        os << data.ToString();
        return os;
    }

    std::string Serialize() const
    {
        std::stringstream ss;
        ss << "u_" << this->value;
        return ss.str();
    }

    bool operator==(const ReverseLimitValue& data) const
    {
        return this->value == data.value;
    }
    bool operator==(int data) const
    {
        return this->value == data;
    }
    bool operator<(const ReverseLimitValue& data) const
    {
        return this->value < data.value;
    }
    bool operator<(int data) const
    {
        return this->value < data;
    }
};

/**
 * \brief  The applied rotor polarity.  This typically is determined by the
 *         Inverted config, but can be overridden if using Follower features.
 */
class AppliedRotorPolarityValue : public ISerializable
{
public:
    int value;

    static constexpr int PositiveIsCounterClockwise = 0;
    static constexpr int PositiveIsClockwise = 1;

    AppliedRotorPolarityValue(int value) :
        value{value}
    {}

    AppliedRotorPolarityValue() :
        value{-1}
    {}

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    std::string ToString() const
    {
        switch(value)
        {
        case AppliedRotorPolarityValue::PositiveIsCounterClockwise: return "PositiveIsCounterClockwise";
        case AppliedRotorPolarityValue::PositiveIsClockwise: return "PositiveIsClockwise";
        default: return "Invalid Value";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const AppliedRotorPolarityValue& data)
    {
        os << data.ToString();
        return os;
    }

    std::string Serialize() const
    {
        std::stringstream ss;
        ss << "u_" << this->value;
        return ss.str();
    }

    bool operator==(const AppliedRotorPolarityValue& data) const
    {
        return this->value == data.value;
    }
    bool operator==(int data) const
    {
        return this->value == data;
    }
    bool operator<(const AppliedRotorPolarityValue& data) const
    {
        return this->value < data.value;
    }
    bool operator<(int data) const
    {
        return this->value < data;
    }
};

/**
 * \brief  The active control mode of the motor controller
 */
class ControlModeValue : public ISerializable
{
public:
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

    ControlModeValue(int value) :
        value{value}
    {}

    ControlModeValue() :
        value{-1}
    {}

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    std::string ToString() const
    {
        switch(value)
        {
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
        default: return "Invalid Value";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const ControlModeValue& data)
    {
        os << data.ToString();
        return os;
    }

    std::string Serialize() const
    {
        std::stringstream ss;
        ss << "u_" << this->value;
        return ss.str();
    }

    bool operator==(const ControlModeValue& data) const
    {
        return this->value == data.value;
    }
    bool operator==(int data) const
    {
        return this->value == data;
    }
    bool operator<(const ControlModeValue& data) const
    {
        return this->value < data.value;
    }
    bool operator<(int data) const
    {
        return this->value < data;
    }
};

/**
 * \brief  Check if Motion Magic® is running.  This is equivalent to checking
 *         that the reported control mode is a Motion Magic® based mode.
 */
class MotionMagicIsRunningValue : public ISerializable
{
public:
    int value;

    static constexpr int Enabled = 1;
    static constexpr int Disabled = 0;

    MotionMagicIsRunningValue(int value) :
        value{value}
    {}

    MotionMagicIsRunningValue() :
        value{-1}
    {}

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    std::string ToString() const
    {
        switch(value)
        {
        case MotionMagicIsRunningValue::Enabled: return "Enabled";
        case MotionMagicIsRunningValue::Disabled: return "Disabled";
        default: return "Invalid Value";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const MotionMagicIsRunningValue& data)
    {
        os << data.ToString();
        return os;
    }

    std::string Serialize() const
    {
        std::stringstream ss;
        ss << "u_" << this->value;
        return ss.str();
    }

    bool operator==(const MotionMagicIsRunningValue& data) const
    {
        return this->value == data.value;
    }
    bool operator==(int data) const
    {
        return this->value == data;
    }
    bool operator<(const MotionMagicIsRunningValue& data) const
    {
        return this->value < data.value;
    }
    bool operator<(int data) const
    {
        return this->value < data;
    }
};

/**
 * \brief  Invert state of the device
 */
class InvertedValue : public ISerializable
{
public:
    int value;

    static constexpr int CounterClockwise_Positive = 0;
    static constexpr int Clockwise_Positive = 1;

    InvertedValue(int value) :
        value{value}
    {}

    InvertedValue() :
        value{-1}
    {}

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    std::string ToString() const
    {
        switch(value)
        {
        case InvertedValue::CounterClockwise_Positive: return "CounterClockwise_Positive";
        case InvertedValue::Clockwise_Positive: return "Clockwise_Positive";
        default: return "Invalid Value";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const InvertedValue& data)
    {
        os << data.ToString();
        return os;
    }

    std::string Serialize() const
    {
        std::stringstream ss;
        ss << "u_" << this->value;
        return ss.str();
    }

    bool operator==(const InvertedValue& data) const
    {
        return this->value == data.value;
    }
    bool operator==(int data) const
    {
        return this->value == data;
    }
    bool operator<(const InvertedValue& data) const
    {
        return this->value < data.value;
    }
    bool operator<(int data) const
    {
        return this->value < data;
    }
};

/**
 * \brief  The state of the motor controller bridge when output is neutral or
 *         disabled.
 */
class NeutralModeValue : public ISerializable
{
public:
    int value;

    static constexpr int Coast = 0;
    static constexpr int Brake = 1;

    NeutralModeValue(int value) :
        value{value}
    {}

    NeutralModeValue() :
        value{-1}
    {}

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    std::string ToString() const
    {
        switch(value)
        {
        case NeutralModeValue::Coast: return "Coast";
        case NeutralModeValue::Brake: return "Brake";
        default: return "Invalid Value";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const NeutralModeValue& data)
    {
        os << data.ToString();
        return os;
    }

    std::string Serialize() const
    {
        std::stringstream ss;
        ss << "u_" << this->value;
        return ss.str();
    }

    bool operator==(const NeutralModeValue& data) const
    {
        return this->value == data.value;
    }
    bool operator==(int data) const
    {
        return this->value == data;
    }
    bool operator<(const NeutralModeValue& data) const
    {
        return this->value < data.value;
    }
    bool operator<(int data) const
    {
        return this->value < data;
    }
};

/**
 * \brief  Choose what sensor source is reported via API and used by closed-loop
 *         and limit features.  The default is RotorSensor, which uses the
 *         internal rotor sensor in the Talon FX.  Choose RemoteCANcoder to use
 *         another CANcoder on the same CAN bus (this also requires setting
 *         FeedbackRemoteSensorID).  Talon FX will update its position and
 *         velocity whenever CANcoder publishes its information on CAN bus. 
 *         Choose FusedCANcoder (requires Phoenix Pro) and Talon FX will fuse
 *         another CANcoder's information with the internal rotor, which
 *         provides the best possible position and velocity for accuracy and
 *         bandwidth (note this requires setting FeedbackRemoteSensorID). 
 *         FusedCANcoder was developed for applications such as swerve-azimuth.
 *
 * \details  Note: When the Talon Source is changed to FusedCANcoder, the Talon
 *           needs a period of time to fuse before sensor-based (soft-limit,
 *           closed loop, etc.) features are used. This period of time is
 *           determined by the update frequency of the CANcoder's Position
 *           signal.
 */
class FeedbackSensorSourceValue : public ISerializable
{
public:
    int value;

    static constexpr int RotorSensor = 0;
    static constexpr int RemoteCANcoder = 1;
    static constexpr int FusedCANcoder = 5;

    FeedbackSensorSourceValue(int value) :
        value{value}
    {}

    FeedbackSensorSourceValue() :
        value{-1}
    {}

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    std::string ToString() const
    {
        switch(value)
        {
        case FeedbackSensorSourceValue::RotorSensor: return "RotorSensor";
        case FeedbackSensorSourceValue::RemoteCANcoder: return "RemoteCANcoder";
        case FeedbackSensorSourceValue::FusedCANcoder: return "FusedCANcoder";
        default: return "Invalid Value";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const FeedbackSensorSourceValue& data)
    {
        os << data.ToString();
        return os;
    }

    std::string Serialize() const
    {
        std::stringstream ss;
        ss << "u_" << this->value;
        return ss.str();
    }

    bool operator==(const FeedbackSensorSourceValue& data) const
    {
        return this->value == data.value;
    }
    bool operator==(int data) const
    {
        return this->value == data;
    }
    bool operator<(const FeedbackSensorSourceValue& data) const
    {
        return this->value < data.value;
    }
    bool operator<(int data) const
    {
        return this->value < data;
    }
};

/**
 * \brief  Determines if limit is normally-open (default) or normally-closed.
 */
class ForwardLimitTypeValue : public ISerializable
{
public:
    int value;

    static constexpr int NormallyOpen = 0;
    static constexpr int NormallyClosed = 1;

    ForwardLimitTypeValue(int value) :
        value{value}
    {}

    ForwardLimitTypeValue() :
        value{-1}
    {}

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    std::string ToString() const
    {
        switch(value)
        {
        case ForwardLimitTypeValue::NormallyOpen: return "NormallyOpen";
        case ForwardLimitTypeValue::NormallyClosed: return "NormallyClosed";
        default: return "Invalid Value";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const ForwardLimitTypeValue& data)
    {
        os << data.ToString();
        return os;
    }

    std::string Serialize() const
    {
        std::stringstream ss;
        ss << "u_" << this->value;
        return ss.str();
    }

    bool operator==(const ForwardLimitTypeValue& data) const
    {
        return this->value == data.value;
    }
    bool operator==(int data) const
    {
        return this->value == data;
    }
    bool operator<(const ForwardLimitTypeValue& data) const
    {
        return this->value < data.value;
    }
    bool operator<(int data) const
    {
        return this->value < data;
    }
};

/**
 * \brief  Determines where to poll the forward limit switch.  This defaults to
 *         the limit switch pin on the limit switch connector.
 */
class ForwardLimitSourceValue : public ISerializable
{
public:
    int value;

    static constexpr int LimitSwitchPin = 0;

    ForwardLimitSourceValue(int value) :
        value{value}
    {}

    ForwardLimitSourceValue() :
        value{-1}
    {}

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    std::string ToString() const
    {
        switch(value)
        {
        case ForwardLimitSourceValue::LimitSwitchPin: return "LimitSwitchPin";
        default: return "Invalid Value";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const ForwardLimitSourceValue& data)
    {
        os << data.ToString();
        return os;
    }

    std::string Serialize() const
    {
        std::stringstream ss;
        ss << "u_" << this->value;
        return ss.str();
    }

    bool operator==(const ForwardLimitSourceValue& data) const
    {
        return this->value == data.value;
    }
    bool operator==(int data) const
    {
        return this->value == data;
    }
    bool operator<(const ForwardLimitSourceValue& data) const
    {
        return this->value < data.value;
    }
    bool operator<(int data) const
    {
        return this->value < data;
    }
};

/**
 * \brief  Determines if limit is normally-open (default) or normally-closed.
 */
class ReverseLimitTypeValue : public ISerializable
{
public:
    int value;

    static constexpr int NormallyOpen = 0;
    static constexpr int NormallyClosed = 1;

    ReverseLimitTypeValue(int value) :
        value{value}
    {}

    ReverseLimitTypeValue() :
        value{-1}
    {}

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    std::string ToString() const
    {
        switch(value)
        {
        case ReverseLimitTypeValue::NormallyOpen: return "NormallyOpen";
        case ReverseLimitTypeValue::NormallyClosed: return "NormallyClosed";
        default: return "Invalid Value";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const ReverseLimitTypeValue& data)
    {
        os << data.ToString();
        return os;
    }

    std::string Serialize() const
    {
        std::stringstream ss;
        ss << "u_" << this->value;
        return ss.str();
    }

    bool operator==(const ReverseLimitTypeValue& data) const
    {
        return this->value == data.value;
    }
    bool operator==(int data) const
    {
        return this->value == data;
    }
    bool operator<(const ReverseLimitTypeValue& data) const
    {
        return this->value < data.value;
    }
    bool operator<(int data) const
    {
        return this->value < data;
    }
};

/**
 * \brief  Determines where to poll the reverse limit switch.  This defaults to
 *         the limit switch pin on the limit switch connector.
 */
class ReverseLimitSourceValue : public ISerializable
{
public:
    int value;

    static constexpr int LimitSwitchPin = 0;

    ReverseLimitSourceValue(int value) :
        value{value}
    {}

    ReverseLimitSourceValue() :
        value{-1}
    {}

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    std::string ToString() const
    {
        switch(value)
        {
        case ReverseLimitSourceValue::LimitSwitchPin: return "LimitSwitchPin";
        default: return "Invalid Value";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const ReverseLimitSourceValue& data)
    {
        os << data.ToString();
        return os;
    }

    std::string Serialize() const
    {
        std::stringstream ss;
        ss << "u_" << this->value;
        return ss.str();
    }

    bool operator==(const ReverseLimitSourceValue& data) const
    {
        return this->value == data.value;
    }
    bool operator==(int data) const
    {
        return this->value == data;
    }
    bool operator<(const ReverseLimitSourceValue& data) const
    {
        return this->value < data.value;
    }
    bool operator<(int data) const
    {
        return this->value < data;
    }
};

/**
 * \brief  Magnet health as measured by CANcoder.
 *
 * \details  Magnet health as measured by CANcoder. Red indicates too close or
 *           too far, Orange is adequate but with reduced accuracy, green is
 *           ideal. Invalid means the accuracy cannot be determined.
 */
class MagnetHealthValue : public ISerializable
{
public:
    int value;

    static constexpr int Magnet_Red = 1;
    static constexpr int Magnet_Orange = 2;
    static constexpr int Magnet_Green = 3;
    static constexpr int Magnet_Invalid = 0;

    MagnetHealthValue(int value) :
        value{value}
    {}

    MagnetHealthValue() :
        value{-1}
    {}

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    std::string ToString() const
    {
        switch(value)
        {
        case MagnetHealthValue::Magnet_Red: return "Magnet_Red";
        case MagnetHealthValue::Magnet_Orange: return "Magnet_Orange";
        case MagnetHealthValue::Magnet_Green: return "Magnet_Green";
        case MagnetHealthValue::Magnet_Invalid: return "Magnet_Invalid";
        default: return "Invalid Value";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const MagnetHealthValue& data)
    {
        os << data.ToString();
        return os;
    }

    std::string Serialize() const
    {
        std::stringstream ss;
        ss << "u_" << this->value;
        return ss.str();
    }

    bool operator==(const MagnetHealthValue& data) const
    {
        return this->value == data.value;
    }
    bool operator==(int data) const
    {
        return this->value == data;
    }
    bool operator<(const MagnetHealthValue& data) const
    {
        return this->value < data.value;
    }
    bool operator<(int data) const
    {
        return this->value < data;
    }
};

/**
 * \brief  The applied output of the bridge.
 */
class BridgeOuputValue : public ISerializable
{
public:
    int value;

    static constexpr int BridgeReq_Coast = 0;
    static constexpr int BridgeReq_Brake = 1;
    static constexpr int BridgeReq_Trapez = 6;
    static constexpr int BridgeReq_FOCTorque = 7;
    static constexpr int BridgeReq_MusicTone = 8;
    static constexpr int BridgeReq_FOCEasy = 9;
    static constexpr int BridgeReq_FaultBrake = 12;
    static constexpr int BridgeReq_FaultCoast = 13;

    BridgeOuputValue(int value) :
        value{value}
    {}

    BridgeOuputValue() :
        value{-1}
    {}

    /**
     * \brief Gets the string representation of this enum
     *
     * \returns String representation of this enum
     */
    std::string ToString() const
    {
        switch(value)
        {
        case BridgeOuputValue::BridgeReq_Coast: return "BridgeReq_Coast";
        case BridgeOuputValue::BridgeReq_Brake: return "BridgeReq_Brake";
        case BridgeOuputValue::BridgeReq_Trapez: return "BridgeReq_Trapez";
        case BridgeOuputValue::BridgeReq_FOCTorque: return "BridgeReq_FOCTorque";
        case BridgeOuputValue::BridgeReq_MusicTone: return "BridgeReq_MusicTone";
        case BridgeOuputValue::BridgeReq_FOCEasy: return "BridgeReq_FOCEasy";
        case BridgeOuputValue::BridgeReq_FaultBrake: return "BridgeReq_FaultBrake";
        case BridgeOuputValue::BridgeReq_FaultCoast: return "BridgeReq_FaultCoast";
        default: return "Invalid Value";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const BridgeOuputValue& data)
    {
        os << data.ToString();
        return os;
    }

    std::string Serialize() const
    {
        std::stringstream ss;
        ss << "u_" << this->value;
        return ss.str();
    }

    bool operator==(const BridgeOuputValue& data) const
    {
        return this->value == data.value;
    }
    bool operator==(int data) const
    {
        return this->value == data;
    }
    bool operator<(const BridgeOuputValue& data) const
    {
        return this->value < data.value;
    }
    bool operator<(int data) const
    {
        return this->value < data;
    }
};


}
}
}
