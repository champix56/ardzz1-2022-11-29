void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Setup");
  initFeuxPieton();
}

void loop() {
  Serial.println("loop");
  // put your main code here, to run repeatedly:
  sequencePassagePieton(50000);
}
