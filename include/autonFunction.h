#ifndef AUTONFUNCTION_H_
#define AUTONFUNCTION_H_
void driveAuton(int targetL, int targetR,int maxSpeedL,int maxSpeedR, int timeout);
void trayUp();
void notProtectedAuton(bool colorSide);
void protectedAuton(bool colorSide);
void arcAuton();
#endif