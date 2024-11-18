#include "vex.h"
#include <string>
using std::string;
using namespace vex;

motor armMotor = motor(PORT8, ratio18_1, false);
motor clawMotor = motor(PORT3, ratio18_1, false);
controller Controller = controller();
motor left_motor = motor(PORT1, false);
  motor right_motor = motor(PORT10, true);
  

  // Creates drivetrain
drivetrain Drive = drivetrain(left_motor, right_motor, 259.34, 320, 40, mm, 1);

//Simple print method to print a string to the brain screen
void print(string text) {
  Brain.Screen.print(text.c_str());
}
//Opens claw
void open() {
  clawMotor.spinFor(reverse, 160, degrees);
}
//Closes claw
void close() {
  clawMotor.spinFor(160, degrees);
}