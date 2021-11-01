byte myByte = 0; // decimal
//byte myByte = B00000000; // binary
//byte myByte = 0x0; // hexadecimal

int dt = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DEC      BIN      HEX");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(myByte, DEC);
  Serial.print("        ");
  Serial.print(myByte, BIN);
  Serial.print("        ");
  Serial.println(myByte, HEX);
  myByte++;

  delay(dt);
}
