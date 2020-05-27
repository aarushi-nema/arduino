int led1=8;
int led2=9;
int led3=10;
int led4=11;
int wait=2000;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      for(int k=0; k<2; k++){
        for(int l=0; l<2; l++){
          if(i==0){
            digitalWrite(led4, LOW);
          }

          else {
            digitalWrite(led4, HIGH);
          }

          if(j==0){
            digitalWrite(led3, LOW);
          }

          else {
            digitalWrite(led3, HIGH);
          }

          if(k==0){
            digitalWrite(led2, LOW);
          }

          else {
            digitalWrite(led2, HIGH);
          }

          if(l==0){
            digitalWrite(led1, LOW);
          }

          else {
            digitalWrite(led1, HIGH);
          }

          delay(wait);
        }
      }
    }
  }

}
