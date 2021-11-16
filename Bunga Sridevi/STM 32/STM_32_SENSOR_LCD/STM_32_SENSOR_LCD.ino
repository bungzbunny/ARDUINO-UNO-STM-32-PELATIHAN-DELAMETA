//DOWNLOAD LIBRARY
  #include <LiquidCrystal_I2C.h>

//INISIALISASI VARIABEL
  LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
//BAUDRATE
  Serial.begin(9600);
  lcd.begin();
}

void loop() {
//LOGIKA
  lcd.clear();
  lcd.setCursor(4,0); lcd.print("WELCOME");
  lcd.setCursor(5,1); lcd.print("BUNGA");
  delay(1000);

//LOGIKA 2
  lcd.clear();
  lcd.setCursor(4,0); lcd.print("WELCOME");
  lcd.setCursor(4,1); lcd.print("TIENNE");
  delay(1000);
}
