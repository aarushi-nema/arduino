int pot_val;
float led_val;
int led_pin=9;
int pot_pin=A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pot_pin, INPUT);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pot_val= analogRead(pot_pin);
  led_val= (255.0/1023.0)*pot_val;
  analogWrite(led_pin, led_val);

}
