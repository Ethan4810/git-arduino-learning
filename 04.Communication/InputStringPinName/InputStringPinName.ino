int redPin = 13;
int yellowPin = 12;
int greenPin = 11;
int dt = 300;

String msg = "What color LED? (r/y/g): ";
String errorMsg = "Error! Enter right color! (r/y/g)";
String pinSel;


void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}


void loop() {
  Serial.print(msg);

  while (Serial.available() == 0) {
  }

  pinSel = Serial.readString();

  Serial.println(pinSel);


  if (pinSel == "r") {
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
    delay(dt);
  }
  else if (pinSel == "y") {
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, LOW);
    delay(dt);
  }
  else if (pinSel == "g") {
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, HIGH);
    delay(dt);
  }
  else {
    Serial.println(errorMsg);
  }

  delay(dt);
}
