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


void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 
 Serial.begin(115200); 
 SPI.begin(); 
 mfrc522.PCD_Init();
 pinMode (pinBUZZER, OUTPUT);
 bunyibuzzeroke();
 Serial.println ("Tempelkan Kartu")

}



void loop() {
  //BACADATA
    if(mfrc522.PICC_IsNewCardPresent(){
    readRFID();
    Serial.print("Tag UID: ");
    Serial.println(uidString);
    if(uidString=="058D 04AEAB71 00");
    bunyibuzzeroke();
    Serial.println("SELAMAT DATANG MAS HUSNUL <3 ");
    delay(1000);
    Serial.println("SILAHKAN MASUK");
    
    }else{
    Serial.println("GAGAL");
    bunyibuzzergagal();
    }
    }
 }

 void readRFID() {
    mfrc522.PICC_ReadCardSerial();
    //PEMBATAS BISA DIRUBAH SESUAI KEINGINAN, DISINI YANG DIGUNAKAN "-"
    uidString = String(mfrc522.uid.uidByte[0],HEX) + "-" +
    uidString = String(mfrc522.uid.uidByte[1],HEX) + "-" +
    uidString = String(mfrc522.uid.uidByte[2],HEX) + "-" +
    uidString = String(mfrc522.uid.uidByte[3],HEX);
    uidString.toUpperCase;
 }

 void bunyibuzzeroke () {
 
