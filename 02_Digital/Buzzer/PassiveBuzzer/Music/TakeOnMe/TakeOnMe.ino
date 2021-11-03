/*
   A-ha! Take On Me
*/

#include "pitches.h"

// passive buzzer variables
int musicPin = 2;

// melodies
int melody[] = {
  NOTE_FS5, NOTE_FS5, NOTE_D5, NOTE_B4, NOTE_B4, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_B5,
  NOTE_A5, NOTE_A5, NOTE_A5, NOTE_E5, NOTE_D5, NOTE_FS5,
  NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_E5
};

// durations
int durations[] = {
  8, 8, 8, 4, 4, 4,
  4, 7, 8, 8, 8, 8,
  8, 8, 8, 4, 4, 4,
  4, 7, 8, 8, 8, 8
};

// determine the length of the arrays to use in the loop iteration
int songLength = sizeof(melody) / sizeof(melody[0]);

void setup() {
  pinMode(musicPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for (int thisNote = 0; thisNote < songLength; thisNote++) 
  {
    int duration = 1000 / durations[thisNote];
    int pauseTime = duration * 1.3;
   
    tone(musicPin, melody[thisNote], duration);
    delay(pauseTime);
    noTone(musicPin);
  }
}
