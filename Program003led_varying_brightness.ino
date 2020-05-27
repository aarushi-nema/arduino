int led=9;
int bright=0;
int wait=500;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=0; i<4; i++){
    bright+=63;
    if(bright>253){
      bright=0;
    }
    analogWrite(led, bright);
    delay(wait);
  }
}
