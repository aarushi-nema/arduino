#include <IRremote.h>

int reciever_pin= 11;

IRrecv recv(reciever_pin);

decode_results results;

int greenled=5;
int redled=6;
int yellowled=7;
int blueled=4;

int redtoggle=0;
int yellowtoggle=0;
int bluetoggle=0;
int greentoggle=0;

long int readval;

void setup() {
  Serial.begin(9600);
  recv.enableIRIn();
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(yellowled, OUTPUT);
  pinMode(blueled, OUTPUT);
}

void loop() {
  if(recv.decode(&results)){
    readval= results.value;
    Serial.println(results.value);
    if ((readval==109 || readval==65645) && redtoggle==0){
      digitalWrite(redled, HIGH);
      delay(100);
      redtoggle++;
    } else if ((readval==109 || readval==65645) && redtoggle==1){
      digitalWrite(redled, LOW);
      delay(100);
      redtoggle--;
    } else if ((readval==110 || readval==65646) && greentoggle==0){
      digitalWrite(greenled, HIGH);
      delay(100);
      greentoggle++;
    } else if ((readval==110 || readval==65646) && greentoggle==1){
      digitalWrite(greenled, LOW);
      delay(100);
      greentoggle--;
    } else if ((readval==111 || readval==65647) && yellowtoggle==0){
      digitalWrite(yellowled, HIGH);
      delay(100);
      yellowtoggle++;
    } else if ((readval==111 || readval==65647) && yellowtoggle==1){
      digitalWrite(yellowled, LOW);
      delay(100);
      yellowtoggle--;
    } else if ((readval==112 || readval==65648) && bluetoggle==0){
      digitalWrite(blueled, HIGH);
      delay(100);
      bluetoggle++;
    } else if ((readval==112 || readval==65648) && bluetoggle==1){
      digitalWrite(blueled, LOW);
      delay(100);
      bluetoggle--;
    }
    recv.resume(); 
  }

  delay(100);
}
