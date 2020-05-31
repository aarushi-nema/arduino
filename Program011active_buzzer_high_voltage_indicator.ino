int potpin=A2;
int potval;
float volt;
int buzzpin=12;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzpin, OUTPUT);
  pinMode(potpin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  potval=analogRead(potpin);
  volt=(5.0/1023.0)*potval;
  Serial.println(volt);

  if(volt>4){
    digitalWrite(buzzpin, HIGH);
  } else {
    digitalWrite(buzzpin, LOW);
  }

}
