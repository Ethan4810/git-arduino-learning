// led pin
int redPin = 9;
int brightness = 125;
int brightnessVal = 15;

// button pins
int buttonPin1 = 11;
int buttonPin2 = 12;

// delay time
int dt = 50;
int dt2 = 100;

void setup() {
  // led setup
  pinMode(redPin, OUTPUT);

  // button setup
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  
  Serial.begin(9600);
}

void loop() {
  // show info in serial monitor
  // 1 is button not pressed, 0 is button pressed
  Serial.print("Button 1 = ");
  Serial.print(digitalRead(buttonPin1));
  Serial.print(", Button 2 = ");
  Serial.print(digitalRead(buttonPin2));
  Serial.print(", Brightness = ");
  Serial.println(brightness);

  // no button pressed: do nothing
  if (digitalRead(buttonPin1) == true && digitalRead(buttonPin2) == true) {
    brightness += 0;
    delay(dt2);
  }

  // button 1 pressed: reduce brightness
  if (digitalRead(buttonPin1) == false && digitalRead(buttonPin2) == true) {
    brightness -= brightnessVal;
    delay(dt2);
    if (brightness < 0) {
      brightness = 0; // minimum brightness reached
    }
  }

  // button 2 pressed: increase brightness
  if (digitalRead(buttonPin1) == true && digitalRead(buttonPin2) == false) {
    brightness += brightnessVal;
    delay(dt2);
    if (brightness > 255) {
      brightness = 255; // maximum brightness reached
    }
  }

  // 2 buttons pressed: reset
  if (digitalRead(buttonPin1) == false && digitalRead(buttonPin2) == false) {
    brightness = 0;
  }

  analogWrite(redPin, brightness);
  delay(dt);
}
