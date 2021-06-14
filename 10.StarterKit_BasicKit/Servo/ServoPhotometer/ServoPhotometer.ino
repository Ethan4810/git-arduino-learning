#include <Servo.h>

int lightPin = A1;
int servoPin = 9;
int lightVal;
float angle;
int dt = 10;
Servo sv;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lightPin, INPUT);
  sv.attach(servoPin);
}

void loop() {
  // variables (bright = 600, dark = 0)
  lightVal = analogRead(lightPin);
  angle = lightVal * (180. /  500.);
//  angle = ((-16. / 63. ) * lightVal) + (16. * (780. / 63.));

  // set limits
  if (angle > 180) {
    angle = 180;
  }
  if (angle < 0) {
    angle = 0;
  }

  // show info
  Serial.print("Light value = ");
  Serial.print(lightVal);
  Serial.print(", Angle = ");
  Serial.println(angle);

  // servo movement
  sv.write(angle);

  delay(dt);
}
