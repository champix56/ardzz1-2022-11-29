#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>
#define TFT_CS        10
#define TFT_RST        9 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC         8
#define W_SCREEN 128
#define H_SCREEN 160
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
void setupScreen() {
  //initialisation de l'ecran
  tft.initR(INITR_BLACKTAB);
  //remplissage tout l'ecran avec couleur noir
  tft.fillScreen(ST77XX_BLACK);
  initMainFrame();
}
void loopScreen(){
   tft.setCursor(30,90);
  tft.setTextColor(ST77XX_MAGENTA);
  tft.setTextSize(1);
  tft.print("bon appetit");
  tft.setCursor(30,100);
  tft.print("biensur");
}
void initMainFrame(){
  tft.fillRect(0,0,W_SCREEN,7,ST77XX_CYAN);
  showTime(0,0);

  showButtons("STOP","START");
}
void showButtons(const char *textL,const char *textR){
  tft.fillRect(0,H_SCREEN-13,(int)(W_SCREEN/2.0F),13,ST77XX_RED);
  tft.fillRect((W_SCREEN/2.0F),H_SCREEN-13,(int)(W_SCREEN/2.0F),13,ST77XX_GREEN);
  tft.fillCircle((W_SCREEN/2.0F),H_SCREEN,14,ST77XX_BLUE);
  tft.setTextSize(1);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(12,H_SCREEN-10);
  tft.print(textL);
  tft.setCursor((W_SCREEN/2.0F)+24,H_SCREEN-10);
  tft.print(textR);
}
void showTime(uint8_t h,uint8_t m){
   char tmp[6];
    sprintf(tmp,"%02d:%02d",h,m);
    tft.fillRect(44,0,40,14,ST77XX_CYAN);
    tft.setCursor(49,4);
    tft.setTextColor(ST77XX_RED);
    tft.setTextSize(1);
    tft.print(tmp);
}
