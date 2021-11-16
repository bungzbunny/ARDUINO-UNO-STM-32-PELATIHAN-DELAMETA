//LIBRARY ULRTRASONIC
  #include <NewPing.h>

//INISIALISASI INPUT
  int FLAME=PA4;
  int PIR=PA5;
  int ECHO=PA6;
  int TRIGER=PA7;

//INISIALISASI OUTPUT
  int r=PA1;
  int y=PA2;
  int g=PA3;

//INISIALISASI BATAS ULTRASONIC
  int BATAS=400;

  
void AMAN(){
digitalWrite(r,LOW);
delay(100);
digitalWrite(y,LOW);
delay(100);
digitalWrite(g,HIGH);
delay(1000);
}
void WASPADA(){
digitalWrite(r,LOW);
delay(100);
digitalWrite(y,HIGH);
delay(1000);
digitalWrite(g,LOW);
delay(100);
}
void BAHAYA(){
digitalWrite(r,HIGH);
delay(1000);
digitalWrite(y,LOW);
delay(100);
digitalWrite(g,LOW);
delay(100);
}
void MATI(){
digitalWrite(r,LOW);
digitalWrite(y,LOW);
digitalWrite(g,LOW);
delay(200);
}


NewPing cm(TRIGER,ECHO,BATAS);

void setup() {
Serial.begin(9600);
//SETUP INPUT
  pinMode(FLAME,INPUT);
  pinMode(PIR,INPUT);
//SETUP OUTPUT
  pinMode(r,OUTPUT);
  pinMode(y,OUTPUT);
  pinMode(g,OUTPUT);
}

void loop() {
//BACADATA
  int bacaJARAK =cm.ping_cm();
  int bacaPIR   =digitalRead(PIR);
  int bacaFLAME =analogRead(FLAME);
      bacaFLAME =map(bacaFLAME,4095,0,255,0);

//SERIAL PRINT
  Serial.print(" NILAI FLAME :  ");
  Serial.print(bacaFLAME);
  Serial.println();
  Serial.print(" NILAI PIR :  ");
  Serial.print(bacaPIR);
  Serial.println();
  Serial.print(" JARAK :  ");
  Serial.print(bacaJARAK);
  Serial.print("cm");
  Serial.println();
  delay(200);

//LOGIKA
  if(bacaPIR==1 && bacaFLAME>=200){
  delay(200);
  AMAN();
  Serial.print(" AMAN ");
  Serial.println();
  }

  else if(bacaPIR==1 && bacaFLAME>=50 && bacaFLAME<=200){
  delay(200);
  WASPADA();
  Serial.print(" WASPADA ");
  Serial.println();
  }

  else if(bacaPIR==1 && bacaFLAME<=50){
  delay(200);
  BAHAYA();
  Serial.print(" BAHAYA ");
  Serial.println();
  }

  else{
  MATI();
  }
}
