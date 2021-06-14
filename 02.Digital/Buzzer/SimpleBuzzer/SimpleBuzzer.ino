int buzzPin = 8;
int dt = 2000;

void setup() {
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  digitalWrite(buzzPin, HIGH);
  delay(dt);
}
