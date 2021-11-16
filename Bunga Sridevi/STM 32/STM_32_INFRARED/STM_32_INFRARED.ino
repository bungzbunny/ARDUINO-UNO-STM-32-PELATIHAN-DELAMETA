//INISIALISASI INPUT
  int INFRARED =PA1;

//INISIALISASI OUTPUT
  int r =PA2;
  int y =PA3;
  int g =PA4;

void setup() {
Serial.begin (9600);
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
  
//SERIAL PRINT
  Serial.print ("KONDISI INFRARED:  ");
  Serial.print (bacaINFRARED);
  Serial.println();

//LOGIKA
  if(bacaINFRARED==0){
   Serial.print("LED ON");
   digitalWrite(r,HIGH);
  }
  else{
    Serial.print("LED OFF");
    digitalWrite(r,LOW);
  }
}
  
