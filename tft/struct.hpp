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
struct S_Pressure{
  uint16_t pressure;
  float altitude;
};
struct S_GPS{
  float lat,lng;
  float speed;  
}
struct S_Sensor {
  
  tmElements_t tm;
  float temperature;
  struct S_Gyro gyro;
  struct S_GPS gps;
};
#endif
