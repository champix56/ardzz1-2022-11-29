#include "config.h"

#ifdef _DS18B20_
#define __TEMPERATURE_

// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino


// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(PIN_DS18B20);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
//setup
void setupTemp() {
  sensors.begin();

}
//loop
bool loopTemp(float *temp) {
  sensors.requestTemperatures();
  *temp= sensors.getTempCByIndex(0);
  if (*temp != DEVICE_DISCONNECTED_C)return true;
  else return false;
}
#endif
