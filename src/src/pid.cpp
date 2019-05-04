#ifndef _PID_SOURCE_
#define _PID_SOURCE_

#include <iostream>
#include <cmath>
#include <cassert>
#include "pid/pid.h"

using namespace std;
using namespace PID;

pid::pid(double max, double min):
  _max(max), 
  _min(min),
  _is_ready(false),
  _pre_error(0),
  _integral(0)
  {}

pid::pid(double max, double min, double kp, double kd, double ki):
  _max(max), 
  _min(min),
  _kp(kp),
  _ki(ki),
  _kd(kd),
  _is_ready(true),
  _pre_error(0),
  _integral(0)
  {}

void pid::resetPid(void){
 _pre_error = 0;
 _integral = 0;
}

double pid::calculate(double setpoint, double pv, double dt){
  assert(_is_ready); // Check if controller ready
  // Calculate error
  double error = setpoint - pv;
  // Propotional term
  double Pout = error * _kp;
  // Integral term
  _integral += error * dt;
  double Iout = _integral * _ki;
  // Derivative term
  double derivative = (error - _pre_error) / dt;
  double Dout = derivative * _kd;
  // Calculate total ouput
  double output = Pout + Iout + Dout;
  // Restrict to in range [_min, _max]
  if(output > _max) output = _max;
  else if(output < _min) output = _min;
  // Save error to previous error
  _pre_error = error;
  
  return output;
}
#endif
