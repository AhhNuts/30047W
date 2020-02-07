#include "autonFunction.h"
#include "vex.h"
#include "pid.h"
#include <iostream>

PID leftD;
PID rightD;
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
  if( (targetL > 0 && targetR < 0 ) || (targetL < 0 && targetR > 0)){ //Condition for turning auton to change PID
    leftD.setPID(0.2,0,0.13);
    rightD.setPID(0.2,0,0.13);
  }else{
     leftD.setPID(0.16,0,0.1);
     rightD.setPID(0.16,0,0.1);
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
      wait(25,msec); //To stablize
      break;
    }
    LF.spin(forward, leftD.getSpeed(), pct);
    LB.spin(forward, leftD.getSpeed(), pct);
    RF.spin(forward, rightD.getSpeed(), pct);
    RB.spin(forward, rightD.getSpeed(), pct); 
  }
  // (2/3/20) Added Stop b/c realize that the motor was still spinning after the time was out.
  //Ideally this shouldn't happen and I should increase the timeout to make sure it reaches the distance 
  //but its a precaution if it doesn't reach
  LF.stop();
  LB.stop();
  RF.stop();
  RB.stop();
}
void trayUp(){ //automatic tray up starts fast and slows down fast
  TRAY.resetRotation();
  TRAY.setPosition(0,deg);
  timeD.clear();
  while(!(timeD.time() >= 5000)){ //Ideally it should take 5 secs 
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
  TRAY.stop(hold); 
}
//true - blue and false - red
void notProtected(bool colorSide){
  int colorNum = 1; //1 - red and -1- blue
  if(colorSide){
    colorNum = -1;
  }else{
    colorNum = 1;
  }

  SUCTION2.spin(forward,100,pct);
  SUCTION1.spin(forward,100,pct); //Start Intaking
  driveAuton(720,720,40,2500); //drives forward 
  driveAuton(600,600,40,1500); //drives forward 
  wait(200,msec);   //wait a few
  SUCTION1.stop();
  SUCTION2.stop();  

  driveAuton(-650,-650,45,1900); //drive back 

  driveAuton(390 * colorNum,-390 * colorNum,50,1000); //turn to face corner
  SUCTION1.spin(reverse,50,pct); //outake a little
  SUCTION2.spin(reverse,50,pct);
  wait(500,msec); 
  SUCTION1.stop();
  SUCTION2.stop();
  wait(10,msec);
  driveAuton(450,450,60,2000);  //drive to corner
  trayUp(); //Change SpinToPosition to my own function to have faster tray going up 
  driveAuton(100,100,25,2000);  //move forward just a little
  wait(20,msec);
  TRAY.spin(reverse, 30, pct);
  SUCTION1.spin(fwd,100,pct);//Spin to climb up the goal and drive back 
  SUCTION2.spin(fwd,100,pct);

  driveAuton(-300,-300,100,1000); 
  TRAY.stop();
  SUCTION1.stop();
  SUCTION2.stop();
}
