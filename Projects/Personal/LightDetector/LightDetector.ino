int lightPin = A0;
int redPin = 11;
int yellowPin = 10;
int greenPin = 9;
int buzzPin = 8;
int dt = 50;
int lightVal;

void setup() {
  // put your setup code here, to run once:
  pinMode(lightPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(lightPin);

  // lights off
  if (lightVal < 60) {
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(buzzPin, LOW);
    delay(dt);
  }
  // lights dim
  else if (60 <= lightVal && lightVal < 200) {
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(buzzPin, LOW);
    delay(dt);
  }
  // light bright
  else if (200 <= lightVal) {
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(buzzPin, HIGH);
    delay(dt);
  }
  // default
  else {
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(buzzPin, LOW);
  }

  Serial.println(lightVal);
  delay(dt);
}
