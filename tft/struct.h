#ifndef __STRUCT_H__
#define __STRUCT_H__
#include <TimeLib.h>
struct S_Accel {
  float x, y, z;
};
struct S_Att {
  float pitch, roll, yaw;
};
struct S_Gyro {
  struct  S_Accel accel;
  struct S_Att att;
};
struct S_Sensor {
  
  float temperature;
  uint16_t pressure;
  struct S_Gyro gyro;
};
#endif
