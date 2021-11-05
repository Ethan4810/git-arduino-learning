int Buzzer = 2;
int songLength = 17;
char notes[] = "cdefgabC";

// A "1" represents a quarter-note, 2 a half-note
int beats[] = {1, 1, 1, 1, 1, 1, 1, 1};

// how fast to play the song
int tempo = 240;


void setup() {
  pinMode(Buzzer, OUTPUT);
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
      tone(Buzzer, frequency(notes[i]), duration);
      
      delay(duration);
    }
    
    // brief pause between notes
    delay(tempo / 10);
  }
}


int frequency(char note)
{
  int i;

  const int numNotes = 8; // number of notes stored

  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};

  for (i = 0; i < numNotes; i++)  // Step through the notes
  {
    if (names[i] == note)         // Is this the one?
    {
      return (frequencies[i]);    // Yes! Return the frequency
    }
  }
  
  return 0;
}
