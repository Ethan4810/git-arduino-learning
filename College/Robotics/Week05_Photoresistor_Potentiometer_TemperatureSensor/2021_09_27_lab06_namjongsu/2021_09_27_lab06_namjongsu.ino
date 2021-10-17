/*
	Lab. 6 - Temperature Sensor & LED
	The sensed temperature is displayed with 6 LEDs 
    in a range from 20 – 31°C.
*/

// temperature sensor variables
int tmpPin = A0;
int tmpVal;
float tmpVol;
float tmpCel;

// led variables
int rPin1 = 7;
int rPin2 = 6;
int yPin1 = 5;
int yPin2 = 4;
int gPin1 = 3;
int gPin2 = 2;

int dt = 100;

void setup()
{
  // temperature sensor setup
  pinMode(tmpPin, INPUT);
  
  // led setup
  pinMode(rPin1, OUTPUT);
  pinMode(rPin2, OUTPUT);
  pinMode(yPin1, OUTPUT);
  pinMode(yPin2, OUTPUT);
  pinMode(gPin1, OUTPUT);
  pinMode(gPin2, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  tmpVal = analogRead(tmpPin);
  tmpVol = tmpVal * (5. / 1024.0);
  tmpCel = (tmpVol - 0.5) * 100.;
  
  if (20 <= tmpCel && tmpCel < 22) {
    digitalWrite(rPin1, HIGH);
    digitalWrite(rPin2, LOW);
    digitalWrite(yPin1, LOW);
    digitalWrite(yPin2, LOW);
    digitalWrite(gPin1, LOW);
    digitalWrite(gPin2, LOW);
  }
  else if (22 <= tmpCel && tmpCel < 24) {
    digitalWrite(rPin1, HIGH);
    digitalWrite(rPin2, HIGH);
    digitalWrite(yPin1, LOW);
    digitalWrite(yPin2, LOW);
    digitalWrite(gPin1, LOW);
    digitalWrite(gPin2, LOW);
  }
    else if (24 <= tmpCel && tmpCel < 26) {
    digitalWrite(rPin1, HIGH);
    digitalWrite(rPin2, HIGH);
    digitalWrite(yPin1, HIGH);
    digitalWrite(yPin2, LOW);
    digitalWrite(gPin1, LOW);
    digitalWrite(gPin2, LOW);
  }
    else if (26 <= tmpCel && tmpCel < 28) {
    digitalWrite(rPin1, HIGH);
    digitalWrite(rPin2, HIGH);
    digitalWrite(yPin1, HIGH);
    digitalWrite(yPin2, HIGH);
    digitalWrite(gPin1, LOW);
    digitalWrite(gPin2, LOW);
  }
    else if (28 <= tmpCel && tmpCel < 30) {
    digitalWrite(rPin1, HIGH);
    digitalWrite(rPin2, HIGH);
    digitalWrite(yPin1, HIGH);
    digitalWrite(yPin2, HIGH);
    digitalWrite(gPin1, HIGH);
    digitalWrite(gPin2, LOW);
  }
    else if (30 <= tmpCel && tmpCel < 32) {
    digitalWrite(rPin1, HIGH);
    digitalWrite(rPin2, HIGH);
    digitalWrite(yPin1, HIGH);
    digitalWrite(yPin2, HIGH);
    digitalWrite(gPin1, HIGH);
    digitalWrite(gPin2, HIGH);
  }
    else {
    digitalWrite(rPin1, LOW);
    digitalWrite(rPin2, LOW);
    digitalWrite(yPin1, LOW);
    digitalWrite(yPin2, LOW);
    digitalWrite(gPin1, LOW);
    digitalWrite(gPin2, LOW);
  }
  
  Serial.print(tmpCel);
  Serial.println(" 'C");
  
  delay(dt);
}