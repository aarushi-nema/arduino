#include<SPI.h>
#include<MFRC522.h>
#include<LiquidCrystal.h>

int rs=2;
int en=3;
int d7=4;
int d6=5;
int d5=6;
int d4=7;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int ss_pin= 10;
const int reset_pin=9;

MFRC522 mfrc522(ss_pin, reset_pin);

byte readCard[4];
String master_id= "B2481E39";
String tag_id;

void setup() {
  SPI.begin();
  mfrc522.PCD_Init();
  lcd.begin(16,2);
  lcd.clear();
  lcd.print(" Access Control ");
  lcd.setCursor(0,1);
  lcd.print("Scan Your Card>>");
}

void loop() {
  while(getID()){
    lcd.clear();
    lcd.setCursor(0,0);

    if(tag_id==master_id){
      lcd.print("Access Granted!");
    } else {
      lcd.print("Access Denied!");
    }

    lcd.setCursor(0,1);
    lcd.print(" ID: ");
    lcd.print(tag_id);

    delay(3000);

    lcd.clear();
    lcd.print(" Access Control ");
    lcd.setCursor(0,1);
    lcd.print("Scan Your Card>>");
  }
}

boolean getID(){
  if(!mfrc522.PICC_IsNewCardPresent()){
    return false;
  }

  if(!mfrc522.PICC_ReadCardSerial()){
    return false;
  }

  tag_id="";

  for( uint8_t i=0; i<4; i++){
    tag_id.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  tag_id.toUpperCase();
  mfrc522.PICC_HaltA();
  return true;
}
