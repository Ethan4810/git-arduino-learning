int pin = 6;
int pot = A2;
int dt = 1;

int analogValue;
float voltage;
float brightness;

void setup() {
  // set pin as output, potentiometer as input
  pinMode(pin, OUTPUT);
  pinMode(pot, INPUT);
  Serial.begin(9600); // baud rate
}

void loop() {
  analogValue = analogRead(pot);
  voltage =  analogValue * (5.0 / 1023.0);
  brightness = analogValue * (255.0 / 1023.0);

  analogWrite(pin, brightness);
  delay(dt);

  Serial.print("Brightness = ");
  Serial.print(brightness);
  Serial.print("  Voltage = ");
  Serial.println(voltage);
}
