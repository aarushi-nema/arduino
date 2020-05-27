int LEDpin=13;
int wait= 500;
void setup() {
  pinMode(LEDpin,OUTPUT);
}

void loop() {
  digitalWrite(LEDpin, HIGH);
  delay(wait);
  digitalWrite(LEDpin, LOW);
  delay(wait);
}
