#include <LiquidCrystal.h>
#include <DHT.h>
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// arduino led variable
int ledPin = 13;

// temperature sensor variables
float tmpCel;
float humid;

// time variables
int ldt = 1000;

void setup() {
  lcd.begin(16, 2); // set lcd columns abd rows
  dht.begin();
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
}

void loop() {
  // read temperature and humidity
  tmpCel = dht.readTemperature();
  humid = dht.readHumidity();

  // lcd reset
  lcd.clear();

  // show temperature in celsius
  lcd.setCursor(0, 0);
  lcd.print("Temp = ");
  lcd.print(tmpCel);
  lcd.print(" ");
  lcd.write((char)0b11011111);
  lcd.print("C");
  
  // show humidity in %
  lcd.setCursor(0, 1);
  lcd.print("Humi = ");
  lcd.print(humid);
  lcd.print(" %");
  
  delay(ldt);
}
