// A-ha!
#include "pitches.h"

// Two things need to be created: the array for the notes of the melody (in order)
// and the duration of each (think of it like sheet music in two parts)

// BOTH ARRAYS MUST BE THE SAME SIZE!

// The melody array
int melody[] = {
  NOTE_FS5, NOTE_FS5, NOTE_D5, NOTE_B4, NOTE_B4, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_B5,
  NOTE_A5, NOTE_A5, NOTE_A5, NOTE_E5, NOTE_D5, NOTE_FS5,
  NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_E5
};

int durations[] = {
  8, 8, 8, 4, 4, 4,
  4, 7, 8, 8, 8, 8,
  8, 8, 8, 4, 4, 4,
  4, 7, 8, 8, 8, 8
};

// determine the length of the arrays to use in the loop iteration
int songLength = sizeof(melody) / sizeof(melody[0]);

void setup() {
  // we don't need anything here
}

void loop() {
  for (int thisNote = 0; thisNote < songLength; thisNote++) {
    int duration = 1000 / durations[thisNote];

    tone(8, melody[thisNote], duration);

    int pause = duration * 1.3;

    delay(pause);

    noTone(8);
  }
}
