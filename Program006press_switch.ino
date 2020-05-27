int led= 9;
int button= 8;
int dt=100;
int buttonread;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonread= digitalRead(button);
  Serial.println(buttonread);
  
  if (buttonread==1){
    digitalWrite(led,LOW);
  }

  if(buttonread==0){
    digitalWrite(led, HIGH);
  }

  delay(dt); 

}
