#ifndef __CONFIG_H
  #define __CONFIG_H

  /* RTC list */
  #define _DS1307_ 
  // #define _DSXXxx_
  #if defined(_DS1307_)
    #include "ds1307.h"
  #endif


  /* SD list */
  #define _SD_CSV_
  //#define _SD_BIN_ //Si enregistrement binaire

  #if defined(_SD_CSV_) || defined(_SD_BIN_)
    #include "sd_all.h"
  #endif
  
  #define PIN_CS_SD 7
  #if defined(_SD_CSV_)
    #define SD_FILENAME "sensors.csv"
  #elif
    #define SD_FILENAME "sensors.bin"
  #endif


  /* GPS List */
   #define _GPS_STD_
   #if defined(_GPS_STD_)
      #include "gps.h"
   #endif
   
   #define PIN_GPS_TX 5
   #define PIN_GPS_RX 6

   /* Temperatue */
   #define _DS18B20_ 
   #if defined(_DS18B20_)
      #include "ds18b20.h"
   #endif
   #define ONE_WIRE_BUS 4
#endif
