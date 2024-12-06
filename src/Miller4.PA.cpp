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
//Waits for 1 second
void wait1() {
    wait(1, seconds);
}


int main() {
  //Raises arm with specmien in it
  raise();
  //Drives to the first rung
  Drive.driveFor(36, inches);
  //Lowers arm to hook on rung
  armMotor.spinFor(reverse, 200, degrees);
  //Opens claw to release specimen
  open();
  //Lowers arm fully
  armMotor.spinFor(reverse, 200, degrees);
  //Backs up from rung
  Drive.driveFor(reverse, 12, inches);
  //Turns to face samples
  Drive.turnFor(right, 90, degrees);
  //Drives to samples 
  Drive.driveFor(36, inches);
  //Turns and picks up sample
  Drive.turnFor(left, 45, degrees);
  close();
  //Turns 180 degrees in prepreation for return
  Drive.turnFor(right, 180, degrees);
  //Drives to clear submersible
  Drive.driveFor(12, inches);
  //Turns to paralell with walls
  Drive.turnFor(right, 45, degrees);
  //Drives to sample area
  Drive.driveFor(156, inches);
  //Opens claw to release sample
  open();
  //Drives to clear sample area
  while(bumperA.pressing() == 0) {
    Drive.drive(reverse);
  }
  //Stops driving when back wall is hit
  Drive.stop();
  Drive.driveFor(6, inches);
  //Turns to face samples
  Drive.turnFor(right, 90, degrees);
  //Drives to samples
  Drive.driveFor(36, inches);
  //grabs sample
  close();
  //Backs up and turns for return
  Drive.driveFor(reverse, 12, inches);
  Drive.turnFor(left, 90, degrees);
  //Drives to return area
  Drive.driveFor(156, inches);
  //Releases sample
  open();
  //Drives to ending position
  while(bumperA.pressing() == 0) {
    Drive.drive(reverse);
  }
  Drive.stop();

}