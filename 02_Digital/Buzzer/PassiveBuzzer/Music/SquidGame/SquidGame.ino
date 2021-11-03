int buzzPin = 8;

// squid game
char notes[] = "bbbbbb#bbagabbbbbbbbagagee";
int songLength = strlen(notes);
int beats[] = {1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2};
int tempo = 280; // how fast

void setup() {
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  int duration;

  for (int i = 0; i < songLength; i++)
  {
    duration = beats[i] * tempo;

    if (notes[i] == ' ')
    {
      delay(duration);
    }

    else
    {
      tone(buzzPin, frequency(notes[i]), duration);
      delay(duration);
    }

    // brief pause between notes
    delay(tempo / 10);
  }
}

int frequency(char note)
{
  char names[] = {'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C', 'D', '#', 'E'};
  int numNotes = strlen(names);
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523, 587, 622, 659};

  for (int i = 0; i < numNotes; i++)
  {
    if (names[i] == note)
    {
      return (frequencies[i]);
    }
  }

  return (0);
}
