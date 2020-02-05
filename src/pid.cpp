#include "pid.h"
#include "vex.h"
#include <iostream>

PID::PID(){
  kP = 0;
  kI = 0;
  kD = 0;
}

PID::PID(double kP, double kI, double kD) {
  this->kP = kP;
  this->kI = kI;
  this->kD = kD;
  maxSpeed = 100;
}
void PID::setPID(double kP, double kI, double kD) {
  this->kP = kP;
  this->kI = kI;
  this->kD = kD;
}
void PID::setMaxSpeed(int speed){
  maxSpeed = speed;
}
void PID::setTarget(double target) { this->target = target; }
void PID::setSpeed(double speed) { this->speed = speed; }
void PID::pidCalculate(double actual) {
  error = target - actual;
  integral += error;
  if (error == 0) {
    integral = 0;
  }
  if (fabs(error) > 40) {
    integral = 0;
  }
  derivative = error - previous_error;
  previous_error = error; 

  if(fabs(error) < 10){
    speed = 0;
  }else{
    speed = kP * error + kI * integral + kD * derivative;
  }

  if(abs(speed) > maxSpeed){
    if(speed < 0){
      speed = -maxSpeed;
    }else{
      speed = maxSpeed;
    }
  }

}
int PID::getTarget() { return target; }
int PID::getSpeed() { return speed; }
int PID::getError() { return error; }