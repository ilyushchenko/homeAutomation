#include <Button.h>
#include <RCSwitch.h>

Button button(8, 50);
RCSwitch mySwitch = RCSwitch();

long intime;
int outPin = 7;
int state = LOW;


void setup() {
  mySwitch.enableReceive(0);
  button.begin(INPUT);
  pinMode(outPin, OUTPUT);
  digitalWrite(outPin, state);
}

void loop() {
  if (button.pressed()) {
    Switch();
  }
  if (mySwitch.available())
  {
    int value = mySwitch.getReceivedValue();
    mySwitch.resetAvailable();
    if(value == 20928) Switch();
  }
}

void Switch()
{
  state = (state == HIGH) ? LOW : HIGH;
  digitalWrite(outPin, state);
}
