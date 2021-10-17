/* Weight Sensor */

// fsr sensor variables
int fsrAnalogPin = 0; // A0 pin
int fsrReading;

// buzzer variable
int buzzerPin = 11;

// time variables (msec)
int sdt = 150;
int mdt = 1000;
int ldt = 3000;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  fsrReading = analogRead(fsrAnalogPin);
  Serial.print("Analog reading= ");
  Serial.println(fsrReading);
//
//  if (fsrReading < 170) {
//    digitalWrite(buzzerPin, LOW);
//  }
//
//  else if (fsrReading >= 170) {
//    for (int i = 0; i < 3; i++) {
//      digitalWrite(buzzerPin, HIGH);
//      delay(sdt);
//      digitalWrite(buzzerPin, LOW);
//      delay(sdt);
//      digitalWrite(buzzerPin, HIGH);
//      delay(sdt);
//      digitalWrite(buzzerPin, LOW);
//      delay(mdt);
//    }
//    delay(ldt);
//  }
}
