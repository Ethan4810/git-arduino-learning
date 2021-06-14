// motor pins
const int speedPin = 5;
const int dirPin1 = 4;
const int dirPin2 = 3;
int mSpeed = 255; // 0 ~ 255


int dt = 1000;

void setup() {
  // motor setup
  pinMode(speedPin, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // counter clockwise
  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, LOW);

  // set speed
  analogWrite(speedPin, mSpeed);
  delay(dt);

  // clockwise
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, HIGH);

  // set speed
  analogWrite(speedPin, mSpeed);
  delay(dt);
  
}
