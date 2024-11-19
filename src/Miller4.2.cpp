#include "vex.h"
#include <string>
#include "lib.cpp"
using std::string;
using namespace vex;


//Main program logic - Autonomous Retrial
int main() {
    //Sets claw open prior to leaving starting position
    open();
    //Drives foward just over 3 feet to account for any error
    Drive.driveFor(40, inches);
    //redundant stop of robot motion 
    Drive.stop();
    //Closes claw to grab object
    close();
    //Raises claw
    raise();
    //Full spin to turn around, using 135º from 4.1 due to robot processing errors
    Drive.turnFor(right, 135, degrees);
    //Drives forward to return to starting position, adding on 4 inches to account for error
    Drive.driveFor(44, inches);
    //Opens claw to drop ball
    open();
}