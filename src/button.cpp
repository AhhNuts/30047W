#include "button.h"
#include <iostream>
#include "vex.h"
bool Button::isPress(bool buttonState, bool isToggle){
  this->buttonState = buttonState;
  if(isToggle){
    if(isButtonHold()){
      buttonTog = !buttonTog;
    }
    return buttonTog;
  }
  if(isButtonHold()){
    return true;
  }
  return false;
}

//Checks if button is press, make sure only output once(reason why added hold)
bool Button::isButtonHold(){
  if(buttonState && !hold){
    hold = true;
    return true;
  }else if(!buttonState && hold){
    hold = false;
    return false;
  }
  return false;
}
