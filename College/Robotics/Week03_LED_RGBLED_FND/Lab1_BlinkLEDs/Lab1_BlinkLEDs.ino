/*
   Lab. 1 - Blink two LEDs inversely
*/

// led pin variables
int pin1 = 13;
int pin2 = 12;

// time variable
unsigned long dt = 1000; // 1 second

void setup()
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
}

void loop()
{
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  delay(dt);

  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
  delay(dt);
}
