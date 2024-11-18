#include "vex.h"
#include <string>
using std::string;
using namespace vex;

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
