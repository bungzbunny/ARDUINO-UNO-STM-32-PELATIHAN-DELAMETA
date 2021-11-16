//INISIALISASI INPUT
  int FLAME =A1;

//INISIALISASI OUTPUT
  int BUZZER =5;
  int r =9;
  int y =10;
  int g =11;




void setup() {
//SETUP INPUT  
  pinMode (FLAME,INPUT);
  
//SETUP OUTPUT
  pinMode (r,OUTPUT);
  pinMode (y,OUTPUT);
  pinMode (g,OUTPUT);
  pinMode (BUZZER,OUTPUT);
Serial.begin(9600);
}

void loop() {

//BACA DATA
  int bacaFLAME = analogRead(FLAME);
  bacaFLAME = map(bacaFLAME,1023,700,0,100);

//SERIAL PRINT
  Serial.print("NILAI FLAME :  ");
  Serial.print(bacaFLAME);
  Serial.println();
//LOGIKA

// START KONDISI AMAN
  if(bacaFLAME<10){
  delay(500);
  Serial.print("AMAN   ");
  digitalWrite(r,LOW);
  digitalWrite(y,LOW);
  digitalWrite(g,HIGH);
  digitalWrite(BUZZER,LOW);
  }
// END KONDISI AMAN

// START KONDISI WASPADA
  else if(bacaFLAME >=10 && bacaFLAME <=50){
  delay(500);
  Serial.print("WASPADA   ");
  digitalWrite(r,LOW);
  digitalWrite(y,HIGH);
  digitalWrite(g,LOW);
  digitalWrite(BUZZER,HIGH);
  delay(200);
  digitalWrite(BUZZER,LOW);
  delay(500);
  }
// END KONDISI WASPADA

// START KONDISI BAHAYA
  else if(bacaFLAME>50){
  delay(500);
  Serial.print("BAHAYA   ");
  digitalWrite(r,HIGH);
  digitalWrite(y,LOW);
  digitalWrite(g,LOW);
  digitalWrite(BUZZER,HIGH);
  delay(150);
  digitalWrite(BUZZER,LOW);
  delay(20);
  digitalWrite(BUZZER,HIGH);
  delay(150);
  digitalWrite(BUZZER,LOW);
  delay(20);
  }
// END KONDISI BAHAYA
}
