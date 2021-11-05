#include "pitches.h"

// passive buzzer pin
const int musicPin = 2;

// main theme (squid game)
int melodies[] = {
  NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4,
  NOTE_DS5, NOTE_B4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_B4,
  NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4,
  NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_E4
};
int durations[] = {
  4, 4, 2, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 2, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2
};
int theme_len = sizeof(melodies) / sizeof(int);

void setup() {
  Serial.begin(9600);

  // passive buzzer setup
  pinMode(musicPin, OUTPUT);
  digitalWrite(musicPin, LOW);
}

void loop() {
  playTheme(melodies, durations, theme_len);
}

void playTheme(int melodies[], int durations[], int theme_length)
{
  for (int i = 0; i < theme_length; i++)
  {
    int duration = 1000 / durations[i];
    int pause_time = duration * 1.13;

    tone(musicPin, melodies[i], duration);
    delay(pause_time);
    noTone(musicPin);
  }
}
