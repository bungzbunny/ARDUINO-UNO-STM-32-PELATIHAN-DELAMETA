//Download dan masukan Library MFRC522
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>


//Inisialisasi pembuatan variable
#define A1 5
#define A2 6

//Inisialisasi pembuatan variable
LiquidCrystal_I2C lcd(0x27, 16, 2);

String uidString;

//inisialisasi output
int pinBUZZER = 7; 
int pinINFRARED = 2;

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
 
void buka() {          
  analogWrite(A1, 255);
  analogWrite(A2, 0);
  delay(100);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);

}

void tutup() {         
  analogWrite(A1, 0);
  analogWrite(A2, 210);
  delay(100);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
}

void diem() {         
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  
}

void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 
 Serial.begin(115200); 
 pinMode(A1, OUTPUT);
 pinMode(A2, OUTPUT);


 digitalWrite(A1, LOW);
 digitalWrite(A2, LOW);
 
 SPI.begin(); 
 lcd.begin();
 mfrc522.PCD_Init();
 pinMode (pinBUZZER, OUTPUT);
 pinMode (pinINFRARED, INPUT);
 lcd.clear();
 lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU");
 delay(1000);

}



void loop() {
  //BACADATA
    if(mfrc522.PICC_IsNewCardPresent()){
    readRFID();
    Serial.print("ID : ");
    Serial.println(uidString);

  //LOGIKA
    if(uidString=="5-8D-4-AE"){
    bunyibuzzeroke();
    lcd.clear(); 
    lcd.setCursor(4,0); lcd.print("BERHASIL");
    lcd.setCursor(2,1); lcd.print("SILAHKAN MASUK");
    delay(500);
    buka();
    lcd.clear();
    lcd.setCursor(0,1); lcd.print("PALANG TERBUKA");
    while(1){
      int state = digitalRead(pinINFRARED);
      if (state == 1){
      continue;
      }else {
      tutup();
      lcd.setCursor(0,1); lcd.print("PALANG TERTUTUP");
      bunyibuzzergagal();
      break;
      }
    }
    }

    else{
   lcd.clear();
   lcd.setCursor(0,0); lcd.print("TIDAK TERDAFTAR");
   delay(1000);
   lcd.setCursor(0,1); lcd.print("PALANG TERTUTUP");
   diem();
   bunyibuzzergagal();
   }

}
}
 
