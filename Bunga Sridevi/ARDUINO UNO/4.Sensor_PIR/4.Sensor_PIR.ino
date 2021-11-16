//Inisialisasi pembuatan variable
int pinPIR    =2;
int pinBUZZER =5;


void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(9600); 
 pinMode(pinPIR,INPUT);
 pinMode(pinBUZZER,OUTPUT);
}


void loop() {
 //Baca data
 int VPIR=digitalRead(pinPIR); //Membaca Nilai Sensor PIR
 
 //Print ke Serial Monitor
 Serial.print("Nilai PIR : ");
 Serial.print(VPIR);
 Serial.println();// untuk enter

 //Logika 
 
 if(VPIR==1) {
  digitalWrite(pinBUZZER,HIGH);
  delay(100);
  digitalWrite(pinBUZZER,LOW);
  delay(100);
  Serial.println("ADA PELAKOR!!!");
 }else{
  digitalWrite(pinBUZZER,LOW);
 }

  

}
