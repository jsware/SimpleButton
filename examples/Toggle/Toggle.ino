/**
 * @file
 * Example clicked callback from a button. The built-in LED lights on/off when a
 * button connected between pin 2 and ground is clicked (pressed and released).
 * Uses the internal pull-up resistor within an Arduino for the simplest button
 * connection.
 * 
 * @copyright Copyright (c) 2022 John Scott
 */
#include <AbleButtons.h>

// Identify which buttons you are using...
using Button = AblePullupButton; ///< Using basic pull-up button.
using ButtonList = AblePullupButtonList; ///< Using basic pull-up button list.

#define BUTTON_PIN 2 ///< Connect button between this pin and ground.
Button btn(BUTTON_PIN); ///< The button to check.

bool led=false; ///< On/off state of the LED.

/**
 * Setup the Toggle example. Called once to initialise everything.
 */
void setup() {
  btn.begin();
  pinMode(LED_BUILTIN, OUTPUT);
}

/**
 * Control the Toggle example. Called repeatedly in a loop.
 */
void loop() {
  btn.handle();

  if(btn.resetClicked()) {
    led = !led;
    digitalWrite(LED_BUILTIN, led);
  }
}
