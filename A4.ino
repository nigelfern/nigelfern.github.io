/*
 * Nigel Fernandes
 * A4 Libraries
 * HCDE 439
 * 2/15/21

Changes LED brightness based on received signals from Remote.
LED gets brighter when higher numbers are pressed and is less bright when lower numbers are pressed.
*/

/*
 * Specify which protocol(s) should be used for decoding.
 * If no protocol is defined, all protocols are active.
 */
#define DECODE_NEC 1

#include <IRremote.h>

int IR_RECEIVE_PIN = 11;
const int ledPin =  6;

void setup() {
  pinMode(6, OUTPUT); // initialize pin 6 as an output.
    Serial.begin(115200);
    // Prints the program that is running
    Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));

    /*
     * Start the receiver, enable feedback LED and take LED feedback pin from the internal boards definition
     */
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);//, USE_DEFAULT_FEEDBACK_LED_PIN);

    Serial.print(F("Ready to receive IR signals at pin ")); //Prints that the Arduino is ready to receive from remote
    Serial.println(IR_RECEIVE_PIN); //prints the pin number where signals are received at
}

void loop() {
    /*
     * Check if received data is available and if yes, try to decode it.
     * 
     */
    if (IrReceiver.decode()) {
        switch (IrReceiver.decodedIRData.command) {//Decoded result is in the IrReceiver.decodedIRData structure.
          case 0x45: Serial.println("Power button"); //Prints which button is pressed
          digitalWrite(ledPin, HIGH); //turns on red LED
             break;
          case 0x47: Serial.println("Func/Stop"); //Prints which button is pressed
          digitalWrite(ledPin, LOW); //turns off red LED
             break;
          case 0x0C: Serial.println("1"); //Prints which button is pressed
          analogWrite(ledPin, 10); // Sends appropriate amount of brightness based on which button is pressed
             break;
          case 0x18: Serial.println("2"); //Prints which button is pressed
          analogWrite(ledPin, 40); // Sends appropriate amount of brightness based on which button is pressed
             break;
          case 0x5E: Serial.println("3"); //Prints which button is pressed
          analogWrite(ledPin, 70); // Sends appropriate amount of brightness based on which button is pressed
             break;
          case 0x08: Serial.println("4"); //Prints which button is pressed
          analogWrite(ledPin, 100); // Sends appropriate amount of brightness based on which button is pressed
             break;
          case 0x1C: Serial.println("5"); //Prints which button is pressed
          analogWrite(ledPin, 130); // Sends appropriate amount of brightness based on which button is pressed
             break;
          case 0x5A: Serial.println("6"); //Prints which button is pressed
          analogWrite(ledPin, 160); // Sends appropriate amount of brightness based on which button is pressed
             break;
          case 0x42: Serial.println("7"); //Prints which button is pressed
          analogWrite(ledPin, 190); // Sends appropriate amount of brightness based on which button is pressed
             break;
          case 0x52: Serial.println("8"); //Prints which button is pressed
          analogWrite(ledPin, 220); // Sends appropriate amount of brightness based on which button is pressed
             break;
          case 0x4A: Serial.println("9"); //Prints which button is pressed
          analogWrite(ledPin, 250); // Sends appropriate amount of brightness based on which button is pressed
             break;
        }
        IrReceiver.resume(); // Enable receiving of the next value      
    }
}
