// dht11 sensor
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE); // create dht object
int humid;
float tempC;

// led variables
int pin1 = 5;
int pin2 = 6;
int pin3 = 9;
int pin4 = 10;
int pin5 = 11;
int brightness = 15; // 0 ~ 255

// time variables
int sdt = 100;
int mdt = 500;
int ldt = 10000;

void setup() {
  Serial.begin(9600);
  dht.begin(); // initialize dht11 sensor
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
}

void loop() {
  humid = dht.readHumidity(); // read humidity
  tempC = dht.readTemperature(); // read temperature

  if ((0 <= humid) and (humid < 20)) {
    analogWrite(pin1, brightness);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW);
    digitalWrite(pin5, LOW);
    delay(sdt);
  }
  else if ((20 <= humid) and (humid < 40)) {
    digitalWrite(pin1, LOW);
    analogWrite(pin2, brightness);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW);
    digitalWrite(pin5, LOW);
    delay(sdt);
  }
  else if ((40 <= humid) and (humid < 60)) {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    analogWrite(pin3, brightness);
    digitalWrite(pin4, LOW);
    digitalWrite(pin5, LOW);
    delay(sdt);
  }
  else if ((60 <= humid) and (humid < 80)) {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    analogWrite(pin4, brightness);
    digitalWrite(pin5, LOW);
    delay(sdt);
  }
  else if ((80 <= humid) and (humid < 100)) {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW);
    analogWrite(pin5, brightness);
    delay(sdt);
  }
  else {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW);
    digitalWrite(pin5, LOW);
    delay(sdt);
  }

  Serial.println(humid);
  delay(ldt);
}
