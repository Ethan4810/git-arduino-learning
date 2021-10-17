/*
	Lab. 3 - LED blink with Potentiometer 
	An analog value controls the rate at which an LED blinks.
	turns on and off a LED.
    The amount of time the LED will be on and off 
    depends on the value obtained by potentiometer.
*/

// potentiometer variables
int potPin = A0;
int potVal;
int potDt;

int ledPin = 11;

int dt = 500;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  // read potentiometer 
  potVal = analogRead(potPin);
  potDt = map(potVal, 1, 1024, 100, 1000);
  
  // blink led
  digitalWrite(ledPin, LOW);
  delay(potDt);
  digitalWrite(ledPin, HIGH);
  delay(potDt);
  
  Serial.println(potVal);
}