#include "BluetoothSerial.h"

const int trigPin = 27;
const int echoPin = 13;
const int buzzer = 4;
int playing = 0;
int threshold = 99999;

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
  pinMode(buzzer,OUTPUT);
}

void tone(byte pin, int freq) {
  ledcSetup(0, 8000, 8);
  ledcAttachPin(pin, 0);
  ledcWriteTone(0, freq);
  playing = pin;
}

void noTone(byte pin) {
  if (playing == pin) {
    ledcWriteTone(0, 0);
    playing = 0;
  }
}

void loop() {
  static float threshold = 50; // initialize threshold to a default value
  if (SerialBT.available()) {
    // If there's data available on the Bluetooth serial port, read it and print it on the serial monitor
    noTone(buzzer);
    String input = SerialBT.readStringUntil('\n');
    input.trim();
    if (input.length() > 0) { // if user provided input, update threshold
      float new_threshold = input.toFloat();
      threshold = new_threshold;
      Serial.print("New Threshold: ");
      Serial.println(threshold);
    }
  }

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
  for(int i = 0; i < strlen(ans.c_str()); i++) {
    char data = ans[i];
    SerialBT.write(data);
  }
  SerialBT.write('\n');

  if(distanceCm < threshold) {
    String alert = "Breached threshold!";
    for(int i = 0; i < strlen(alert.c_str()); i++) {
      char data = alert[i];
      SerialBT.write(data);
    }
    SerialBT.write('\n');

    tone(buzzer,2000);
    delay(1000);
  }
  noTone(buzzer);
  delay(500);
}