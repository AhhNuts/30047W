#ifndef PID_H_
#define PID_H_

class PID {
private:
  double kP;
  double kI;
  double kD;
  double error;
  double integral;
  double derivative;
  double previous_error;
  double target;
  int speed;
  int maxSpeed;
public:
  PID();
  PID(double kP, double kI, double kD);
  void setPID(double kP, double Ki, double kD);
  void setTarget(double target);
  void setSpeed(double speed);
  void pidCalculate(double actual);
  void setMaxSpeed(int speed);
  int getTarget();
  int getSpeed();
  int getError();
};
#endif