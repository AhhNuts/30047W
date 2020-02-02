#include "autonFunction.h"
#include "vex.h"
#include "pid.h"

PID leftD(0.07,0,0.1);
PID rightD(0.07,0,0.1);
vex::timer timeD;
vex::timer timeT;
vex::timer timeS;
void driveAuton(int targetL, int targetR,int maxSpeed, int timeout){
  LF.resetRotation();
  LB.resetRotation();
  RF.resetRotation();
  RB.resetRotation();
  leftD.setTarget(targetL);
  rightD.setTarget(targetR);
  leftD.setMaxSpeed(maxSpeed);
  rightD.setMaxSpeed(maxSpeed);
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
  }
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

