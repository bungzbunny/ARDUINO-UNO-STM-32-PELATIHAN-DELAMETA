int sensor = 2;
int r =6;
int status=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode(r, OUTPUT);
  pinMode(sensor, INPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  int bunga = digitalRead(sensor);

  if(bunga == 0){
    digitalWrite(r, HIGH);
    delay(200);
  }
  else if(bunga == 1){
    digitalWrite(r, LOW);
    delay(200);
  }
}
