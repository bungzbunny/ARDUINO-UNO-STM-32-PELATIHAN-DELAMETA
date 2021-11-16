int r= 2;
int y= 3;
int g= 4;


void setup() {

  for (int i=2; i<=4; i++) {
  pinMode(i, OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
for (int i=2; i<=4; i++) {
digitalWrite(i, HIGH);
delay(7000);
digitalWrite(i, LOW);
delay(1000);
}

}
