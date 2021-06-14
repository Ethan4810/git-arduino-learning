int potPin = A0;
int redPin = 7;

int potVal;
float vol;

int delayTime = 100;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(potPin, INPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(redPin, LOW);
  print();
  delay(delayTime);

  while (potVal > 500) {
    digitalWrite(redPin, HIGH);
    print();
    delay(delayTime);
  }
}


void print() {
  potVal = analogRead(potPin);
  vol = potVal * (5.0 / 1023.0);
  Serial.print("Analog value = ");
  Serial.print(potVal);
  Serial.print(" Voltage = ");
  Serial.println(vol);
}
