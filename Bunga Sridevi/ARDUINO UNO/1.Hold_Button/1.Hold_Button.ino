int button1 = 2;
int button2 = 3;
int button3 = 4;
int r = 5;
int y = 6;
int g = 7;
int kunci1;

void setup() {
  // put your setup code here, to run once:
  
Serial.begin (9600);
pinMode(r, OUTPUT);
pinMode(y, OUTPUT);
pinMode(g, OUTPUT);
pinMode(button1,INPUT); 
pinMode(button2,INPUT);
pinMode(button3,INPUT);
}

void loop() {
 int bacabutton1 = digitalRead(button1);//Membaca keadaan tombol
 int bacabutton2 = digitalRead(button2);//Membaca keadaan tombol
 int bacabutton3 = digitalRead(button3);//Membaca keadaan tombol
 
 
 //PRINT SERIAL
 Serial.print(" | Kondisi button 1 : "); Serial.print(bacabutton1);
 Serial.print(" | Kondisi button 2 : "); Serial.print(bacabutton2);
 Serial.print(" | Kondisi button 3 : "); Serial.print(bacabutton3);
 Serial.println();


 //LOGIKA PROGRAM

  if(bacabutton1==0 && kunci1==0){
  delay (500);
  Serial.println("LED ON");
  digitalWrite(r,HIGH);
  kunci1=1;
  }else if(bacabutton1==0 && kunci1==1){
  delay (500);
  Serial.println("LED OFF");
  digitalWrite(r,LOW);
  kunci1=0;
  }
}

//  if(bacabutton2==0 && kunci1==0){
//  delay (500);
//  Serial.println("LED ON");
//  digitalWrite(y,HIGH);
//  kunci1=1;
//  }else if(bacabutton2==0 && kunci1==1){
//  delay (500);
//  Serial.println("LED OFF");
//  digitalWrite(y,LOW);
//  kunci1=0;
//  }
//
//  if(bacabutton3==0 && kunci1==0){
//  delay (500);
//  Serial.println("LED ON");
//  digitalWrite(g,HIGH);
//  kunci1=1;
//  }else if(bacabutton3==0 && kunci1==1){
//  delay (500);
//  Serial.println("LED OFF");
//  digitalWrite(g,LOW);
//  kunci1=0;
//  }
//}
