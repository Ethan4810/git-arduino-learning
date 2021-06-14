int ds = 12; // serial data input pin
int st = 11; // storage register clock pin (latch)
int sh = 9; // shift register clock pin

byte LEDs = 0; // decimal
//byte LEDs = 0b00000000; // binary
//byte LEDs = 0x00; // hexadecimal

int dt = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(ds, OUTPUT);
  pinMode(st, OUTPUT);
  pinMode(sh, OUTPUT);
}

void loop() {
  digitalWrite(st, LOW);
  shiftOut(ds, sh, LSBFIRST, LEDs); // least significant bit first
  digitalWrite(st, HIGH);

  // print bits
  Serial.print(LEDs, BIN);
  Serial.print(" in binary, ");
  Serial.print(LEDs, DEC);
  Serial.println(" in decimal.");

  LEDs ++;

  delay(dt);
}
