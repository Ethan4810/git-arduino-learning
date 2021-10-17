/**
 * @file 20210913-lab3-남종수
 * @author 남종수
 * @course Robotics
 * @date 2021-09-13
 *
 * @brief Describe different colors using RGB LED
 */

int rPin = 9;
int gPin = 10;
int bPin = 11;
int dt = 1000;

void setup()
{
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
}

void loop()
{
  // no light
  analogWrite(rPin, 0);
  analogWrite(gPin, 0);
  analogWrite(bPin, 0);
  delay(dt);

  // red
  analogWrite(rPin, 255);
  analogWrite(gPin, 0);
  analogWrite(bPin, 0);
  delay(dt);
  
  // organe
  analogWrite(rPin, 255);
  analogWrite(gPin, 50);
  analogWrite(bPin, 0);
  delay(dt);
  
  // yellow
  analogWrite(rPin, 255);
  analogWrite(gPin, 255);
  analogWrite(bPin, 0);
  delay(dt);
  
  // green
  analogWrite(rPin, 0);
  analogWrite(gPin, 255);
  analogWrite(bPin, 0);
  delay(dt);
  
  // blue
  analogWrite(rPin, 0);
  analogWrite(gPin, 0);
  analogWrite(bPin, 255);
  delay(dt);
  
  // indigo
  analogWrite(rPin, 0);
  analogWrite(gPin, 0);
  analogWrite(rPin, 80);
  delay(dt);
  
  // magenta
  analogWrite(rPin, 255);
  analogWrite(gPin, 0);
  analogWrite(bPin, 255);
  delay(dt);

  // white
  analogWrite(rPin, 255);
  analogWrite(gPin, 255);
  analogWrite(bPin, 255);
  delay(dt);
}