#include "vex.h"
#include "GUI.h"
#include "button.h"
//Makes the button with parameters of strut files in GUI.h
void make_button(GuiButton button) {
    Brain.Screen.drawRectangle(button.x,button.y,button.w,button.h,button.c); //Draw Rectangle
    Brain.Screen.setFillColor(button.c); //Set Button
    Brain.Screen.printAt(button.x+button.tx,button.y+button.ty,button.title); //Print text 
    Brain.Screen.setFillColor(black); //Reset Color for future uses
}
//Check if button was clicked and return true or false
bool is_clicked(GuiButton button) {
  int x = Brain.Screen.xPosition(); //store x clicked
  int y = Brain.Screen.yPosition(); //store y clicked
  int rx = x - button.x; //Difference of X clicked and where the button x is equals the distance relative from the top left of the ButtonX,
  int ry = y - button.y; ////Difference of Y clicked and where the button xy is equals the distance relative from the top left of the ButtonY,
  return rx > 0 && rx < button.w && ry >  0 && ry < button.h; //Checks the distance from the button(x,y). If negative then its not in the region 
                                                              //if positive it must be less than the width of the button, vice-versa for height
                                                            
}

