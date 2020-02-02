#include "tray.h"
#include "vex.h"
#include "button.h"

Button lb;
void tray(){
    if(Controller1.ButtonR1.pressing() && Controller1.ButtonR2.pressing()){
      TRAY.spin(reverse,100,pct);
    }
    else if(Controller1.ButtonR1.pressing()){
      Brain.Screen.setCursor(5,0);
      Brain.Screen.print(TRAY.position(deg));
      Brain.Screen.print(" ");
      if(TRAY.position(deg) > 400){
        TRAY.spin(forward,65,pct);
      }
      else if(TRAY.position(deg) > 600){
        TRAY.spin(forward,15,pct);
      }else{
        TRAY.spin(forward,100,pct);
      }
    }
    else if(Controller1.ButtonR2.pressing()){
      TRAY.spin(reverse,50,pct);
    }else{
      TRAY.stop(hold);
    }
}