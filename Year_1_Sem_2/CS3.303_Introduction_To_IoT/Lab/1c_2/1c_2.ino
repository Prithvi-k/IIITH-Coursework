int minLimit = 0; // Initial minimum limit
int maxLimit = 10; // Initial maximum limit
int iterationCount = 20; // Number of iterations

void setup() {
  Serial.begin(9600); // Begin serial communication
}

void loop() {
  // Generate a random number between the current min and max limits
  int randomNumber = random(minLimit, maxLimit);
  
  // Print the random number on the serial monitor
  Serial.println(randomNumber);
  
  // Increase the min and max limits by 10 for the next iteration
  minLimit += 10;
  maxLimit += 10;
  
  // Decrement the iteration count
  iterationCount--;
  
  // Stop the loop after 20 iterations
  if (iterationCount == 0) {
    while (true); // Stop the program
  }
  
  delay(1000); // Wait for 1 second before generating the next random number
}