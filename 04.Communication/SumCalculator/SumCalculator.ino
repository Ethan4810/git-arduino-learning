int shortDelay = 750;

int x, y, z;

String msg1 = "Enter x: ";
String msg2 = " / Enter y: ";
String result = " / x + y = ";

void setup() {
  // baud rate
  Serial.begin(115200);
  delay(shortDelay);
}


void loop() {

  Serial.print(msg1);
  while (Serial.available() == 0 ) {
  }
  x = Serial.parseInt();
  Serial.print(x);

  Serial.print(msg2);
  while (Serial.available() == 0 ) {
  }
  y = Serial.parseInt();
  Serial.print(y);

  z = x + y;

  Serial.print(result);
  Serial.println(z);
  delay(shortDelay);
}
