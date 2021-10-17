/*
	Lab. 1 - Counter
*/

int count = 0;

int dt = 1000;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print(count);
  Serial.println(" sec");
  count++;

  delay(dt);
}
