int ledPin = 2; // LED Pin number
int delayTime = 1000; // Initial delay time in milliseconds
bool decreasingDelay = false; // Flag to indicate decreasing delay

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {

  digitalWrite(ledPin, LOW);
  delay(delayTime);
  digitalWrite(ledPin, HIGH);
  delay(1000);
  
  // Check if we need to decrease the delay time
  if (delayTime == 5000) {
    decreasingDelay = true;
  }
  
  // Increase or decrease the delay time based on the flag
  if (!decreasingDelay) {
    delayTime += 1000;
  } else {
    delayTime -= 1000;
  }
  
  // Reset the flag if the delay time becomes 0
  if (delayTime == 0) {
    decreasingDelay = false;
  }
}