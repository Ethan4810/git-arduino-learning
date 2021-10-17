/*
	Lab. 1 - Servo motor
    Sweeps the shaft of a servo motor
    back and forth across 180 degress
*/

#include <Servo.h>

int pos = 0;
Servo servo;

int dt = 10;

void setup()
{
  servo.attach(9, 500, 2500); // pin, min angle, max angle
}

void loop()
{
   for (pos = 0; pos <= 180; pos ++) 
  {
    servo.write(pos);
    delay(dt); 
  }
  for (pos = 180; pos >= 0; pos --) 
  {
    servo.write(pos);
    delay(dt); 
  }
}