//INISIALISASI
#include <OneWire.h>
#include <DallasTemperature.h>


int sensorSuhu=12;
OneWire oneWire(sensorSuhu);
DallasTemperature sensors(&oneWire);
int r=5;
int y=6;
int g=7;
int pinBUZZER=3;




void setup() {
//MENENTUKAN FUNGSI DARI PIN PADA MICROCONTROLLER
Serial.begin(9600); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
sensors.begin(); //Memanggil fungsi


pinMode (r, OUTPUT);
pinMode (y, OUTPUT);
pinMode (g, OUTPUT);
pinMode (pinBUZZER, OUTPUT);
}

void loop() {
 //BACA SENSOR
 sensors.requestTemperatures();
 float bacaSuhu = sensors.getTempCByIndex(0); 

 

 //LOGIKA
 if(bacaSuhu !=DEVICE_DISCONNECTED_C)
 {
 Serial.print("Data suhu yang terbaca pada bus 1 (index 0): ");
 Serial.println(bacaSuhu);
 }
 else
 {
 Serial.println("Error: sensor pada index 0 tidak ditemukan!");
 }

 if(bacaSuhu >=31){
  digitalWrite (r,HIGH);
  digitalWrite (y,LOW);
  digitalWrite (g,LOW);
  digitalWrite (pinBUZZER,HIGH);
  delay(500);
  digitalWrite (pinBUZZER,LOW);
  delay(50);
  Serial.print("PANAS ANED");
  
 }else {
  digitalWrite (r,LOW);
  digitalWrite (y,LOW);
  digitalWrite (g,HIGH);
  digitalWrite (pinBUZZER,HIGH);
  delay(100);
  digitalWrite (pinBUZZER,LOW );
  delay(500);
  Serial.print("DINGIN ANED");
 }
}
