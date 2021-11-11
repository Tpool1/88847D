// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    11, 20          
// OpticalSensor        optical       10              
// left_arm             motor_group   2, 9            
// right_arm            motor_group   3, 1            
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
    }
  }
}

void usercontrol(void) {

  left_arm.setVelocity(15, percent);
  right_arm.setVelocity(15, percent);

  while (1) {

    if (Controller1.ButtonR2.pressing()) {
      left_arm.spin(forward);
      right_arm.spin(forward);
    } else if (Controller1.ButtonL2.pressing()) {
      left_arm.spin(reverse);
      right_arm.spin(reverse);
    } else {
      left_arm.stop();
      right_arm.stop();
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
