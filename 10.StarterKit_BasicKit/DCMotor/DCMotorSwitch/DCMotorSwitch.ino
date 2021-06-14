// motor pins and values
const int speedPin = 5;
const int dirPin1 = 4;
const int dirPin2 = 3;
int mSpeed = 0; // range (0 ~ 255)
int mSpeedVal = 5;

// button pins and values
const int bPin1 = 11;
const int bPin2 = 12;
int bVal1;
int bVal2;

int dt1 = 50;
int dt2 = 1000;

void setup() {
  // motor setup
  pinMode(speedPin, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);

  // button setup
  pinMode(bPin1, INPUT_PULLUP);
  pinMode(bPin2, INPUT_PULLUP);

  Serial.begin(9600);
  delay(dt2);
}

void loop() {
  // read button value (0 when pressed, 1 when not pressed)
  bVal1 = digitalRead(bPin1);
  bVal2 = digitalRead(bPin2);

  // no button pressed: do nothing
  if (bVal1 == true && bVal2 == true) {
    mSpeed += 0;
  }

  // button 1 pressed: reduce speed
  if (bVal1 == false && bVal2 == true) {
    mSpeed -= mSpeedVal;
    delay(dt1);
    if (mSpeed < -255) {
      mSpeed = -255; // maximum speed reached
    }
  }

  // button 2 pressed: increase speed
  if (bVal1 == true && bVal2 == false) {
    mSpeed += mSpeedVal;
    delay(dt1);
    if (mSpeed > 255) {
      mSpeed = 255; // maximum speed reached
    }
  }

  // 2 buttons pressed: reset
  if (bVal1 == false && bVal2 == false) {
    mSpeed = 0;
  }

  if (mSpeed >= 0) {
    // clockwise
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, HIGH);
    // set speed
    analogWrite(speedPin, mSpeed);
  }
  
  if (mSpeed < 0) {
    // counter clockwise
    digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, LOW);
    // set speed
    analogWrite(speedPin, -mSpeed);
  }

  Serial.print("Speed = ");
  Serial.println(mSpeed);
  delay(dt1);
}
