#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    20, 19, 11, 12, 18
// Controller1          controller                    
// arms                 motor_group   17, 13          
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;

competition Competition;

void pre_auton(void) {

  vexcodeInit();

}

// functions for commonly utilized controls
void spin_arms_to_degree(int positon_degree) {
  arms.spinTo(positon_degree, degrees);
}

void spin_arms_forward(void) {
  arms.spin(forward);
}

void spin_arms_reverse(void) {
  arms.spin(reverse);
}

void stop_arms(void) {
  arms.stop();
}

void autonomousLeft(void) {

  Brain.Screen.newLine();
  Brain.Screen.print("left auton started");

  // initiallly lift arms to go down on goal
  spin_arms_to_degree(90*4);

  Drivetrain.turnToHeading(12, degrees);

  // drive forward towards goal
  Drivetrain.driveFor(forward, 55, inches); 

  wait(1, sec);

  // move down arms to clamp down on goal
  spin_arms_to_degree(20*4);

  Drivetrain.turnToHeading(12, degrees);

  // drive back to initial position
  Drivetrain.driveFor(reverse, 55, inches);

}

void autonomousRight(void) {

  // initiallly lift arms to go down on goal
  spin_arms_to_degree(90*4);

  // drive forward towards goal
  Drivetrain.driveFor(forward, 55, inches); 

  wait(1, sec);

  // move down arms to clamp down on goal
  spin_arms_to_degree(20*4);

  // drive back to initial position
  Drivetrain.driveFor(reverse, 55, inches);

}

void autonomousMiddle(void) {

  // initially lift arms to go down on goal
  spin_arms_to_degree(90*4);

  Drivetrain.turnToHeading(36, degrees);

  // drive forward towards goal
  Drivetrain.driveFor(forward, 60, inches); 

  wait(1, sec);

  // move down arms to clamp down on goal
  spin_arms_to_degree(20*4);

  Drivetrain.turnToHeading(24, degrees);

  // drive back to initial position
  Drivetrain.driveFor(reverse, 55, inches);

}

void usercontrol(void) {

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

    wait(20, msec); 
  
  }
}

int main() {

  Drivetrain.setDriveVelocity(70, percent);

  Competition.autonomous(autonomousMiddle);

  Competition.drivercontrol(usercontrol);

  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
