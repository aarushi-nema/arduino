#include<LiquidCrystal.h>
int rs=7;
int en=6;
int d4=2;
int d5=3;
int d6=4;
int d7=5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int trigpin=12;
int echopin=11;
int traveltime;
int dt=25;
int distance;

void setup() {
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);

}

void loop() {
  digitalWrite(trigpin, LOW);
  delayMicroseconds(dt);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(dt);
  digitalWrite(trigpin, LOW);
  traveltime= pulseIn(echopin, HIGH);
  distance= traveltime*(0.034/2);
  delay(300);
  lcd.setCursor(0,0);
  lcd.print("Distance= ");
  lcd.print(distance);
  lcd.print(" cm");
}
