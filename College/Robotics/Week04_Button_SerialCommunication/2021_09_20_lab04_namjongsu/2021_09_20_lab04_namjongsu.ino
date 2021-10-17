/*
	lab.4 - PushButton RGB LED
*/

// rgb led pins
int rPin = 11;
int gPin = 10;
int bPin = 9;

// button pins
int rBtn = 4;
int gBtn = 3;
int bBtn = 2;

// button states
int rBtnState; 
int gBtnState;
int bBtnState;

int dt = 100;

void setup()
{
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(rBtn, INPUT);
  pinMode(gBtn, INPUT);
  pinMode(bBtn, INPUT);
  Serial.begin(9600);
}

void loop()
{ 
  // read states
  rBtnState = digitalRead(rBtn);
  gBtnState = digitalRead(gBtn);
  bBtnState = digitalRead(bBtn);
  
  digitalWrite(rPin, rBtnState);
  digitalWrite(gPin, gBtnState);
  digitalWrite(bPin, bBtnState);
  
  Serial.print("R = ");
  Serial.print(rBtnState);
  Serial.print(", G = ");
  Serial.print(gBtnState);
  Serial.print(", B = ");
  Serial.println(bBtnState);
  
  delay(dt);
}