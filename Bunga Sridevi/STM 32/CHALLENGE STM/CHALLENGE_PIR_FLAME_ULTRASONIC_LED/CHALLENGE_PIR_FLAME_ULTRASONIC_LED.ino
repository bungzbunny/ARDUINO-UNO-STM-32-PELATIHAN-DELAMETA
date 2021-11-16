#include <NewPing.h>


//INISIALIASI INPUT
int FLAME  =PA4;
int ECHO   =PA6;
int TRIGER =PA7;

//INISIALISASI OUTPUT
int r  =PA1;
int y  =PA2;
int g  =PA3;


//INISIALISASI BATAS
int BATAS =400;

//INT KUNCI
int kunci;

NewPing cm(TRIGER,ECHO,BATAS);



void setup() {
Serial.begin(9600);
//SETUP INPUT
pinMode(FLAME,INPUT);

//SETUP OUTPUT
pinMode(r,OUTPUT);
pinMode(y,OUTPUT);
pinMode(g,OUTPUT);
}

void loop(){
//BACA DATA
int bacaFLAME =digitalRead(FLAME);
int bacaJARAK=cm.ping_cm();

//SERIAL PRINT
Serial.print( " | NILAI FLAME : " );
Serial.print(bacaFLAME);
Serial.print( " | JARAK : " );
Serial.print(bacaJARAK);
Serial.print( "cm" );
Serial.print(" | kunci : ");
Serial.print(kunci);
Serial.println();
delay(500);


//LOGIKA  
if(bacaFLAME==0 && kunci==0){
  kunci=1;
}
else if(bacaFLAME==0 && kunci==1){
  kunci=0;
}


if(bacaJARAK>=200 && kunci==1){
 digitalWrite(r, HIGH);
 delay(100);
 digitalWrite(r, LOW);
 delay(50);
 digitalWrite(y, HIGH);
 delay(100);
 digitalWrite(y, LOW);
 delay(50);
 digitalWrite(g, HIGH);
 delay(100);
 digitalWrite(g, LOW);
 delay(50);
 digitalWrite(y, HIGH);
 delay(100);
 digitalWrite(y, LOW);
 delay(50);
 digitalWrite(r, HIGH);
 delay(100);
 digitalWrite(r, LOW);
 delay(50);
 Serial.print("JAUH");
 Serial.println();
 }
else if(bacaJARAK>=20 && bacaJARAK<=200 && kunci==1){
 digitalWrite(r,HIGH);
 digitalWrite(y,HIGH);
 digitalWrite(g,HIGH);
 delay(1000);
 digitalWrite(r,LOW);
 digitalWrite(y,LOW);
 digitalWrite(g,LOW);
 delay(1000);
 Serial.print("SEDANG");
 Serial.println();
 }
else if(bacaJARAK<=20 && kunci==1){
 digitalWrite(r,HIGH);
 digitalWrite(y,HIGH);
 digitalWrite(g,HIGH);
 delay(100);
 digitalWrite(r,LOW);
 digitalWrite(y,LOW);
 digitalWrite(g,LOW);
 delay(100);
 Serial.print("DEKAT");
 Serial.println();
 }
}
