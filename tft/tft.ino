//https://learn.adafruit.com/adafruit-gfx-graphics-library/graphics-primitives

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>
#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

#define TFT_CS        10
#define TFT_RST        9 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC         8

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //initialisation de l'ecran
    tft.initR(INITR_BLACKTAB);
    //remplissage tout l'ecran avec couleur noir 
    tft.fillScreen(ST77XX_BLACK);
}

void loop() {
  // put your main code here, to run repeatedly:
   tmElements_t tm;

  if (RTC.read(tm)) {
    char tmp[6];
    sprintf(tmp,"%2d:%2d",tm.Hour,tm.Minute);
    Serial.println(tmp);
  }
  tft.setCursor(30,90);
  tft.setTextColor(ST77XX_MAGENTA);
  tft.setTextSize(1);
  tft.print("bon appetit");
  tft.setCursor(30,100);
  tft.print("biensur");
}
