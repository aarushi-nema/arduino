int redled=10;
int greenled=9;
int blueled=8;
String choice;
String msg="Enter red, green, blue or off";


void setup() {
  // put your setup code here, to run once:
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(blueled, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  while(Serial.available()==0){
    
  }

  choice= Serial.readString();

  if(choice=="red"){
    digitalWrite(redled, HIGH);
    digitalWrite(blueled, LOW);
    digitalWrite(greenled, LOW);
  }

  else if (choice=="green"){
    digitalWrite(greenled, HIGH);
    digitalWrite(redled, LOW);
    digitalWrite(blueled, LOW);
  }

  else if (choice=="blue"){
    digitalWrite(blueled, HIGH);
    digitalWrite(redled, LOW);
    digitalWrite(greenled, LOW);
  }

  else {
     digitalWrite(blueled, LOW);
    digitalWrite(redled, LOW);
    digitalWrite(greenled, LOW);
    
  }

}
