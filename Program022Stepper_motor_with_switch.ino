#include<Stepper.h>
int spr=2048;
Stepper myStepper (spr, 8,10,9,11);
int motspeed=10;
int buttonpin=2;
int motDir=1;
int buttonvalnew;
int buttonvalold=1;

void setup() {
  pinMode(buttonpin, INPUT);
  myStepper.setSpeed(motspeed);
  digitalWrite(buttonpin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonvalnew= digitalRead(buttonpin);

  if(buttonvalold==1 && buttonvalnew==0){
    motDir=motDir*(-1);
  }

  myStepper.step(motDir*1);

  buttonvalold= buttonvalnew;
}
