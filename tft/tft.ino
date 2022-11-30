//https://learn.adafruit.com/adafruit-gfx-graphics-library/graphics-primitives
#include <TimeLib.h>

tmElements_t tm;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  setupScreen();
}

void loop() {
  // put your main code here, to run repeatedly:


  /*if (RTC.read(tm)) {
    char tmp[6];
    sprintf(tmp,"%2d:%2d",tm.Hour,tm.Minute);
    Serial.println(tmp);
  }*/
  if(loopRTC(&tm)){showTime(tm.Hour,tm.Minute);}
  loopScreen();
}
