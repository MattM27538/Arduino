// Description: Allows for an on and off switch to control an led light via an Arudino microcontroller.

namespace{
  namespace Peripherals{
    enum PinNumbers:uint8_t{
      led=5,
      ledOnButton=9,
      ledOffButton=8
    };
  }
}

void setup(){
  pinMode(Peripherals::led,OUTPUT);
  pinMode(Peripherals::ledOnButton,INPUT_PULLUP);
  pinMode(Peripherals::ledOffButton,INPUT_PULLUP);
}

void loop(){
  //Turn led on.
  if(digitalRead(Peripherals::ledOnButton)==LOW){
    digitalWrite(Peripherals::led,HIGH);
  }

  //Turn led off.
  if(digitalRead(Peripherals::ledOffButton)==LOW){
    digitalWrite(Peripherals::led,LOW);
  }
}
