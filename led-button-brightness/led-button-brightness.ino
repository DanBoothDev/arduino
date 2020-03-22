/*
    LED toggle and change brightness with Pushbutton.

    Short press of button will turn the LED on/off.
    Long press of button will change the brightness of the LED.

    The circuit:
    * Input  - Pushbutton connected to pin #7
    * Output - LED connected to pin #9

    Created SEP 2017
    By Dan Booth
*/

const int LED = 9;                  // pin for the LED
const int BUTTON = 7;               // pin for the pushbutton
const int TRANSITION_DELAY = 10;    // millisecond delay for the pushbutton bouncing
const int BUTTON_HOLD_TIME = 500;    // millisecond delay for holding the pushbutton
const int BRIGHTNESS_MAX = 255;     // max. level of brightness for the LED
const int BRIGHTNESS_MIN = 0;       // min. level of brightness for the LED
const int BRIGHTNESS_OFF = 0;       // level of brightness that turns the LED off
const int BRIGHTNESS_DEFAULT = (int) BRIGHTNESS_MAX / 2; // default brightness level

int buttonVal = 0;      // current button state
int prevButtonVal = 0;  // previous button state
int ledState = 0;       // led state - 0=off, 1=on
int brightness = BRIGHTNESS_DEFAULT; // current brightness value
unsigned long startTime = 0; // when did we begin pressing?

void setup() {
    pinMode(LED, OUTPUT);   // set the LED is an output
    pinMode(BUTTON, INPUT); // set the BUTTON is an input
}

void loop(){
    buttonVal = digitalRead(BUTTON);  // get the current value of the button
    
    // check for a transition from low to high
    if (isButtonTransition(buttonVal, prevButtonVal)) {
        ledState = 1 - ledState; // toggle the LED state
        startTime = millis(); // note when button is pressed
        delay(TRANSITION_DELAY);
    }

    // check whether the button is being held down
    if (isButtonHeld(buttonVal, prevButtonVal)){
        // check if button is held longer then BUTTON_HOLD_TIME ms
        if (ledState == 1 && (millis() - startTime) > BUTTON_HOLD_TIME) {
            brightness++; // increment brightness
            delay(TRANSITION_DELAY); // delay to prevent brightness increasing too quickly
            // reset brightness if required
            if (brightness > BRIGHTNESS_MAX) {
                brightness = BRIGHTNESS_MIN; // revert back to the min.
            }
        }
    }
    prevButtonVal = buttonVal;

    if (ledState == 1) {
        setLedBrightness(brightness); // turn LED on at current brightness
    } else {
        setLedBrightness(BRIGHTNESS_OFF); // turn LED off
    }
}

bool isButtonTransition(int buttonVal, int prevButtonVal) {
    /*
    Returns True if the button transition is from HIGH to LOW
    */
    return (buttonVal == HIGH) && (prevButtonVal == LOW);
}

bool isButtonHeld(int buttonVal, int prevButtonVal) {
    /*
    Returns True if the button state remains HIGH
    */
    return (buttonVal == HIGH) && (prevButtonVal == HIGH);
}

void setLedBrightness(int brightness) {
    /*
    Sets the LED brightness
    */
    analogWrite(LED, brightness);
}