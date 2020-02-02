#include "vex.h"
#include "button.h"
#include "pid.h"
/*---------------------------------------------------------------------------*/
/*                         VISION SESNOR Public Variables                    */
/*---------------------------------------------------------------------------*/

int width[3] = {0,0,0};
int maxIndex = 0;
PID visionPid(0.1,0,0);
Button y;

//Finds the largest Width of the Array
void largestWidth(){
  int max = width[0];
  maxIndex = 0;
  for(int i = 0;i<3;i++){
    if(width[i] > max){
      maxIndex = i;
      max = width[i];
    }
  }
}
//get Width of each color 
void visionWidth(){
  width[0] = 0;
  width[1] = 0;
  width[2] = 0;
  for(int i = 0; i < 3; i++){
    switch(i){
      case 0: 
        VISIONA.takeSnapshot(VISIONA__VISIONA_ORANGE);
        VISIONB.takeSnapshot(VISIONB__VISIONB_ORANGE);
        break;
      case 1:
        VISIONA.takeSnapshot(VISIONA__VISIONA_GREEN);
        VISIONB.takeSnapshot(VISIONB__VISIONB_GREEN); 
        break;
      case 2:
        VISIONA.takeSnapshot(VISIONA__VISIONA_PURPLE);
        VISIONB.takeSnapshot(VISIONB__VISIONB_PURPLE);
        break;
    }
    if(VISIONA.objectCount > 0){
      if(VISIONA.largestObject.width > 10){
        width[i] = VISIONA.largestObject.width;
      }
    }
    if(VISIONB.objectCount > 0){
      if(VISIONB.largestObject.width > 10){
        if(width[i] < VISIONB.largestObject.width){
          width[i] = VISIONB.largestObject.width;
        }
      }
    }
    largestWidth();
  }
}
void visionCalculate(){
  switch(maxIndex){
      case 0: 
        VISIONA.takeSnapshot(VISIONA__VISIONA_ORANGE);
        VISIONB.takeSnapshot(VISIONB__VISIONB_ORANGE);
        break;
      case 1:
        VISIONA.takeSnapshot(VISIONA__VISIONA_GREEN);
        VISIONB.takeSnapshot(VISIONB__VISIONB_GREEN); 
        break;
      case 2:
        VISIONA.takeSnapshot(VISIONA__VISIONA_PURPLE);
        VISIONB.takeSnapshot(VISIONB__VISIONB_PURPLE);
        break;
  }
   //https://docs.google.com/spreadsheets/d/1rPjnKj7dXVsCu5H4uYK2RXnXCAtPgEzE6dF_SBjQB_Q/edit?usp=sharing
  if(VISIONA.objectCount > 0 && (VISIONA.largestObject.width > 10) ){
    visionPid.setTarget(-114);
    visionPid.pidCalculate(VISIONA.largestObject.centerY - VISIONA.largestObject.centerX); //1.05

  }else if(VISIONB.objectCount > 0 && VISIONB.largestObject.width > 10){
    visionPid.setTarget(202);
    visionPid.pidCalculate(VISIONB.largestObject.centerY - VISIONB.largestObject.centerX);
  }
}
int visionSpeed(){ 
  if(y.isPress(Controller1.ButtonY.pressing(),false)){
    visionWidth();
  }
  if(Controller1.ButtonY.pressing()){
    visionCalculate();
    return visionPid.getSpeed();
  }else{
    return 0;
  }
}