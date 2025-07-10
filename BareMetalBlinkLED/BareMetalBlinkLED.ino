//Description: Blinks LED on pin 5.

void setup() {
  //Set pin 5 to output.
  DDRB = DDRB | (1 << DDB5); 
}

void loop() {
  //Turn on LED.
  PORTB = PORTB | (1 << PORTB5);

  _delay_ms(1000);

  //Turn off LED.
  PORTB = PORTB & ~(1 << PORTB5);

  _delay_ms(1000);
}
