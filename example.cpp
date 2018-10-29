#include "ctre/Phoenix.h"
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include "Platform-linux-socket-can.h"
#include <SDL2/SDL.h>
#include <unistd.h>

using namespace ctre::phoenix;
using namespace ctre::phoenix::platform;
using namespace ctre::phoenix::motorcontrol;
using namespace ctre::phoenix::motorcontrol::can;

TalonSRX * talLeft = 0;
TalonSRX * talRght = 0;

void initDrive()
{
    talLeft = new TalonSRX(1);
    talRght = new TalonSRX(0);
    talRght->SetInverted(true);
}

void drive(double left, double rght)
{
    talLeft->Set(ControlMode::PercentOutput, left);
    talRght->Set(ControlMode::PercentOutput, rght);
}

void sleepApp(int ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

int main() {
    std::cout << "Please input the name of your can interface: ";
    std::string interface;
    //std::cin >> interface;
    interface = "can0";

    ctre::phoenix::platform::can::SetCANInterface(interface.c_str());

    initDrive();

    while (true) {

        drive(0,0);

        // wait for gamepad
        printf("Waiting for gamepad\n");
        while (true) {

            // Initialize the joystick subsystem
            SDL_Quit();
                                                                                                                                                                                                            46,0-1        Top
