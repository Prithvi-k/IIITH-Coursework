// Define the trigger and echo pins
const int trigPin = 27;
const int echoPin = 13;

// Define the speed of sound and conversion measurements
const float speedOfSound = 331; // m/s
const float inchesPerMeter = 39.37;
const float cmPerMeter = 100;

void setup() {
  // Start the serial communication
  Serial.begin(9600);
  
  // Define trigger pin as output and echo pin as input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Set trigger pin high for 10 microseconds and set it back to low
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of sound wave travel using pulseIn() function
  long duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in meters, inches, and centimeters
  float distanceMeters = duration * 0.5 * speedOfSound / 1000000;
  float distanceInches = distanceMeters * inchesPerMeter;
  float distanceCm = distanceMeters * cmPerMeter;

  // Display the distance readings on the serial monitor
  Serial.print("Distance in inches: ");
  Serial.print(distanceInches);
  Serial.print(" | Distance in cm: ");
  Serial.println(distanceCm);
  
  // Wait for 500 milliseconds before taking the next reading
  delay(500);
}