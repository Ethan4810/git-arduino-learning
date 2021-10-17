/*
  Lab. 1 - Piezo Buzzer (Speaker) I
  Play school bell ring tone.
*/

int buzzPin = 8;


// school bell 1
char notes[] = "ggaaggeggeedggaaggegedec";
int songLength = strlen(notes);
int beats[] = {1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 4};
int tempo = 220; // how fast


//// plane
//char notes[] = "edcdeeedddeeeedcdeeeddedc";
//int songLength = strlen(notes);
//int beats[] = {1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 4};
//int tempo = 220; // how fast

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
  const int numNotes = 8;
  char names[] = {'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C'};
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
