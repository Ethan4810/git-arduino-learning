/*
   Lab. 4 - Countdown Timer using FND
*/

// fnd pin variables
int aPin = 3;
int bPin = 4;
int cPin = 5;
int dPin = 6;
int ePin = 7;
int fPin = 8;
int gPin = 9;

// time variable
int dt = 1000;

void setup()
{
  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(ePin, OUTPUT);
  pinMode(fPin, OUTPUT);
  pinMode(gPin, OUTPUT);
}

void loop()
{
  // 9 (abcdfg)
  digitalWrite(aPin, HIGH);
  digitalWrite(bPin, HIGH);
  digitalWrite(cPin, HIGH);
  digitalWrite(dPin, HIGH);
  digitalWrite(ePin, LOW);
  digitalWrite(fPin, HIGH);
  digitalWrite(gPin, HIGH);
  delay(dt);

  // 8 (abcdefg)
  digitalWrite(aPin, HIGH);
  digitalWrite(bPin, HIGH);
  digitalWrite(cPin, HIGH);
  digitalWrite(dPin, HIGH);
  digitalWrite(ePin, HIGH);
  digitalWrite(fPin, HIGH);
  digitalWrite(gPin, HIGH);
  delay(dt);

  // 7 (abcf)
  digitalWrite(aPin, HIGH);
  digitalWrite(bPin, HIGH);
  digitalWrite(cPin, HIGH);
  digitalWrite(dPin, LOW);
  digitalWrite(ePin, LOW);
  digitalWrite(fPin, HIGH);
  digitalWrite(gPin, LOW);
  delay(dt);

  // 6 (acdefg)
  digitalWrite(aPin, HIGH);
  digitalWrite(bPin, LOW);
  digitalWrite(cPin, HIGH);
  digitalWrite(dPin, HIGH);
  digitalWrite(ePin, HIGH);
  digitalWrite(fPin, HIGH);
  digitalWrite(gPin, HIGH);
  delay(dt);

  // 5 (acdfg)
  digitalWrite(aPin, HIGH);
  digitalWrite(bPin, LOW);
  digitalWrite(cPin, HIGH);
  digitalWrite(dPin, HIGH);
  digitalWrite(ePin, LOW);
  digitalWrite(fPin, HIGH);
  digitalWrite(gPin, HIGH);
  delay(dt);

  // 4 (bcfg)
  digitalWrite(aPin, LOW);
  digitalWrite(bPin, HIGH);
  digitalWrite(cPin, HIGH);
  digitalWrite(dPin, LOW);
  digitalWrite(ePin, LOW);
  digitalWrite(fPin, HIGH);
  digitalWrite(gPin, HIGH);
  delay(dt);

  // 3 (abcdg)
  digitalWrite(aPin, HIGH);
  digitalWrite(bPin, HIGH);
  digitalWrite(cPin, HIGH);
  digitalWrite(dPin, HIGH);
  digitalWrite(ePin, LOW);
  digitalWrite(fPin, LOW);
  digitalWrite(gPin, HIGH);
  delay(dt);

  // 2 (abdeg)
  digitalWrite(aPin, HIGH);
  digitalWrite(bPin, HIGH);
  digitalWrite(cPin, LOW);
  digitalWrite(dPin, HIGH);
  digitalWrite(ePin, HIGH);
  digitalWrite(fPin, LOW);
  digitalWrite(gPin, HIGH);
  delay(dt);

  // 1 (bc)
  digitalWrite(aPin, LOW);
  digitalWrite(bPin, HIGH);
  digitalWrite(cPin, HIGH);
  digitalWrite(dPin, LOW);
  digitalWrite(ePin, LOW);
  digitalWrite(fPin, LOW);
  digitalWrite(gPin, LOW);
  delay(dt);

  // 0 (abcdef)
  digitalWrite(aPin, HIGH);
  digitalWrite(bPin, HIGH);
  digitalWrite(cPin, HIGH);
  digitalWrite(dPin, HIGH);
  digitalWrite(ePin, HIGH);
  digitalWrite(fPin, HIGH);
  digitalWrite(gPin, LOW);
  delay(dt);
}
