String msg="How many blinks?";
int blinks;
int led=8;
int dt=500;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  while(Serial.available()==0){
    
  }
  blinks=Serial.parseInt();

  for(int i=1; i<=blinks; i++){
    digitalWrite(led, HIGH);
    delay(dt);
    digitalWrite(led, LOW);
    delay(dt);
  }
  

}
