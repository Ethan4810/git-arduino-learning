/**
 * @file 20210913-lab2-남종수
 * @author 남종수
 * @course Robotics
 * @date 2021-09-13
 *
 * @brief Fading two LEDs inversely
 */

// pin variables
int pin1 = 11;
int pin2 = 10;

// time variables
int sdt = 10;
unsigned long ldt = 1000;

void setup()
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
}

void loop()
{
  for(int i = 0; i <= 255; i++)
  {
    analogWrite(pin1, i);
    analogWrite(pin2, 255 -i);
    delay(sdt);
  }

  for(int i = 0; i <= 255; i++)
  {
    analogWrite(pin1, 255 -i);
    analogWrite(pin2, i);
    delay(sdt);
  }
}