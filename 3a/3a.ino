#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include "Adafruit_Sensor.h"

Adafruit_BMP280 bmp; // use I2C interface
int count = 0;
float sum_t = 0, sum_p = 0, sum_a = 0, mean_t = 0, mean_p = 0, mean_a = 0;

void setup() {
  // put your setup code here, to run once:
  bmp.begin(0x76);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  count++;
  float temp = bmp.readTemperature();
  sum_t = sum_t + temp;
  mean_t = sum_t/count;
  // Serial.print("Temperature: ");
  // Serial.print(temp);
  // Serial.println("");
  Serial.print(mean_t);
  Serial.print("\t");
  
  float pressure = bmp.readPressure();
  // Serial.print("Pressure: ");
  // Serial.print(pressure/100);
  sum_p = sum_p + pressure;
  mean_p = sum_p/count;
  Serial.print(mean_p/100);
  Serial.print("\t");

  float altitude = bmp.readAltitude();
  // Serial.print("Altitude: ");
  // Serial.print(altitude);
  // Serial.println("");
  Serial.println(mean_a);
  sum_a = sum_a + altitude;
  mean_a = sum_a/count;
  delay(2000);
}
