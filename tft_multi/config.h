#ifndef __CONFIG_
  #define __CONFIG_

  #define _DS1307_
  
  #define _DS18B20
  #define PIN_DS18B20 4
  
  #define _SERIAL_GPS_
  #define PIN_SERIAL_RX_GPS 5
  
  #define _ST7735_1_8_
  #define PIN_CS_TFT 10
  #define PIN_RST_TFT 9 // Or set to -1 and connect to Arduino RESET pin
  #define PIN_DC_TFT 8
  
  #define _SERIAL_SCREEN_

  #define _SD_CSV_
  #define PIN_CS_SD 7
  
#endif
