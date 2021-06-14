int redPin = 8;
int buttonPin = 12;
int buttonVal;
int dt = 50;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonVal = digitalRead(buttonPin);
  Serial.println(buttonVal);
  delay(dt);

  if (buttonVal == 1) {
    digitalWrite(redPin, LOW);
    delay(dt);
  }
  else {
    digitalWrite(redPin, HIGH);
    delay(dt);
  }

}
