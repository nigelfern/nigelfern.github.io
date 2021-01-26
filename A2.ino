/*
 * Nigel Fernandes
 * A2 Fade
 * HCDE 439
 * 1/23/21

  Makes RGB LED turn on and then fade off; also has yellow LED turn off while button is held down (stays on until button is pressed).
*/
const int buttonPin = 10;     // the number of the pushbutton pin
const int ledPin =  11;      // the number of the Yellow LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(3, OUTPUT); // initialize digital pin 3 as an output.
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  // set initial LED state
}

void loop() {
  //loops through fade sequence and checks for change of button state
  for(int i = 0; i<512; i++){ //256*2 = 512
    // first half of fade sequence
    if (i<256) {
      analogWrite(3, i); //blue pin
      delay(10); //delays for 10 miliseconds
    }
    //second half of fade sequence
    else {
      analogWrite(3, 512-i); //blue pin
      delay(10); //delays for 10 miliseconds
    }
    // read the state of the pushbutton value:
    buttonState = digitalRead(buttonPin);
    // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    if (buttonState == HIGH) {
      // turn LED on:
      digitalWrite(ledPin, HIGH);
    } else {
      // turn LED off:
      digitalWrite(ledPin, LOW);
    }
  }
}
