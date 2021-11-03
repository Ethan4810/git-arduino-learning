/*
 * Toggle Button
*/

// led variable
int ledPin = 9; // 220 ohm
int ledState = LOW;

// button variables
int buttonPin = 10; // 10k ohm
int buttonVal;
int lastButtonState;
int currentButtonState;

int dt = 10;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  currentButtonState = digitalRead(buttonPin);
  
  Serial.begin(9600);
}

void loop()
{
  lastButtonState = currentButtonState;         // save the last state
  currentButtonState = digitalRead(buttonPin); // read new state

  if(lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.println("The button is pressed");

    // toggle state of LED
    ledState = !ledState;

    // control LED arccoding to the toggled state
    digitalWrite(ledPin, ledState); 
  }

  delay(dt);
}
