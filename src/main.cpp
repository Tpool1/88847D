// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    11, 20          
// right_arm            motor         1               
// left_arm             motor         10              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

competition Competition;

void pre_auton(void) {

  vexcodeInit();

}

void autonomous(void) {

}

void usercontrol(void) {
   
   while (1) {

    if (Controller1.ButtonA.pressing()) {
      right_arm.spinToPosition(90, degrees);
      left_arm.spinToPosition(90, degrees);

      wait(20, msec);
      
    } else {

      right_arm.spinToPosition(180, degrees);
      left_arm.spinToPosition(90, degrees);

      wait(20, msec);

    }

    wait(20, msec); 
  
  }
}

int main() {

  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  // create array to organize arm motors
  motor arm_motors[2] = {right_arm, left_arm};

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
