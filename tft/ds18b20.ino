//includes
#define HARDWARE_COMPONENT_TEMP

// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 4

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

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
