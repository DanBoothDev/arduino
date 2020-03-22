/*
    LED LDR Blink

    Uses a Light-dependent resistor (LDR) connected an analog input to 
    change the blink rate of an LED.

    The circuit:
    * Input - LDR conencted to analog pin #0
    * Output - LED connected to pin #13

    Created SEP 2017
    By Dan Booth
*/

const int LED = 13;     // pin for the LED
const int LDR = 0;      // pin for the LDR
int sensorVal = 0;  // variable used to store the value coming from the sensor

void setup() {
    pinMode(LED, OUTPUT);   // set the LED is an output
}

void loop() {
    sensorVal = analogRead(LDR); // get the value from the sensor

    digitalWrite(LED, HIGH); // turn the LED on
    delay(sensorVal); // delay for a period of time

    digitalWrite(LED, LOW); // turn the LED off
    delay(sensorVal); // delay for a period of time
}
