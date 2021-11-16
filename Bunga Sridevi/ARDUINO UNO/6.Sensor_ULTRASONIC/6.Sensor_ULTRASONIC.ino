#include <NewPing.h>

//INISIALISASI

int triger =10;
int echo =9;
int batas =400; 

NewPing cm(triger,echo,batas);

int r=5;
int y=6;
int g=7;
int pinBUZZER=3;




void setup() {
Serial.begin(9600);
pinMode (r, OUTPUT);
pinMode (y, OUTPUT);
pinMode (g, OUTPUT);
pinMode (pinBUZZER, OUTPUT);
}

void loop() {
//BACADATA
 int bacaJarak=cm.ping_cm();
 
//Print ke Serial Monitor
 Serial.print("Jarak: ");
 Serial.print(bacaJarak);
 Serial.print(" cm");
 Serial.println();
 delay(500); //
 
//LOGIKA
 if(bacaJarak <=20 && bacaJarak!=0){
  delay(100);
  digitalWrite (r,HIGH);
  digitalWrite (y,LOW);
  digitalWrite (g,LOW);
  digitalWrite (pinBUZZER,HIGH);
  Serial.print("BERHENTI  ");
  
 }else if (bacaJarak >=21 && bacaJarak <=70) {
  delay(100);
  digitalWrite (r,LOW);
  digitalWrite (y,HIGH);
  digitalWrite (g,LOW);
  digitalWrite (pinBUZZER,HIGH);
  delay(100);
  digitalWrite (pinBUZZER,LOW );
  delay(500);
  Serial.print("BAHAYA  ");
 
  }else if (bacaJarak >=71 or bacaJarak==0) {
  delay(100);
  digitalWrite (r,LOW);
  digitalWrite (y,LOW);
  digitalWrite (g,HIGH);
  digitalWrite (pinBUZZER,LOW );
  delay(1000);
  Serial.print("AMAN ");
 }
} 


 
