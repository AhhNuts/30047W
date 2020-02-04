#include "vex.h"
#include "information.h"
#include "suction.h"
#include "drive.h"

int information(){
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1,0);
  Controller1.Screen.print("CurrMaxSped: ");
  while(true){
    informationD();
    wait(2000,msec); //wait time b/c bandwidth issue to Brain causing delay to Brain functions and found that 2 seconds was ideal
  }
  return 0;
}