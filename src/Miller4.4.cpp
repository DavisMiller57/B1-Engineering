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

//Variable that determines if the robot is in panic mode
bool panic = false;
bool kill = false;
    
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

//Bumper Hit
void bumperHit() {
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

//Drives foward, turns around and drives back
void btnA() {
    Drive.driveFor(10, inches);
    wait1();
    Drive.turnFor(120, degrees);
    wait1();
    Drive.driveFor(10, inches);
    wait1();
}
//Raises arm, opens claw, lowers arm, closes claw
void btnB() {
    raise();
    wait1();
    open();
    wait1();
    lower();
    wait1();
    close();
    wait1();
}
//drives backwards until bumper is pressed, then calls bumperHit()
void btnY() {
   while(true) {
    Drive.drive(reverse);
    if(bumperA.pressing()) {
        bumperHit();
    }
   }
}

//drives in a box until button R1 is pressed
void btnX() {
    while (true) {
        for(int i = 0; i < 4; i++) {
            if (Controller.ButtonR1.pressing()) {
                Drive.stop();
                return;
            }
            Drive.driveFor(12, inches);
            Drive.turnFor(right, 90, degrees);
        }
        if (Controller.ButtonR1.pressing()) {
            Drive.stop();
            return;
        }
        Drive.turnFor(right, 180, degrees);
        for(int i = 0; i < 4; i++) {
            if (Controller.ButtonR1.pressing()) {
                Drive.stop();
                return;
            }
            Drive.driveFor(12, inches);
            Drive.turnFor(left, 90, degrees);
        }
        if (Controller.ButtonR1.pressing()) {
            Drive.stop();
            return;
        }
    }
}
//sets panic variable to true, stopping main program flow, and stopping the robot
void btnR1() {
    panic = true;
    Drive.stop();
}

//loop while killswitch variable (panic) is false
int main () {
    while(panic == false) {
        if(Controller.ButtonA.pressing()) {
            btnA();
        }
        if(Controller.ButtonB.pressing()) {
            btnB();
        }
        if(Controller.ButtonY.pressing()) {
            btnY();
        }
        if(Controller.ButtonX.pressing()) {
            btnX();
        }
        if(Controller.ButtonR1.pressing()) {
            btnR1();
        }
    }
}