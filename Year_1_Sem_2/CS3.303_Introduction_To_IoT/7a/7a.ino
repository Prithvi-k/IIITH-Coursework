#include "ThingSpeak.h"
#include <WiFi.h>
#include "PubSubClient.h"

const char* ssid = "motorola edge 30_2538";
const char* password = "cxh2cev2gi99cp7";
const char* server = "mqtt3.thingspeak.com";
const char* mqttUserName = "LiQQLg44CwkCKQAxGhwuLxU";
const char* clientID = "LiQQLg44CwkCKQAxGhwuLxU";
const char* mqttPass = "pQO6FymZGrGw/Sa+y2DXP4Rl";
int writeChannelID = 2151459;
char writeAPIKey[] = "8AZ8PK52G0E39D91";
int signal_pin = 32, sensor_power_pin = 12;

WiFiClient client;
PubSubClient mqttClient(client);

void setup() {
  Serial.begin(9600);
  pinMode(signal_pin, INPUT);
  pinMode(sensor_power_pin, OUTPUT);
  digitalWrite(sensor_power_pin, LOW);

  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    Serial.println("loading...");
    delay(1000);
  }
  Serial.println("WiFi Connected!");
  mqttClient.setServer(server, 1883);
}


void loop() {
  while(mqttClient.connected()==NULL)
  {
     Serial.println("Trying to connect to mqtt...");
     mqttClient.connect(clientID, mqttUserName, mqttPass);
     delay(1000);
  }
  mqttClient.loop();
  Serial.println("Connected to mqtt");

  digitalWrite(sensor_power_pin, HIGH);
  delay(100);
  float val = analogRead(signal_pin);
  digitalWrite(sensor_power_pin, LOW);
  float sensor_data = map(val, 0, 2000, 0, 20);
  Serial.println(sensor_data);

  delay(1000);
  Serial.print("Reading: ");
  Serial.println(sensor_data);
  
  String dataString = "field1=" + String(sensor_data);
  String topicString ="channels/" + String( writeChannelID ) + "/publish";
  mqttClient.publish( topicString.c_str(), dataString.c_str() );
}