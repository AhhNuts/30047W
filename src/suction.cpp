#include "vex.h"
#include "suction.h"
#include "button.h"
Button down;
void suction(){ 

  /* *REMOVED* Found that it was more intuitive to use left and right instead of down and the down can be used for the tray
  if(down.isPress(Controller1.ButtonDown.pressing(), true)){
    reverseS = -1;
  }else{
    reverseS = 1;
  }  *REMOVED*  */

  if(Controller1.ButtonL1.pressing()){ //Intakes
    SUCTION1.spin(forward,100,pct);
    SUCTION2.spin(forward,100,pct);
  }
  else if(Controller1.ButtonL2.pressing()){ //Outakes
    SUCTION1.spin(reverse,100,pct);
    SUCTION2.spin(reverse,100,pct);
  }
  else if(Controller1.ButtonLeft.pressing()){ //Intake moves Counter-ClockWise to the point of view of robot
    SUCTION1.spin(reverse,100,pct);
    SUCTION2.spin(forward,100,pct);
  }
  else if(Controller1.ButtonRight.pressing()){ //Intake moves ClockWise to the point of view of robot
    SUCTION1.spin(forward,100,pct);
    SUCTION2.spin(reverse,100,pct);
  }else if(Controller1.ButtonUp.pressing()){ //outtake slower
    SUCTION1.spin(reverse,40,pct);
    SUCTION2.spin(reverse,40,pct);
  }
  else{
     SUCTION1.stop(hold);
     SUCTION2.stop(hold);
  }

}
