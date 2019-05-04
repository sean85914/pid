#ifndef _PID_H_
#define _PID_H_

namespace PID
{
 class pid
 {
  private:
   double _max; // Maximum output
   double _min; // Minimum output
   double _kp; // Propotion gain
   double _ki; // Integration gain
   double _kd; // Derivation gain
   bool _is_ready; // Is the controller ready?
   double _pre_error; // Last error
   double _integral; // Error sum
  public:
   pid(double max, double min);
   pid(double max, double min, double kp, double kd, double ki);
   void setMax(double max) {_max = max;}
   void setMin(double min) {_min = min;}
   void setKp(double kp) {_kp = kp;}
   void setKi(double ki) {_ki = ki;}
   void setKd(double kd) {_kd = kd;}
   double getMax(void) {return _max;}
   double getMin(void) {return _min;}
   double getKp(void) {return _kp;}
   double getKi(void) {return _ki;}
   double getKd(void) {return _kd;}
   // Reset the controller, i.e., clear "_pre_error" and "_integral"
   void resetPid(void); 
   // Returns the manipulated variable given a setpoint(target), current process value and time difference
   double calculate(double setpoint, double pv, double dt);
 }; // End class
}; // End namespace

#endif
