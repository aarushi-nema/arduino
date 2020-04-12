//SOS

int pin=8;
int dit=100;
int dat=1000;

void setup() {
  pinMode(pin, OUTPUT);// put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<3; i++){
    digitalWrite(pin, HIGH);
    delay(dit);
    digitalWrite(pin,LOW);
    delay (dit);
  }

    for(int i=0; i<3; i++){
      digitalWrite(pin,HIGH);
      delay(dat);
      digitalWrite(pin,LOW);
      delay(dat);
    }

    for(int i=0; i<3; i++){
    digitalWrite(pin, HIGH);
    delay(dit);
    digitalWrite(pin,LOW);
    delay (dit);

    }

    delay(5000);
}
