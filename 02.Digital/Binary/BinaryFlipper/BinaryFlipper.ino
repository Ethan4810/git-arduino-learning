int ds = 12; // serial data input pin
int st = 11; // storage register clock pin (latch)
int sh = 9; // shift register clock pin

//byte LEDs = 0; // decimal
//byte LEDs = 0b11010000; // binary
byte LEDs = 0xFA; // hexadecimal
byte flippedLEDs;

int dt = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(ds, OUTPUT);
  pinMode(st, OUTPUT);
  pinMode(sh, OUTPUT);
}

void loop() {
  // original bits
  digitalWrite(st, LOW);
  shiftOut(ds, sh, LSBFIRST, LEDs); // least significant bit first
  digitalWrite(st, HIGH);

  // print bits
  Serial.print(LEDs, BIN);
  Serial.print(" in binary, ");
  Serial.print(LEDs, DEC);
  Serial.println(" in decimal.");

  // binary bit flipper operation
  LEDs = 255 - LEDs ;

  delay(dt);
}
