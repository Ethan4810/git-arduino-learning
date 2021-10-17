float sinVal;
float cosVal;
float tanVal;
float i;

int dt = 500;

void setup() {
  Serial.begin(9600);
  delay(dt);
}

void loop() {
  for (i = 0; i <= 2 * 3.14159265; i = i + 0.01) {
    sinVal = sin(i);
    cosVal = cos(i);
    tanVal = tan(i);

    Serial.print(sinVal);
    Serial.print(",");
    Serial.print(cosVal);
    Serial.print(",");
    Serial.println(tanVal);
  }

}
