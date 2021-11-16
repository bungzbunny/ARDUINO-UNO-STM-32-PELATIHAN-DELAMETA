int button1 = 2;
int button2 = 3;
int button3 = 4;
int r = 5;
int y = 6;
int g = 7;

void setup() {
  // put your setup code here, to run once:
  
Serial.begin (9600);
pinMode(r, OUTPUT);
pinMode(y, OUTPUT);
pinMode(g, OUTPUT);
pinMode(button1,INPUT); 
pinMode(button2,INPUT);
pinMode(button3,INPUT);
}

void loop() {
 int bacatombol1 = digitalRead(button1);//Membaca keadaan tombol
 int bacatombol2 = digitalRead(button2);//Membaca keadaan tombol
 int bacatombol3 = digitalRead(button3);//Membaca keadaan tombol
 
 
 //PRINT SERIAL
 Serial.print(" | Kondisi button 1 : "); Serial.print(bacabutton1);
 Serial.print(" | Kondisi button 2 : "); Serial.print(bacabutton2);
 Serial.print(" | Kondisi button 3 : "); Serial.print(bacabutton3);
 Serial.println();


 //LOGIKA PROGRAM
 //START TOMBOL 1
 if(bacabutton1 == 1){
 digitalWrite(r,HIGH);
 }else{
 digitalWrite(r,LOW);
 }
 //END TOMBOL 1

 //START TOMBOL 1
 if(bacabutton2 == 1){
 digitalWrite(y,HIGH);
 }else{
 digitalWrite(y,LOW);
 }
 //END TOMBOL 1

  //START TOMBOL 1
 if(bacabutton3 == 1){
 digitalWrite(g,HIGH);
 }else{
 digitalWrite(g ,LOW);
 }
  //END TOMBOL 1
 //delay(100); //Jeda waktu perulagan seama 500 mili detik
}
