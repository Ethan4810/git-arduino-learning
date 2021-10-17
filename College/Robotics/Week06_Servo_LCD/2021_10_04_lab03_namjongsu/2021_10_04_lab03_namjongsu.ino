/*
	Lab. 3 - LCD
  	Prints "Hello World!" to the LCD 
  	and adjust the screen contrast by the potentiometer
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.print("hello, world!");
}

void loop(){
}

  