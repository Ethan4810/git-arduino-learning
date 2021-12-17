// motor pins and vals
const int speedPin = 5;
const int dirPin1 = 4;
const int dirPin2 = 3;
int mSpeed; // 0 ~ 255
String mDir;

// joystick pins and vals
const int xPin = A5;
const int yPin = A4;
const int sPin = 2;
int xVal, yVal, sVal;

int dt = 50;

void setup() {
  // motor setup
  pinMode(speedPin, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);

  // joystick setup
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(sPin, INPUT);
  digitalWrite(sPin, HIGH);

  Serial.begin(9600);
}

void loop() {
  // joystick read
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  sVal = digitalRead(sPin); // not pressed = 1, pressed = 0

  if (xVal < 512) {
    // clockwise
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, HIGH);
    // set speed
    mSpeed = xVal * (-255. / 512.) + 255.;
    mDir = "cw";
    analogWrite(speedPin, mSpeed);
  }
  if (xVal >= 512) {
    // counter clockwise
    digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, LOW);
    // set speed
    mSpeed = xVal * (255. / 512.) - 255.;
    mDir = "ccw";
    analogWrite(speedPin, mSpeed);
  }

  Serial.print("X = ");
  Serial.print(xVal);

  Serial.print(", Y = ");
  Serial.print(yVal);

  Serial.print(", Swtich = ");
  Serial.print(sVal);

  Serial.print(", Speed = ");
  Serial.print(mSpeed);

  Serial.print(", Direction = ");
  Serial.println(mDir);

  delay(dt);
}
