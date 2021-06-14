#include <Stepper.h>

// Stepper Motor
int in1 = 8;
int in2 = 9;
int in3 = 10;
int in4 = 11;
int spr = 2048; // steps per revolution
int motSpeed = 10;
int motDir = 1;
Stepper stp(spr, 8, 10, 9, 11);

// Button
int bPin = 12;
int bValOld = 1;
int bValNew;

int dt = 10;

void setup() {
  Serial.begin(9600);
  stp.setSpeed(motSpeed);
  pinMode(bPin, INPUT);
  digitalWrite(bPin, 1);
}

void loop() {
  // Button action
  bValNew = digitalRead(bPin);

  if (bValOld == 1 && bValNew == 0) {
    motDir *= -1;
    bValNew = bValOld ;
  }

  stp.step(motDir * 1);
}
