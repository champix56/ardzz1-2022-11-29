//https://learn.adafruit.com/adafruit-gfx-graphics-library/graphics-primitives
#include "struct.h"

struct S_Sensor sensorsDatas;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  setupScreen();
  setupTemp();
}

void loop() {
  // put your main code here, to run repeatedly:
  //if(loopRTC(&tm)){showTime(tm.Hour,tm.Minute);}
  if (loopRTC(&sensorsDatas.tm)) {
    showTime(sensorsDatas.tm.Hour, sensorsDatas.tm.Minute);
  }
  if (loopTemp(&sensorsDatas.temperature)) {
    Serial.println(sensorsDatas.temperature);
    showTemp(sensorsDatas.temperature);
  }

  loopScreen();
}
