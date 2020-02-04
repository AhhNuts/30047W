/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LF                   motor         8               
// LB                   motor         9               
// RF                   motor         3               
// RB                   motor         2               
// Controller1          controller                    
// SUCTION1             motor         10              
// SUCTION2             motor         1               
// TRAY                 motor         4               
// VISIONB              vision        5               
// VISIONA              vision        7               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "drive.h"
#include "GUI.h"
#include "suction.h"
#include "tray.h"
#include "autonFunction.h"
#include "information.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

bool exitAuton = false;;
int auton = 6; //-1 is default for nothin

//x, y, textX, textY, title, color, width , height
//char* is there to remove warning
GuiButton button[]{
  //MENU 0
  {57,50,35,50,(char*)"Red",color(255,0,0),100,100}, //RED BUTTON
  {177,50,30,50,(char*)"Blue",color(0,0,255),100,100}, //BLUE BUTTON
  {400,0,20,30,(char*)"Quit",color(255,153,255),80,50}, //QUIT BUTTON
  {390,180,25,30,(char*)"Run",color(76,0,153),90,50}, //RUN FORWARD
  {390,100,20,30,(char*)"Skill",color(76,0,153),90,50}, //Skill

  //PART OF MENU 0 
  {390,180,25,30,(char*)"Run",color(255,255,0),90,50},//RUN FORWARD HIGHLIGHT
  {390,100,20,30,(char*)"Skill",color(255,255,0),90,50}, //Skil Highlight, 

  //MENU 1
  {400,190,20,30,(char*)"Back",color(255,153,255),80,50}, //BACK BUTTON
  {30,50,35,50,(char*)"R1",color(255,0,0),90,90}, //RED 1 AUTON
  {140,50,35,50,(char*)"R2",color(255,0,0),90,90}, //RED 2 AUTON
  {250,50,35,50,(char*)"R3",color(255,0,0),90,90}, //RED 3 AUTON
  {360,50,35,50,(char*)"R4",color(255,0,0),90,90}, //RED 4 Auton

  //PART OF MENU 1
  {30,50,35,50,(char*)"R1",color(255,255,0),90,90}, //RED 1 AUTON HIGHLIGHT
  {140,50,35,50,(char*)"R2",color(255,255,0),90,90}, //RED 2 AUTON HIGHLIGHT
  {250,50,35,50,(char*)"R3",color(255,255,0),90,90}, //RED 3 AUTON HIGHLIGHT
  {360,50,35,50,(char*)"R4",color(255,255,0),90,90}, //RED 4 AUTON HIGHLIGHT

  //MENU 2
  {400,190,20,30,(char*)"Back",color(255,153,255),80,50}, //BACK BUTTON
  {30,50,35,50,(char*)"B1",color(0,0,255),90,90}, //BLUE 1 AUTON
  {140,50,35,50,(char*)"B2",color(0,0,255),90,90}, //BLUE 2 AUTON
  {250,50,35,50,(char*)"B3",color(0,0,255),90,90}, //BLUE 3 AUTON
  {360,50,35,50,(char*)"B4",color(0,0,255),90,90}, //BLUE 4 Auton

  //PART OF MENU 2
  {30,50,35,50,(char*)"B1",color(255,255,0),90,90}, //BLUE 1 AUTON HIGHLIGHT
  {140,50,35,50,(char*)"B2",color(255,255,0),90,90}, //BLUE 2 AUTON HIGHLIGHT
  {250,50,35,50,(char*)"B3",color(255,255,0),90,90}, //BLUE 3 AUTON HIGHLIGHT
  {360,50,35,50,(char*)"B4",color(255,255,0),90,90}, //BLUE 4 AUTON HIGHLIGHT

};
void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  bool screenHold = false; //Want a hold so when you click on the Screen It won't press the next menu screen as well making it 
                           //impossible to click on wha tthe user wants

  bool menuChange = true; //allow of menuChange
  int menu = 0; //set the menu state 

  while(!exitAuton){
    if(menuChange){
      Brain.Screen.clearScreen();
      switch(menu){
        case 0: //title 
          Brain.Screen.printAt(100,20,"AUTON SELECTOR");
          Brain.Screen.drawLine(90, 25, 250, 25); 
          make_button(button[0]);
          make_button(button[1]);
          make_button(button[2]);
          make_button(button[3]);
          make_button(button[4]);
          if(auton == 0){
            make_button(button[5]);
            Brain.Screen.printAt(30,200,"YOU PICKED RUN STRAIGHT  ");
          }
          if(auton == 9){
            make_button(button[6]);
            Brain.Screen.printAt(30,200,"YOU PICKED SKILL       "); //Spaces are there to delete the previous text instead of just clear line
          }
          break;
        case 1: //RED
          Brain.Screen.printAt(150,20,"RED AUTON SELECTOR");
          Brain.Screen.drawLine(130, 25, 350, 25); 
          make_button(button[7]);
          make_button(button[8]);
          make_button(button[9]);
          make_button(button[10]);
          make_button(button[11]);
          if(auton == 1){ 
            make_button(button[12]); 
            Brain.Screen.printAt(30,200,"YOU PICKED R1");
          }
          if(auton == 2){
            make_button(button[13]); 
            Brain.Screen.printAt(30,200,"YOU PICKED R2");
          }
          if(auton == 3){
            make_button(button[14]); 
            Brain.Screen.printAt(30,200,"YOU PICKED R3");
          }
          if(auton == 4){
            make_button(button[15]); 
            Brain.Screen.printAt(30,200,"YOU PICKED R4");
          }
          break;
        case 2: //Blue 
          Brain.Screen.printAt(150,20,"RED AUTON SELECTOR");
          Brain.Screen.drawLine(130, 25, 350, 25); 
          make_button(button[16]);
          make_button(button[17]);
          make_button(button[18]);
          make_button(button[19]);
          make_button(button[20]);
          if(auton == 5){ 
            make_button(button[21]); 
            Brain.Screen.printAt(30,200,"YOU PICKED B1");
          }
          if(auton == 6){
            make_button(button[22]); 
            Brain.Screen.printAt(30,200,"YOU PICKED B2");
          }
          if(auton == 7){
            make_button(button[23]); 
            Brain.Screen.printAt(30,200,"YOU PICKED B3");
          }
          if(auton == 8){
            make_button(button[24]); 
            Brain.Screen.printAt(30,200,"YOU PICKED B4");
          }
          break;
      } 
      menuChange = false;
    }
    //If the Screen is not pressing, dont do anything: This helps with constantly checking 
    while(!menuChange && !Brain.Screen.pressing()){
      wait(50,msec);
      screenHold = false; 
    }
    while(!menuChange && Brain.Screen.pressing() && !screenHold){
      switch(menu){
        case 0:
          if(is_clicked(button[0])){
            menu = 1;
            menuChange = true;
            break;
          }
          else if(is_clicked(button[1])){
            menu = 2;
            menuChange = true;
            break;
          }
          else if(is_clicked(button[2])){
            exitAuton = true;
            break;
          }
          else if(is_clicked(button[3])){
            menu = 0;
            auton = 0;
            menuChange = true;
            break;
          }
          else if(is_clicked(button[4])){
            menu = 0;
            auton = 9;
            menuChange = true;
            break;
          }
        case 1:
          if(is_clicked(button[7])){ //BACK 
            menu = 0;
            menuChange = true;
            break;
          }
          else if(is_clicked(button[8])){ //R1
            menu = 1;
            auton = 1;
            menuChange = true;
            break;
          }
          else if(is_clicked(button[9])){ //R2
            menu = 1;
            auton = 2;
            menuChange = true;
            break;
          }
          else if(is_clicked(button[10])){ //R3
            menu = 1;
            auton = 3;
            menuChange = true;
            break;
          }
          else if(is_clicked(button[11])){ //R3
            menu = 1;
            auton = 4;
            menuChange = true;
            break;
          }
        case 2:
          if(is_clicked(button[16])){ //BACK 
            menu = 0;
            menuChange = true;
            break;
          }
          else if(is_clicked(button[17])){ //B1
            menu = 2;
            auton = 5;
            menuChange = true;
            break;
          }
          else if(is_clicked(button[18])){ //B2
            menu = 2;
            auton = 6;
            menuChange = true;
            break;
          }
          else if(is_clicked(button[19])){ //B3
            menu = 2;
            auton = 7;
            menuChange = true;
            break;
          }
          else if(is_clicked(button[20])){ //B3
            menu = 2;
            auton = 8;
            menuChange = true;
            break;
          }
      }
      screenHold = true;
      wait(50,msec);
    }
  }  

  //Quit Text 
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(black);
  Brain.Screen.print("EXITED PREAUTON");
  Brain.Screen.newLine();
  Brain.Screen.print("AUTON WILL DEFAULT NOTHIN");
}



