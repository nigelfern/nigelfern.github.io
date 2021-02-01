/*
 * Nigel Fernandes
 * A3 Input/Output
 * HCDE 439
 * 1/29/21

Changes LED brightness based on readings from a photoresistor. 
LED gets brighter in darker environments and dimmer in brighter environments.
 */
 
int photoresPin = 0;     // photoresistor and 10K resistor are connected to A0
int photoresReading;     // analog reading
int LEDpin = 9;          // Blue LED is in pin 9
int LEDbrightness;       // how bright the LED is (0-255)
void setup(void) {
  // Serial monitor contains messages and details on info collected by sensor
  Serial.begin(9600);   
}
 
void loop(void) {
  // stores readings from A0
  photoresReading = analogRead(photoresPin);  

  // if readings is less than 200
  if (photoresReading < 200) {
    Serial.println("Dark"); // Serial monitor prints Dark
  } else if (photoresReading < 400) { // if readings is less than 400
    Serial.println("Dim"); // Serial monitor prints Dim
  } else if (photoresReading < 700) { // if readings is less than 700
    Serial.println("Bright"); // Serial monitor prints Bright
  } else { // if readings are greater than 700
    Serial.println("Very bright"); // Serial monitor prints Very bright
  }
 
  // LED gets brighter based on how dark the environment around the photoresistor is
  photoresReading = 1023 - photoresReading; // invert reading from 0-1023 to 1023-0
  //maps 0-1023 to 0-255 to fit analogWrite range
  LEDbrightness = map(photoresReading, 0, 1023, 0, 255);
  
  Serial.print("brightness = "); // Serial monitor prints LED's brightness
  Serial.println(LEDbrightness); // brightness amount
  analogWrite(LEDpin, LEDbrightness); // sends brightness amount to LED
 
  delay(300); // waits 300 milliseconds
}
