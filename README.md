# Phoenix-Linux-SocketCAN-Example

General example using CTRE Phoenix class library on Linux/RaspPi platforms.
Two use cases are demonstrated...
- Run robot with **no roboRIO** for nonFRC use cases (wireless gamepad plugged into Raspberry PI).
- Run  robot **with roboRIO** in FRC competition (roboRIO is used for gamepad and enable/disable, Talons controlled from Raspberry PI).

Note: Requires libsdl2-dev (sudo apt-get install libsdl2-dev) for USB Gamepad interface on Raspberry PI.

Note: There is no more FRC versus nonFRC firmware.  Latest Talon/Victor firmware works for both use cases.

Simple example here, we use libSDL2 to get gamepad values...
- [example.cpp](example.cpp)

Library binaries here
- [Raspberry PI (linux-armhf) ](lib/raspberry)
- [Linux Desktop (linux-amd64)](lib/x86-64)
- [Jetson TX2 (linux-aarch64)](lib/jetsontx)

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

# Using Raspbian Buster Raspberry Pi image to control your robot

### Materials needed:
 - Raspberry Pi (3B+)
 - Micro SD card
 - CANable with CandleLight Firmware (https://canable.io/updater/ update here if not already done)
 - Laptop
 - Raspbian Buster with desktop (https://www.raspberrypi.org/downloads/raspbian/)


### Procedure:
 1. Flash SD card with Raspbian Desktop image. (see https://www.raspberrypi.org/documentation/installation/installing-images/README.md)
 2. Boot your Pi and connect to a Wi-Fi network (if you'd like to use Tuner on a windows PC make sure your windows PC and Raspberry Pi is connected to the same network.
 3. Continue with Software Setup.


# Jetson Nano setup
### Materials needed:
 - Jetson Nano
 - Micro SD card
 - CANable with CandleLight Firmware (https://canable.io/updater/ update here if not already done)
 - Laptop  
 1. Setup Jetson Nano using instructions from Nvidia. 
https://developer.nvidia.com/embedded/learn/get-started-jetson-nano-devkit#intro  
2. Continue with Software Setup.

# Software Setup: 
1. Once you have your Device setup open a terminal and run the following commands to install necessary files.  
     -  `sudo apt-get upgrade`  
     -  `sudo apt-get update`    
     -  `sudo apt-get upgrade`  
1.	Install CAN tools `sudo apt-get install can-utils`.
2.	Install git `sudo apt-get install git`.  
3.	Install necessary libs to build example.   
     -  `sudo apt-get install cmake`  
     -  `sudo apt-get install libsdl2-dev`    
4. Clone repo into user directory `git clone https://github.com/CrossTheRoadElec/Phoenix-Linux-SocketCAN-Example.git`.  
5. Navigate into repo `cd ./Phoenix-Linux-SocketCAN-Example/.`
13.	Chmod shell scripts to allow you to use them:  
     -  `chmod +x build.sh`  
     -  `chmod +x clean.sh`  
     -  `chmod +x canableStart.sh`  
14.	Bring up can 0 `./canableStart.sh` (if you see the message `Device or resource busy` it means the can network is already up and requires no further action).   
     
# Validating SocketCan functionality 
1. Make sure you have talons or another CTRE CAN device connected for validation of can network.
2. Use `ifconfig` to display status of the CAN socket.
2. The first network listed should be can0 and should look like this
![can0](https://user-images.githubusercontent.com/51933047/63381988-c6733e80-c367-11e9-91fc-7e2f620fea02.png).  
3. Type `cansend can0 999#DEADBEEF` to send a CAN frame, your talons should now blink orange since a valid CAN message has been seen.
4. Use `candump can0` to see all incoming CAN traffic, which should display all periodic information being sent by a Talon.  
5. You should see a constant stream of messages similar to this:![candump](https://user-images.githubusercontent.com/51933047/63384109-2f5cb580-c36c-11e9-8688-d3fa774eab43.png)
6. To end the stream press `Ctrl+z`.



## Set up hot swapping
1. adding files for hot swapping compatibility 
5. Open a new terminal
6. Type `cd /etc/network/.`
7. Type `sudo gedit interfaces`
8. Copy the following lines into the file and click save  
    `allow-hotplug can0`    
    `iface can0 can static`     
    `bitrate 1000000`    
    `up /sbin/ip link set $IFACE down`    
    `up /sbin/ip link set $IFACE up type can`    
    Your file should look like this when finished.
![sudo](https://user-images.githubusercontent.com/51933047/63291621-e9332380-c291-11e9-8eac-91f53e9e89ce.png)
9.	When saving you may get a warning in your terminal; this is expected and not an issue.
10. Type `cd`.

# Connecting to Diagnostics server:
1. Make sure your device is connected to the same Wi-Fi network as the windows PC you want to run Tuner on. 
2. Open a terminal on the device and run `ifconfig`.
4. Find the ip listed under wlan0 and next to inet. (**Note: depending on your connection setup the ip you want to use may be under a different wlan#**).   
![ip](https://user-images.githubusercontent.com/51933047/63195155-e214d700-c03f-11e9-949a-33190ce20944.PNG)  
5. Enter your ip into Phoenix tuner. 
6. Click `Install Phoenix Library/Diagnostics`.
7. Enter your username and password when prompted. (**Note: The user must have sudo permissions to successfully install Tuner** ).  
	(To find your username look at the text before the `@` in the terminal for example in this terminal the user is `ctre`. ).  
	![image](https://user-images.githubusercontent.com/51933047/63195027-7fbbd680-c03f-11e9-9e5e-c310d0eebff4.PNG)
8. Tuner will then install and start the diagnostics server on the device.
9. The diagnostics server is now installed and running on your device.
10. See https://phoenix-documentation.readthedocs.io/en/latest/ch08_BringUpCAN.html?highlight=field%20upgrade#field-upgrade-devices for information about field upgrading your devices to the latest version.
10. Once connected see  https://phoenix-documentation.readthedocs.io/en/latest/ch13_MC.html?highlight=frc%20lock#confirm-frc-unlock
to confirm the device you are using is not frc locked.


# Running Socket Can Example: 
1.	Run Build.sh with `./build.sh`.
16.	Run program with `./bin/example`.
17.	You're now running Phoenix on your device. Confirm there are no error messages being sent to console output.
19.	You can stop your Program with `Ctrl+z`.

#### Errata: The wireless Logitech F710 is currently not supported on the Nvidia Jetson Nano due to a driver issue.

