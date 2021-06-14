// tilt switch
int tiltPin = 2;
int tiltVal;

// led
int redPin = 8;
int greenPin = 9;

int dt = 50;

void setup() {
  Serial.begin(9600);
  pinMode(tiltPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  digitalWrite(tiltPin, HIGH);
}

void loop() {
  // 0 when still, 1 when tilted
  tiltVal = digitalRead(tiltPin);

  if (tiltVal == 0) {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    delay(dt);
  }
  if (tiltVal == 1) {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    delay(dt);
  }
  Serial.println(tiltVal);

  delay(dt);
}
