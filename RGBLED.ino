enum class pinColor:uint8_t{
  BLUE=3,
  GREEN=5,
  RED=6
};

//LED Color Values
namespace {
  int redValue{255};
  int greenValue{0};
  int blueValue{0};
}

void changeLEDColor(int& currColorValue,int& newColorValue,uint8_t currPinColor,uint8_t newPinColor, const int delayTime){
  for(int i{0};i<255;++i){
    --currColorValue;
    ++newColorValue;

    analogWrite(currPinColor, currColorValue);
    analogWrite(newPinColor, newColorValue);
    delay(delayTime);
  }
}

void setup(){
  pinMode(static_cast<uint8_t>(pinColor::RED), OUTPUT);
  pinMode(static_cast<uint8_t>(pinColor::GREEN), OUTPUT);
  pinMode(static_cast<uint8_t>(pinColor::BLUE), OUTPUT);

  digitalWrite(static_cast<uint8_t>(pinColor::RED), HIGH);
  digitalWrite(static_cast<uint8_t>(pinColor::GREEN), LOW);
  digitalWrite(static_cast<uint8_t>(pinColor::BLUE), LOW);
}


//Main loop
void loop(){
  constexpr unsigned long delayTime{10}; //Transition time between LED color fades.
  
  //Change LED from red to green.
  changeLEDColor(::redValue,::greenValue,static_cast<uint8_t>(pinColor::RED),static_cast<uint8_t>(pinColor::GREEN),delayTime);

  //Change LED from green to blue.
  changeLEDColor(::greenValue,::blueValue,static_cast<uint8_t>(pinColor::GREEN),static_cast<uint8_t>(pinColor::BLUE),delayTime);

  //Change LED from blue to red.
  changeLEDColor(::blueValue,::redValue,static_cast<uint8_t>(pinColor::BLUE),static_cast<uint8_t>(pinColor::RED),delayTime);
}

