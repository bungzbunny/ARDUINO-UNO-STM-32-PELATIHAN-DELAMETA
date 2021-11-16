//Inisialisasi pembuatan variable
int pinFLAME    =A1;
int pinBUZZER   =5;
int r=9;
int y=10;
int g=11;

//pin pwm


void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(9600); 
 pinMode(pinFLAME,INPUT);
 pinMode(pinBUZZER,OUTPUT);
 pinMode(r,OUTPUT);
 pinMode(y,OUTPUT);
 pinMode(g,OUTPUT);

}


void loop() {
 //Baca data
 int VFLAME=analogRead(pinFLAME); //Membaca Nilai Sensor PIR
  VFLAME=map(VFLAME,1023,19,0,100);
 //Tampung map=merubah data(tampung,data awal sensor, data akhir sensor,nilai awal rubah,nilai akhir rubah)
 
 //Print ke Serial Monitor
 Serial.print("Nilai FLAME : ");
 Serial.print(VFLAME);
 Serial.println();// untuk enter


 //Logika
if(VFLAME < 10){
delay(500);
Serial.println("aman sayang");
digitalWrite(r, LOW);
digitalWrite(y, LOW);
digitalWrite(g, HIGH);
digitalWrite(pinBUZZER, LOW);

} else if (VFLAME >=10 && VFLAME<=50){
delay(500);
Serial.println("hati-hati ada api sayang");
digitalWrite(r, LOW);
digitalWrite(y, HIGH);
digitalWrite(g, LOW);
digitalWrite(pinBUZZER, HIGH);
delay(100);
digitalWrite(pinBUZZER, LOW);
delay(500);

}else if (VFLAME >50){
delay(500);
Serial.println("kabur kebakaran sayang");
digitalWrite(r, HIGH);
digitalWrite(y, LOW);
digitalWrite(g, LOW);
digitalWrite(pinBUZZER, HIGH);
delay(500);
digitalWrite(pinBUZZER, LOW);
delay(10);
digitalWrite(pinBUZZER, HIGH);
delay(500);
digitalWrite(pinBUZZER, LOW);
delay(10);
digitalWrite(pinBUZZER, HIGH);
delay(500);
digitalWrite(pinBUZZER, LOW);
delay(10);
}



}
