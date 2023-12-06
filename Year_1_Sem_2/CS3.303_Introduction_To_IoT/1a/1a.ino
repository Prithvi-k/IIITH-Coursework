int ledPin = 2; // LED Pin number

void setup() {
  pinMode(ledPin, OUTPUT); // Set LED Pin as output
}

void loop() {
  digitalWrite(ledPin, LOW); // Turn LED OFF
  delay(1000); // Wait for 1 second
  digitalWrite(ledPin, HIGH); // Turn LED ON
  delay(1000); // Wait for 1 second
}