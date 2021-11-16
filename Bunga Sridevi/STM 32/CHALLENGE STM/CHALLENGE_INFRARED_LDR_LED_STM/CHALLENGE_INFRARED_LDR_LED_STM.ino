//INISIALISASI INPUT
  int LDR=PA1;
  int INFRARED=PA5;

//INISIALISASI OUTPUT
  int r=PA2;
  int y=PA3;
  int g=PA4;

//INISALISASI KUNCI
  int kunci;


void setup() {
Serial.begin (9600);
//INPUT
  pinMode (INFRARED,INPUT);
  pinMode (LDR,INPUT);
//OUTPUT
  pinMode (r,OUTPUT);
  pinMode (y,OUTPUT);
  pinMode (g,OUTPUT);
}

void loop() {
//BACA DATA
  int bacaINFRARED =digitalRead(INFRARED);
  int bacaLDR =analogRead(LDR);
  bacaLDR =map(bacaLDR,4095,0,255,0);

//LOGIKA

//START LOGIKA INFRARED
if(bacaINFRARED==0 && kunci==0){
 delay(500);
 kunci=1;
 Serial.print("LDR AKTIF");
 Serial.println();
}
else if(bacaINFRARED==0 && kunci==1){
 delay(500);
 kunci=0;
 digitalWrite(r,LOW);
 digitalWrite(y,LOW);
 digitalWrite(g,LOW);
 Serial.print("LDR TIDAK AKTIF");
 Serial.println();
}
//END LOGIKA INFRARED


//START LOGIKA LDR
if(bacaLDR>=200 && kunci==1){
 delay(100);
 digitalWrite(r,LOW);
 digitalWrite(y,LOW);
 digitalWrite(g,HIGH);
 Serial.print("HIJAU : ");
 Serial.print(bacaINFRARED);
 Serial.print(bacaLDR);
 Serial.println();
}
if(bacaLDR>=100 && bacaLDR<=200 && kunci==1){
 delay(100);
 digitalWrite(r,LOW);
 digitalWrite(y,HIGH);
 digitalWrite(g,LOW);
 Serial.print("KUNING : ");
 Serial.print(bacaINFRARED);
 Serial.print(bacaLDR);
 Serial.println();
}
if(bacaLDR>=0 && bacaLDR<=100 && kunci==1){
 delay(100);
 digitalWrite(r,HIGH);
 digitalWrite(y,LOW);
 digitalWrite(g,LOW);
 Serial.print("MERAH : ");
 Serial.print(bacaINFRARED);
 Serial.print(bacaLDR);
 Serial.println();
}
//END LOGIKA LDR
}
