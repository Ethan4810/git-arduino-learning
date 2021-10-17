int redLED = 13;
int yellowLED = 12;
int greenLED = 11;
int dit = 100;
int dah = 250;
int shortWait = 300;
int longWait = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  // S in morse code
  digitalWrite(redLED, HIGH);
  delay(dit);
  digitalWrite(redLED, LOW);
  delay(dit);
  digitalWrite(redLED, HIGH);
  delay(dit);
  digitalWrite(redLED, LOW);
  delay(dit);
  digitalWrite(redLED, HIGH);
  delay(dit);
  digitalWrite(redLED, LOW);
  delay(shortWait);

  // O in morse code
  digitalWrite(yellowLED, HIGH);
  delay(dah);
  digitalWrite(yellowLED, LOW);
  delay(dah);
  digitalWrite(yellowLED, HIGH);
  delay(dah);
  digitalWrite(yellowLED, LOW);
  delay(dah);
  digitalWrite(yellowLED, HIGH);
  delay(dah);
  digitalWrite(yellowLED, LOW);
  delay(shortWait);

  // S in morse code
  digitalWrite(greenLED, HIGH);
  delay(dit);
  digitalWrite(greenLED, LOW);
  delay(dit);
  digitalWrite(greenLED, HIGH);
  delay(dit);
  digitalWrite(greenLED, LOW);
  delay(dit);
  digitalWrite(greenLED, HIGH);
  delay(dit);
  digitalWrite(greenLED, LOW);
  delay(shortWait);

  delay(longWait);
}
