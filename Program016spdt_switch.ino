int spdt=3;
int blueled=12;
int yellowled=11;
int switch_val;

void setup() {
  // put your setup code here, to run once:
  pinMode(spdt, INPUT);
  pinMode(blueled, OUTPUT);
  pinMode(yellowled, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  switch_val= digitalRead(spdt);

  if(switch_val==1){
    digitalWrite(blueled, LOW);
    digitalWrite(yellowled, HIGH);
  } else {
    digitalWrite(blueled, HIGH);
    digitalWrite(yellowled, LOW);
  }

}
