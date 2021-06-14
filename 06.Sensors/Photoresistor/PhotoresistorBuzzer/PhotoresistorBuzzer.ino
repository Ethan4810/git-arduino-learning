int lightPin = A0;
int redPin = 11;
int yellowPin = 10;
int greenPin = 9;
int buzzPin = 8;
int dt1 = 50;
int dt2;
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
  dt2 = (9. / 550.) * lightVal  - (1800. / 550.) + 4.;
  Serial.print("dt2 = ");
  Serial.println(dt2);

  digitalWrite(buzzPin, HIGH);
  delay(dt2);
  digitalWrite(buzzPin, LOW);
  delay(dt2);

  // lights off
  if (lightVal < 60) {
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
    delay(dt1);
  }
  // lights dim
  else if (60 <= lightVal && lightVal < 200) {
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, LOW);
    delay(dt1);
  }
  // light bright
  else if (200 <= lightVal) {
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, HIGH);
    delay(dt1);
  }
  // default
  else {
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
    delay(dt1);
  }

  Serial.print(" lightVal = ");
  Serial.println(lightVal);
  delay(dt1);
}
