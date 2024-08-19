/* Copyright (C) Cross The Road Electronics 2024 */
#pragma once

namespace ctre {
namespace phoenix {
namespace led {

/** Enumerated type for status frame types. */
enum CANdleStatusFrame {
    CANdleStatusFrame_Status_1_General              = 0x041400,
    CANdleStatusFrame_Status_2_Startup              = 0x041440,
    CANdleStatusFrame_Status_3_FirmwareApiStatus    = 0x041480,
    CANdleStatusFrame_Status_4_ControlTelem         = 0x0414C0,
    CANdleStatusFrame_Status_5_PixelPulseTrain      = 0x041500,
    CANdleStatusFrame_Status_6_BottomPixels         = 0x041540,
    CANdleStatusFrame_Status_7_TopPixels            = 0x041580,
};

} // namespace led
} // namespace phoenix
} // namespace ctre
