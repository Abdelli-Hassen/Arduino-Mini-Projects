// Define the pins for the RGB LED
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

// Define the pin for the push button
const int buttonPin = 2;

// Variables to hold the state of the button and the current color
int buttonState = 0;
int lastButtonState = 0;
int colorIndex = 0;

// Define the colors (R, G, B)
int colors[][3] = {
  {255, 0, 0}, // Red
  {0, 255, 0}, // Green
  {0, 0, 255}, // Blue
  {255, 255, 0}, // Yellow
  {0, 255, 255}, // Cyan
  {255, 0, 255}, // Magenta
  {255, 255, 255}, // White
  {0, 0, 0} // Off
};

void setup() {
  // Set the RGB LED pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Set the push button pin as input
  pinMode(buttonPin, INPUT);

  // Initialize the RGB LED to off
  setColor(0, 0, 0);
}

void loop() {
  // Read the state of the push button
  buttonState = digitalRead(buttonPin);

  // Check if the button is pressed
  if (buttonState == HIGH && lastButtonState == LOW) {
    // Move to the next color
    colorIndex = (colorIndex + 1) % 8;
    setColor(colors[colorIndex][0], colors[colorIndex][1], colors[colorIndex][2]);
  }

  // Save the current button state
  lastButtonState = buttonState;
  delay(70);
}

// Function to set the color of the RGB LED
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
