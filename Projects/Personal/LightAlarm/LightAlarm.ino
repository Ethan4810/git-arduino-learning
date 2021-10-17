/*
    ALARM CLOCK USING SUNLIGHT
*/


// photoresistor pin (1k ohm)
int lightPin = A0;
int lightVal;

// led pin (220 ohms)
int redPin = 3;
int yellowPin = 5;
int greenPin = 6;
int dimVal = 2;

// buzzer pin
int buzzPin = 8;
int buzzDelay =500;

int dt = 100;

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
  if (lightVal < 50) {
    analogWrite(redPin, dimVal);
    analogWrite(yellowPin, 0);
    analogWrite(greenPin, 0);
    digitalWrite(buzzPin, LOW);
    delay(dt);
  }
  // lights dim
  else if (50 <= lightVal && lightVal < 90) {
    analogWrite(redPin, 0);
    analogWrite(yellowPin, dimVal);
    analogWrite(greenPin, 0);
    digitalWrite(buzzPin, LOW);
    delay(dt);
  }
  // light bright
  else if (90 <= lightVal) {
    analogWrite(redPin, 0);
    analogWrite(yellowPin, 0);
    analogWrite(greenPin, dimVal);
    digitalWrite(buzzPin, HIGH);
    delay(buzzDelay);
    digitalWrite(buzzPin, LOW);
    delay(buzzDelay);
  }
  // default
  else {
    analogWrite(redPin, 0);
    analogWrite(yellowPin, 0);
    analogWrite(greenPin, 0);
    digitalWrite(buzzPin, LOW);
  }

  Serial.println(lightVal);
  delay(dt);
}
