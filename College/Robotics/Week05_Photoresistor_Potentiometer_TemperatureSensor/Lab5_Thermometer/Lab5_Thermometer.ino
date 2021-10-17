/*
  Lab. 5 - Thermometer
	Measure surrounding temperature.
  Display the measured temperature to serial communication
*/

int tmpPin = A0;
int tmpVal;
float tmpVol;
float tmpCel;

int dt = 100;

void setup()
{
  pinMode(tmpPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  tmpVal = analogRead(tmpPin);
  tmpVol = tmpVal * (5. / 1024.0);
  tmpCel = (tmpVol - 0.5) * 100.;

  Serial.print(tmpCel);
  Serial.println(" 'C");

  delay(dt);

}
