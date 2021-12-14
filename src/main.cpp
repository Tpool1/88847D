#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    11, 4, 12, 8, 5 
// OpticalSensor        optical       10              
// Controller1          controller                    
// left_arm             motor_group   1, 3            
// right_arm            motor_group   9, 2            
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;

competition Competition;

void pre_auton(void) {

  vexcodeInit();

}

void autonomous(void) {

  left_arm.spinTo(-90, degrees);
  right_arm.spinTo(-90, degrees);

  Drivetrain.driveFor(forward, 55, inches); 

  wait(1, sec);

  left_arm.spinTo(-20, degrees);
  right_arm.spinTo(-20, degrees);

  Drivetrain.driveFor(reverse, 55, inches);

}

void usercontrol(void) {

  left_arm.setVelocity(40, percent);
  right_arm.setVelocity(40, percent);

  while (1) {

    if (Controller1.ButtonR2.pressing()) {
      left_arm.spin(forward);
      right_arm.spin(forward);
    } else if (Controller1.ButtonL2.pressing()) {
      left_arm.spin(reverse);
      right_arm.spin(reverse);
    } else if (Controller1.ButtonR1.pressing()) {
      left_arm.spin(reverse);
      right_arm.spin(reverse);
    } else if (Controller1.ButtonL1.pressing()) {
      left_arm.spin(forward);
      right_arm.spin(forward);
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