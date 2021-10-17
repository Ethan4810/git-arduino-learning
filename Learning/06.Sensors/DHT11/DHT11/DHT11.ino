// dht sensor
# include "DHT.h"
# define DHTTYPE DHT11
# define DHTPIN 2
DHT dht (DHTPIN, DHTTYPE); // create dht object

// dht11 variables
float humid; // humidity
float tempC; // celsius
float tempF; // farenheit

// buzzer
int buzzPin = 7;

// time variable
int setTime = 1000;
int dt = 1000;

void setup() {
  dht.begin(); // initialize dht11 sensor
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
  delay(setTime);
}

void loop() {
  // read temperature & humidity
  humid = dht.readHumidity(); // read humidity
  tempC = dht.readTemperature(); // read celsius
  tempF = dht.readTemperature(true); // read farenheit

  // show humidity
  Serial.print("Humidity(%) = ");
  Serial.print(humid);

  // show temperature (C)
  Serial.print(", Temp(C) = ");
  Serial.print(tempC);

  // show temperature (F)
  Serial.print(", Temp(F) = ");
  Serial.println(tempF);

  // buzz when sensor is overheated
  if (tempC >= 50) {
    digitalWrite(buzzPin, HIGH);
    delay(dt);
    digitalWrite(buzzPin, LOW);
  }

  delay(dt);
}
