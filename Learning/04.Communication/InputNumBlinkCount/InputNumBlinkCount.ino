int i, blinkNum;
int redPin = 12;
int dt = 100;

String msg1 = "How many blinks do you want: ";


void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
}
 
void loop() {
  Serial.print(msg1);

  while (Serial.available() == 0 ) {
  }

  blinkNum = Serial.parseInt();
  Serial.println(blinkNum);

  for (i = 1; i <= blinkNum; i++) {
    digitalWrite(redPin, LOW);
    delay(dt);
    digitalWrite(redPin, HIGH);
    delay(dt);
    digitalWrite(redPin, LOW);
    delay(dt);
  }

}
