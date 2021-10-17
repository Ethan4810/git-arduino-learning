/*
	Lab. 1 - Streetlight
	Using a photoresistor, 
    turn on an LED when it is dark
    and turn it off when it is bright.
*/

int ledPin = 9;

int lightPin = A0; 
int lightVal;

int dt = 100;


void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(lightPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  lightVal = analogRead(lightPin);
  lightVal = map(lightVal, 0, 1023, 255, 0);
  
  analogWrite(ledPin, lightVal);
  Serial.println(lightVal);
  
  delay(dt);
}