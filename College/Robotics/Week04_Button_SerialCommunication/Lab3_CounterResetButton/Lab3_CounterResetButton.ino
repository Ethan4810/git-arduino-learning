/*
  Lab. 3 - PushButton Counter
*/

// led variable
int ledPin = 13;

// button variables
int buttonPin = 8;
int buttonState;

int count = 0;

int dt = 1000;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  digitalWrite(ledPin, buttonState);

  // button pressed
  if (buttonState == true)
  {
    count = 0;
  }
  // button not pressed
  else
  {
    Serial.println(count);
    count++;
    delay(dt);
  }
}
