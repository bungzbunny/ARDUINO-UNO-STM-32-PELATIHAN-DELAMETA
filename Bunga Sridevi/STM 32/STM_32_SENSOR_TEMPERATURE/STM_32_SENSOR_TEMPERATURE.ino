//DOWNLOAD LIBRARY
  #include <OneWire.h>
  #include <DallasTemperature.h>

//INISIALISASI VARIABEL INPUT
  int TEMPERATURE=PA0;
  OneWire oneWire(TEMPERATURE);
  DallasTemperature sensors(&oneWire);

//INISIALISASI VARIABEL OUTPUT
  int r=PA1;
  int y=PA2;
  int g=PA3;
  int BUZZER=PA6;

void setup() {
//BAUDRATE
  Serial.begin(9600);
  sensors.begin();

//SETUP INPUT
  pinMode(TEMPERATURE,INPUT);

//SETUP OUTPUT
  pinMode(r,OUTPUT);
  pinMode(y,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(BUZZER,OUTPUT);
}

void loop() {
//BACA DATA SENSOR
sensors.requestTemperatures();
float bacaTEMPERATURE =sensors.getTempCByIndex(0);

//LOGIKA
if(bacaTEMPERATURE !=DEVICE_DISCONNECTED_C){
  Serial.print("Data temperature: ")
  Serial.print(bacaTEMPERATURE);
  Serial.print("C");
}
else{
  Serial.print("Error:Sensor Temperature tidak ditemukan");
}

if(bacaTEMPERATURE >=31){
  digitalWrite(r,HIGH);
  digitalWrite(y,LOW);
  digitalWrite(g,LOW);
  digitalWrite(BUZZER,HIGH);
  delay(150);
  digitalWrite(BUZZER,LOW);
  delay(50);
  Serial.print("HOT");
}
else{
  digitalWrite(r,LOW);
  digitalWrite(y,LOW);
  digitalWrite(g,HIGH);
  digitalWrite(BUZZER,HIGH);
  delay(100);
  digitalWrite(BUZZER,LOW);
  delay(500);
  Serial.print("COLD");
}

}
