int readPin = A3;

float V2;
float readVal;

int shortDelay = 300;

void setup() {

  pinMode(readPin, INPUT);
  Serial.begin(9600);
}


void loop() {

  readVal = analogRead(readPin);
  V2 = (5. / 1023.) * readVal;
  Serial.println(V2);
  delay(shortDelay);
}
