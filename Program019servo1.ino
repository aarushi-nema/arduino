#include<Servo.h>
int servoPin=9;
int servoPos=90;
Servo myservo;

void setup() {
  Serial.begin(9600);
  myservo.attach(servoPin);

}

void loop() {
  Serial.println("What angle for the Servo?");
  while(Serial.available()==0){
    
  }

  servoPos= Serial.parseInt();
  myservo.write(servoPos);
}
