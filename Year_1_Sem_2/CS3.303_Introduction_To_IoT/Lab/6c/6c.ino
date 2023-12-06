#include "BluetoothSerial.h"

const int trigPin = 27;
const int echoPin = 13;
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
}

void loop() {
  
  if (SerialBT.available()) {
    char data = SerialBT.read();
    if(data == 'y')
    {
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      long duration = pulseIn(echoPin, HIGH);
      float distanceMeters1 = duration * 0.5 * speedOfSound / 1000000;
      Serial.println(distanceMeters1);

      delay(500);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      long duration2 = pulseIn(echoPin, HIGH);
      float distanceMeters2 = duration2 * 0.5 * speedOfSound / 1000000;
      Serial.println(distanceMeters2);
      
      float speed = ((distanceMeters2 - distanceMeters1) * 2);
      String ans = String(speed);
      for(int i = 0; i < strlen(ans.c_str()); i++) {
        char data = ans[i];
        SerialBT.write(data);
      }
      SerialBT.write('\n');
    }
  }
}