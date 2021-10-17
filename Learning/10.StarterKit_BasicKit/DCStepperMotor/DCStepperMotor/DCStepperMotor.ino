#include <Stepper.h>

// Stepper Motor
int in1 = 8;
int in2 = 9;
int in3 = 10;
int in4 = 11;
int spr = 2048; // steps per revolution
int motSpeed = 10;
Stepper stp(spr, 8, 10, 9, 11);

int dt = 10;

void setup() {
  Serial.begin(9600);
  stp.setSpeed(motSpeed);
}

void loop() {
  stp.step(spr);
  delay(dt);
  stp.step(-spr);
  delay(dt);
}
