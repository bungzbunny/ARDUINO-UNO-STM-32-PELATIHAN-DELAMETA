int r = PA0;
int y = PA1;
int g = PA2;



void setup() {
pinMode(PA0,OUTPUT);
pinMode(PA1, OUTPUT);
pinMode(PA2, OUTPUT);


}

void loop() {
digitalWrite(PA0, HIGH); //ini lampu merah
delay(3000);
digitalWrite(PA0, LOW);
delay(1000);

digitalWrite(PA1, HIGH); //ini lampu kuning
delay(1000);
digitalWrite(PA1, LOW);
delay(1000);

digitalWrite(PA2, HIGH);  //ini lampu hijau
delay(3000);
digitalWrite(PA2, LOW);
delay(1000);

}
