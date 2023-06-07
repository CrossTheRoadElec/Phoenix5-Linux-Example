/*
 * Copyright (C) Cross The Road Electronics.  All rights reserved.
 * License information can be found in CTRE_LICENSE.txt
 * For support and suggestions contact support@ctr-electronics.com or file
 * an issue tracker at https://github.com/CrossTheRoadElec/Phoenix-Releases
 */
#pragma once

namespace ctre {
namespace phoenix {
namespace platform {

    /** List of all supported device types */
    #define kDeviceTypeListInitializer	\
        TalonSRXType,	\
        VictorSPXType,	\
        PigeonIMUType,	\
        RibbonPigeonIMUType,	\
        TalonFXType,	\
        CANCoderType,	\
        PRO_TalonFXType,	\
        PRO_CANcoderType,	\
        PRO_Pigeon2Type

    /** Enumeration of all supported device types. */
    enum DeviceType {kDeviceTypeListInitializer};

}
}
}
