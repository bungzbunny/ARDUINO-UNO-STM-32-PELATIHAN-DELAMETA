//INISIALISASI OUTPUT
  int r =PA0;
  int y =PA1;
  int g =PA2;

//INISIALISASI INPUT
  int b1 =PA4;
  int b2 =PA5;
  int b3 =PA6;


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
if (bacabutton1==1){
  digitalWrite (r,HIGH);
}else{
  digitalWrite (r,LOW);
}
//END1


//START2
if (bacabutton2==1){
  digitalWrite (y,HIGH);
}else{
  digitalWrite (y,LOW);
}
//END2


//START3
if (bacabutton3==1){
  digitalWrite (g,HIGH);
}else{
  digitalWrite (g,LOW);
}
//END3

}
