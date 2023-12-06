#include <DHT.h>
#include <DHT_U.h>
#include "DHT.h"

#define DHTTYPE DHT11
#define dht_dpin 13

DHT dht(dht_dpin, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C, Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  delay(2000);
}
