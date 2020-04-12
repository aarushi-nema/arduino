int redLED=10;
int greenLED=11;
int blueLED=12;

int redwait= 100;
int greenwait= 300;
int bluewait= 900;

int longwait=1200;


void setup() {
  // put your setup code here, to run once:
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<5; i++){
    digitalWrite(redLED, HIGH);
    delay(redwait);
    digitalWrite(redLED, LOW);
    delay(redwait);
  }

  for(int i=0; i<10; i++){
    digitalWrite(greenLED, HIGH);
    delay(greenwait);
    digitalWrite(greenLED, LOW);
    delay(greenwait);
  }

  for(int i=0; i<15; i++){
    digitalWrite(blueLED, HIGH);
    delay(bluewait);
    digitalWrite(blueLED, LOW);
    delay(bluewait);
  }

  delay(longwait);

}
