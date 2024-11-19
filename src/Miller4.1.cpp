#include "vex.h"
#include <string>
using std::string;
using namespace vex;

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
//Opens claw
void open() {
  clawMotor.spinFor(reverse, 160, degrees);
}
//Closes claw
void close() {
  clawMotor.spinFor(160, degrees);
}
int main() {
  for(int i = 0; i <= 4; i++) {
    Drive.driveFor(12, inches);
    print("Drive");
    Drive.stop();
    wait(1, seconds);
    Drive.turnFor(right, 65, degrees);
    Brain.Screen.clearScreen();
    print("Turn");
    Drive.stop();
    wait(1, seconds);
    Brain.Screen.clearScreen();
  }
  //full turn
  print("out of loop");
  Drive.turnFor(right, 70, degrees);
  Drive.stop();
  wait(1, seconds);
  
  //Counter clockwise square
  for(int i = 0; i < 4; i++) {
    Drive.driveFor(12, inches);
    Drive.stop();
    wait(1, seconds);
    Drive.turnFor(left, 65, degrees);
    Drive.stop();
    wait(1, seconds);
  }
}
