#define GREEN_PORT 10
#define YELLOW_PORT 9
#define RED_PORT 8

void initFeuxPieton(){
   //def des pullup res
  pinMode(GREEN_PORT, OUTPUT);
  pinMode(YELLOW_PORT, OUTPUT);
  pinMode(RED_PORT, OUTPUT);
}
/**
   declenchement pour le passage pieton de sequence des feux
   @params waitTime {uint6_t} temps d'attente au vert pour le pieton en ms
*/
void sequencePassagePieton(uint16_t waitTime) {
  //extinction rouge
  digitalWrite(RED_PORT, LOW);
  //allumage vert
  digitalWrite(GREEN_PORT, HIGH);
  //attente
  delay(1000);
  //extinction vert
  digitalWrite(GREEN_PORT, LOW);
  //allumage orange
  digitalWrite(YELLOW_PORT, HIGH);
  //attente
  delay(1000);
  //extinction orange
  digitalWrite(YELLOW_PORT, LOW);
  //allumage rouge
  digitalWrite(RED_PORT, HIGH);
  delay(waitTime);
}
/**
 * lecture depuis A0 d'une valeur de tension convertie vers une valeur en sec 25sec max
 * @returns {uint16_t} temps en millis seconde
 */
uint16_t lectureTemps(){
  //lecture du potentiometre sur A0
  uint16_t potarLevel=analogRead(A0);
  float voltValue=potarLevel*PAS_CAN;
  /*  Serial.print("Valeur en volt :");Serial.print(voltValue);Serial.println("v");*/
  return voltValue*voltValue*1000;
}
