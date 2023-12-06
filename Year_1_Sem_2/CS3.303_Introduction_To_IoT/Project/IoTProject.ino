// PINS USED
// bmp -> 22(SCL), 21(SDA)
// voltage -> 4
// servo -> 14, 18
// ldr -> 32, 33, 34, 35

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include "Adafruit_Sensor.h"
#include <Servo.h>
#include "WiFi.h"
#include "ThingSpeak.h"
#include <HTTPClient.h>
int master_count = 0;
int thingspeakcount=0;
Adafruit_BMP280 bmp; // use I2C interface
int count = 0;
float sum_t = 0, sum_p = 0, sum_a = 0, mean_t = 0, mean_p = 0, mean_a = 0;
const int voltage_analog_channel_pin= 4;
int ADC_VALUE = 0;
int voltage_value = 0;
#define Channel_ID 2163205
#define Channel_API_Key "3NFJ999UA29ABUYQ"
char* SSID="Redmi 9 Prime";
char* pass="ameya3103";
WiFiClient client;
#define CSE_IP      "192.168.43.184"
#define CSE_PORT    5089
#define HTTPS     false
#define OM2M_ORGIN    "admin:admin"
#define OM2M_MN     "/~/in-cse/in-name/"
#define OM2M_AE     "SOLAR-OPTIMISATION"
#define OM2M_DATA_CONT  "Node-1/Data"

const char* ntpServer = "pool.ntp.org";
unsigned long epochTime; 
long randNumber;
unsigned long getTime() {
  time_t now;
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    //Serial.println("Failed to obtain time");
    return(0);
  }
  time(&now);
  return now;
}

HTTPClient http;
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
configTime(0, 0, ntpServer);
  bmp.begin(0x76);
 Serial.begin(9600);
  Serial.println("Connecting to WiFi...");
  WiFi.begin(SSID,pass);
  delay(2000);
  if(WiFi.status()==WL_CONNECTED){
    Serial.println("WiFi connected successfully!");
  }
  Serial.println("Local IP: ");
  Serial.print(WiFi.localIP());
  ThingSpeak.begin(client);
  pinMode(ldrtopl, INPUT);
  pinMode(ldrtopr, INPUT);
  pinMode(ldrbotl, INPUT);
  pinMode(ldrbotr, INPUT);
  servohori.attach(18);
  servohori.write(90);
  servoverti.attach(14);
  servoverti.write(90);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
   epochTime = getTime();
  count++;
  master_count++;
  int occupancy=0;
  thingspeakcount++;
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

  Serial.println("!");
  int adc=analogRead(voltage_analog_channel_pin);
  // float v=adc*5000/5800.0;
  float cur=v-2500;//2470.345;
  cur/=185;
  cur=-cur;
  if(thingspeakcount==8){
  ThingSpeak.setField(1,temp);
  ThingSpeak.setField(2,pressure);
  ThingSpeak.setField(3,altitude);
  ThingSpeak.setField(4,cur);
  ThingSpeak.setField(5,v);
  ThingSpeak.writeFields(Channel_ID,Channel_API_Key);
    thingspeakcount=0;
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
  static int i=0;
  String data="[" + String(epochTime) + ", " + String(occupancy) + " , " + String(temp)+"]";

String server="http://" + String() + CSE_IP + ":" + String() + CSE_PORT + String()+OM2M_MN;

Serial.println(data);
http.begin(server + String() +OM2M_AE + "/" + "Temp/Data" + "/");

http.addHeader("X-M2M-Origin", OM2M_ORGIN);
http.addHeader("Content-Type", "application/json;ty=4");
http.addHeader("Content-Length", "100");

String label = "Temp";

String req_data = String() + "{\"m2m:cin\": {"

  + "\"con\": \"" + data + "\","

  + "\"rn\": \"" + "cin_"+String(i) + "\","

  + "\"lbl\": \"" + label + "\","

  + "\"cnf\": \"text\""

  + "}}";
int code = http.POST(req_data);
http.end();
Serial.println(code);
data="[" + String(epochTime) + ", " + String(occupancy) + " , " + String(pressure)+"]";

server="http://" + String() + CSE_IP + ":" + String() + CSE_PORT + String()+OM2M_MN;

Serial.println(data);
http.begin(server + String() +OM2M_AE + "/" + "Pressure/Data" + "/");

http.addHeader("X-M2M-Origin", OM2M_ORGIN);
http.addHeader("Content-Type", "application/json;ty=4");
http.addHeader("Content-Length", "100");

label = "Pressure";
req_data = String() + "{\"m2m:cin\": {"

  + "\"con\": \"" + data + "\","

  + "\"rn\": \"" + "cin_"+String(i) + "\","

  + "\"lbl\": \"" + label + "\","

  + "\"cnf\": \"text\""

  + "}}";
code = http.POST(req_data);
http.end();
Serial.println(code);
data="[" + String(epochTime) + ", " + String(occupancy) + " , " + String(altitude)+"]";

server="http://" + String() + CSE_IP + ":" + String() + CSE_PORT + String()+OM2M_MN;

Serial.println(data);
http.begin(server + String() +OM2M_AE + "/" + "Humidity/Data" + "/");

http.addHeader("X-M2M-Origin", OM2M_ORGIN);
http.addHeader("Content-Type", "application/json;ty=4");
http.addHeader("Content-Length", "100");

label = "Humidity";

req_data = String() + "{\"m2m:cin\": {"

  + "\"con\": \"" + data + "\","

  + "\"rn\": \"" + "cin_"+String(i) + "\","

  + "\"lbl\": \"" + label + "\","

  + "\"cnf\": \"text\""

  + "}}";
code = http.POST(req_data);
http.end();
Serial.println(code);
data="[" + String(epochTime) + ", " + String(occupancy) + " , " + String(cur)+"]";

server="http://" + String() + CSE_IP + ":" + String() + CSE_PORT + String()+OM2M_MN;

Serial.println(data);
http.begin(server + String() +OM2M_AE + "/" + "Current-1/Data" + "/");

http.addHeader("X-M2M-Origin", OM2M_ORGIN);
http.addHeader("Content-Type", "application/json;ty=4");
http.addHeader("Content-Length", "100");

label = "Current-1";
req_data = String() + "{\"m2m:cin\": {"

  + "\"con\": \"" + data + "\","

  + "\"rn\": \"" + "cin_"+String(i) + "\","

  + "\"lbl\": \"" + label + "\","

  + "\"cnf\": \"text\""

  + "}}";
code = http.POST(req_data);
http.end();
Serial.println(code);
data="[" + String(epochTime) + ", " + String(occupancy) + " , " + String(v)+"]";

server="http://" + String() + CSE_IP + ":" + String() + CSE_PORT + String()+OM2M_MN;

Serial.println(data);
http.begin(server + String() +OM2M_AE + "/" + "Voltage-1/Data" + "/");

http.addHeader("X-M2M-Origin", OM2M_ORGIN);
http.addHeader("Content-Type", "application/json;ty=4");
http.addHeader("Content-Length", "100");
label = "Voltage-1";

req_data = String() + "{\"m2m:cin\": {"

  + "\"con\": \"" + data + "\","

  + "\"rn\": \"" + "cin_"+String(i++) + "\","

  + "\"lbl\": \"" + label + "\","

  + "\"cnf\": \"text\""

  + "}}";
code = http.POST(req_data);
http.end();
Serial.println(code);
  delay(50);
}
