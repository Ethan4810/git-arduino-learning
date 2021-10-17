/**
 * @file 20210913-lab1-남종수
 * @author 남종수
 * @course Robotics
 * @date 2021-09-13
 *
 * @brief Blinking two LEDs inversely
 */

int pin1 = 13;
int pin2 = 12;
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