using namespace vex;

extern brain Brain;

// VEXcode devices
extern smartdrive Drivetrain;
extern optical OpticalSensor;
extern controller Controller1;
extern motor_group left_arm;
extern motor_group right_arm;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );