#define HARDWARE_RTC_COMPONENT
#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

void setupRTC() {
}
bool loopRTC(tmElements_t *myTimeStruct) {
  if (RTC.read(*myTimeStruct)) return true;
  else return false;
}
