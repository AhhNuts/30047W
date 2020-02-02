#include "tray.h"
#include "vex.h"
#include "button.h"

Button lb;
void tray(){
    if(TRAY.rotation(deg) < 0){ //Safety precaution if tray doesn't start all the way down
      TRAY.resetPosition();
    }
    //if both button hold then max speed down
    if(Controller1.ButtonR1.pressing() && Controller1.ButtonR2.pressing()){
      TRAY.spin(reverse,100,pct);
    }
    else if(Controller1.ButtonR1.pressing()){ //Button to hold to go up fast then depending on the position
      if(TRAY.position(deg) > 1000){           //it will go slower (Semi-Automatic)
        TRAY.spin(forward,30,pct);
      }
      else if(TRAY.position(deg) > 600){
        TRAY.spin(forward,60,pct);
      }else{
        TRAY.spin(forward,100,pct); 
      }
    }
    else if(Controller1.ButtonR2.pressing()){ //Button R2 to go down slow
      TRAY.spin(reverse,50,pct);
    }else{
      TRAY.stop(hold); //Hold if none button is press
    }
}