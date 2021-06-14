int buzzPin = 8;
int potPin  = A0;
int dt1 = 500;
int dt2 = 250;
int dt3 = 200;
int dt4 = 100;
int dt5 = 50;
int dt6 = 25;
int dt7 = 10;
int dt8 = 5;
int dt9 = 2;
int dt10 = 1;
int dtLong = 300;
int potVal;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {

  potVal = analogRead(potPin);
  if (0 <= potVal && potVal < 100) {
    digitalWrite(buzzPin, LOW);
  }
  else if (100 <= potVal && potVal < 200) {
    digitalWrite(buzzPin, HIGH);
    delay(dt1);
    digitalWrite(buzzPin, LOW);
    delay(dt1);
  }
  else if (200 <= potVal && potVal < 300) {
    digitalWrite(buzzPin, HIGH);
    delay(dt2);
    digitalWrite(buzzPin, LOW);
    delay(dt2);
  }
  else if (300 <= potVal && potVal < 400) {
    digitalWrite(buzzPin, HIGH);
    delay(dt3);
    digitalWrite(buzzPin, LOW);
    delay(dt3);
  }
  else if (400 <= potVal && potVal < 500) {
    digitalWrite(buzzPin, HIGH);
    delay(dt4);
    digitalWrite(buzzPin, LOW);
    delay(dt4);
  }
  else if (500 <= potVal && potVal < 600) {
    digitalWrite(buzzPin, HIGH);
    delay(dt5);
    digitalWrite(buzzPin, LOW);
    delay(dt5);
  }
  else if (600 <= potVal && potVal < 700) {
    digitalWrite(buzzPin, HIGH);
    delay(dt6);
    digitalWrite(buzzPin, LOW);
    delay(dt6);
  }
  else if (700 <= potVal && potVal < 800) {
    digitalWrite(buzzPin, HIGH);
    delay(dt7);
    digitalWrite(buzzPin, LOW);
    delay(dt7);
  }
  else if (800 <= potVal && potVal < 900) {
    digitalWrite(buzzPin, HIGH);
    delay(dt8);
    digitalWrite(buzzPin, LOW);
    delay(dt8);
  }
  else if  (900 <= potVal && potVal < 1000) {
    digitalWrite(buzzPin, HIGH);
    delay(dt9);
    digitalWrite(buzzPin, LOW);
    delay(dt9);
  }
  else {
    digitalWrite(buzzPin, HIGH);
  }

  Serial.println(potVal);
}
