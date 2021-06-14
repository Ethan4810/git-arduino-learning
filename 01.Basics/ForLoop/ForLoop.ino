int redLED = 9;
int redTime = 300;
int redBlink = 5;

int yellowLED = 6;
int yellowTime = 150;
int yellowBlink = 7;

int shortDelay = 500;
int longDelay = 300;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i, j;

  for (i = 1; i <= redBlink; i++) {
    digitalWrite(redLED, LOW);
    delay(redTime);
    digitalWrite(redLED, HIGH);
    delay(redTime);
    digitalWrite(redLED, LOW);
  }

  delay(longDelay);

  for (j = 1; j <= yellowBlink; j++) {
    digitalWrite(yellowLED, LOW);
    delay(yellowTime);
    digitalWrite(yellowLED, HIGH);
    delay(yellowTime);
    digitalWrite(yellowLED, LOW);
  }

  delay(longDelay);
}
