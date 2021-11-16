//DOWNLOAD LIBRARY
  #include <SPI.h>               //LIBRARY RFID
  #include <MFRC522.h>           //LIBRARY RFID
  #include <LiquidCrystal_I2C.h> //LIBRARY LCD
  #include <Servo.h>             //LIBRARY SERVO

//INISIALISASI VARIABEL INPUT RFID
  #define SS_PIN  10            //SDA
  #define RST_PIN  9            //RESET
  MFRC522 mfrc522(SS_PIN, RST_PIN);

//INISIALISASI VARIABEL OUTPUT
  int BUZZER   =5;
  int INFRARED =6;
  int SERVO    =3;
  Servo myservo;
  LiquidCrystal_I2C lcd(0x27, 16, 2);

//INISIALISASI TAG ID
  String ID;

//VOID BUZZER
void buzzeroke(){
 digitalWrite(BUZZER,HIGH);
 delay(100);
 digitalWrite(BUZZER,LOW);
 delay(100);
 digitalWrite(BUZZER,HIGH);
 delay(100);
 digitalWrite(BUZZER,LOW);
 delay(100);
}
void buzzertertutup(){
 digitalWrite(BUZZER,HIGH);
 delay(50);
 digitalWrite(BUZZER,LOW);
 delay(50);
}
void buzzergagal(){
 digitalWrite(BUZZER,HIGH);
 delay(500);
 digitalWrite(BUZZER,LOW);
 delay(10);
}

//VOID SERVO
void palangterbuka(){
 myservo.write(0); 
 delay(50);
 myservo.write(90);
 delay(50);
}
void palangtertutup(){
 myservo.write(90); 
 delay(50);
 myservo.write(0);
 delay(50);
}
void palangdiam(){
 myservo.write(0); 
 delay(50);
 myservo.write(0);
 delay(50);
}

//VOID RFID
void readRFID() {
 mfrc522.PICC_ReadCardSerial();
 ID= String(mfrc522.uid.uidByte[0],HEX) + "-" +
     String(mfrc522.uid.uidByte[1],HEX) + "-" +
     String(mfrc522.uid.uidByte[2],HEX) + "-" +
     String(mfrc522.uid.uidByte[3],HEX);
     ID.toUpperCase();
}
 
void setup() {
//FUNGSIONALITAS DARI PIN PADA ARDUINO
  Serial.begin(115200);
  SPI.begin();
  lcd.begin();
  mfrc522.PCD_Init();
  myservo.attach(SERVO);
  palangdiam();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TEMPELKAN KARTU");
   
//SETUP INPUT
  pinMode(INFRARED,INPUT);
  
//SETUP OUTPUT
  pinMode(BUZZER,OUTPUT);
  pinMode(SERVO,OUTPUT);
}

void loop() {
//BACA DATA SENSOR
  if(mfrc522.PICC_IsNewCardPresent() ){
   readRFID();

//SERIAL PRINT
   Serial.print("TAG ID: ");
   Serial.print(ID);
   Serial.println();
   
//LOGIKA
  if(ID=="5-8D-4-AE" or ID=="4-1B-2D-DA"){
    //BUZZER
    buzzeroke();
    //SERVO
    palangterbuka();
    //LCD
    lcd.clear();
    lcd.setCursor(4,0); lcd.print("BERHASIL");
    delay(500);
    lcd.clear();
    lcd.setCursor(0,0); lcd.print("SELAMAT DATANG");
    lcd.setCursor(0,1); lcd.print("SILAHKAN MASUK");
    delay(500);
    //INFRARED
    while(1){
      int state=digitalRead(INFRARED);
       if(state==1){
       continue;
       }
       else{
       //BUZZER
       buzzertertutup();
       //SERVO
       palangtertutup();
       //LCD
       lcd.clear();
       lcd.setCursor(0,0); lcd.print("PALANG TERTUTUP");
       delay(500);
       lcd.clear();
       lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU");
       delay(500);
       break;
       }
     }
   }
  else{
   //BUZZER
   buzzergagal();
   //SERVO
   palangdiam();
   //LCD
   lcd.clear();
   lcd.setCursor(6,0); lcd.print("GAGAL");
   delay(500);
   lcd.clear();
   lcd.setCursor(0,0); lcd.print("TIDAK TERDAFTAR");
   delay(500);
   lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU");
   delay(500);
   
  }
}
}
