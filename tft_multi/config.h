#ifndef __CONFIG_H
  #define __CONFIG_H
  /* unit type*/
  //#define UNIT_SENSORS
  #define UNIT_DATA_TREATMENT

  #ifdef UNIT_SENSORS
    #define _DS1307_ 
    #define _DS18B20_
    #define _SERIAL_GPS_
  #endif
  #ifdef UNIT_DATA_TREATMENT
    #define _ST7735_
    #define _SD_CSV_
  #endif




  /*RTC LISTE*/
  //#define _DS1307_ "RTC1307"
    #if defined(_DS1307_)
      #include "ds1307.h"
    #endif
  //#define _DS1308_
  
  /*SD CONFIG LISTE*/
  //#define _SD_CSV_
  //#define _SD_BIN_
  #if defined(_SD_CSV_)||defined(_SD_BIN_)
    #include "sd_ all.h"
    #define PIN_CS_SD 7
    #if defined(_SD_CSV_)
      #define SD_FILENAME "sensors.txt"
    #elif defined(_SD_BIN_)
      #define SD_FILENAME "sensors.BIN"
    #endif
  #endif

  /*TEMPERATURE CONFIG LISTE*/
  //#define _DS18B20_
  #ifdef _DS18B20_
    #define PIN_DS18B20 4
  #endif
  //#define _BMP180_TEMP_

  /*GPS CONFIG LISTE*/
  //#define _SERIAL_GPS_
  #ifdef _SERIAL_GPS_
    #define PIN_RX_GPS 5
    #define PIN_TX_GPS 6
  #endif

  /*SCREEN LISTE*/
  //#define _ST7735_
  #ifdef _ST7735_
    #include "screen.h"
   #endif
#endif
