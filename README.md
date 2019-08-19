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
- [Jetson TX2 (linux-aarch64)] (lib/jetsontx)

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

## Using Raspbian Buster Raspberry Pi image to control your robot

### Materials needed:
 - Raspberry Pi (3B+)
 - Micro SD card
 - CANable with CandleLight Firmware (https://canable.io/updater/ update here if not already done)
 - Laptop
 - Raspbian Buster with desktop  (https://www.raspberrypi.org/downloads/raspbian/)


### Procedure:
 1. Flash SD card with Raspbian Dessktop image.(see https://www.raspberrypi.org/documentation/installation/installing-images/README.md)
 2. Boot your pi and connect to a wifi network(if you'd like to use tuner on a windows pc make sure your windows pc and raspberry pi is connected to the same network.
 3. Open a terminal in the raspberry pi.
 4. Install CAN tools `sudo apt-get install can-utils`.
 5. Install git `sudo apt-get install git`.
 6. Install necessary libs to build example.  
     -  `sudo apt-get install cmake`  
     -  `sudo apt-get install libsdl2-dev `  
 7. Clone repo into user directory `git clone https://github.com/CrossTheRoadElec/Phoenix-Linux-SocketCAN-Example.git`
 8. Navigate into repo `cd ./Phoenix-Linux-SocketCAN-Example/`.
 9. Chmod shell scripts to allow you to use them:
     -  `chmod +x build.sh`
     -  `chmod +x clean.sh`
     -  `chmod +x canableStart.sh`
 10. Bring up CAN0 `./canableStart.sh` -> `sudo ifconfig can0 up` 
 11. Run build.sh `./build.sh`
 12. Run program `./bin/example`
 13. You're now running Phoenix on a raspberry pi.  Confirm there are no error messages being sent to console output.

If your talons do not appear to enable when operating with the gamepad plugged dirrectly into the pi it's possible that they are frc locked.
Follow the instructions below to clear frc lock without Phoenix Tuner.   
1.Remove power from each talon.   
2.With the talon you'd like to clear unpowered hold the B/C cal button and apply power.  
3.Once the talon leds flash green you can release the B/C cal button.  
4.The talon is no longer frc locked.  

Currently only the Raspberry Pi 3 running ubuntu mate supports Phoenix tuner.
Future updates will expand compatibility.


# Jetson nano setup
Setup nano using instructions from Nvidia. 
https://developer.nvidia.com/embedded/learn/get-started-jetson-nano-devkit#intro  
Once you have your nano setup open a terminal and run the following commands to install necessary files.  
    
`sudo apt-get install update`  
`sudo apt-get install upgrade`  
Once this is completed continue to the  Example setup.  
#### Example setup: 
1.	Install CAN tools `sudo apt-get install can-utils`.
2.	Install git `sudo apt-get install git`.  
3.	Install necessary libs to build example.   
		`sudo apt-get install cmake`  
		`sudo apt-get install libsdl2-dev`  
4.	adding files for hotswapping compatibility 
5.	Open a new terminal
6.	Type `cd /etc/network/.`
7.	Type `sudo gedit interfaces`
8.	Copy the following lines into the file and click save  
    `allow-hotplug can0`    
    `iface can0 can static`     
    `bitrate 1000000`    
    `up /sbin/ip link set $IFACE down`    
    `up /sbin/ip link set $IFACE up type can`    
    Your file should look like this when finished.
![sudo](https://user-images.githubusercontent.com/51933047/63291621-e9332380-c291-11e9-8eac-91f53e9e89ce.png)
9.	When saving you may get a warning in your terminal; this is expected and not an issue.
10.	Clone repo into user directory `git clone https://github.com/CrossTheRoadElec/Phoenix-Linux-SocketCAN-Example.git`
11.	Navigate into repo `cd ./Phoenix-Linux-SocketCAN-Example/.`
12.	`git checkout addJetsonTx` 
13.	Chmod shell scripts to allow you to use them:
	`chmod +x build.sh`
	`chmod+x clean.sh`
	`chmod+x canableStart.sh`
14.	Bring up can 0 `./canableStart.sh`  or `sudo ifconfig can0 up`
15.	Run Build.sh `./build.sh`
16.	Run program `./bin/example`
17.	You're now running Phoenix on a Jetson nano. Confirm there are no error messages being sent to console output.
18.	If you get the error `SocketCan: No buffer space available`.
19.	Stop your Program with `Ctrl+z`.
20.	Run the command `sudo ifconfig can0 txqueuelen 1000`.  
21.	Restart your program with `./bin/example`.



### Connecting to Diag server:
1.	Make sure your Nvidia jetson is connected to the same wifi network as the windows pc you want to run tuner on 
2.	Open a terminal on the jetson and run `ifconfig`.
3.	![ip](https://user-images.githubusercontent.com/51933047/63195155-e214d700-c03f-11e9-949a-33190ce20944.PNG)
4.	Find the ip listed under wlan0 and next to inet. 
5.	Enter your ip into Phoenix tuner. 
6.	Click `Install Phoenix Library/Diagnostics`.
7.	Enter your user name and password when prompted.(To find your user name look at the text before the `@` in the terminal).  
	In this terminal the user is `ctre`.
	![image](https://user-images.githubusercontent.com/51933047/63195027-7fbbd680-c03f-11e9-9e5e-c310d0eebff4.PNG)
8.	Tuner will then install and start the diag server on the jetson.
9.	The diagnostics server is now installed and running on your jetson.
#### Errata: The wireless Logitech f710 is currently not supported on the nvidia jetson nano due to a driver issue.

