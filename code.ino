#include <Bounce.h>

// Define our two buttons. We are using the
// 3rd party "bounce" library to more reliably
// read the button clicks.
//
// Read more:
// https://www.pjrc.com/teensy/td_libs_Bounce.html
Bounce buttonTrue = Bounce(PIN_D4, 10);
Bounce buttonFalse = Bounce(PIN_B1, 10);

// Setup the two buttons with the pins we
// have connected to and make sure to
// make use of the internal pull-up circuitry
void setup() {
  pinMode(PIN_D4, INPUT_PULLUP); // True button
  pinMode(PIN_B1, INPUT_PULLUP); // False button
  pinMode(PIN_D6, OUTPUT); // LED
}

void loop() {
  buttonTrue.update();
  buttonFalse.update();

  // Our 'true' button; outputs a 't' keypress
  if (buttonTrue.fallingEdge()) {
   Keyboard.print("t");
    digitalWrite(PIN_D6, HIGH); // LED ON
  }
  if(buttonTrue.risingEdge()){
    digitalWrite(PIN_D6, LOW); // LED OFF
  }

  // Our 'false' button; outputs a 'f' keypress
  if (buttonFalse.fallingEdge()) {
    Keyboard.print("f");
    digitalWrite(PIN_D6, HIGH); // LED ON
  }
  if(buttonFalse.risingEdge()){
    digitalWrite(PIN_D6, LOW); // LED OFF
  }
}
