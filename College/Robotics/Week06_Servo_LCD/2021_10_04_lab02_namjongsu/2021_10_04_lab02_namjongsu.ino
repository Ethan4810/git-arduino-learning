/*
	Lab. 2 - Servo motor & Potentiometer
    Control the position of a servo motor 
    with your anrduino and a potentiometer
*/

#include <Servo.h>

int pos = 0;
Servo servo;

int potPin = A0;
int potVal = 0;

int dt = 10;

void setup()
{
  servo.attach(9, 500, 2500); // pin, min angle, max angle
  pinMode(potPin, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  // read potentiometer 
  potVal = analogRead(potPin);
  pos = map(potVal, 1, 1024, 0, 180);

  servo.write(pos);
  delay(dt); 
}