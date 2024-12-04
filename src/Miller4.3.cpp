#include "vex.h"
#include <string>
using std::string;
using namespace vex;

//Initializes motors, controller, and drivetrain
brain Brain;
motor armMotor = motor(PORT8, ratio18_1, false);
motor clawMotor = motor(PORT3, ratio18_1, false);
controller Controller = controller();
motor left_motor = motor(PORT1, false);
motor right_motor = motor(PORT10, true);
drivetrain Drive = drivetrain(left_motor, right_motor, 259.34, 320, 40, mm, 1);
bumper bumperA = bumper(Brain.ThreeWirePort.A);

//Simple print method to print a string to the brain screen
void print(string text) {
  Brain.Screen.print(text.c_str());
}
//Raises arm to a 160 degree angle
void raise() {
  armMotor.spinFor(360, degrees);
}
//Lowers arm from a 160 degree angle
void lower() {
  armMotor.spinFor(reverse, 400, degrees);
}
//Opens claw to a 160 degree angle
void open() {
  clawMotor.spinFor(reverse, 140, degrees);
}
//Closes claw from 160 degree angle
void close() {
    clawMotor.spinFor(140, degrees);
}

int main () {
    //Drives forward until bumper is pressed
    while(bumperA.pressing() == 0) {
        Drive.drive(reverse);
    }
    //Stops and drives foward 4 inches and waits 1 second
    Drive.stop();
    Drive.driveFor(4, inches);
    Drive.stop();
    wait(1, seconds);
    //Turns 180 degrees and raises/lowers arm and opens/closes claw CHANGE FROM INITIAL - Angle to 120
    Drive.turnFor(120, degrees);
    raise();
    wait(1, seconds);
    lower();
    wait(1, seconds);
    open();
    wait(1, seconds);
    close();
}