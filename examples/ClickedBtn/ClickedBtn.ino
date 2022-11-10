/**
 * @filele-
 * Example clicked callback from a button. The built-in LED lights on/off when a
 * button connected between pin 2 and ground is clicked (pressed and released).
 * Uses the internal pull-up resistor within an Arduino for the simplest button
 * connection.
 * 
 * @copyright Copyright (c) 2022 John Scott
 */
#include <AbleButtons.h>

// Identify which buttons you are using...
using Button = AblePullupClickerButton;
using ButtonList = AblePullupClickerButtonList;

#define BUTTON_PIN 2 ///< Connect button between this pin and ground.
Button btn(BUTTON_PIN);
bool led=LOW;

/**
 * Setup the ClickedBtn example. Called once to initialise everything.
 */
void setup() {
  btn.begin();
  pinMode(LED_BUILTIN, OUTPUT);
}

/**
 * Control the ClickedBtn example. Called repeatedly in a loop.
 */
void loop() {
  btn.handle();

  if(btn.resetClicked()) {
    led = !led;
    digitalWrite(LED_BUILTIN, led);
  }
}
