#include "config.h"

#ifdef _SERIAL_GPS_
#define __GPS_
#include <SoftwareSerial.h>

#include <TinyGPS.h>
TinyGPS gps;
SoftwareSerial ss(PIN_SERIAL_RX_GPS, 6);

void setupGPS(){
    ss.begin(9600);
}

void loopGPS(struct S_GPS gpsdata){
  unsigned long age;
  gps.f_get_position(&gpsdata.lat,&gpsdata.lng,&age);
  float *spd=&gpsdata.speed;
  *spd=gps.f_speed_kmph();
}
#endif
