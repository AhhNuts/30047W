using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern motor LF;
extern motor LB;
extern motor RF;
extern motor RB;
extern controller Controller1;
extern motor SUCTION1;
extern motor SUCTION2;
extern motor TRAY;
extern signature VISIONB__VISIONB_ORANGE;
extern signature VISIONB__VISIONB_GREEN;
extern signature VISIONB__VISIONB_PURPLE;
extern signature VISIONB__SIG_4;
extern signature VISIONB__SIG_5;
extern signature VISIONB__SIG_6;
extern signature VISIONB__SIG_7;
extern vision VISIONB;
extern signature VISIONA__VISIONA_ORANGE;
extern signature VISIONA__VISIONA_GREEN;
extern signature VISIONA__VISIONA_PURPLE;
extern signature VISIONA__SIG_4;
extern signature VISIONA__SIG_5;
extern signature VISIONA__SIG_6;
extern signature VISIONA__SIG_7;
extern vision VISIONA;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );