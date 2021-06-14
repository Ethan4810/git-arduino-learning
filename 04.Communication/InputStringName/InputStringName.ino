String msg1 = "What is your name? ";
String msg2 = "Your name is ";
String myName;

int dt = 500;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(msg1);
  while (Serial.available() == 0) {

  }
  myName = Serial.readString();
  Serial.print(msg2);
  Serial.println(myName);
  delay(dt);


}
