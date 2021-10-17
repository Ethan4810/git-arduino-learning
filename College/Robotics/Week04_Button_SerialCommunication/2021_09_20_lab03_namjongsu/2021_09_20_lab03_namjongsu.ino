/*
	Lab. 3 - PushButton Counter
*/

int ledPin = 13;
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
  
  while (buttonState != ture)
  

  /*
  if(buttonState == true)
  {
    count = 0;
  }
  
  else
  {
    Serial.println(count);
 	count++;
    delay(dt);
  }
  */
}