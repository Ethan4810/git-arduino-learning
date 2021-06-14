// 1602 lcd
#include <LiquidCrystal.h>
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// dht11 sensor
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE); // create dht object
float humid;
float tempC;
float tempF;

// time variables
int sdt = 100;
int mdt = 500;
int ldt = 1000;

void setup() {
  Serial.begin(9600);
  dht.begin(); // initialize dht11 sensor
  delay(ldt);
  lcd.begin(16, 2); //initialize lcd
}

void loop() {
  humid = dht.readHumidity(); // read humidity
  tempC = dht.readTemperature(); // read temperature

  // show temperature (C)
  lcd.setCursor(0, 0);
  lcd.print("Tempe(C) = ");
  lcd.print(tempC);

  // show humidity (%)
  lcd.setCursor(0, 1);
  lcd.print("Humid(%) = ");
  lcd.print(humid);

  // clear output
  delay(ldt);
  lcd.clear();
}
