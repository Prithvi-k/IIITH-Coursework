// Define the analog input pins for current and voltage
const int currentPin = 32;
const int voltagePin = 35;

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
}

void loop() {
  // Read the current and voltage values
  float current = analogRead(currentPin) * (3.3 / 4095.0); // Scale the reading based on the ESP32's reference voltage
  float voltage = analogRead(voltagePin) * (3.3 / 4095.0); // Scale the reading based on the ESP32's reference voltage

  // Print the current and voltage values
  Serial.print("Current: ");
  Serial.print(current);
  Serial.println(" A");

  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  delay(1000); // Wait for a second
}
