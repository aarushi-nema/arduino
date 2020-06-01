int redled=8;
int tilt_switch=2;

void setup() {
  // put your setup code here, to run once:
  pinMode(redled, OUTPUT);
  pinMode(tilt_switch, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(tilt_switch)==HIGH){
    digitalWrite(redled, HIGH);
  } else {
    digitalWrite(redled, LOW);
  }

}
