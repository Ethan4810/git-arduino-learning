// 1st traffic
int redLED1 = 8;
int yellowLED1 = 9;
int greenLED1 = 10;

// 2nd traffic
int redLED2 = 11;
int yellowLED2 = 12;
int greenLED2 = 13;

// delay time
int shortDelay = 3000;
int middleDelay = 5000;
int longDelay = 15000;


void setup() {
  // setup LED lights as output //

  // 1st traffic
  pinMode(redLED1, OUTPUT);
  pinMode(yellowLED1, OUTPUT);
  pinMode(greenLED1, OUTPUT);

  // 2nd traffic
  pinMode(redLED2, OUTPUT);
  pinMode(yellowLED2, OUTPUT);
  pinMode(greenLED2, OUTPUT);
}


void loop() {
  changeLights();
  delay(longDelay); // wait for 15 sec
}


void changeLights() {
  // greens off, yellows on for 3 sec //
  // 1st traffic
  digitalWrite(greenLED1, LOW);
  digitalWrite(yellowLED1, HIGH);
  // 2nd traffic
  digitalWrite(greenLED2, LOW);
  digitalWrite(yellowLED2, HIGH);
  delay(shortDelay);

  // yellows off, green red opposite for 5 sec //
  // 1st traffic
  digitalWrite(yellowLED1, LOW);
  digitalWrite(greenLED1, LOW);
  digitalWrite(redLED1, HIGH);
  // 2nd traffic
  digitalWrite(yellowLED2, LOW);
  digitalWrite(greenLED2, HIGH);
  digitalWrite(redLED2, LOW);
  delay(middleDelay);

  // yellows on, green2 off for 3 sec //
  // 1st traffic
  digitalWrite(yellowLED1, HIGH);
  digitalWrite(redLED1, HIGH);
  // 2nd traffic
  digitalWrite(yellowLED2, HIGH);
  digitalWrite(greenLED2, LOW);
  delay(shortDelay);

  // yellows off, opposite green red for 5 sec //
  // 1st traffic
  digitalWrite(yellowLED1, LOW);
  digitalWrite(greenLED1, HIGH);
  digitalWrite(redLED1, LOW);
  // 2nd traffic
  digitalWrite(yellowLED2, LOW);
  digitalWrite(redLED2, HIGH);
  digitalWrite(greenLED2, LOW);
  delay(middleDelay);
}
