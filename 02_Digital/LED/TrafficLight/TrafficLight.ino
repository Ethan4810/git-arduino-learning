int redLED = 8;
int yellowLED = 9;
int greenLED = 10;

int button = 12;


void setup() {
  // set LED lights as output
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  // set button as input
  pinMode(button, INPUT);

  // set green light as default
  digitalWrite(greenLED, HIGH);
}


void loop() {
  // press button to start traffic lights
  if (digitalRead(button) == HIGH) {
    delay(15); // software debounce
    if (digitalRead(button) == HIGH) {
      changeLights();
      delay(15); 
    }
  }
}


void changeLights() {
  // green off, yellow on for 3 sec
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, HIGH);
  delay(3000);

  // yellow off, red on for 5 sec
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, HIGH);
  delay(5000);

  // red on, yellow on for 3 sec
  digitalWrite(redLED, HIGH);
  digitalWrite(yellowLED, HIGH);
  delay(3000);

  // red off, yellow off, green on
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, HIGH);
  delay(15);
}
