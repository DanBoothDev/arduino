/*
    LED Button

    Turns an LED on when a button is pressed.

    The circuit:
    * Input  - Pushbutton connected to pin #7
    * Output - LED connected to pin #13

    Created AUG 2017
    By Dan Booth
*/

const int LED = 13;     // pin for the LED
const int BUTTON = 7;   // pin for the pushbutton

int buttonVal = 0;    // input pin state

void setup() {
    pinMode(LED, OUTPUT);   // set the LED is an output
    pinMode(BUTTON, INPUT); // set the BUTTON is an input
}

void loop(){
    buttonVal = digitalRead(BUTTON);  // get the current value of the button
    if (buttonVal == HIGH) {
        // button pressed
        digitalWrite(LED, HIGH);  // turn LED on
    } else {
        // button has not been pressed
        digitalWrite(LED, LOW);  // turn LED off
    }
}