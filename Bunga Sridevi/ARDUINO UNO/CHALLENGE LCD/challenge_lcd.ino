//Download dan masukan Library MFRC522
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>

//Inisialisasi pembuatan variable
LiquidCrystal_I2C lcd(0x27, 16, 2);

String uidString;

//inisialisasi output
int pinBUZZER = 8; 
int pinINFRARED = 7;

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
 lcd.begin();
 mfrc522.PCD_Init();
 pinMode (pinBUZZER, OUTPUT);
 pinMode (pinINFRARED, INPUT);
 lcd.clear();
 lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU");
 lcd.setCursor(0,1); lcd.print("GERBANG TERTUTUP");

}



void loop() {
  //BACADATA
    if(mfrc522.PICC_IsNewCardPresent()){
    readRFID();
    Serial.print("ID : ");
    Serial.println(uidString);
    if(uidString=="5-8D-4-AE"){
    bunyibuzzeroke();
    lcd.clear(); 
    lcd.setCursor(4,0); lcd.print("BERHASIL");
    lcd.setCursor(2,1); lcd.print("SILAHKAN MASUK");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,1); lcd.print("GERBANG TERBUKA");
    while(1){
      int state = digitalRead(pinINFRARED);
      if (state == 1){
      state =1;
      }else {
      lcd.setCursor(0,1); lcd.print("GERBANG TERTUTUP");
      bunyibuzzergagal();
      break;
      }
    }
    }

    else{
   lcd.clear();
   lcd.setCursor(0,0); lcd.print("TIDAK TERDAFTAR");
   lcd.clear();
   lcd.setCursor(0,1); lcd.print("GERBANG TERTUTUP");
    bunyibuzzergagal();
    }

}
}
 
