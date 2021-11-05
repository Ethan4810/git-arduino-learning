// hc-sr04 senosr pins
const int trigPin = 5;
const int echoPin = 6;
long duration;
long distance;

// delay time variables
int sdt = 50; // short
int mdt = 500; // middle
int ldt = 1000; // long

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // send ping from trigger
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);

  // read reflected ping from receiver
  // speed of sound = 343 m/s (20'C)
  duration = pulseIn(echoPin, HIGH); // microseconds
  distance = (duration * 0.0343) / 2.; // centimeter

  // show distance
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(sdt);
}
