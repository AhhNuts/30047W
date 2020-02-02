#include "button.h"
#include <iostream>
#include "vex.h"
//isToggle is just a true and false telling the function that do u want it to become a toggle button
bool Button::isPress(bool buttonState, bool isToggle){
  this->buttonState = buttonState; 
  if(isToggle){ 
    if(!isButtonHold()){ //if button is not held then change button state 
      buttonTog = !buttonTog;
    }
    return buttonTog; //return whatever the buttonState is
  }
  if(!isButtonHold()){ //Checks if button is held if it is not return true then if it is keep returning false 
    return true;
  }
  return false;
}

//Checks if button is press, make sure only output once(reason why added hold)
bool Button::isButtonHold(){
  if(buttonState && !hold){
    hold = true;
    return false;
  }else if(!buttonState && hold){
    hold = false;
    return true;
  }
  return true;
}
