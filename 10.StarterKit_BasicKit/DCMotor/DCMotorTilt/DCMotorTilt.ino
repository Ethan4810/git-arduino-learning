// motor pins
const int speedPin = 5;
const int dirPin1 = 4;
const int dirPin2 = 3;

// tilt pin
const int tiltPin = 2;
int tiltVal;

int mSpeed = 40; // 0 ~ 255
int dt = 100;

void setup() {
  // motor setup
  pinMode(speedPin, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(tiltPin, INPUT);
  digitalWrite(tiltPin, HIGH);

  Serial.begin(9600);
}

void loop() {
  // 0 when still, 1 when tilted
  tiltVal = digitalRead(tiltPin);

  // still
  if (tiltVal == 0) {
    // counter clockwise
    digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, LOW);

    // set speed
    analogWrite(speedPin, 255);
  }

  // titled
  if (tiltVal == 1) {
    // clockwise
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, HIGH);

    // set speed
    analogWrite(speedPin, 0);
  }

  Serial.println(tiltVal);
  delay(dt);
}
