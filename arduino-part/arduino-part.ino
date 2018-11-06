/*
  Code References:
  https://learn.sparkfun.com/tutorials/sik-experiment-guide-for-arduino---v32/experiment-2-reading-a-potentiometer
  https://www.arduino.cc/en/tutorial/fade
*/

// set up pins for LEDs and potentiometer
const int led1Pin =  9;   // analog pin 9
const int led2Pin = 10;   // analog pin 10
const int sensorPin = 0;    // analog pin A0

int brightness = 0;    // how bright the first LED is
int led2brightness = 0;   // how bright the second LED is
int incomingByte;   // variable for holding the data from p5.js

void setup() {
  // set up the LED pin to be an output:
  pinMode(led1Pin, OUTPUT);
  // initialize the serial port for communication
  Serial.begin(9600);
}

void loop() {
  // read from potentiometer
  int sensorValue;
  sensorValue = analogRead(sensorPin);
  brightness = map(sensorValue, 0, 1023, 0, 255);   // map sensor value to brightness

  // write the changed brighntess for first LED to p5.js
  Serial.write(brightness);

  // Actually change output to the first LED based on changes in potential meter
  if (sensorValue >= 0) {
    analogWrite(led1Pin, brightness);  // turn the LED on with certain brightness
  } else{
    digitalWrite(led1Pin, LOW);  // turn the LED off
  }

  // read the input from p5.js and use that data to controle the second LED light
  if (Serial.available() > 0) {   // see if there's incoming serial data
   incomingByte = Serial.read();  // read it and store it in the variable
   led2brightness = map(incomingByte, 0, 255, 0, 255);  // map the incoming value to brightness
   } else { }

   // write the input brightness value to the second LED
   analogWrite(led2Pin, led2brightness);
}
