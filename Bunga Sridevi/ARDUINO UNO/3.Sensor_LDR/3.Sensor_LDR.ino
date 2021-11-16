//Inisialisasi pembuatan variable
int pinLDR    =A0;

//pin pwm
int r=9;
int y=10;
int g=11;


void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(9600); 
 pinMode(pinLDR,INPUT);
 pinMode(r,OUTPUT);
 pinMode(y,OUTPUT);
 pinMode(g,OUTPUT);
}


void loop() {
 //Baca data
 int VLDR=analogRead(pinLDR); //Membaca Nilai Sensor PIR
     VLDR=map(VLDR,0,1024,0,255);
 //Tampung map=merubah data(tampung,data awal sensor, data akhir sensor,nilai awal rubah,nilai akhir rubah)
 
 //Print ke Serial Monitor
 Serial.print("Nilai LDR : ");
 Serial.print(VLDR);
 Serial.println();// untuk enter

 analogWrite(r, VLDR);
 analogWrite(y, VLDR);
 analogWrite(g, VLDR);


  

}
