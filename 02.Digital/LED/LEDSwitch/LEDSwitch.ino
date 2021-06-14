int redPin = 8;
int buttonPin = 12;
int dt = 100;
int status = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}
 
void loop() {

  if (digitalRead(buttonPin) == true) {
    status = ! status;
    digitalWrite(redPin, status);
  } 
  while (digitalRead(buttonPin) == true);
  delay(dt);
}
