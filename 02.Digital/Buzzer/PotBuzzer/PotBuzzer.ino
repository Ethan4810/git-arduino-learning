int buzzPin = 8;
int potPin  = A0;
int dt = 50;
int potVal;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {

  potVal = analogRead(potPin);
  if (potVal >= 500) {
    digitalWrite(buzzPin, HIGH);
    delay(dt);
  }
  else  {
    digitalWrite(buzzPin, LOW);
    delay(dt);
  }
  Serial.println(potVal);
  delay(dt);

}
