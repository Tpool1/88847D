// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    11, 20          
// arms                 motor_group   18, 1           
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
      arms.spin(forward);
    } else if (Controller1.ButtonB.pressing()){
      arms.spin(reverse);
    } else {
      arms.stop();
    }

    wait(20, msec); 
  
  }
}

int main() {

  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}