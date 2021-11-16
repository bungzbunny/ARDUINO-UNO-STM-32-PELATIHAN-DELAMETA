//INISIALISASI OUTPUT
  int r =PA1;
  int y =PA2;
  int g =PA3;

//INISIALISASI INPUT
  int b1 =PA4;
  int b2 =PA5;
  int b3 =PA6;
  
//INISIALISI KUNCI
  int kuncir;
  int kunciy;
  int kuncig;

void setup() {
//OUTPUT
  pinMode (r,OUTPUT);
  pinMode (y,OUTPUT);
  pinMode (g,OUTPUT);

//INPUT
  pinMode (b1,INPUT);
  pinMode (b2,INPUT);
  pinMode (b3,INPUT);

}

void loop() {
  Serial.begin (9600);

//BACA BUTTON
  int bacabutton1 = digitalRead(b1);
  int bacabutton2 = digitalRead(b2);
  int bacabutton3 = digitalRead(b3);

//SERIAL PRINT
  Serial.print (  " | Kondisi button1 :  "); Serial.print(b1);
  Serial.print (  " | Kondisi button2 :  "); Serial.print(b2);
  Serial.print (  " | Kondisi button3 :  "); Serial.print(b3);
  Serial.println ();


//LOGIKA

//START1
if(bacabutton1==1 && kuncir==0){
  Serial.println("LED ON");
  delay(500);
  digitalWrite(r,HIGH);
  kuncir=1;
}
else if(bacabutton1==1 && kuncir==1){
  Serial.println("LED OFF");
  delay(500);
  digitalWrite(r,LOW);
  kuncir=0;
}
//END1


//START2
if(bacabutton2==1 && kunciy==0){
  Serial.println("LED ON");
  delay(500);
  digitalWrite(y,HIGH);
  kunciy=1;
}
else if(bacabutton2==1 && kunciy==1){
  Serial.println("LED OFF");
  delay(500);
  digitalWrite(y,LOW);
  kunciy=0;
}
//END2


//START3
if(bacabutton3==1 && kuncig==0){
  Serial.println("LED ON");
  delay(500);
  digitalWrite(g,HIGH);
  kuncig=1;
}
else if(bacabutton3==1 && kuncig==1){
  Serial.println("LED OFF");
  delay(500);
  digitalWrite(g,LOW);
  kuncig=0;
}
//END3

}
