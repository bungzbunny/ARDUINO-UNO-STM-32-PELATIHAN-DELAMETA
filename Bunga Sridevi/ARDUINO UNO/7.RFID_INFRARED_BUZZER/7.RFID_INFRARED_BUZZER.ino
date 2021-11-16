//Download dan masukan Library MFRC522
#include <SPI.h>
#include <MFRC522.h>

String uidString;

//inisialisasi output
int pinBUZZER = 3; 
int pinINFRARED = 5;

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);

void bunyibuzzeroke() {
    digitalWrite(pinBUZZER, HIGH);
    delay(150);
    digitalWrite(pinBUZZER, LOW);
    delay(50);
    digitalWrite(pinBUZZER, HIGH);
    delay(150);
    digitalWrite(pinBUZZER, LOW);
    delay(50);
}
 void bunyibuzzergagal() {
    digitalWrite(pinBUZZER, HIGH);
    delay(650);
    digitalWrite(pinBUZZER, LOW);
    delay(50);
}
 void readRFID() {
    mfrc522.PICC_ReadCardSerial();
    //PEMBATAS BISA DIRUBAH SESUAI KEINGINAN, DISINI YANG DIGUNAKAN "-"
    uidString = String(mfrc522.uid.uidByte[0],HEX) + "-" +
                String(mfrc522.uid.uidByte[1],HEX) + "-" +
                String(mfrc522.uid.uidByte[2],HEX) + "-" +
                String(mfrc522.uid.uidByte[3],HEX);
                uidString.toUpperCase();
 }
 


void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 
 Serial.begin(115200); 
 SPI.begin(); 
 mfrc522.PCD_Init();
 pinMode (pinBUZZER, OUTPUT);
 Serial.println ("Tempelkan Kartu");
 pinMode (pinINFRARED, INPUT);
 Serial.println ("GERBANG TERTUTUP");

}



void loop() {
  //BACADATA
    if(mfrc522.PICC_IsNewCardPresent()){
    readRFID();
    Serial.print("ID : ");
    Serial.println(uidString);
    if(uidString=="5-8D-4-AE"){
    bunyibuzzeroke();
    Serial.println("BERHASIL");
    delay(500);
    Serial.println("SILAHKAN MASUK");
    Serial.println("GERBANG TERBUKA");
    while(1){
      int state = digitalRead(pinINFRARED);
      if (state == 1){
      state =1;
      }else {
      Serial.println("GERBANG TERTUTUP");
      break;
      }
    }
    }

    else{
    Serial.println("TIDAK TERDAFTAR");
    Serial.println("GERBANG TERTUTUP");
    bunyibuzzergagal();
    }

}
}
 
