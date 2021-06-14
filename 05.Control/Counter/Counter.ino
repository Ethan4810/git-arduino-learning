int i;
int counter = 10;
int sec = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (i = counter; i >= 1; i--) {
    Serial.println(i);
    delay(sec);
  }

  Serial.println("Start new loop.");
  delay(sec);

}
