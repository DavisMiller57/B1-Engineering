#include "vex.h"
#include <string>
#include "lib.cpp"
using std::string;
using namespace vex;

//Initializes motors, controller, and drivetrain
motor armMotor = motor(PORT8, ratio18_1, false);
motor clawMotor = motor(PORT3, ratio18_1, false);
controller Controller = controller();
motor left_motor = motor(PORT1, false);
motor right_motor = motor(PORT10, true);
drivetrain Drive = drivetrain(left_motor, right_motor, 259.34, 320, 40, mm, 1);

//Simple print method to print a string to the brain screen
void print(string text) {
  Brain.Screen.print(text.c_str());
}
//Raises arm to a 160 degree angle
void raise() {
  armMotor.spinFor(160, degrees);
}
//Lowers arm from a 160 degree angle
void lower() {
  armMotor.spinFor(reverse, 160, degrees);
}
//Opens claw to a 160 degree angle
void open() {
  clawMotor.spinFor(reverse, 160, degrees);
}
//Closes claw from 160 degree angle
void close() {
    clawMotor.spinFor(160, degrees);
}

//Main program logic - Autonomous Retrial
int main() {
    //Sets claw open prior to leaving starting position
    clawMotor.spinFor(reverse, 360, degrees);
    //Drives foward just over 3 feet to account for any error
    Drive.driveFor(40, inches);
    //redundant stop of robot motion 
    Drive.stop();
    //Closes claw to grab object
    clawMotor.spinFor(250, degrees);
    //Adds wait time to allow claw to close
    wait(1, seconds);
    //Raises claw
    raise();
    //Full spin to turn around, using 135º from 4.1 due to robot processing errors
    Drive.turnFor(right, 135, degrees);
    //Drives forward to return to starting position
    Drive.driveFor(40, inches);
    //Opens claw to drop ball
    open();
}