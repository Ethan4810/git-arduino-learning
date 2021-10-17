int redPin = 9;
int greenPin = 10;
int bluePin = 11;
int potPin = A0;
int dt = 500;
int potVal;
float brightness;

String msg = "Choose color (R/G/B/M/Y/C/W): ";
String errMsg = "Error! Type valid color! (R/G/B/M/Y/C/W) ";
String colSel;


void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:

  Serial.print(msg);

  while (Serial.available() == 0) {
    potVal = analogRead(potPin);
    brightness = potVal * (255.0 / 1023.0);

    if (colSel == "r") {
      analogWrite(redPin, brightness);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
      break;
    }
    else if (colSel == "g") {
      digitalWrite(redPin, LOW);
      analogWrite(greenPin, brightness);
      digitalWrite(bluePin, LOW);
    }
    else if (colSel == "b") {
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      analogWrite(bluePin, brightness);
    }
    else if (colSel == "m") {
      analogWrite(redPin, brightness);
      digitalWrite(greenPin, LOW);
      analogWrite(bluePin, brightness);
    }
    else if (colSel == "y") {
      analogWrite(redPin, brightness);
      analogWrite(greenPin, brightness);
      digitalWrite(bluePin, LOW);
    }
    else if (colSel == "c") {
      digitalWrite(redPin, LOW);
      analogWrite(greenPin, brightness);
      analogWrite(bluePin, brightness);
    }
    else if (colSel == "w") {
      analogWrite(redPin, brightness);
      analogWrite(greenPin, brightness);
      analogWrite(bluePin, brightness);
    }
  }

  colSel = Serial.readString();
  Serial.print(colSel);
  Serial.print(" Brightness = ");
  Serial.println(brightness);



}
