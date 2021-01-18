/*
 * Nigel Fernandes
 * A1 Blink
 * HCDE 439
 * 1/14/21

  Turns three different LED's on for 0.5 seconds, then off for 0.5 seconds, repeatedly.
*/

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(9, OUTPUT); // initialize digital pin 9 as an output.
  pinMode(10, OUTPUT); // initialize digital pin 10 as an output.
  pinMode(11, OUTPUT); // initialize digital pin 11 as an output.
}

// the loop function runs over and over again forever
void loop() {

  //Blue LED is mapped to pin 9
  digitalWrite(9, HIGH);   // turn the blue LED on (HIGH is the voltage level)
  delay(500);              // wait for 0.5 seconds
  digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
  delay(500);              // wait for 0.5 seconds

  //Yellow LED is mapped to pin 10
  digitalWrite(10, HIGH);   // turn the yellow LED on (HIGH is the voltage level)
  delay(500);               // wait for 0.5 seconds
  digitalWrite(10, LOW);    // turn the LED off by making the voltage LOW
  delay(500);               // wait for 0.5 seconds
  
  //Red LED is mapped to pin 11
  digitalWrite(11, HIGH);   // turn the red LED on (HIGH is the voltage level)
  delay(500);               // wait for 0.5 seconds
  digitalWrite(11, LOW);    // turn the LED off by making the voltage LOW
  delay(500);               // wait for 0.5 seconds
}
