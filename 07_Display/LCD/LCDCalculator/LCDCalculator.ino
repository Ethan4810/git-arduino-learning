#include <LiquidCrystal.h>

// variables
int num1;
String op;
int num2;
int answer;

int sdt = 500;
int ldt = 5000;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2); // (columns, rows)

  Serial.begin(9600);
}

void loop() {
  delay(sdt);

  // input first number
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Input 1st num: ");
  Serial.print("Input 1st num: ");
  while (Serial.available() == 0) {
  }
  num1 = Serial.parseFloat();
  Serial.println(num1);

  // input opeartor
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter operator: ");
  Serial.print("Enter operator: ");
  while (Serial.available() == 0) {
  }
  op = Serial.readString();
  Serial.println(op);

  // input second number
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Input 2nd num: ");
  Serial.print("Input 2nd num: ");
  while (Serial.available() == 0) {
  }
  num2 = Serial.parseFloat();
  Serial.println(num2);

  // operation
  if (op == "+") {
    answer = num1 + num2;
  }
  if (op == "-") {
    answer = num1 - num2;
  }
  if ((op == "*") || (op == "x")) {
    answer = num1 * num2;
  }
  if (op == "/") {
    answer = num1 / num2;
  }

  // show result in serial monitor
  Serial.print(num1);
  Serial.print(" ");
  Serial.print(op);
  Serial.print(" ");
  Serial.print(num2);
  Serial.print(" = ");
  Serial.println(answer);

  // show result in lcd
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(num1);
  lcd.print(" ");
  lcd.print(op);
  lcd.print(" ");
  lcd.print(num2);
  lcd.print(" = ");
  lcd.print(answer);
  delay(ldt);

  lcd.clear();
}
