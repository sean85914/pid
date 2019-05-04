#include "pid/pid.h"
#include <stdio.h>

int main()
{
  PID::pid myPid = PID::pid(100, -100, 0.1, 0.01, 0.5);
  double val = 20;
  for (int i = 0; i < 100; i++) {
    double inc = myPid.calculate(0, val, 0.1);
    printf("val: % 7.3f inc: % 7.3f\n", val, inc);
    val += inc;
  }
  return 0;
}
