#include <Servo.h>

int servoPin = 8;
int servoPos;
int dt = 10;
Servo sv;

void setup() {
  Serial.begin(9600);
  sv.attach(servoPin);
}

void loop() {
  Serial.print("Enter angle for the servo: ");
  while (Serial.available() == 0) {

  }
  servoPos = Serial.parseInt();
  sv.write(servoPos);
  Serial.println(servoPos);
}
