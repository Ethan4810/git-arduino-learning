/*
  Lab. 2 - Streetlight with Button
  Control the brightness (0-255) of the LED
    depends on the value (0-1023) obtained by a photoresistor.
  When the pushbutton is pressed, turn off the LED
*/

// led variable
int ledPin = 9; // 220 ohm

// photoresistor variables
int lightPin = A0; // 10k ohm
int lightVal;

// button variables
int buttonPin = 10; // 10k ohm
int buttonState;

int dt = 100;

void setup()
{
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(lightPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop()
{
  buttonState = digitalRead(buttonPin);

  // button not pressed
  if (buttonState == 0)
  {
    // read photoresistor value
    lightVal = analogRead(lightPin);
    lightVal = map(lightVal, 0, 1023, 255, 0);
    analogWrite(ledPin, lightVal);
  }

  // button  pressed
  else
  {
    digitalWrite(ledPin, LOW);
  }

  delay(dt);
}