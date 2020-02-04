#include "autonFunction.h"
#include "vex.h"
#include "pid.h"
#include <iostream>

PID leftD(0.07,0,0.1);
PID rightD(0.07,0,0.1);
vex::timer timeD;
vex::timer timeT;
vex::timer timeS;
void driveAuton(int targetL, int targetR, int maxSpeed, int timeout){
  LF.resetRotation();
  LB.resetRotation();
  RF.resetRotation();
  RB.resetRotation();
  leftD.setTarget(targetL);
  rightD.setTarget(targetR);
  leftD.setMaxSpeed(maxSpeed);
  rightD.setMaxSpeed(maxSpeed);
  // (2/3/20) Realize that P was too low when turning so added this condition to change P whenever its turning
  if( (targetL > 0 && targetR < 0 )|| (targetL < 0 && targetR > 0)){ //Condition for turning auton to change PID
    leftD.setPID(0.3,0,0.1);
    PID rightD(0.3,0,0.1);
  }else{
     leftD.setPID(0.07,0,0.1);
     PID rightD(0.07,0,0.1);
  }
  timeD.clear();
  while(!(timeD.time() >= timeout)){
    leftD.pidCalculate( ( LF.rotation(deg) + LB.rotation(deg) ) / 2);
    rightD.pidCalculate( (RF.rotation(deg) + RB.rotation(deg) ) / 2);

    if(leftD.getSpeed() == 0 && rightD.getSpeed() == 0){
      LF.stop();
      LB.stop();
      RF.stop();
      RB.stop();
      break;
    }
    LF.spin(forward, leftD.getSpeed(), pct);
    LB.spin(forward, leftD.getSpeed(), pct);
    RF.spin(forward, rightD.getSpeed(), pct);
    RB.spin(forward, rightD.getSpeed(), pct); 
    std::cout << rightD.getSpeed() << std::endl;
  }
  LF.stop();
  LB.stop();
  RF.stop();
  RB.stop();
}
void trayUp(){
  TRAY.resetRotation();
  timeD.clear();
  while(!(timeD.time() >= 5000)){
    if(TRAY.position(deg) > 1000){   
      TRAY.spin(forward,30,pct);
    }
    else if(TRAY.position(deg) > 600){
      TRAY.spin(forward,60,pct);
    }else{
      TRAY.spin(forward,100,pct); 
    }
    if(TRAY.position(deg) > 1400){
      TRAY.stop(hold);
      break;
    }
  }
}


