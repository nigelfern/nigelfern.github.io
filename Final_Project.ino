#include "DHT.h"
/*
 * Nigel Fernandes
 * Final Project Plant Stand
 * HCDE 439
 * 3/13/21

Detects light exposure, heat, and humidity in a potted plant's environment. 
Red LED turns on when temperature exceeds 78 degrees F
Yellow LED turns on when exposed to partial and direct sunlight.
 */
#define DHTPIN 10    //sets pin for temp and humidity sensor signals  
#define DHTTYPE DHT11 // defines DHT sensor
DHT dht(DHTPIN, DHTTYPE); //initializes DHT sensor

int photoresPin = 0;     // photoresistor and 10K resistor are connected to A0
int photoresReading;    // raw numerical reading from LDR
int tempLED = 9;  // red LED in pin 9
int lightLED = 5; // yellow LED is in pin 5

void setup() {
  Serial.begin(9600); //begins serial
  Serial.println(F("DHTxx test!")); //prints test statements
  pinMode(tempLED, OUTPUT); //sets pin 9 as output
  pinMode(lightLED, OUTPUT); //sets pin 5 as output
  dht.begin(); // start DHT sensor
} 
 
void loop(void) {
  float h = dht.readHumidity(); // stores humidity reading
  float t = dht.readTemperature();     // stores temperature reading
  float f = dht.readTemperature(true); // stores temperature reading as F
  if (isnan(h) || isnan(t) || isnan(f)) { //checks sensor connection
    Serial.println(F("Failed to read from DHT sensor!")); //prints error message
    return;
  }
   // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  //Prints formatted reading from DHT sensor so that values are formatted correctly
  Serial.print(F(" Humidity: "));
  Serial.print(h); //value for humidity
  Serial.print(F("%  Temperature: "));
  Serial.print(t); //value for temp in C
  Serial.print(F("C "));
  Serial.print(f); //value for temp in F
  Serial.print(F("F  Heat index: "));
  Serial.print(hic); //value for heat index in C
  Serial.print(F("C "));
  Serial.print(hif); //value for heat index in F
  Serial.println(F("F"));
  Serial.println();
  delay(500); // waits 0.5 seconds

  // 78 degrees F is my determined warning temperature from when the environment would potentially be too hot for my plants.
  if (f > 78) { 
   Serial.println("Too Hot"); //prints warning message
   digitalWrite(tempLED, HIGH); //turns on red LED
   Serial.println(f); //prints temp
  } else if (f <= 78) { //if less than 78 deg
   Serial.println("Safe Temp"); //prints safe message
   digitalWrite(tempLED, LOW); //turns off red LED
   Serial.println(f); //prints temp
  }
    // stores readings from A0
    photoresReading = analogRead(photoresPin);  
    Serial.println(photoresReading); //prints LDR value
    // if reading is less than 100
    if (photoresReading < 100) {
      Serial.println("Very Dark"); // Serial monitor prints Very Dark
      digitalWrite(lightLED, LOW); // turns off yellow LED
    } else if (photoresReading < 400) { // if reading is less than 400
      digitalWrite(lightLED, LOW); // turns off yellow LED
      Serial.println("Dim"); // Serial monitor prints Dim
    } else if (photoresReading < 650) { // if reading is less than 650
      Serial.println("Bright"); // Serial monitor prints Bright
      digitalWrite(lightLED, HIGH); //turns on yellow LED
    } else { // if readings are greater than 650
      Serial.println("Very bright"); // Serial monitor prints Very bright
      digitalWrite(lightLED, HIGH); //turns on yellow LED
    }   
    delay(1000); // waits one second
}
