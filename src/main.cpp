// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    11, 20          
// arms                 motor_group   18, 1           
// OpticalSensor        optical       2               
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

  OpticalSensor.setLightPower(100, percent);
  OpticalSensor.setLight(ledState::on);
   
  while (1) {

    if (Controller1.ButtonR1.pressing()) {
      arms.spin(forward);
    } else if (Controller1.ButtonL1.pressing()){
      arms.spin(reverse);
    } else {
      arms.stop();
    }

    if (OpticalSensor.isNearObject()) {
      Brain.Screen.print("Object found");
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
