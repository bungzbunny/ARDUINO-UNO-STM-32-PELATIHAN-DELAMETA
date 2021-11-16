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
digitalWrite(r, HIGH);
delay(1000);
digitalWrite(r, LOW);
delay(1000);
digitalWrite(y, HIGH);
delay(1000);
digitalWrite(y, LOW);
delay(1000);
digitalWrite(g, HIGH);
delay(1000);
digitalWrite(g, LOW);
delay(1000);
}
