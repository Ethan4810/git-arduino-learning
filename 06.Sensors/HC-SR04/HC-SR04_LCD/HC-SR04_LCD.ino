// button pin
const int buttonPin = A0;
int oldButtonVal = 1;
int newButtonVal = 1;
int counter = 1;

// hc-sr04 senosr pins
const int trigPin = 5;
const int echoPin = 6;
long duration;
long distance;

// 1602 lcd pins
#include <LiquidCrystal.h>
const int rs = 7;
const int en = 8;
const int d4 = 9;
const int d5 = 10;
const int d6 = 11;
const int d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// delay time variables
int sdt = 50; // short
int mdt = 100; // middle
int ldt = 1500; // long

void setup() {
  // hc-sr04 setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // button setup
  pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(buttonPin, HIGH);

  // lcd setup
  lcd.begin(16, 2); //initialize lcd

  Serial.begin(9600);
  delay(mdt);

  mainDisplay();
}

void loop() {
  newButtonVal = digitalRead(buttonPin);
  //  o  n  c
  //  1  1  1
  //  1  0 -1 (pressed)
  //  1  1 -1
  //  1  0  1 (pressed again)

  // show serial info
  Serial.print("Old = ");
  Serial.print(oldButtonVal);

  Serial.print(", New = ");
  Serial.print(newButtonVal);

  Serial.print(", Counter = ");
  Serial.println(counter);

  delay(sdt);

  if (newButtonVal != oldButtonVal)
  {
    counter *= - 1;
    delay(sdt);

    if (counter == 1)
    {
      mainDisplay();
    }
    else // counter == -1
    {
      readVal();
    }
  }

}

void mainDisplay() {
  // main interface
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance Ruler");
  lcd.setCursor(0, 1);
  lcd.print("Press to start.");
  delay(sdt);
}

void readVal() {
  while (counter == -1) {
    // send ping from trigger
    digitalWrite(trigPin, LOW);
    delayMicroseconds(10);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // read reflected ping from receiver
    // speed of sound = 343 m/s (20'C)
    duration = pulseIn(echoPin, HIGH); // microseconds
    distance = (duration * 0.0343) / 2.; // centimeter
    delay(sdt);

    // show distance (cm)
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Target Distance");
    lcd.setCursor(0, 1);
    lcd.print(distance);
    lcd.print(" cm");
    delay(sdt);
  }
}
