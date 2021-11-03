// hc-sr04 senosr pins
const int trigPin = 5;
const int echoPin = 6;

// led pins
const int greenPin = 7;
const int redPin = 8;

// buzzer pins
const int musicPin = 2;
const int alarmPin = 3;

// green light red light theme
char notes[] = "eaaagaaeeg";
int songLength = strlen(notes);
int beats[] = {1, 1, 2, 2, 2, 1, 1, 1, 1, 1};
int tempo = 280; // how fast
int t_duration;

long h_duration;
long distance;
long first_distance;

// delay time variables
int sdt = 50; // short
int mdt = 500; // middle
int ldt = 1000; // long

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(musicPin, OUTPUT);
  pinMode(alarmPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  /*
     Play Theme
  */
  digitalWrite(greenPin, HIGH);
  for (int i = 0; i < songLength; i++)
  {
    t_duration = beats[i] * tempo;
    if (notes[i] == ' ')
    {
      delay(t_duration);
    }
    else
    {
      tone(musicPin, frequency(notes[i]), t_duration);
      delay(t_duration);
    }
    // brief pause between notes
    delay(tempo / 10);
  }
  digitalWrite(greenPin, LOW);
  digitalWrite(redPin, HIGH);
  delay(t_duration * 2);

  /*
    Play Game
  */

  // send ping from trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  // read ping from echo pin
  h_duration = pulseIn(echoPin, HIGH);
  first_distance = (h_duration * 0.0343) / 2.;

  // save first distance
  Serial.print("First Distance = ");
  Serial.print(first_distance);
  Serial.println(" cm");

  // check distance i times
  int i = 0;
  while (i < 10) {
    // send ping from trigger pin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(10);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);

    // read ping from echo pin
    h_duration = pulseIn(echoPin, HIGH);
    distance = (h_duration * 0.0343) / 2.;

    // total 3 seconds (10 x 300 = 3000)
    delay(300);
    i++;

    // show distance
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println(" cm");

    // player move
    if ((3 <= abs(first_distance - distance)) && (abs(first_distance - distance) < 30)) {
      tone(musicPin, 600, 3000);
      delay(500);
      noTone(musicPin);
      delay(500);
      tone(musicPin, 600, 3000);
      delay(500);
      noTone(musicPin);
      delay(500);
      break;
    }
    // player don't move
    else {
      digitalWrite(alarmPin, LOW);
      continue;
    }

  }
  digitalWrite(redPin, LOW);
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
