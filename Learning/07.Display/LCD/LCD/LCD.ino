#include <LiquidCrystal.h>

int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

int dt = 1000;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2); // (columns, rows)
}


void loop() {
  lcd.setCursor(0, 0); // 1st column, 1st row
  lcd.print("Hello World! This is a counter.");

  // counter
  for (int i = 1; i <= 10; i++) {
    lcd.setCursor(0, 1); // 1st column, 2nd row
    lcd.print(i);
    delay(dt);
  }

  lcd.clear();
}
