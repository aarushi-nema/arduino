#include<LiquidCrystal.h>
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);
int random_number;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(0,0);
  random_number=(long)(random(1,301));
  lcd.print("Random number: ");
  lcd.setCursor(0,1);
  lcd.print(random_number);
  delay(1000);
}
