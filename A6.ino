/*
 * Nigel Fernandes
 * A6 Talking to the Web
 * HCDE 439
 * 3/1/21

Changes LED brightness based on movements of the joystick. 
The corresponding JS code awaits a spacebar keypress, which activates the joysticks and sends back data
*/

void setup() {
 Serial.begin(9600);    // initialize serial communications
 Serial.setTimeout(10); // set the timeout for parseInt
 pinMode(5, OUTPUT); // set Pin 5 for output
}

//This loop receives, reads, and sends data to webpage. The LED's brightness is determined by the X-coordinate of the Joystick
// The data is sent back to the Arduino after a spacebar keypress (ASCII code 32) is detected by the JS code
void loop() {
 if (Serial.available() > 0) {   // if there's serial data 
     int inByte = Serial.read(); // read it
     Serial.write(inByte);      // send it back out as raw binary data
     analogWrite(5, inByte);    // use it to set the LED brightness
 }
}
