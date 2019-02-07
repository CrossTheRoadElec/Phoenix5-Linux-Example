# Phoenix-Linux-SocketCAN-Example

General example using CTRE Phoenix class library on Linux/RaspPi platforms.
Two use cases are demonstrated...
- Run robot with **no roboRIO** for nonFRC usecases (wireless gamepad plugged into Raspberry PI).
- Run  robot **with roboRIO** in FRC competition (roboRIO is used for gamepad and enable/disable, Talons controlled from Raspberry PI).

Note: Requires libsdl2-dev (sudo apt-get install libsdl2-dev) for USB Gamepad interface on Raspberry PI.

Note: There is no more FRC versus nonFRC firmware.  Latest Talon/Victor firmware works for both use cases.

Simple example here, we use libSDL2 to get gamepad values...
- [example.cpp](example.cpp)

Library binaries here
- [Raspberry PI (linux-armhf) ](lib/raspberry)
- [Linux Desktop (linux-amd64)](lib/x86-64)

This is the requisite platform interface for the integrator to provide for other platforms.
- [include/ctre/phoenix/Platform/Platform.h](include/ctre/phoenix/Platform/Platform.h)

If you link in phoenix-can-utils, you don't need to implement   CANComm_* , just implement   CANbus_*.  Conversely you can just implement the mid-level and don't bother with the low-level.
- [include/ctre/phoenix/Platform/Platform.h#L27](include/ctre/phoenix/Platform/Platform.h#L27)

#### Binaries
| Name        |  Notes |
| ------------- | ------------- |
| libCTRE_PhoenixPlatformLinuxSocketCan.a | Platform implementation to support USB-to-CANbus adapters in Linux (see parent folder for arch).|
| libCTRE_PhoenixCanutils.a | Implements CANComm_* routines so you don't have to.  But if you want to, remove this from the link list. |
| libCTRE_PhoenixCCI.a | Phoenix Common C Interface, leave this be. |
| libCTRE_Phoenix.a | Class library, this is built from Phoenix-frc-lib. |

For the latest version of binaries, see our maven repository here:  
http://devsite.ctr-electronics.com/maven/release/com/ctre/phoenix/

#### CAN USB Adapter
SocketCAN USB adapter used below.
- Firmware : https://github.com/HubertD/candleLight_fw
- Hardware : http://canable.io/

Or alternatively deploy the SocketCAN firmware to a HERO
- Firmware : https://github.com/CrossTheRoadElec/HERO-STM32F4
- Hardware : http://www.ctr-electronics.com/control-system/hro.html

#### Test Platform
Test robot has a RaspPi + CANable.
![image](https://user-images.githubusercontent.com/14191527/48369511-c7fb3200-e684-11e8-8188-a9b38075beb3.png)

Robot also has an FRC roboRIO - however this only necessary to enable actuators if CTRE CAN devices are FRC-Locked.  See Phoenix Tuner to determine/modify FRC Lock state.
