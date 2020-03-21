/*
    LED breathe

    Fades an LED in and out.

    The circuit:
    * Output - LED connected to pin #9

    Created SEP 2017
    By Dan Booth
*/

const int LED = 9;                  // pin for the LED
const int LED_BRIGHTNESS_MIN = 0;   // minimum brightness for the LED
const int LED_BRIGHTNESS_MAX = 255; // maximum brightness for the LED
const int LED_DELAY = 10;           // delay after the LED brightness is adjusted


int level = 0; // used to set the power level

void setup() {
    pinMode(LED, OUTPUT); // set the LED is an output
}
void loop(){
    // fade in
    for (level = LED_BRIGHTNESS_MIN; level < LED_BRIGHTNESS_MAX; level++) {
        analogWrite(LED, level); // set the LED brightness
        delay(LED_DELAY); // delay to make change visible
    }

    // fade out
    for (level = LED_BRIGHTNESS_MAX; level > LED_BRIGHTNESS_MIN; level--) {
        analogWrite(LED, level); // set the LED brightness
        delay(LED_DELAY); // delay to make change visible
    }
}