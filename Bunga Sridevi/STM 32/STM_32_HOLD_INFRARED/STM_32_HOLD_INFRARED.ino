//INISIALISASI INPUT
  int INFRARED =PA1;

//INISIALISASI OUTPUT
  int r =PA2;
  int y =PA3;
  int g =PA4;

//INISIALISASI KUNCI
  int kuncir;

//FUNGTION CONVERT
  int convert (int x){
  if(x==1){
   x=0;
  }
  else{
   x=1;   
  }
  return x;
  }

void setup() {
  
Serial.begin(9600);

//SETUP INPUT
  pinMode (INFRARED, INPUT);

//SETUP OUTPUT
  pinMode (r, OUTPUT);
  pinMode (y, OUTPUT);
  pinMode (g, OUTPUT);


}

void loop() {
//BACA DATA
  int bacaINFRARED = digitalRead(INFRARED);
  bacaINFRARED = convert(bacaINFRARED);

//SERIAL PRINT
  Serial.print (bacaINFRARED);
  Serial.println();


//LOGIKA
  if(bacaINFRARED==1 && kuncir==0){
   Serial.println("LED ON");
   delay(500);
   digitalWrite(r,HIGH);
   kuncir=1;
  }
  else if(bacaINFRARED==1 && kuncir==1){
   Serial.println("LED OFF");
   delay(500);
   digitalWrite(r,LOW);
   kuncir=0;
  }
}
