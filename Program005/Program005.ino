void setup() {
  // put your setup code here, to run once:
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=0; i<5; i++){
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(10, HIGH);
    delay(1000);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    delay(1000);
  }

  for (int j=0; j<5; j++){
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    delay(1000);
    digitalWrite(9,LOW);
    digitalWrite(10, LOW);
    delay(1000);
  }

  for (int k=0; k<5; k++){
    digitalWrite(10, HIGH);
    delay(1000);
    digitalWrite(10,LOW);
    delay(1000);
  }

}
