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


## Using FRCVision Raspberry Pi image to control your robot

### Materials needed:
 - Raspberry Pi (3B+)
 - Micro SD card
 - CANable with CandleLight Firmware
 - Laptop
 - [FRC Vision Image](https://github.com/wpilibsuite/FRCVision-pi-gen/releases)

### Network Topology:
This guide was tested with a Windows PC, which can bridge two network adapters.
The typical setup is to connect one network adapter to the Raspberry Pi, and another network to the Internet.  The windows “network bridge” feature is then used to bridge both networks, which provides Internet to the Raspberry PI.

### Procedure:
 1. Flash SD card with FRC vision image.
 2. Use Windows computer and network bridging to (or alternative strategy) to provide Internet to the Raspberry PI.
 3. Connect to raspberry pi directly over Ethernet.
 4. SSH into raspberry pi using its DNS IP `ssh frcvision.local -lpi`
     - Username is pi
     - Password is raspberry
 5. Connect to internet over WiFi/other Ethernet port.
 6. Bridge internet and raspberry pi.
    1. Open network adapters/network connections (Control Panel/Network and Internet/Network Connections)
    2. Highlight both connections.
    3. Right-Click and select bridge.
 7. Set raspberry pi to write mode by navigating to frcvision.local on webpage, and pressing Writable button at top.
 8. Install CAN tools `sudo apt-get install can-utils`.
 9. Install git `sudo apt-get install git`.
 10. Install necessary libs to build example.
     -  `sudo apt-get install cmake`
     -  `sudo apt-get install libsdl2-dev `
 11. Clone repo into user directory `git clone https://github.com/CrossTheRoadElec/Phoenix-Linux-SocketCAN-Example.git`
 12. Navigate into repo `cd ./Phoenix-Linux-SocketCAN-Example/`.
 13. Chmod shell scripts to allow you to use them:
     -  `chmod +x build.sh`
     -  `chmod +x clean.sh`
     -  `chmod +x canableStart.sh`
 14. Bring up CAN0 `./canableStart.sh` -> `sudo ifconfig can0 up` 
 15. Run build.sh `./build.sh`
 16. Run program `./bin/example`
 17. You're now running Phoenix on a raspberry pi.  Confirm there are no error messages being sent to console output.
