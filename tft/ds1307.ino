#define HARDWARE_COMPONENT_RTC
#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

void setupRTC() {
}
bool loopRTC(tmElements_t *myTimeStruct) {
  if (RTC.read(*myTimeStruct)) return true;
  else return false;
}
