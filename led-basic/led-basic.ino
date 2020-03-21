/*
	LED Blinker

    Turns an LED on, waits for a period of time then turns it off

	The circuit:
	* Output - LED connected to pin #13

	Created 20 AUG 2017
	By Dan Booth

*/

const int LED = 13;         // the pin for the LED
const int ON_DELAY = 1000;  // milliseconds to keep LED on
const int OFF_DELAY = 1000; // milliseconds to keep LED off

void setup()
{
    pinMode(LED, OUTPUT);   // set the digital pin as output
}

void loop()
{
    digitalWrite(LED, HIGH);    // turn the LED on
    delay(ON_DELAY);            // wait for ON_DELAY to hold the LED on

    digitalWrite(LED, LOW);     // turn the LED off
    delay(OFF_DELAY);           // wait for OFF_DELAY to hold the LED off
}