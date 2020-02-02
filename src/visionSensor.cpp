#include "vex.h"
#include "button.h"
#include "pid.h"

/*---------------------------------------------------------------------------*/
/*                         VISION SESNOR Public Variables                    */
/*---------------------------------------------------------------------------*/
int indexLarg = 0; //Store largest Index for each cycle
PID visionPid(0.1,0,0.4);
Button y;


//IMPORTANT FACT: We are using VisionA as the parent of VISIONB which means that we are 
//                overiding what visionB sees if visionA sees a block


//return largest width index of the three values 
int largestWidthIndex(int num1, int num2, int num3){
  int largestIndex = 0; 
  int num[3] = {num1,num2,num3};
  int max = num[0];
  for(int i = 0;i<3;i++){ 
    if(num[i] > max){
      largestIndex = i;
      max = num[i];
    }
  }
  if(num[0] == 0 && num[1] == 0 && num[2] == 0){
    return -1; //all width are zero so return 0;
  }
  return largestIndex; 
}
void visionSnapShot(int index){
  switch(index){
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
}
//store width value of the largest block color specify in parameter 
//0 - ORANGE : 1 - GREEN : 2 - PURPLE
int widthOfBlock(int count){
    visionSnapShot(count);
    if(VISIONA.objectCount > 0 && VISIONA.largestObject.width > 5){ //Checks for A width first if found use A 
      return VISIONA.largestObject.width;
    }
    else if(VISIONB.objectCount > 0 && VISIONB.largestObject.width > 5){//Checks for B width if nothin is found in A
      return VISIONB.largestObject.width; 
    }
    else{
      return 0; //Happens when nothin is found
    }
}
int calculateSpeed(int index){
  switch(index){
    case -1:
      return 0;
    case 0:
      visionSnapShot(0); //take orange snapshot
      break;
    case 1:
      visionSnapShot(1); //take green snapshot
      break;
    case 2:
      visionSnapShot(2); //take purple snapshot
      break;
  }
  /*
    DOCUMENTATION of an experiement of vision Sensor by placing blocks in the center of the robot and moving it back
    I realize that the line makes a linear slope line. The y-intercept is where the center is so solving for the center 
    we get eh equation y - mx = b with m is slope, y as centerY, x as centerX and b as Y-intercept. 
  */
  //Below is the spreadsheet in finding the slope.
  //https://docs.google.com/spreadsheets/d/1rPjnKj7dXVsCu5H4uYK2RXnXCAtPgEzE6dF_SBjQB_Q/edit?usp=sharing

  if(VISIONA.objectCount > 0){ 
    visionPid.setTarget(-114); 
    visionPid.pidCalculate( VISIONA.largestObject.centerY - VISIONA.largestObject.centerX); 

  }else if(VISIONB.objectCount > 0){
    visionPid.setTarget(202);
    visionPid.pidCalculate( VISIONB.largestObject.centerY - VISIONB.largestObject.centerX);
  }
  return visionPid.getSpeed();
}


int visionSpeed(){ 
  if(y.isPress(Controller1.ButtonY.pressing(),false)){ //Only happens once
    indexLarg = largestWidthIndex(widthOfBlock(0), widthOfBlock(1), widthOfBlock(2)); //Get the biggest width of each color block 
                                                                                      //then find the largest width index 
  }
  if(Controller1.ButtonY.pressing()){
    return calculateSpeed(indexLarg); 
  }else{
    return 0;
  }
}