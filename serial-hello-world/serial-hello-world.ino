/*
    Serial comms - hello world

    Connects to a serial port and prints a message

    Created NOV 2017
    By Dan Booth
*/

const int BAUD_RATE = 9600; // speed to connect to
const int DELAY = 1000;     // delay after printing a message

void setup() {
    // open a serial port
    Serial.begin(BAUD_RATE);
}

void loop() {
    Serial.println("Hello World");
    delay(DELAY);
}