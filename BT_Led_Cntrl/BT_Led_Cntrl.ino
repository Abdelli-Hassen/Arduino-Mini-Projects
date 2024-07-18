// Define pins for LEDs, push button, and relay
const int led1Pin = 8;
const int led2Pin = 9;
const int led3Pin = 10;
const int buttonPin = 2;
const int relayPin = 7;

// Bluetooth module communication
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(0, 1); // RX | TX

// Variables
int buttonState = 0;
int relayState = LOW;

void setup() {
  // Initialize digital pins
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(relayPin, OUTPUT);
  
  // Start serial communication with Bluetooth
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  // Read the state of the push button
  buttonState = digitalRead(buttonPin);

  // Check if the button is pressed
  if (buttonState == HIGH) {
    // Toggle relay state
    relayState = !relayState;
    digitalWrite(relayPin, relayState);
    delay(250); // Debounce delay
  }

  // Check for Bluetooth commands
  if (BTSerial.available()) {
    char command = BTSerial.read();

    // Process commands
    switch (command) {
      case '1':
        digitalWrite(led1Pin, HIGH);
        break;
      case '2':
        digitalWrite(led2Pin, HIGH);
        break;
      case '3':
        digitalWrite(led3Pin, HIGH);
        break;
      case '0':
        digitalWrite(led1Pin, LOW);
        digitalWrite(led2Pin, LOW);
        digitalWrite(led3Pin, LOW);
        break;
      default:
        break;
    }
  }
}
