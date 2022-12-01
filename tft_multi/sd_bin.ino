#include "config.h"
#ifdef _SD_BIN_
#ifndef __SD_
#define __SD_
#define CS_PIN_SD 7
#define SD_FILENAME "sensors.bin"
#include <SD.h>
File myFile;
bool setupSD() {
  if (SD.begin(PIN_CS_SD))return true;
  return false;
}
bool writeSDData(struct S_Sensor datas)
{
  //binary write
}
#endif
#endif
