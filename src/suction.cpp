#include "vex.h"
#include "suction.h"
#include "button.h"
Button down;
int reverseS = 1;;
void suction(){
  if(down.isPress(Controller1.ButtonDown.pressing(), true)){
    reverseS = -1;
  }else{
    reverseS = 1;
  }

  if(Controller1.ButtonL1.pressing()){
    SUCTION1.spin(forward,100 * reverseS,pct);
    SUCTION2.spin(forward,100,pct);
  }
  else if(Controller1.ButtonL2.pressing()){
    SUCTION1.spin(reverse,100 * reverseS,pct);
    SUCTION2.spin(reverse,100,pct);
  }
  else{
     SUCTION1.stop(hold);
     SUCTION2.stop(hold);
  }

}
void informationS(){
  Controller1.Screen.setCursor(2,13);
  if(reverseS == -1){ //if it negative then state to controller true
    Controller1.Screen.print("True  ");
  }else{
    Controller1.Screen.print("False  ");
  }
}