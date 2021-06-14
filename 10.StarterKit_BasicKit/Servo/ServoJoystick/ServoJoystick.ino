#include <Servo.h>

// Joystick
int xPin = A0;
int yPin = A1;
int sPin = 2;
int xVal, yVal, sVal;

// Servo
Servo svX;
Servo svY;
int servoPinX = 8;
int servoPinY = 9;
float angleX;
float angleY;

// Buzzer
int buzzPin = 7;

// Time
int dt = 50;

void setup() {
  Serial.begin(9600);

  // Joystick Setup
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(sPin, INPUT);
  digitalWrite(sPin, HIGH);

  //Buzzer setup
  pinMode(buzzPin, OUTPUT);

  // Servo Setup
  svX.attach(servoPinX);
  svY.attach(servoPinY);
}

void loop() {
  // Joystick Values
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  sVal = digitalRead(sPin); // not pressed = 1, pressed = 0

  // Servo Values
  angleX = xVal * (180. / 1023.);
  angleY = yVal * (180. / 1023.);

  // Show Joystick Info
  Serial.print("X = ");
  Serial.print(xVal);
  Serial.print(", Y = ");
  Serial.print(yVal);
  Serial.print(", Swtich = ");
  Serial.println(sVal);

  // Servo Movement
  svX.write(angleX);
  svY.write(angleY);

  // Buzzer Effect
  if (sVal == 1) {
    digitalWrite(buzzPin, LOW);
  }
  if (sVal == 0) {
    digitalWrite(buzzPin, HIGH);
  }

  delay(dt);
}
