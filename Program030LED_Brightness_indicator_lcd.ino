#include <LiquidCrystal.h>
int rs= 7;
int en= 8;
int d7= 9;
int d6= 10;
int d5= 11;
int d4= 12;

int led=6;
int potpin= A0;
int brightness;
int potval;
int indicator;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

byte pBar[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

void setup() {
  pinMode(led, OUTPUT);
  pinMode(potpin, INPUT);
  lcd.begin(16,2);
  digitalWrite(led, LOW);
  lcd.createChar(0, pBar);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" LED BRIGHTNESS");
  potval=analogRead(potpin);
  brightness=(255.0/1023.0)*potval;
  analogWrite(led, brightness);
  indicator= (17.0/255.0)*brightness;
  lcd.setCursor(0,1);
  for(int i=0; i<indicator; i++){
    lcd.setCursor(i,1);
    lcd.write(byte(0));
  }

  delay(500);
  
}
