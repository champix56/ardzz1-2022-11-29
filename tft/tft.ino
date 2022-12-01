//https://learn.adafruit.com/adafruit-gfx-graphics-library/graphics-primitives
#include <TimeLib.h>

tmElements_t tm;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  setupScreen();
  setupTemp();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(loopRTC(&tm)){showTime(tm.Hour,tm.Minute);}
  float temperature=0.0F;
  if(loopTemp(&temperature)){
    Serial.println(temperature);
    showTemp(temperature);
  }
  
  loopScreen();
}
