//Description: Activates active buzzer to simulate heartbeat monitor.

namespace{
  namespace Buzzer{
    constexpr uint8_t pin{12};
    unsigned long soundDuration{500};
  }
}

void setup(){
  pinMode(::Buzzer::pin, OUTPUT); //Initialize the buzzer pin as an output.
}

void loop(){
  for(int i{0}; i<20; ++i) {
    //Adjust buzzer duration time.
    if(i<5){
      ::Buzzer::soundDuration=500;
    } 
    else if(i<10){
      ::Buzzer::soundDuration=300;
    } 
    else if(i<20){
      ::Buzzer::soundDuration=100;
    }

    //Activate the buzzer.
    digitalWrite(::Buzzer::pin, HIGH);

    delay(::Buzzer::soundDuration);

    //Deactivate the buzzer.
    digitalWrite(::Buzzer::pin, LOW);

    delay(::Buzzer::soundDuration);
  }
  
  //Activate the buzzer.
  digitalWrite(::Buzzer::pin, HIGH);

  delay(5000);//keep playing sound for 5 seconds.
}
