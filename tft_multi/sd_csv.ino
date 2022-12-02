#include "config.h"
#if defined(_SD_CSV_)&&!defined(_SD_BIN_) 
#include "struct.hpp"
#include <SD.h>
File myFile;

bool setupSD() {
  if (SD.begin(PIN_CS_SD))return true;
return false;
}
bool writeSDData(struct S_Sensor datas){
  myFile = SD.open(SD_FILENAME, FILE_WRITE);
  Serial.println("sd write data");
  if (myFile) {
  Serial.println("File ok");
    //AAAA-MM-JJTHH:MM:SS
    char *datetime=(char *)calloc(21,sizeof(char));
    sprintf(datetime,"%4d-%2d-%2dT%2d:%2d:%2d;",
            datas.tm.Year,datas.tm.Month,datas.tm.Day,
            datas.tm.Hour,datas.tm.Minute,datas.tm.Second);
    myFile.print(datetime);
    Serial.print(datetime);
    free(datetime);
    
    // close the file:
    myFile.print("\n");
    Serial.print("\n");
    myFile.close();
  return true;
  } 
    return false;
}
#endif
