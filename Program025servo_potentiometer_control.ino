#include<Servo.h>
int servopin=9;
int servopos=0;;
Servo myservo;

int potpin=A0;
int potval;

void setup() {
  pinMode(potpin, INPUT);
  myservo.attach(servopin);
  myservo.write(servopos);
  Serial.begin(9600);
}

void loop() {
  potval=analogRead(potpin);
  servopos=(180.0/1023.0)*potval;
  myservo.write(servopos);
  Serial.println(servopos);
}
