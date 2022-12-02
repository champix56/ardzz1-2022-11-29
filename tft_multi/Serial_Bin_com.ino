#include "config.h"
#include "struct.hpp"
#if defined(UNIT_SENSORS) && !defined(UNIT_DATA_TREATMENT)
uint16_t lastSend=0;
  void serialValuesExcahnge(struct S_Sensor *sensors){
    if(millis()<lastSend+200)return;
    U_Sensors unionSensors;
    unionSensors.datas=*sensors;
    for(int i=0;i<sizeof(struct S_Sensor);i++){
      Serial.write(unionSensors.bytes[i]);
    }
    lastSend=millis();
  }

#elif defined(UNIT_DATA_TREATMENT) && !defined(UNIT_SENSORS)
  void serialValuesExcahnge(struct S_Sensor *sensors){
    U_Sensors uSensors;
    //bool isTimeOut=false;
    Serial.flush();
    uint32_t startTime=millis();
    while(Serial.available()>1&& startTime+250<millis()){delay(50);}
    uint8_t i=0;
    while(Serial.available()){
      uSensors.bytes[i++]=Serial.read();
    }
    *sensors=*(&uSensors.datas);
}
#endif
