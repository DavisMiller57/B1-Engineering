
# B1 - Engineering in Robotics 2024

Vex V5 Assigments/Projects for B1  

## File List
🔑 ***Name Key:*** [Last Name].Unit.Lesson *Non Tested Files End With **"-Initial"***

All Programs are located inside the [/src/](https://github.com/DavisMiller57/B1-Engineering/tree/main/src) directory

| File Name | Title | Description |
| -------- | -------- | -------- | 
| lib.txt | Library | Library of shared methods and constructors used in all programs |
|Miller4.1 | First Program in VEXCode V5 | Clockwise 12" box then coiunterclockwise 12" box |
| Miller4.2 | Autonomous Retrieval | Drives 3' Foward to pick up ball and return to basket at starting area |


## Vex V5 Objects
| Type | Port | Description | Name | Constructor |
| ----------- | ----------- | ----------- | ----------- | ----------- | 
| Drivetrain | 1, 10 | 2 Motor Drivetrain | Drive | `drivetrain Drive = drivetrain(left_motor, right_motor, 259.34, 320, 40, mm, 1);` |
| Motor | 1 | Left Drivetrain Motor| leftMotor | `motor left_motor = motor(PORT1, false);` |
| Motor | 10 | Right Drivetrain Motor| rightMotor | `motor right_motor = motor(PORT10, true);` |
| Motor | 8 | Arm Movement Motor | armMotor | `motor armMotor = motor(PORT8, ratio18_1, false); ` |
| Motor | 3 | Claw Movement Motor | clawMotor | `motor clawMotor = motor(PORT3, ratio18_1, false);` |
| Controller | n/a | Controller for Input | Controller | `controller Controller = controller();` |
