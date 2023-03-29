void setup() {
  Serial.begin(9600); // Begin serial communication
}

void loop() {
  int randomNumber = random(0, 100); // Generate a random number between 0 and 100
  Serial.println(randomNumber); // Print the random number on the serial monitor
  delay(1000); // Wait for 1 second
}