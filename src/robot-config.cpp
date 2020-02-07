#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LF = motor(PORT8, ratio18_1, false);
motor LB = motor(PORT9, ratio18_1, false);
motor RF = motor(PORT3, ratio18_1, true);
motor RB = motor(PORT2, ratio18_1, true);
controller Controller1 = controller(primary);
motor SUCTION1 = motor(PORT10, ratio18_1, true);
motor SUCTION2 = motor(PORT1, ratio18_1, false);
motor TRAY = motor(PORT4, ratio18_1, true);
/*vex-vision-config:begin*/
signature VISIONB__VISIONB_ORANGE = signature (1, 5723, 7415, 6568, -1585, -1267, -1426, 3, 0);
signature VISIONB__VISIONB_GREEN = signature (2, -6687, -5263, -5975, -2917, -1739, -2328, 3, 0);
signature VISIONB__VISIONB_PURPLE = signature (3, 595, 1725, 1160, 5995, 8803, 7399, 3, 0);
signature VISIONB__SIG_4 = signature (4, 0, 0, 0, 0, 0, 0, 3, 0);
signature VISIONB__SIG_5 = signature (5, 0, 0, 0, 0, 0, 0, 3, 0);
signature VISIONB__SIG_6 = signature (6, 0, 0, 0, 0, 0, 0, 3, 0);
signature VISIONB__SIG_7 = signature (7, 0, 0, 0, 0, 0, 0, 3, 0);
vision VISIONB = vision (PORT5, 50, VISIONB__VISIONB_ORANGE, VISIONB__VISIONB_GREEN, VISIONB__VISIONB_PURPLE, VISIONB__SIG_4, VISIONB__SIG_5, VISIONB__SIG_6, VISIONB__SIG_7);
/*vex-vision-config:end*/
/*vex-vision-config:begin*/
signature VISIONA__VISIONA_ORANGE = signature(1, 5723, 7415, 6568, -1585, -1267, -1426, 3, 0);
signature VISIONA__VISIONA_GREEN = signature(2, -6687, -5263, -5975, -2917, -1739, -2328, 3, 0);
signature VISIONA__VISIONA_PURPLE = signature(3, 595, 1725, 1160, 5995, 8803, 7399, 3, 0);
vision VISIONA = vision (PORT7, 46, VISIONA__VISIONA_ORANGE, VISIONA__VISIONA_GREEN, VISIONA__VISIONA_PURPLE);
/*vex-vision-config:end*/

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}