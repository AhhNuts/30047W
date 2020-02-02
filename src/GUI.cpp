#include "vex.h"
#include "GUI.h"
#include "button.h"

void make_button(GuiButton button) {
    Brain.Screen.drawRectangle(button.x,button.y,button.w,button.h,button.c);
    Brain.Screen.setFillColor(button.c);
    Brain.Screen.printAt(button.x+button.tx,button.y+button.ty,button.title);
    Brain.Screen.setFillColor(black);
}
bool is_clicked(GuiButton button) {
  int x = Brain.Screen.xPosition();
  int y = Brain.Screen.yPosition();
  int rx = x - button.x;
  int ry = y - button.y;
  return rx >  0 && rx < button.w && ry >  0 && ry < button.h;
}