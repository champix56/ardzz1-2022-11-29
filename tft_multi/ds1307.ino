#include "config.h"
#ifdef _DS1307_
#define __RTC_
#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

void setupRTC() {
}
bool loopRTC(tmElements_t *myTimeStruct) {
  if (RTC.read(*myTimeStruct)) return true;
  else return false;
}
#endif
