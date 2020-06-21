int pir_pin=8;
int relay_pin=7;
int pir_value;

void setup() {
  pinMode(pir_pin, INPUT);
  pinMode(relay_pin, OUTPUT);
  digitalWrite(relay_pin, LOW);
  Serial.begin(9600);
}

void loop() {
  pir_value= digitalRead(pir_pin);
  Serial.println(pir_value);
  if(pir_value==1){
    digitalWrite(relay_pin, HIGH);
  } else {
    digitalWrite(relay_pin, LOW);
  }
}