void autonomous(void) {
  exitAuton = true;
  switch(auton){
    case -1:
      break;
    case 1:      
      //CONSIST MOST OF TIME in tournment 7/8 times 

      SUCTION1.spin(forward,100,pct); //Start Intaking
      SUCTION2.spin(forward,100,pct);
      driveAuton(1200,1200,30,2500); //drives forward 
      wait(250,msec);   //wait a few
      SUCTION1.stop();
      SUCTION2.stop();  

      driveAuton(-800,-800,45,1900); //drive back 

      SUCTION1.spin(reverse,75,pct); //outake a little
      SUCTION2.spin(reverse,75,pct);
      wait(225,msec); 
      SUCTION1.stop();
      SUCTION2.stop();

      driveAuton(560,-560,75,1000); //turn to face corner
      wait(10,msec);
      driveAuton(430,430,60,1400);  //drive to corner
      trayUp(); //Change SpinToPosition to my own function to have faster tray going up 
      driveAuton(75,75,25,1000);  //move forward just a little
      wait(20,msec);

      SUCTION1.spin(forward,100,pct); //Spin to climb up the goal and drive back 
      SUCTION2.spin(forward,100,pct);
      driveAuton(-600,-600,100,2000); 

      SUCTION1.stop();
      SUCTION2.stop();
      break;
    case 5:
      //Same as case 1 but in the blue side 
      SUCTION1.spin(forward,100,pct); //Start Intake
      SUCTION2.spin(forward,100,pct);

      driveAuton(1200,1200,30,2500); //Drive Forward set distance
      wait(250,msec);
      SUCTION1.stop(); //stop Intake
      SUCTION2.stop();
      driveAuton(-800,-800,45,1900); //Drive Back set distance
      SUCTION1.spin(reverse,75,pct); //Outake set time just enough so the block almost touches the ground
      SUCTION2.spin(reverse,75,pct);
      wait(225,msec);
      SUCTION1.stop();
      SUCTION2.stop();
      driveAuton(-560,560,75,1000);   //Only difference from case 1 is that turning is opposite 
      wait(10,msec);
      driveAuton(430,430,60,1400); //Drive Forward to Goal
      trayUp();
      driveAuton(75,75,25,1000); //Move forward
      wait(20,msec);

      SUCTION1.spin(forward,100,pct); //Spin to climb up the goal and move back
      SUCTION2.spin(forward,100,pct); 
      driveAuton(-600,-600,100,3000); 

      SUCTION1.stop();
      SUCTION2.stop();
      LF.stop();
      LB.stop();
      RB.stop();
      RF.stop();
      break;
    case 6:
      //SUCTION1.spin(forward,100,pct);
      //SUCTION2.spin(forward,100,pct);
      //driveAuton(800,800,60,2000);

      driveAuton(-270,270,100,2500); 

     /* driveAuton(1200,1200,50,4500);
      wait(225,msec);
      SUCTION1.stop();
      SUCTION2.stop();
      driveAuton(-1200,-1200, 50, 4500);

      driveAuton(-435,435,75, 4000);
      driveAuton(100,100, 50, 1500);
      trayUp();
      driveAuton(75,75,25,500);
      driveAuton(-100,-100,25,500);  */

      break;
 
 
  }
}

void usercontrol(void) {
  Brain.Screen.clearScreen();
  task informationTask = task(information); //Starts its own thread to calculate information to Controller every 2 seconds
  TRAY.resetPosition(); 
  while (true) {
    drive();  
    suction();
    tray();
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.

  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();
  // Prevent main from exiting with an infinite loop.
  while (true) {

    wait(100, msec);
  }
}
