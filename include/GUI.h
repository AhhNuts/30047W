#ifndef GUI_H_
#define GUI_H_


struct GuiButton{
  int x;
  int y;
  int tx;
  int ty;
  char *title;
  vex::color c;
  int w;
  int h;
};

bool is_clicked(GuiButton button);
void make_button(GuiButton button);

#endif