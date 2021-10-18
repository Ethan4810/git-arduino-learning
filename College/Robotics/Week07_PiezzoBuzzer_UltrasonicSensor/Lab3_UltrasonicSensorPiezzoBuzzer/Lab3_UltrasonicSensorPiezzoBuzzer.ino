/*
	Lab. 3 - Ultrasonic Sensor + Piezo Buzzer
  Play the notes (more than 3) depending on a distance.
*/

int buzzPin = 8;
int trigPin = 3;
int echoPin = 2;

// delay time variables
int sdt = 10;
int ldt = 200;

void setup()
{
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(sdt);
  digitalWrite(trigPin, LOW);

  int duration = pulseIn(echoPin, HIGH);
  float distance = (float)duration * (101. / 5869.);

  // show duration and distance 
  Serial.print("duration = ");
  Serial.print(duration);
  Serial.print(", distance = ");
  Serial.println(distance);

  // c
  if (distance < 40) {
    tone(buzzPin, 262);
    delay(ldt);
  }

  // d
  else if (40 <= distance && distance < 80) {
    tone(buzzPin, 294);
    delay(ldt);
  }

  // e
  else if (80 <= distance && distance < 120) {
    tone(buzzPin, 330);
    delay(ldt);
  }

  // f
  else if (120 <= distance && distance < 160) {
    tone(buzzPin, 349);
    delay(ldt);
  }

  // g
  else if (160 <= distance && distance < 200) {
    tone(buzzPin, 392);
    delay(ldt);
  }

  // a
  else if (200 <= distance && distance < 240) {
    tone(buzzPin, 440);
    delay(ldt);
  }

  // b
  else if (240 <= distance && distance < 280) {
    tone(buzzPin, 494);
    delay(ldt);
  }

  // C
  else {
    tone(buzzPin, 523);
    delay(ldt);
  }
}
