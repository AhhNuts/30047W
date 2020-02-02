#include "vex.h"
#include "information.h"
#include "suction.h"
#include "drive.h"

int information(){
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1,0);
  Controller1.Screen.print("CurrMaxSped: ");
  Controller1.Screen.setCursor(2,0);
  Controller1.Screen.print("SuctionR ");
  while(true){
    informationD();
    informationS();
    wait(2000,msec);
  }
  return 0;
}