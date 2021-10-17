// buzzer pin
const int buzzPin = 3;

// led pin
const int redPin = 4;

// hc-sr04 sensor pins
const int trigPin = 5;
const int echoPin = 6;
long duration;
int distance;

// delay time variables
int sdt = 100; // short
int mdt = 500; // middle
int ldt = 1000; // long

void setup() {
  // hc-sr04 setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // buzzer setup
  pinMode(buzzPin, OUTPUT);
  digitalWrite(buzzPin, LOW);

  // led setup
  pinMode(redPin, OUTPUT);
  digitalWrite(redPin, LOW);

  Serial.begin(9600);
  delay(ldt);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // send ultrasound
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // centimeter

  // distance condition
  if (distance < 20) {
    digitalWrite(buzzPin, LOW);
    digitalWrite(redPin, LOW);
  }
  if (20 <= distance && distance < 50 ) {
    digitalWrite(buzzPin, HIGH);
    digitalWrite(redPin, HIGH);
    delay(ldt);
    digitalWrite(buzzPin, LOW);
    digitalWrite(redPin, LOW);
  }
  if (50 <= distance) {
    digitalWrite(buzzPin, LOW);
    digitalWrite(redPin, LOW);
  }

  // show distance
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(sdt);
}
