// Define pins for the joystick
const int joyXPin = A0;  // Joystick X-axis
const int joyYPin = A1;  // Joystick Y-axis
const int joyButtonPin = 2; // Joystick button

// Define pins for the buttons labeled A, B, C, D, E, F
const int buttonAPin = 3;
const int buttonBPin = 4;
const int buttonCPin = 5;
const int buttonDPin = 6;
const int buttonEPin = 7;
const int buttonFPin = 8;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set up joystick button pin
  pinMode(joyButtonPin, INPUT_PULLUP);
  
  // Set up buttons pins
  pinMode(buttonAPin, INPUT_PULLUP);
  pinMode(buttonBPin, INPUT_PULLUP);
  pinMode(buttonCPin, INPUT_PULLUP);
  pinMode(buttonDPin, INPUT_PULLUP);
  pinMode(buttonEPin, INPUT_PULLUP);
  pinMode(buttonFPin, INPUT_PULLUP);
}

void loop() {
  // Read joystick axes
  int joyX = analogRead(joyXPin);
  int joyY = analogRead(joyYPin);
  
  // Read joystick button state
  bool joyButton = digitalRead(joyButtonPin) == LOW; // LOW when pressed
  
  // Read button states
  bool buttonA = digitalRead(buttonAPin) == LOW; // LOW when pressed
  bool buttonB = digitalRead(buttonBPin) == LOW; // LOW when pressed
  bool buttonC = digitalRead(buttonCPin) == LOW; // LOW when pressed
  bool buttonD = digitalRead(buttonDPin) == LOW; // LOW when pressed
  bool buttonE = digitalRead(buttonEPin) == LOW; // LOW when pressed
  bool buttonF = digitalRead(buttonFPin) == LOW; // LOW when pressed
  
  // Print joystick axes values
  Serial.print("Joystick X: ");
  Serial.print(joyX);
  Serial.print(" | Joystick Y: ");
  Serial.print(joyY);
  
  // Print joystick button state
  Serial.print(" | Joystick Button: ");
  Serial.print(joyButton ? "Pressed" : "Released");
  
  // Print buttons states
  Serial.print(" | Button A: ");
  Serial.print(buttonA ? "Pressed" : "Released");
  
  Serial.print(" | Button B: ");
  Serial.print(buttonB ? "Pressed" : "Released");
  
  Serial.print(" | Button C: ");
  Serial.print(buttonC ? "Pressed" : "Released");
  
  Serial.print(" | Button D: ");
  Serial.print(buttonD ? "Pressed" : "Released");
  
  Serial.print(" | Button E: ");
  Serial.print(buttonE ? "Pressed" : "Released");
  
  Serial.print(" | Button F: ");
  Serial.print(buttonF ? "Pressed" : "Released");
  
  Serial.println();
  
  // Small delay to stabilize readings
  delay(100);
}
