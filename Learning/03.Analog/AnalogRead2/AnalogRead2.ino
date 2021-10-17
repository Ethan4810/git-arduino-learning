int myPin = A2;

float V2;
float readVal;

int shortDelay = 300;


void setup() {
  // put your setup code here, to run once:
  pinMode(myPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(myPin);
  V2 = (5. / 1023.) * readVal;
  Serial.println(V2);
  delay(shortDelay);

}
