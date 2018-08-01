# GenericLinuxCanDeviceExample

General example using CTRE Phoenix class library on Linux/RaspPi platforms.

Requires libsdl2-dev (sudo apt-get install libsdl2-dev) for USB Gamepad interface.

Simple example here, we use libSDL2 to get gamepad values...
- [example.cpp](example.cpp)

Library binaries here
- [Raspberry PI (linux-armhf) ](lib/raspberry)
- [Linux Desktop (linux-arm64)](lib/x86-64)

This is the requisite platform interface for the integrator to provide for other platforms.
- [include/ctre/phoenix/Platform/Platform.h](include/ctre/phoenix/Platform/Platform.h)

If you link in phoenix-can-utils, you don't need to implement   CANComm_* , just implement   CANbus_*.  Conversly you can just implement the mid-level and don't bother with the low-level.
- [include/ctre/phoenix/Platform/Platform.h#L27](include/ctre/phoenix/Platform/Platform.h#L27)

#### Binaries
| Name        |  Notes |
| ------------- | ------------- |
| libCTRE_PhoenixPlatformLinuxSocketCan.a | Platform implementation to support usb-to-can adapaters in linux (see parent folder for arch).|
| libCTRE_PhoenixCanutils.a | Implements CANComm_* routines so you don't have to.  But if you want to, remove this from the link list. |
| libCTRE_PhoenixCCI.a | Phoenix Common C Interface, leave this be. |
| libCTRE_Phoenix.a | Class library, this is built from Phoenix-frc-lib. |

#### CAN USB Adapter
CAN adapter used below.
- Firmware : https://github.com/HubertD/candleLight_fw
- Hardware : http://canable.io/
