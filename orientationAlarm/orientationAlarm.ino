/*Description: Sketch turns on green LED when tilt switch is oriented upright.
  Red LED and buzzer alarm turns on when tilt switch is not upright.
*/

namespace{
  namespace TiltSwitch{
    constexpr uint8_t pin{2};
  }

  namespace Buzzer{
    constexpr uint8_t pin{8};
  }

  namespace LED{
    constexpr uint8_t redPin{6};
    constexpr uint8_t greenPin{11};
  }
}

void setup(){
  pinMode(::LED::redPin, OUTPUT); //Initialize the red ledPin as an output.
  pinMode(::LED::greenPin, OUTPUT); //Initialize the green ledPin as an output.
  pinMode(::TiltSwitch::pin, INPUT); //Initialize tilt switch.
  pinMode(::Buzzer::pin, OUTPUT); //Initialize active buzzer as output.

  digitalWrite(::TiltSwitch::pin, HIGH);
} 


void loop(){
  int tiltSwitchDigitalVal=digitalRead(::TiltSwitch::pin);

  if(tiltSwitchDigitalVal==HIGH){
    digitalWrite(::LED::redPin, HIGH); //Turn the red led on.
    digitalWrite(::LED::greenPin, LOW); //Turn the green led off.
    digitalWrite(::Buzzer::pin, HIGH); //Turn buzzer alarm on.
  }
  else{
    digitalWrite(::LED::redPin, LOW); //Turn the red led off.
    digitalWrite(::LED::greenPin, HIGH); //Turn the green led on.
    digitalWrite(::Buzzer::pin, LOW); //Turn buzzer alarm off.
  }
}
