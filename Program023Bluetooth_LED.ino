char ins=0;
int led=8;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available()>0){
    ins= Serial.read();
    Serial.print(ins);
    Serial.print("\n");

    if(ins=='1'){
      digitalWrite(led, HIGH);
    }

    else if(ins=='0'){
      digitalWrite(led, LOW);
    }
  }
}
