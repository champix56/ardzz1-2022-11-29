#include <SoftwareSerial.h>

#include <TinyGPS.h>
TinyGPS gps;
SoftwareSerial ss(5, 6);

void setupGPS(){
    ss.begin(9600);
}

void loopGPS(struct S_GPS gpsdata){
  unsigned long age;
  gps.f_get_position(&gpsdata.lat,&gpsdata.lng,&age);
  float *spd=&gpsdata.speed;
  *spd=gps.f_speed_kmph();
}
