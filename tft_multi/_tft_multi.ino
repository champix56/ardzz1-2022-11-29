//https://learn.adafruit.com/adafruit-gfx-graphics-library/graphics-primitives
#include "config.h"
#include "struct.hpp"

struct S_Sensor sensorsDatas;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(_DS18B20_);
  Serial.println(_DS1307_);
  #ifdef __RTC_
  setupRTC();
  #endif
  #ifdef __SD_
  setupSD();
  #endif
  setupScreen();
  #ifdef __TEMPERATURE
  setupTemp();
  #endif
  #ifdef __GPS_
  setupGPS();
  #endif
}

void loop() {
  // put your main code here, to run repeatedly:
  //if(loopRTC(&tm)){showTime(tm.Hour,tm.Minute);}
  #ifdef __RTC_
  if (loopRTC(&sensorsDatas.tm)) {
    showTime(sensorsDatas.tm.Hour, sensorsDatas.tm.Minute);
  }
  #endif
  #ifdef __TEMPERATURE_
  if (loopTemp(&sensorsDatas.temperature)) {
    Serial.println(sensorsDatas.temperature);
    showTemp(sensorsDatas.temperature);
  }
  #endif
  #ifdef __GPS_
  loopGPS(sensorsDatas.gps);
  //Serial.print(sensorsDatas.gps.lat);  Serial.print(";");  Serial.print(sensorsDatas.gps.lng);  Serial.print(";");  Serial.print(sensorsDatas.gps.speed);
  //showGPS();
  #endif
  #ifdef __SD_
  writeSDData(sensorsDatas);
  #endif
}
