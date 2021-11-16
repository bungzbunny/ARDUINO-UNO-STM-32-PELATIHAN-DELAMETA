int r= 2;
int y= 3;
int g= 4;


void setup() {
  // put your setup code here, to run once:
pinMode(r, OUTPUT);
pinMode(y, OUTPUT);
pinMode(g, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(r, HIGH); //ini lampu merah
delay(7000);
digitalWrite(r, LOW);
delay(1000);
digitalWrite(y, HIGH); //ini lampu kuning
delay(500);
digitalWrite(y, LOW);
delay(1000);
digitalWrite(g, HIGH);  //ini lampu hijau
delay(4000);
digitalWrite(g, LOW);
delay(1000);
}
