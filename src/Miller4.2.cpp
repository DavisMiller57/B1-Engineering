#include "vex.h"
#include <string>
#include "lib.cpp"
using std::string;
using namespace vex;


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