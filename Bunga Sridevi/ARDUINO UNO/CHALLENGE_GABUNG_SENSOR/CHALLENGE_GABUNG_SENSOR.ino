//Inisialisasi pembuatan variable
int pinFLAME    =A1;
int pinBUZZER   =5;
int pinLDR      =3;
int pinPIR      =6;
int r=9;
int y=10;
int g=11;

//pin pwm


void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(9600); 
 pinMode(pinFLAME,INPUT);
 pinMode(pinLDR,INPUT);
 pinMode(pinPIR,OUTPUT);
 pinMode(pinBUZZER,OUTPUT);
 pinMode(r,OUTPUT);
 pinMode(y,OUTPUT);
 pinMode(g,OUTPUT);

}


void loop() {
 //Baca data
 int VFLAME=analogRead(pinFLAME); 
 int VLDR=analogRead(pinLDR); 
 int VBUZZER=analogRead(pinBUZZER); 
 int VPIR=analogRead(pinBUZZER);
  
 //Print ke Serial Monitor
 Serial.print("Nilai FLAME : ");
 Serial.print(VFLAME);
 Serial.println();// untuk enter

 Serial.print("Nilai LED : ");
 Serial.print(VLDR);
 Serial.println();// untuk enter

 Serial.print("Nilai BUZZER: ");
 Serial.print(VBUZZER);
 Serial.println();// untuk enter

 Serial.print("Nilai PIR : ");
 Serial.print(VPIR);
 Serial.println();// untuk enter
 


 //Logika


if(VFLAME < 10){
delay(500);
digitalWrite(pinBUZZER, LOW);

} else if (VFLAME >=20 && VFLAME<=100){
delay(500);
digitalWrite(pinBUZZER, HIGH);



int 
VLDR=analogRead(pinLDR); 
VLDR=map(VLDR,0,1024,0,255);

 analogWrite(r, VLDR);
 analogWrite(y, VLDR);
 analogWrite(g, VLDR);

 if(VPIR==1) {
  digitalWrite(pinBUZZER,HIGH);
  delay(100);
  digitalWrite(pinBUZZER,LOW);
  delay(100);
 }else{
  digitalWrite(pinBUZZER,LOW);
 }

}

}
