#define PAS_CAN 5.0F / 1024.0F
#define BUTTON_PIN 2
volatile bool isPushed=false;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Setup");
  pinMode(BUTTON_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN),interruptionFunction,RISING);
  initFeuxPieton();
}

void loop()
{
  Serial.println("loop");
  // put your main code here, to run repeatedly:
  if(isPushed){
    uint16_t tempsEnMillisSec = lectureTemps();
    sequencePassagePieton(tempsEnMillisSec);
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN),interruptionFunction,RISING);
    isPushed=false;

  }
  delay(5000);
}

void interruptionFunction(){
    detachInterrupt(digitalPinToInterrupt(BUTTON_PIN));
    isPushed=true;
}