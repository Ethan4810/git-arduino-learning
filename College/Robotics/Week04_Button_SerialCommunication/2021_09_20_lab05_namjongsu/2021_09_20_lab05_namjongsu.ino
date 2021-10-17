/*
	Lab.5 - Data Transmission
*/

int ledPin = 13;
int blinkNum;

int dt = 300;

void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.print("Enter blink number: ");
  
  while (Serial.available() == 0){}
  
  blinkNum = Serial.parseInt();
  Serial.println(blinkNum);

  for (int i = 0; i < blinkNum; i++)
  {
    digitalWrite(ledPin, HIGH);
    delay(dt);
    digitalWrite(ledPin, LOW);
    delay(dt);
  }
}