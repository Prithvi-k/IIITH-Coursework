#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include "Adafruit_Sensor.h"

#define I2C_SDA 13
#define I2C_SCL 27

int count = 0;
float sum_t = 0, sum_p = 0, sum_a = 0, mean_t = 0, mean_p = 0, mean_a = 0;
TwoWire I2CBMP = TwoWire(0);
Adafruit_BMP280 bmp(&I2CBMP);

void setup() {
  Serial.begin(9600);
  I2CBMP.begin(I2C_SDA, I2C_SCL, 100000);
  bmp.begin(0x76);
}

void loop() {
  count++;
  float temp = bmp.readTemperature();
  sum_t = sum_t + temp;
  mean_t = sum_t/count;
  Serial.print(mean_t);
  Serial.print("\t");
  
  float pressure = bmp.readPressure();
  sum_p = sum_p + pressure;
  mean_p = sum_p/count;
  Serial.print(mean_p/100);
  Serial.print("\t");

  float altitude = bmp.readAltitude();
  Serial.println(mean_a);
  sum_a = sum_a + altitude;
  mean_a = sum_a/count;
  delay(2000);
}