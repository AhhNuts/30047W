#include "drive.h"
#include "button.h"
#include "vex.h"
#include "suction.h"
#include "visionSensor.h"
/*---------------------------------------------------------------------------*/
/*                         Drive Public Variables                            */
/*---------------------------------------------------------------------------*/

unsigned short maxSpeed = 100; //In Percentage
short LY = 0;
short RX = 0;
unsigned short deadzone = 2; //is area that still of the controller stick
                             //that still counts for zero; 



void update(){
  //Update LY and RX values from controller
  LY = Controller1.Axis3.position(percent); 
  RX = Controller1.Axis1.position(percent); 
  //Changes Speed of the Motor giving driver more precision controls
  if(Controller1.ButtonX.pressing()){
    maxSpeed = 100; 
  }else if(Controller1.ButtonA.pressing()){
    maxSpeed = 50;
  }else if(Controller1.ButtonB.pressing()){
    maxSpeed = 25;
  }

  //Check if LY or RX is under maxspeed
  if(abs(LY) > maxSpeed){
    if(LY < 0){
      LY = -maxSpeed;
    }else{
      LY = maxSpeed;
    }
  }
  if(abs(RX) > maxSpeed){
    if(RX < 0){
      RX = -maxSpeed;
    }else{
      RX = maxSpeed;
    }
  }
  LF.setVelocity((LY + RX) + visionSpeed(),percent);
  LB.setVelocity((LY + RX) + visionSpeed(),percent);
  RF.setVelocity((LY - RX) - visionSpeed(),percent);
  RB.setVelocity((LY - RX) - visionSpeed(),percent);
} 

void drive(){

  update();
  //if the motor are reverse in turning: Solve by changing the 
  //operation sign(+/-) for each motor
  if(abs(LY) < deadzone && abs(RX) < deadzone && visionSpeed() == 0){
    LF.stop(coast);
    LB.stop(coast);
    RF.stop(coast);
    RB.stop(coast);
  }else{
    LF.spin(forward);
    LB.spin(forward);
    RF.spin(forward);
    RB.spin(forward);
  }
} 
void informationD(){
    Controller1.Screen.setCursor(1,13);
    Controller1.Screen.print(maxSpeed);
    Controller1.Screen.print(" ");
}

