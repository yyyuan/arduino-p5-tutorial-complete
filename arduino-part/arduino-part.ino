//  https://learn.sparkfun.com/tutorials/sik-experiment-guide-for-arduino---v32/experiment-2-reading-a-potentiometer
// https://www.arduino.cc/en/tutorial/fade

const int led1Pin =  9; 
const int led2Pin = 10;// LED pin
const int sensorPin = 0; 
int brightness = 0;    // how bright the LED is
int led2brightness = 0;
int incomingByte; 

void setup() {
  // Set up the LED pin to be an output:
  pinMode(led1Pin, OUTPUT);     
  Serial.begin(9600); 
}


void loop() {
  int sensorValue;
  sensorValue = analogRead(sensorPin); 
  brightness = map(sensorValue, 0, 1023, 0, 255); 

  Serial.write(brightness);
  
  if (sensorValue >= 0) {
    analogWrite(led1Pin, brightness);  // turn the LED on
  }
  else{
    digitalWrite(led1Pin, LOW);  // turn the LED off
  }
  
  if (Serial.available() > 0) {   // see if there's incoming serial data
   incomingByte = Serial.read(); // read it
   led2brightness = map(incomingByte, 0, 255, 0, 255); 
   } else {
      //led2brightness = 0;
   }
   
   analogWrite(led2Pin, led2brightness); 
 
}
