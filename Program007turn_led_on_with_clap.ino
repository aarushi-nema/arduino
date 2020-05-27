int led=9;
int sound=10;
int j=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(sound, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(sound)==HIGH){
    j++;
  }

  if(j%2==0){
    digitalWrite(led, LOW);
  }

  if(j%2!=0){
    digitalWrite(led,HIGH);
  }

}
