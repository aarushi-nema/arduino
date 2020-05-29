int redled=9;
int greenled=8;
int lightpin=A2;
int lightval;

void setup() {
  // put your setup code here, to run once:
  pinMode(lightpin, INPUT);
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  lightval= analogRead(lightpin);
  Serial.println(lightval);

  if(lightval<100){
    digitalWrite(redled, HIGH);
    digitalWrite(greenled, LOW);
  } else {
    digitalWrite(redled, LOW);
    digitalWrite(greenled, HIGH);
  }
}
