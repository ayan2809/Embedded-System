#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
byte smiley[8]={
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("19BCE1872");
  lcd.setCursor(0,1);
  lcd.print("Ayan Sadhukhan");
            lcd.createChar(0,smiley);
  lcd.setCursor(15,1);
  lcd.write(byte(0));
}

void loop() {
  delay(1000);
  lcd.noDisplay();
  delay(500);
  lcd.display();
  lcd.setCursor(10,0);
  lcd.print(millis() / 1000);
}
