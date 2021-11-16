
//INISIALISASI OUTPUT
int r = PA0;
int y = PA1;
int g = PA2;

//INISIALISASI INPUT
int button1 = PA5;
int button2 = PA6;
int button3 = PA7;



void setup() {
//OUTPUT
pinMode(r,OUTPUT);
pinMode(y, OUTPUT);
pinMode(g, OUTPUT);

//INPUT
pinMode(button1,INPUT);
pinMode(button2,INPUT);
pinMode(button3,INPUT);

}

void loop() {
  
Serial.begin (9600);
  
//BACA TOMBOL
 int bacabutton1 = digitalRead(button1);//Membaca keadaan tombol
 int bacabutton2 = digitalRead(button2);//Membaca keadaan tombol
 int bacabutton3 = digitalRead(button3);//Membaca keadaan tombol

//PRINT SERIAL
 Serial.print(" | Kondisi button 1 : "); Serial.print(bacabutton1);
 Serial.print(" | Kondisi button 2 : "); Serial.print(bacabutton2);
 Serial.print(" | Kondisi button 3 : "); Serial.print(bacabutton3);
 Serial.println();


//LOGIKA
//START TOMBOL 1
 if(bacabutton1 == 1){
 digitalWrite(r,HIGH);
 }else{
 digitalWrite(r,LOW);
 }
//END TOMBOL 1

 
//START TOMBOL 2
 if(bacabutton2 == 1){
 digitalWrite(y,HIGH);
 }else{
 digitalWrite(y,LOW);
 }
 //END TOMBOL 2


//START TOMBOL 3
 if(bacabutton3 == 1){
 digitalWrite(g,HIGH);
 }else{
 digitalWrite(g,LOW);
 }
//END TOMBOL 3

}
