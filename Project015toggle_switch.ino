int ledstate=0;
int led=7;
int buttonpin=8;
int buttonnew;
int buttonold=1;
int dt=100;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(buttonpin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonnew=digitalRead(buttonpin);
  if(buttonold==0 && buttonnew==1){
    if(ledstate==0){
      digitalWrite(led, HIGH);
      ledstate=1;
    } else {
      digitalWrite(led, LOW);
      ledstate=0;
    }
  }

  buttonold=buttonnew;
  delay(dt);

}
