int buzzPin = 8;

// plane
char notes[] = "edcdeeedddeeeedcdeeeddedc";
int songLength = strlen(notes);
int beats[] = {1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 4};
int tempo = 320; // how fast

void setup() {
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < songLength; i++)
  {
    int duration = beats[i] * tempo;

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
  char names[] = {'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C'};
  int numNotes = strlen(names);
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};

  for (int i = 0; i < numNotes; i++)
  {
    if (names[i] == note)
    {
      return (frequencies[i]);
    }
  }

  return (0);
}
