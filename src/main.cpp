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

// functions for commonly utilized controls
void spin_arms_to_degree(int positon_degree) {
  left_arm.spinTo(positon_degree, degrees);
  right_arm.spinTo(positon_degree, degrees);
}

void spin_arms_forward(void) {
  left_arm.spin(forward);
  right_arm.spin(forward);
}

void spin_arms_reverse(void) {
  left_arm.spin(reverse);
  right_arm.spin(reverse);
}

void stop_arms(void) {
  left_arm.stop();
  right_arm.stop();
}

void autonomous(void) {

  // initiallly lift arms to go down on goal
  spin_arms_to_degree(-90);

  // drive forward towards goal
  Drivetrain.driveFor(forward, 55, inches); 

  wait(1, sec);

  // move down arms to clamp down on goal
  spin_arms_to_degree(-20);

  // drive back to initial position
  Drivetrain.driveFor(reverse, 55, inches);

  Drivetrain.turnToHeading(-90, degrees);

  spin_arms_to_degree(-90);

  spin_arms_to_degree(-20);

}

void usercontrol(void) {

  left_arm.setVelocity(40, percent);
  right_arm.setVelocity(40, percent);

  while (1) {

    if (Controller1.ButtonR2.pressing()) {
      spin_arms_forward();
    } else if (Controller1.ButtonL2.pressing()) {
      spin_arms_reverse();
    } else if (Controller1.ButtonR1.pressing()) {
      spin_arms_reverse();
    } else if (Controller1.ButtonL1.pressing()) {
      spin_arms_forward();
    } else {
      stop_arms();
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