// PINS USED
// bmp -> 22(SCL), 21(SDA)
// voltage -> 4
// servo -> 14, 18
// ldr -> 32, 33, 34, 35
// current 1 -> 13
// current 2 -> TBD (27)

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include "Adafruit_Sensor.h"
#include <Servo.h>

int master_count = 0;
Adafruit_BMP280 bmp; // use I2C interface
int count = 0, cur1_pin = 13, cur1_count = 0, cur2_pin = 27, cur2_count = 0;
float cur1_avg = 0.0, cur2_avg = 0.0;
float sum_t = 0, sum_p = 0, sum_a = 0, mean_t = 0, mean_p = 0, mean_a = 0;
int ADC_VALUE = 0;
const int voltage_analog_pin= 14;
int voltage_adc = 0, voltage_value = 0, voltage_count = 0;
float voltage_avg = 0.0;

//defining Servos
Servo servohori;
int servoh = 90;
int servohLimitHigh = 160;
int servohLimitLow = 20;

Servo servoverti; 
int servov = 90; 
int servovLimitHigh = 160;
int servovLimitLow = 20;
//Assigning LDRs
int ldrtopl = 34; //top left LDR green
int ldrtopr = 33; //top right LDR yellow
int ldrbotl = 35; // bottom left LDR blue
int ldrbotr = 32; // bottom right LDR orange

void setup() {
  // put your setup code here, to run once:
  bmp.begin(0x76);
  Serial.begin(9600);
  pinMode(ldrtopl, INPUT);
  pinMode(ldrtopr, INPUT);
  pinMode(ldrbotl, INPUT);
  pinMode(ldrbotr, INPUT);
  pinMode(cur1_pin,INPUT);
  pinMode(cur2_pin,INPUT);
  servohori.attach(18);
  servohori.write(90);
  servoverti.attach(14);
  servoverti.write(90);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  count++;
  master_count++;

  if(master_count == 10)
  {

    float temp = bmp.readTemperature();
    sum_t = sum_t + temp;
    mean_t = sum_t/count;
    Serial.print("Temperature: ");
    // Serial.print(temp);
    Serial.print(mean_t);
    Serial.println("");
    // Serial.print("\t");
    
    float pressure = bmp.readPressure();
    Serial.print("Pressure: ");
    // Serial.print(pressure/100);
    sum_p = sum_p + pressure;
    mean_p = sum_p/count;
    Serial.print(mean_p/100);
    Serial.println("");
    // Serial.print("\t");

    float altitude = bmp.readAltitude();
    Serial.print("Altitude: ");
    // Serial.print(altitude);
    sum_a = sum_a + altitude;
    mean_a = sum_a/count;
    Serial.println(mean_a);
    Serial.println("");

    ADC_VALUE = analogRead(voltage_analog_channel_pin);
    float v=(ADC_VALUE)*(ADC_VALUE*-9.66631*1e-7+0.0054736);
    Serial.print("Voltage: ");
    Serial.println(v);

    
    cur1_avg = cur1_avg / 10.0;
    Serial.println(cur1_avg);
    cur1_avg = 0.0;

    cur2_avg = cur2_avg / 10.0;
    Serial.println(cur2_avg);
    cur2_avg = 0.0;

    voltage_avg /= 10;
    Serial.println(voltage_avg);
    voltage_count = 0;
    voltage_avg = 0.0;

    master_count = 0;
  }

  servoh = servohori.read();
  servov = servoverti.read();
  //capturing analog values of each LDR
  int topl = analogRead(ldrtopl);
  int topr = analogRead(ldrtopr);
  int botl = analogRead(ldrbotl);
  int botr = analogRead(ldrbotr);
  // Serial.print(topl, DEC);
  Serial.print("LDR Output: ");
  Serial.print(topl, DEC);
  Serial.print(" ");
  Serial.print(topr, DEC);
  Serial.print(" ");
  Serial.print(botl, DEC);
  Serial.print(" ");
  Serial.print(botr, DEC);
  Serial.print(" \n");

  // calculating average
  int avgtop = (topl + topr) / 2; //average of top LDRs
  int avgbot = (botl + botr) / 2; //average of bottom LDRs
  int avgleft = (topl + botl) / 2; //average of left LDRs
  int avgright = (topr + botr) / 2; //average of right LDRs


  if (avgtop < avgbot)
  {
    servoverti.write(servov +1);
    if (servov > servovLimitHigh) 
    { 
      servov = servovLimitHigh;
    }
    delay(10);
  }
  else if (avgbot < avgtop)
  {
    servoverti.write(servov -1);
    if (servov < servovLimitLow)
    {
      servov = servovLimitLow;
    }
    delay(10);
  }
  else 
  {
    servoverti.write(servov);
  }
  
  if (avgleft > avgright)
  {
    servohori.write(servoh +1);
    if (servoh > servohLimitHigh)
    {
      servoh = servohLimitHigh;
    }
    delay(10);
  }
  else if (avgright > avgleft)
  {
    servohori.write(servoh - 1);
    // Serial.println("Hi");
    if (servoh < servohLimitLow)
    {
      servoh = servohLimitLow;
    }
    delay(10);
  }
  else 
  {
    servohori.write(servoh);
  }
  Serial.println("");
  Serial.println("");

  int cur1_adc=analogRead(cur1_pin);
  float cur1_current = (cur1_adc * -0.002246) + 6.499;
  cur1_avg += cur1_current;

  int cur2_adc=analogRead(cur2_pin);
  float cur2_current = (cur2_adc * 0.003842) - 4.491;
  cur2_avg += cur2_current;

  voltage_adc = analogRead(voltage_analog_pin);
  // Serial.println(voltage_adc);
  float v=((voltage_adc * 0.004450) + 0.06588);
  if(v == 0.07)
  {
    v = 0.00;
  }
  voltage_avg += v;
  voltage_count++;
  
  delay(50);
}
