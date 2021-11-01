// joystick pins
const int xPin = A0;
const int yPin = A1;
const int sPin = 2;
int xVal, yVal, sVal;

int dt = 100;

void setup() {
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(sPin, INPUT);
  digitalWrite(sPin, HIGH);
}

void loop() {
  
  xVal = analogRead(xPin); 
  yVal = analogRead(yPin);
  sVal = digitalRead(sPin); // not pressed = 1, pressed = 0

  Serial.print("X = ");
  Serial.print(xVal);

  Serial.print(", Y = ");
  Serial.print(yVal);

  Serial.print(", Swtich = ");
  Serial.println(sVal);

  delay(dt);
}
