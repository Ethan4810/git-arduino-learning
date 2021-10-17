/*
	Lab. 4 - RGB LED with Potentiometer
	This device combines a RGB LED 
    and due to the additive properties of the light.
	Use 3 potentiometers for controlling the brightness of each LED, 
    the signal of each one will be read by the Arduino as an input.
*/

// rgb led variables
int rLedPin = 11;
int gLedPin = 10;
int bLedPin = 9;

// potentiometer variables
int rPotPin = A0;
int gPotPin = A1;
int bPotPin = A2;
int rPotVal;
int gPotVal;
int bPotVal;

int dt = 100;

void setup()
{
  // rgb led setup
  pinMode(rLedPin, OUTPUT);
  pinMode(gLedPin, OUTPUT);
  pinMode(bLedPin, OUTPUT);
  
  // potentiometer setup
  pinMode(rPotPin, INPUT);
  pinMode(gPotPin, INPUT);
  pinMode(bPotPin, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  // control red
  rPotVal = analogRead(rPotPin);
  rPotVal = map(rPotVal, 0, 1023, 0, 255);
  analogWrite(rLedPin, rPotVal);
  
  // control green
  gPotVal = analogRead(gPotPin);
  gPotVal = map(gPotVal, 0, 1023, 0, 255);
  analogWrite(gLedPin, gPotVal);
  
  // control blue
  bPotVal = analogRead(bPotPin);
  bPotVal = map(bPotVal, 0, 1023, 0, 255);
  analogWrite(bLedPin, bPotVal);
  
  delay(dt);
}