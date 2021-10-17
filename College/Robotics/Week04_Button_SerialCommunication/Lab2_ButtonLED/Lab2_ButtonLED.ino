/*
	Lab. 2 - PushButton LED
*/

int ledPin = 13;
int buttonPin = 8;
int buttonState;

int dt = 50;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600); // bps (bits per second)
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  digitalWrite(ledPin, buttonState);
  Serial.println(buttonState);

  delay(dt);
}
