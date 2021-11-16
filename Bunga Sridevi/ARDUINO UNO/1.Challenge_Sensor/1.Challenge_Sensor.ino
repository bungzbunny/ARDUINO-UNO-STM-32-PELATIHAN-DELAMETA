int sensor = 2;
int r = 5;
int y = 6;
int g = 7;

void setup() {
  // put your setup code here, to run once:
  
Serial.begin (9600);
pinMode(r, OUTPUT);
pinMode(y, OUTPUT);
pinMode(g, OUTPUT);
pinMode(sensor,INPUT); 

}

void loop() {
 int sensor = digitalRead(sensor);//Membaca keadaan tombol
 
 
 //PRINT SERIAL
 Serial.print(" | Kondisi sensor : "); Serial.print(sensor);
 Serial.println();


 //LOGIKA PROGRAM

  if(sensor==0){
  delay (500);
  Serial.println("LED ON");
  digitalWrite(r,HIGH);

  }else if(sensor==1){
  delay (500);
  Serial.println("LED OFF");
  digitalWrite(r,LOW);

  }

  if(sensor==0){
  delay (500);
  Serial.println("LED ON");
  digitalWrite(y,HIGH);
  
  }else if(sensor==1){
  delay (500);
  Serial.println("LED OFF");
  digitalWrite(y,LOW);
 
  }

  if(sensor==0){
  delay (500);
  Serial.println("LED ON");
  digitalWrite(g,HIGH);
 
  }else if(sensor==1){
  delay (500);
  Serial.println("LED OFF");
  digitalWrite(g,LOW);
  
  }
}
