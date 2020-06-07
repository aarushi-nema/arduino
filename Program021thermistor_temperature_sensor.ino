#include<LiquidCrystal.h>
int rs= 7;
int en=8;
int d4=12;
int d5=11;
int d6=10;
int d7=9;
LiquidCrystal lcd (rs, en, d4,d5,d6,d7);

int Thermistorpin=A0;
int Vo;
float R1=100000;
float logR2, R2, T;
float A=1.009249522e-03, B= 2.3784054444e-04, C=2.019202697e-07;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Thermistorpin, INPUT);
  lcd.begin(16,2);

}

void loop() {
  // put your main code here, to run repeatedly:
  Vo= analogRead(Thermistorpin);
  R2= R1*(1023.0/(float)Vo -1.0);
  logR2= log(R2);
  T=(1.0/(A+B*logR2 + C*logR2*logR2*logR2));
  T=T-273.15;
  //T= (T*9.0)/5.0 + 32.0;

  Serial.print("Temperature: ");
  Serial.print(T);
  Serial.println(" C");

  lcd.setCursor(0,0);
  lcd.print("Tempertaure: ");
  lcd.setCursor(0,1);
  lcd.print(T);
  lcd.print(" C");

  delay(500);

}
