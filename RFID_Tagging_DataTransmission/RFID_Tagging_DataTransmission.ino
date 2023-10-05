#include <SPI.h>
#include <MFRC522.h>
#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc(SS_PIN, RST_PIN);

// int LED_Y = 3;
// int LED_R = 4;

void setup(){
  Serial.begin(9600);
  SPI.begin();

  // pinMode(LED_Y, OUTPUT);
  // pinMode(LED_R, OUTPUT);
}

void loop(){
  if(!mfrc.PICC_IsNewCardPresent() || !mfrc.PICC_ReadCardSerial()){
    delay(500);
    return;
  }

if(mfrc.uid.uidByte[0] == 64 & mfrc.uid.uidByte[1] == 43
    &&mfrc.uid.uidByte[2] == 23 && mfrc.uid.uidByte[3] == 29){
  // digitalWrite(LED_Y, HIGH);
  // digitalWrtie(LED_R, LOW);
  Serial.println("Patient 1");
  tone(6, 523, 100);
  delay(500);
  
  }

else if(mfrc.uid.uidByte[0] == 179 & mfrc.uid.uidByte[1] == 139
    &&mfrc.uid.uidByte[2] == 70 && mfrc.uid.uidByte[3] == 146){
  // digitalWrite(LED_Y, HIGH);
  // digitalWrtie(LED_R, LOW);
  Serial.println("Patient 2");
  tone(6, 523, 100);
  delay(500);
  
  }

else{
    // digitalWrite(LED_R, HIGH);
    // digitalWrite(LED_Y, LOW);
    Serial.println("None");
    tone(6, 523, 100);
    delay(300);
    tone(6, 523, 100);
    delay(500);
  }
}
