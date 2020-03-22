/*
    LED LDR Brightness

    Uses a light-dependent resistor (LDR) connected an analog input to 
    change the brightness of an LED.

    The circuit:
    * Input - LDR conencted to analog pin #0
    * Output - LED connected to pin #13

    Created SEP 2017
    By Dan Booth
*/

const int LED = 13;     // pin for the LED
const int LDR = 0;      // pin for the LDR
const int DELAY = 10;   // delay after the LED brightness is adjusted
int sensorVal = 0;  // variable used to store the value coming from the sensor

void setup() {
    pinMode(LED, OUTPUT); // set the LED is an output
}

void loop() {
    sensorVal = analogRead(LDR); // get the value from the sensor
    analogWrite(LED, getAnalogBrightness(sensorVal)); // turn the LED on and set the brightness
    delay(DELAY); // delay for a period of time to see the change 
}

int getAnalogBrightness(int readVal) {
    // returns readVal divided by 4, because:
    //  analogRead() returns 0-1023, and
    //  analogWrite() accepts max. of 255
    return (int) readVal/4;
}