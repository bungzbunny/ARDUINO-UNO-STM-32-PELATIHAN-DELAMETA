//DOWNLOAD LIBRARY
  #include <NewPing.h>

//INISIALISASI VARIABEL INPUT
  int TRIGER     =PA4;
  int ECHO       =PA5;

//INISIALISASI VARIABEL OUTPUT
  int BUZZER =PA0;
  int r      =PA1;
  int y      =PA2;
  int g      =PA3;

//INISIALISASI BATAS
  int BATAS  =400;
  
NewPing cm(TRIGER,ECHO,BATAS);

void setup() {
//BAUDRATE
  Serial.begin(9600);

//SETUP INPUT
  pinMode(TRIGER,INPUT);
  pinMode(ECHO,INPUT);

//SETUP OUTPUT
  pinMode(BUZZER,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  pinMode(r,OUTPUT);
  pinMode(y,OUTPUT);
  pinMode(g,OUTPUT);

}

void loop() {
//BACA DATA SENSOR
  int bacaJARAK=cm.ping_cm();

//SERIAL PRINT
  Serial.print("Jarak : ");
  Serial.print(bacaJARAK);
  Serial.print("cm");
  delay(500);

//LOGIKA
  if(bacaJARAK<=20 && bacaJARAK!=0){
    digitalWrite(r,HIGH);
    digitalWrite(y,LOW);
    digitalWrite(g,LOW);
    digitalWrite(BUZZER,HIGH);
    delay(500);
    digitalWrite(BUZZER,LOW);
    delay(50);
    Serial.print(" BERHENTI ")//DEKAT
    Serial.println();
  }
  else if(bacaJARAK>=50 && bacaJARAK<=150){
    digitalWrite(r,LOW);
    digitalWrite(y,HIGH);
    digitalWrite(g,LOW);
    digitalWrite(BUZZER,HIGH);
    delay(150);
    digitalWrite(BUZZER,LOW);
    delay(50);
    Serial.print(" WASPADA ")
    Serial.println();
  }
  else if(bacaJARAK>=150 || bacaJARAK==0){
    digitalWrite(r,LOW);
    digitalWrite(y,LOW);
    digitalWrite(g,HIGH);
    digitalWrite(BUZZER,HIGH);
    delay(100);
    digitalWrite(BUZZER,LOW);
    delay(500);
    Serial.print(" AMAN ")
    Serial.println();
  } 
}
  
  
