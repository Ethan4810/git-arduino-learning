int redPin = 9;
int bright = 16;
int dim = 8;

int shortDelay = 3000;

void setup() {
  pinMode(redPin, OUTPUT);
}

void loop() {
  //  digitalWrite(redPin, HIGH); 
  analogWrite(redPin, bright);
  delay(shortDelay);

  analogWrite(redPin, dim);
  delay(shortDelay);
  
}
