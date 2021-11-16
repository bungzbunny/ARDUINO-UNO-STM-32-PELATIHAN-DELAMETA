//INISIALISASI INPUT
  int INFRARED=PA1;
  int LDR=PA5;
 
//INISIALISASI OUTPUT
  int r=PA2;
  int y=PA3;
  int g=PA4;

void setup() {
Serial.begin (9600);
//SETUP INPUT
  pinMode (LDR, INPUT);

//SETUP OUTPUT
  pinMode (r, OUTPUT);
  pinMode (y, OUTPUT);
  pinMode (g, OUTPUT);
}

void loop() {
//BACA DATA
int bacaLDR= analogRead(LDR);
bacaLDR= map(bacaLDR,4095,0,255,0);

//SERIAL PRINT
 Serial.print("Nilai LDR : ");
 Serial.print(bacaLDR);
 Serial.println();
 
//LOGIKA
 analogWrite(r, bacaLDR);
 analogWrite(y, bacaLDR);
 analogWrite(g, bacaLDR);
}
