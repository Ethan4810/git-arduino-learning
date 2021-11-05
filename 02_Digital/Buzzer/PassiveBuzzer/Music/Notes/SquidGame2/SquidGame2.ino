// passive buzzer pins
const int musicPin = 2;

// squid game theme
char notes[] = "bbbbbbbbbagabbbbbbbbagagee";
int beats[] = {
  1, 1, 2, 1, 1, 2,
  1, 1, 1, 1, 1, 1, 2,
  1, 1, 2, 1, 1, 2,
  1, 1, 1, 1, 1, 1, 2
};

void setup() {
  // passive buzzer setup
  pinMode(musicPin, OUTPUT);
  digitalWrite(musicPin, LOW);
}

void loop()
{
  playTheme(notes, beats);
}

int frequency(char notes)
{
  char names[] = {'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C', 'D', 'E', 'F', 'G', 'A', 'B'};
  int num_notes = strlen(names);
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523, 587, 659, 699, 784, 880, 988};

  for (int i = 0; i < num_notes; i++)
  {
    if (names[i] == notes)
    {
      return (frequencies[i]);
    }
  }

  return 0;
}

void playTheme(char notes[], int beats[])
{
  int tempo = 280;
  int song_length = strlen(notes);
  int music_duration;

  // loop through song
  for (int i = 0; i < song_length; i++)
  {
    music_duration = beats[i] * tempo;

    // pause sound
    if (notes[i] == ' ')
    {
      delay(music_duration);
    }

    // play sound
    else
    {
      tone(musicPin, frequency(notes[i]), music_duration);
      delay(music_duration);
    }

    // brief pause between notes
    delay(tempo / 10);
  }
}
