// ir pins and variables
#include <IRremote.h>
const int IRpin = 9;
IRrecv ir(IRpin); // set pin

decode_results cmd; //

int sdt = 10;
int mdt = 100;
int ldt = 1500;

void setup()
{
  Serial.begin(9600);
  ir.enableIRIn();
}

void loop()
{
  while (ir.decode(&cmd) == 0 ) {
  }
  Serial.parseInt(cmd.value, HEX);
  delay(ldt);
  ir.resume();
}
