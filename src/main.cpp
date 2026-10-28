/*
 * Basic Arduino Template - Blink
 * ------------------------------
 * Blinks an LED connected to pin 13, once per second.
 *
 * Wiring: plug the LED straight into the top header of the UNO.
 *   - long leg  (+, anode)   -> pin 13
 *   - short leg (-, cathode) -> GND (right next to pin 13)
 *   (a 220 ohm resistor in series is the safer habit for LEDs)
 * The UNO's built-in "L" LED is also on pin 13, so it blinks too.
 *
 *              _____
 *             /     \
 *             | LED |
 *             |_____|
 *              |   |
 *          (-) |   | (+)
 *       short  |   |  long leg
 *   +----------|---|--------------------------------+
 *   |  AREF  GND  13   12   11   10    9    8      |
 *   |                                               |
 *   |  [USB]          ARDUINO UNO                   |
 *   |                                               |
 *   |  [PWR]                                        |
 *   +-----------------------------------------------+
 *
 * Every Arduino sketch has two required functions:
 *   setup() -> runs ONCE when the board powers on or is reset
 *   loop()  -> runs AGAIN AND AGAIN, forever, after setup() finishes
 *
 * In PlatformIO (unlike the Arduino IDE) we must include Arduino.h
 * ourselves. It gives us pinMode(), digitalWrite(), delay(), etc.
 */
#include <Arduino.h>

// ---------------------------------------------------------------------------
// Global variables
// Declared OUTSIDE any function, so setup(), loop() and any other
// function can use them. Their values are kept between loop() runs.
// ---------------------------------------------------------------------------

// The pin our LED is connected to. "const" means it can never change.
const int ledPin = 13;

// An "int" stores a whole number (no decimals), e.g. -3, 0, 500.
// Here it holds how long the LED stays on/off, in milliseconds.
int blinkDelay = 500;

// A "bool" (boolean) stores only two values: true or false.
// It remembers whether the LED should be on (true) or off (false).
// We start with the LED off.
bool ledIsOn = false;

// ---------------------------------------------------------------------------
// A dummy function
// Functions let us give a name to a block of code and reuse it.
//   void          -> this function does not return any value
//   sayHello      -> the function's name
//   ()            -> it takes no inputs (parameters)
// It isn't needed for blinking - it's here to show how functions work.
// ---------------------------------------------------------------------------
void sayHello()
{
  Serial.println("Hello from sayHello()!");
}

// ---------------------------------------------------------------------------
// setup(): runs once at the start
// ---------------------------------------------------------------------------
void setup()
{
  // Tell the board that ledPin is an OUTPUT (we send voltage out of it).
  pinMode(ledPin, OUTPUT);

  // Start serial communication at 9600 baud so we can print messages.
  // Open the PlatformIO Serial Monitor to read them (speed must match:
  // see monitor_speed in platformio.ini).
  Serial.begin(9600);

  // Call (use) our dummy function.
  sayHello();
}

// ---------------------------------------------------------------------------
// loop(): runs forever
// ---------------------------------------------------------------------------
void loop()
{
  // Flip the boolean: "!" means NOT, so true becomes false and
  // false becomes true. Each time loop() runs, the state swaps.
  ledIsOn = !ledIsOn;

  // Use the boolean to decide what to do.
  if (ledIsOn)
  {
    digitalWrite(ledPin, HIGH); // HIGH = 5V on the pin -> LED on
    Serial.println("LED is ON");
  }
  else
  {
    digitalWrite(ledPin, LOW); // LOW = 0V on the pin -> LED off
    Serial.println("LED is OFF");
  }

  // Wait blinkDelay milliseconds before loop() runs again.
  delay(blinkDelay);
}
