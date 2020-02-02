#ifndef BUTTON_H_
#define BUTTON_H_

class Button{
private: 
  //Initalize 
  bool hold = false;
  bool buttonTog = false;
  bool buttonState = false;
  bool isButtonHold();
public:
  bool isPress(bool button , bool isToggle); 
};

#endif