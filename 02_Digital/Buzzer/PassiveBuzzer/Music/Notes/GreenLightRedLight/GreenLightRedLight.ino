int musicPin = 8;

// green light red light theme
char notes[] = "eaaagaaeeg";
int songLength = strlen(notes);
int beats[] = {1, 1, 2, 2, 2, 1, 1, 1, 1, 1};
int tempo = 280; // how fast
int t_duration;

void setup() {
  pinMode(musicPin, OUTPUT);
}

void loop() {
    play_theme();
}

int frequency(char note)
{
  char names[] = {'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C', 'D', 'E'};
  int numNotes = strlen(names);
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523, 587, 659};

  for (int i = 0; i < numNotes; i++)
  {
    if (names[i] == note)
    {
      return (frequencies[i]);
    }
  }

  return 0;
}

void play_theme()
{
  // loop through song
  for (int i = 0; i < songLength; i++)
  {
    t_duration = beats[i] * tempo;

    // pause sound
    if (notes[i] == ' ')
    {
      delay(t_duration);
    }

    // play sound
    else
    {
      tone(musicPin, frequency(notes[i]), t_duration);
      delay(t_duration);
    }

    // brief pause between notes
    delay(tempo / 10);
  }
}
