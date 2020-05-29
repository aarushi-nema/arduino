int redled=8;
int yellowled=9;
int greenled=10;
int potpin= A1;
int potval;
float voltage;

void setup(){
  pinMode(redled, OUTPUT);
  pinMode(yellowled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(potpin, INPUT);
  Serial.begin(9600);
}

void loop(){

  potval= analogRead(potpin);
  voltage=(5.0/1023.0)*potval;
  Serial.println(voltage);

  if(voltage<=3){
    digitalWrite(redled,LOW);
    digitalWrite(yellowled,LOW);
    digitalWrite(greenled,HIGH);
  }

   if(voltage>3 && voltage<=4){
    digitalWrite(redled,LOW);
    digitalWrite(yellowled,HIGH);
    digitalWrite(greenled,LOW);
  }

   if(voltage>4){
    digitalWrite(redled,HIGH);
    digitalWrite(yellowled,LOW);
    digitalWrite(greenled,LOW);
  }
  
  
}
