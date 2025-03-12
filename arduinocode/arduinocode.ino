const int button2 = 2;  // Button to increase counter
const int button3 = 3;  // Button to print counter & "Next"
const int button4 = 4;  // Button to print "Repeat"
const int button6 = 6; 
int counter = 0;          // Stores button counter value (0-4)
bool submitted = false;   // Tracks if counter has been printed

void setup() {
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP); 
  pinMode(button6, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  // Button 2: Increase counter (Max 4)
  if (digitalRead(button2) == LOW) {
    delay(300);  // Debounce
    counter++;
    if (counter > 4) {
      Serial.println("4");
    } else {
      Serial.println(counter);
    }
    while (digitalRead(button2) == LOW);  // Wait until button is released
  }

  // Button 3: Print counter
  if (digitalRead(button3) == LOW) {
    delay(300);  // Debounce
    Serial.println(counter);
    while (digitalRead(button3) == LOW);  // Wait until button is released
  }
 if (digitalRead(button6) == LOW) {
    delay(300);  // Debounce
    Serial.println("HHHHHHHHHHHHH");
    while (digitalRead(button6) == LOW);  // Wait until button is released
  }
  // Button 4: Print "Repeat"
  if (digitalRead(button4) == LOW) {
    delay(300);  // Debounce
    Serial.println("Repeat");
    while (digitalRead(button4) == LOW);  // Wait until button is released
  }

}
