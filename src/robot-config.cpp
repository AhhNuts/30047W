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
signature VISIONB__VISIONB_ORANGE = signature (1, 7037, 8027, 7532, -1709, -1269, -1490, 2.5, 0);
signature VISIONB__VISIONB_GREEN = signature (2, -8041, -6985, -7514, -3589, -2639, -3114, 5.3, 0);
signature VISIONB__VISIONB_PURPLE = signature (3, 963, 1725, 1344, 7149, 8529, 7840, 4.8, 0);
signature VISIONB__SIG_4 = signature (4, 0, 0, 0, 0, 0, 0, 3, 0);
signature VISIONB__SIG_5 = signature (5, 0, 0, 0, 0, 0, 0, 3, 0);
signature VISIONB__SIG_6 = signature (6, 0, 0, 0, 0, 0, 0, 3, 0);
signature VISIONB__SIG_7 = signature (7, 0, 0, 0, 0, 0, 0, 3, 0);
vision VISIONB = vision (PORT5, 50, VISIONB__VISIONB_ORANGE, VISIONB__VISIONB_GREEN, VISIONB__VISIONB_PURPLE, VISIONB__SIG_4, VISIONB__SIG_5, VISIONB__SIG_6, VISIONB__SIG_7);
/*vex-vision-config:end*/
/*vex-vision-config:begin*/
signature VISIONA__VISIONA_ORANGE = signature (1, 8821, 9387, 9104, -1667, -1309, -1488, 3, 0);
signature VISIONA__VISIONA_GREEN = signature (2, -8093, -3949, -6022, -1531, 1271, -130, 1.4, 0);
signature VISIONA__VISIONA_PURPLE = signature (3, 1945, 2601, 2274, 8455, 11703, 10078, 3.3, 0);
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