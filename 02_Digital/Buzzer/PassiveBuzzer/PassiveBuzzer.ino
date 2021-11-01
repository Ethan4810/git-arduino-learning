int buzzPin = 8;
int bt1 = 1;
int bt2 = 900;

void setup() {
  pinMode(buzzPin, OUTPUT);

}

void loop() {
  digitalWrite(buzzPin, HIGH);
  delayMicroseconds(bt2);
  digitalWrite(buzzPin, LOW);
  delayMicroseconds(bt2);
}
