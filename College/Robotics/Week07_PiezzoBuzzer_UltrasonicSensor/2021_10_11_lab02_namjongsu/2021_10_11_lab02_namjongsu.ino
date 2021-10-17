/*
	Lab. 2 - Piezo Buzzer (Speaker) II
 	Make a sound when pushbutton is pressed.
*/

int buzzPin = 8;
int cButton = A0;
int dButton = A1;
int eButton = A2;

int sdt = 10;

void setup()
{
  pinMode(cButton, INPUT);
  pinMode(dButton, INPUT);
  pinMode(eButton, INPUT);
  pinMode(buzzPin, OUTPUT);
}

void loop()
{
  // C
  if (digitalRead(cButton) == HIGH) {
    tone(buzzPin, 262, 100); 
  }
  // D
  if (digitalRead(dButton) == HIGH) {
    tone(buzzPin, 294, 100); 
  }
  // E
  if (digitalRead(eButton) == HIGH) {
    tone(buzzPin, 330, 100); 
  }
  
  delay(sdt); 
}