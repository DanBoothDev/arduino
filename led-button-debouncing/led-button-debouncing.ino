/*
    LED toggle with Pushbutton including simple debouncing

    Turns an LED on when a button is pressed.

    The circuit:
    * Input  - Pushbutton connected to pin #7
    * Output - LED connected to pin #13

    Created AUG 2017
    By Dan Booth
*/

const int LED = 13;                 // pin for the LED
const int BUTTON = 7;               // pin for the pushbutton
const int TRANSITION_DELAY = 10;    // millisecond delay for the pushbutton bouncing

int buttonVal = 0;      // current button state
int prevButtonVal = 0;  // previous button state
int ledState = 0;       // led state - 0=off, 1=on

void setup() {
    pinMode(LED, OUTPUT);   // set the LED is an output
    pinMode(BUTTON, INPUT); // set the BUTTON is an input
}

void loop(){
    buttonVal = digitalRead(BUTTON);  // get the current value of the button
    
    // check for a transition from low to high
    if ((buttonVal == HIGH) && (prevButtonVal == LOW)){
        ledState = 1 - ledState;
        delay(TRANSITION_DELAY);
    }
    prevButtonVal = buttonVal;

    if (ledState == 1) {
        digitalWrite(LED, HIGH);  // turn LED on
    } else {
        digitalWrite(LED, LOW);  // turn LED off
    }
}
