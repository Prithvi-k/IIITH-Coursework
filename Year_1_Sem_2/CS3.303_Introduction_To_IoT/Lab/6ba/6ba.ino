#include "BluetoothSerial.h"

const int trigPin = 27;
const int echoPin = 13;

// Define the speed of sound and conversion measurements
const float speedOfSound = 331; // m/s
const float inchesPerMeter = 39.37;
const float cmPerMeter = 100;

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP32Ultra"); // Set the name of the device
  Serial.println("Bluetooth Serial started!");

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
   
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
  
    // Measure the duration of sound wave travel using pulseIn() function
    long duration = pulseIn(echoPin, HIGH);
    
    // Calculate the distance in meters, inches, and centimeters
    float distanceMeters = duration * 0.5 * speedOfSound / 1000000;
    float distanceInches = distanceMeters * inchesPerMeter;
    float distanceCm = distanceMeters * cmPerMeter;

    String ans = String(distanceCm);
    // If there's data available on the serial monitor, read it and send it to the Bluetooth serial port
    if (Serial.available()) {
    // If there's data available on the serial monitor, read it and send it to the Bluetooth serial port
    for(int i = 0; i < strlen(ans.c_str()); i++) {
      char data = ans[i];
      SerialBT.write(data);
    }
    SerialBT.write('\n');
  }  
    delay(500);
}


