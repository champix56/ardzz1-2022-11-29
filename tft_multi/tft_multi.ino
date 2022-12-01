//https://learn.adafruit.com/adafruit-gfx-graphics-library/graphics-primitives
#include "config.h"
#include "struct.hpp"

struct S_Sensor sensorsDatas;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
#ifdef __SD_
  setupSD();
#endif
#ifdef __SCREEN_
  setupScreen();
#endif
#ifdef __TEMPERATURE_
  setupTemp();
#endif
#ifdef __GPS_
  setupGPS();
#endif
#ifdef __RTC_
  setupRTC();
#endif
}

void loop() {
  // put your main code here, to run repeatedly:
  //if(loopRTC(&tm)){showTime(tm.Hour,tm.Minute);}
#ifdef __RTC_
  if (loopRTC(&sensorsDatas.tm)) {
#ifdef __SCREEN_
    showTime(sensorsDatas.tm.Hour, sensorsDatas.tm.Minute);
#endif
  }
#endif
#ifdef __TEMPERATURE_
  if (loopTemp(&sensorsDatas.temperature)) {
#ifdef __SCREEN_
    showTemp(sensorsDatas.temperature);
#endif
  }
#endif
#ifdef __GPS_
  loopGPS(sensorsDatas.gps);
  //Serial.print(sensorsDatas.gps.lat);  Serial.print(";");  Serial.print(sensorsDatas.gps.lng);  Serial.print(";");  Serial.print(sensorsDatas.gps.speed);
    showGPS();
#endif
#ifdef __SD_
  writeSDData(sensorsDatas);
#endif
}
