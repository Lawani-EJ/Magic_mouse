int buttonCounter = 0; // Stores the count
bool button1Pressed = false; // Prevents multiple increments on one press
bool button2Pressed = false; 
bool button3Pressed = false; // Prevents multiple prints of "repeat" 

void setup() {
  pinMode(2, INPUT_PULLUP); // Button 1 (Increase counter)
  pinMode(3, INPUT_PULLUP); // Button 2 (Print counter)
  pinMode(4, INPUT_PULLUP); // Button 3 (Print "repeat")
  Serial.begin(9600);
}

void loop() {
  // Read button states
  int button1State = digitalRead(2);
  int button2State = digitalRead(3);
  int button3State = digitalRead(4);

  // 🔹 Button 1: Increment counter (Only when pressed)
  if (button1State == LOW && !button1Pressed) {
    delay(50); // Debounce delay
    if (digitalRead(2) == LOW) { // Check again to confirm press
      if (buttonCounter >= 3) { 
        buttonCounter = 4;
      } else {
        buttonCounter++;  
      }
      button1Pressed = true; // Prevents multiple counts on a single press
    }
  }
  if (button1State == HIGH) {
    button1Pressed = false; // Reset when button is released
  }

  // 🔹 Button 2: Print counter OR "next"
  if (button2State == LOW && !button2Pressed) {  
    delay(50); // Debounce delay
    if (digitalRead(3) == LOW) { // Confirm press
      if (buttonCounter > 0) {
        Serial.println(buttonCounter);
        buttonCounter = 0; // Reset only after printing counter
      } else {
        Serial.println("next");
      }
      button2Pressed = true;
    }
  }
  if (button2State == HIGH) {
    button2Pressed = false; // Reset when button is released
  }

  // 🔹 Button 3: Print "repeat" only once per press
  if (button3State == LOW && !button3Pressed) { 
    delay(50); // Debounce delay
    if (digitalRead(4) == LOW) { // Confirm press
      Serial.println("repeat");
      button3Pressed = true;
    }
  }
  if (button3State == HIGH) {
    button3Pressed = false; // Reset when button is released
  }
}
