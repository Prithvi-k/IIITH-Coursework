#include <DHT.h>
#include <DHT_U.h>
#include "DHT.h"
#include "Servo.h"

#define DHTTYPE DHT11
#define dht_dpin 27
#define iopin 13

DHT dht(dht_dpin, DHTTYPE);

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  myservo.attach(iopin);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int val = 0;
  if(humidity > 45)
  {
    val = 45;
  }
  else
  {
    val = 90;
  }

  if(temperature == temperature)
  {
    Serial.print(0);
    Serial.print("\t");
    Serial.println(temperature);
  }

  myservo.write(val);
  // Serial.print("Temperature: ");
  // Serial.println(temperature);
  // Serial.print("°C, Humidity: ");
  // Serial.print(humidity);
  // Serial.print("%");

  delay(2000);
}
