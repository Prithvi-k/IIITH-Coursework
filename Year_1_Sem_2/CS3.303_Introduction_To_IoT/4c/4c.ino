#include <time.h>

int sensor_power_pin = 12, signal_pin = 27, required_water_level_value = 20;
const int buzzer = 4, touch_pin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(sensor_power_pin, OUTPUT);
  digitalWrite(sensor_power_pin, LOW);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, HIGH);
}

void loop() {
  digitalWrite(buzzer, HIGH);

  // Get Time
  time_t now = time(nullptr);
  char timeStr[9];
  strftime(timeStr, sizeof(timeStr), "%H:%M:%S", localtime(&now));

  // Water level
  digitalWrite(sensor_power_pin, HIGH);
  delay(10);
  int reading = analogRead(signal_pin);
  digitalWrite(sensor_power_pin, LOW);
  int value = map(reading, 0, 1525, 0, 40);

  // Detect Touch
  int val = touchRead(touch_pin);
  if (val < 30) {
    required_water_level_value = value;
    Serial.println(timeStr);
    Serial.println(value);
    digitalWrite(buzzer, LOW);
  } else {
    if (value > required_water_level_value) {
      Serial.println("Above level");
      digitalWrite(buzzer, LOW);
    } else if (value < required_water_level_value) {
      Serial.println("Below level");
      digitalWrite(buzzer, LOW);
    }
  }

  delay(3000);
}
