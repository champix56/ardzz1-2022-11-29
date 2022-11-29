void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Setup");
  //def des pullup res
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() {
  Serial.println("loop");
  // put your main code here, to run repeatedly:
  //extinction rouge
  digitalWrite(10,LOW);
  
  //allumage vert
  digitalWrite(8,HIGH);
    //attente
  delay(1000);
    //extinction vert
  digitalWrite(8,LOW);
    //allumage orange
  digitalWrite(9,HIGH);
  //attente
  delay(1000);
    //extinction orange
  digitalWrite(9,LOW);
    //allumage rouge
  digitalWrite(10,HIGH);
 
  
  delay(50000);
}
