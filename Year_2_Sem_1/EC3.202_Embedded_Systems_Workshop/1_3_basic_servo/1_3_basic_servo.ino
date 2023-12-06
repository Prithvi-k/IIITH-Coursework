#include "ESP32Servo.h"

#define iopin 13

Servo myservo;
int temp = 1, val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(iopin);
  delay(2000);
}

void loop() {
  if(temp)
  {
    val = val + 1;
  }

  myservo.write(val);

  delay(50);
}
