// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    11, 20          
// arms                 motor_group   19, 1           
// OpticalSensor        optical       10              
// left_arm             motor_group   9, 3            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

competition Competition;

void pre_auton(void) {

  vexcodeInit();

}

void autonomous(void) {

  bool active = true;
  while(active) {
    if (OpticalSensor.isNearObject() == false) {
      Drivetrain.drive(forward);
    } else {
      Drivetrain.stop();
      active = false;
    }
  }
}

void usercontrol(void) {

  left_arm.setVelocity(5, percent);

  while (1) {

    if (Controller1.ButtonR1.pressing()) {
      arms.spin(forward);
    } else if (Controller1.ButtonL1.pressing()){
      arms.spin(reverse);
    } else if (Controller1.ButtonR2.pressing()) {
      left_arm.spin(forward);
    } else if (Controller1.ButtonL2.pressing()) {
      left_arm.spin(reverse);
    } else {
      arms.stop();
      left_arm.stop();
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

  OpticalSensor.setLightPower(100, percent);
  OpticalSensor.setLight(ledState::on);

  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
