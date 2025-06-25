namespace {
  enum PinColor:uint8_t{
    BLUE=3,
    GREEN=5,
    RED=6
  };

  //LED Color Values
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
  pinMode(PinColor::RED, OUTPUT);
  pinMode(PinColor::GREEN, OUTPUT);
  pinMode(PinColor::BLUE, OUTPUT);

  digitalWrite(PinColor::RED, HIGH);
  digitalWrite(PinColor::GREEN, LOW);
  digitalWrite(PinColor::BLUE, LOW);
}


//Main loop
void loop(){
  constexpr unsigned long delayTime{10}; //Transition time between LED color fades.
  
  //Change LED from red to green.
  changeLEDColor(::redValue,::greenValue,PinColor::RED,PinColor::GREEN,delayTime);

  //Change LED from green to blue.
  changeLEDColor(::greenValue,::blueValue,PinColor::GREEN,PinColor::BLUE,delayTime);

  //Change LED from blue to red.
  changeLEDColor(::blueValue,::redValue,PinColor::BLUE,PinColor::RED,delayTime);
}

