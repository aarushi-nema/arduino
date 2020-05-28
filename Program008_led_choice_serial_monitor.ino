int greenled= 11;
int redled=10;
int yellowled=9;
int blueled=8;
String msg1= "Do you want green, red, yellow or blue led on?";
String choice;
String msg2=" led is on";

void setup() {
  // put your setup code here, to run once:
  pinMode(greenled, OUTPUT);
  pinMode(redled, OUTPUT);
  pinMode(yellowled, OUTPUT);
  pinMode(blueled, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg1);
  while(Serial.available()==0){
    
  }

  choice = Serial.readString();

  if(choice=="green"){
    digitalWrite(greenled, HIGH);
    digitalWrite(redled, LOW);
    digitalWrite(yellowled, LOW);
    digitalWrite(blueled, LOW);
  }

  if(choice=="red"){
    digitalWrite(greenled, LOW);
    digitalWrite(redled, HIGH);
    digitalWrite(yellowled, LOW);
    digitalWrite(blueled, LOW);
  }

  if(choice=="yellow"){
    digitalWrite(greenled, LOW);
    digitalWrite(redled, LOW);
    digitalWrite(yellowled, HIGH);
    digitalWrite(blueled, LOW);
  }

  if(choice=="blue"){
    digitalWrite(greenled, LOW);
    digitalWrite(redled, LOW);
    digitalWrite(yellowled, LOW);
    digitalWrite(blueled, HIGH);
  }

}
