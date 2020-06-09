int potpin= A0;
float potval;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(potpin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  potval= analogRead(potpin);
  potval= potval/205;
  Serial.println(potval);
  delay(400);

}
