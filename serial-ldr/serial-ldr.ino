/*
    Serial comms - print LDR value

    Connects to a serial port and prints the value from a light-dependent resistor (LDR)

    The circuit:
    * Input - LDR conencted to analog pin #0

    Created NOV 2017
    By Dan Booth
*/

const int LDR = 0;          // pin for the LDR
const int BAUD_RATE = 9600; // comms speed
const int DELAY = 100;      // delay after the LDR value is printed
int sensorVal = 0;  // variable used to store the value coming from the sensor

void setup() {
    // open a serial port
    Serial.begin(BAUD_RATE);
}

void loop() {
    sensorVal = analogRead(LDR); // get the value from the sensor
    Serial.println(sensorVal); // print the sensor value
    delay(DELAY); // delay sendint too frequently
}