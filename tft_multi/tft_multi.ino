//https://learn.adafruit.com/adafruit-gfx-graphics-library/graphics-primitives
#include "struct.hpp"
#include "sd_csv.h"

struct S_Sensor sensorsDatas;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  setupSD();
  setupScreen();
  setupTemp();
  setupGPS();
}

void loop() {
  // put your main code here, to run repeatedly:
  //if(loopRTC(&tm)){showTime(tm.Hour,tm.Minute);}
  /*if (loopRTC(&sensorsDatas.tm)) {
    showTime(sensorsDatas.tm.Hour, sensorsDatas.tm.Minute);
  }*/
  if (loopTemp(&sensorsDatas.temperature)) {
    Serial.println(sensorsDatas.temperature);
    showTemp(sensorsDatas.temperature);
  }
  loopGPS(sensorsDatas.gps);
  Serial.print(sensorsDatas.gps.lat);  Serial.print(";");  Serial.print(sensorsDatas.gps.lng);  Serial.print(";");  Serial.print(sensorsDatas.gps.speed);
//  showGPS();
  writeSDData(sensorsDatas);
  loopScreen();
}
