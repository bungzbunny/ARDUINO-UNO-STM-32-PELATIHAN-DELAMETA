//DOWNLOAD LIBRARY
  #include <SPI.h>               //LIBRARY RFID
  #include <MFRC522.h>           //LIBRARY RFID
  #include <LiquidCrystal_I2C.h> //LIBRARY LCD
  #include <Servo.h>             //LIBRARY SERVO

//INISIALISASI VARIABEL INPUT
  #define SS_PIN  PB11           //SDA
  #define RST_PIN PB10          //RESET
  MFRC522 mfrc522(SS_PIN, RST_PIN);

//INISIALISASI VARIABEL OUTPUT
  int BUZZER   =PA0;
  int INFRARED =PA1;
  int SERVO    =PA2;
  Servo myservo;
  LiquidCrystal_I2C lcd(0x27, 16, 2);

  String ID;
  
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
void buzzergagal(){
 digitalWrite(BUZZER,HIGH);
 delay(500);
 digitalWrite(BUZZER,LOW);
 delay(10);
}
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
   Serial.print("TAG ID: ");
   Serial.print(ID);
   Serial.println();

//LOGIKA
  if(ID=="5-8D-4-AE"){
    //BUZZER
    buzzeroke();
    //SERVO
    palangterbuka();
    //LCD
    lcd.clear();
    lcd.setCursor(4,0); lcd.print("BERHASIL");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0); lcd.print("SELAMAT DATANG");
    lcd.setCursor(0,1); lcd.print("SILAHKAN MASUK");
    delay(1000);
    //INFRARED
    while(1){
      int state=digitalRead(INFRARED);
       if(state==1){
       continue;
       }
       else{
       //INFRARED
       palangtertutup();
       //LCD
       lcd.clear();
       lcd.setCursor(0,0); lcd.print("PALANG TERTUTUP");
       delay(1000);
       lcd.clear();
       lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU");
       delay(1000);
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
   delay(1000);
   lcd.clear();
   lcd.setCursor(0,0); lcd.print("TIDAK TERDAFTAR");
   delay(1000);
   lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU");
   delay(1000);
   
  }
}
}
