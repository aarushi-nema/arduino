int buzzer = 10;
int redled = 9;
int greenled = 8;
int fire = 11;
int dt = 50;
int fire_state;

void setup() {
  // put your setup code here, to run once:
  pinMode(fire, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  fire_state = digitalRead(fire);

  if (fire_state == HIGH) {
    digitalWrite(redled, HIGH);
    digitalWrite(greenled, LOW);
    
    for (int i = 450; i < 550; i++) {
      tone(buzzer, i, 100);
      delay(dt);
    }

    for (int i = 550; i > 450; i--) {
      tone(buzzer, i, 100);
      delay(dt);
    }

  }  else {
    digitalWrite(redled, LOW);
    digitalWrite(greenled, HIGH);
  }

}
