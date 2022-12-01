#include "config.h"
#ifdef _SERIAL_SCREEN_
#ifndef _ST7735_1_8_
#define __SCREEN_
void setupScreen() {
  Serial.begin(9600);
}
void loopScreen(){
}
void showTemp(float temp){
  char buff[8]="";
  dtostrf(temp, 2, 2, buff);
  char degSymbol=0xf7;
  buff[5]=degSymbol;
  buff[6]='\0';
  strcat(buff,"c");
  Serial.println(buff);
 }
void showTime(uint8_t h,uint8_t m){
   char tmp[6];
    sprintf(tmp,"%02d:%02d",h,m);
    Serial.println(tmp);
}
void showGPS(){
}

#endif
#endif
