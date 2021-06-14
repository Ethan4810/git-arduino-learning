#include <LiquidCrystal.h>

// lcd pins
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

// variables
int num1;
String op;
int num2;
int answer;

int dt1 = 500;
int dt2 = 1000;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2); // (columns, rows)
  Serial.begin(9600);
}


void loop() {
  // Input first number
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Input 1st num: ");
  while (Serial.available() == 0) {
  }
  num1 = Serial.parseFloat();

  // Input second number
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Input 2nd num: ");
  while (Serial.available() == 0) {
  }
  num2 = Serial.parseFloat();

  // Input opeartor
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter operator: ");
  while (Serial.available() == 0) {
  }
  op = Serial.readString();

  // Operation
  if (op == "+") {
    answer = num1 + num2;
  }
  if (op == "-") {
    answer = num1 - num2;
  }
  if (op == "*") {
    answer = num1 * num2;
  }
  if (op == "/") {
    answer = num1 / num2;
  }

  // Show answer
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(num1);
  lcd.print(op);
  lcd.print(num2);
  lcd.print(" = ");
  lcd.print(answer);

  delay(dt2);


  lcd.clear();
}
