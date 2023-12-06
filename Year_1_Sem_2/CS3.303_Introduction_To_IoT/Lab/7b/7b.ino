#include "ThingSpeak.h"
#include <WiFi.h>
#include "PubSubClient.h"
#include "WebServer.h"

const char* ssid = "motorola edge 30_2538";
const char* password = "cxh2cev2gi99cp7";
int writeChannelID = 2151459;
char writeAPIKey[] = "8AZ8PK52G0E39D91";
int led_pin = 27;

WiFiClient client;
WebServer server(80);

String SendHTML(void){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>LED Control</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color:#444444;margin-bottom: 50px;}\n";
  ptr +=".button {display: block;width: 80px;background-color: #1abc9c;border: none;color:white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr +=".button-on {background-color: #1abc9c;}\n";
  ptr +=".button-on:active {background-color: #16a085;}\n";
  ptr +=".button-off {background-color: #34495e;}\n";
  ptr +=".button-off:active {background-color: #2c3e50;}\n";
  ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>ESP32 with ThingSpeak Server</h1>\n";
  ptr +="<h3>Using Station(STA) Mode</h3>\n";
  ptr +="<h4>Control the LED</h4>\n";
  ptr +="<a class=\"button button-on\" href=\"https://api.thingspeak.com/update?api_key=8AZ8PK52G0E39D91&field1=1\">ON</a>\n";
  ptr +="<a class=\"button button-off\"href=\"https://api.thingspeak.com/update?api_key=8AZ8PK52G0E39D91&field1=0\">OFF</a>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
};

void serv_f() {
  server.send(200, "text/html", SendHTML());
}

void setup() {
  Serial.begin(115200);
  pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin, LOW);

  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    Serial.println("loading...");
    delay(1000);
  }
  Serial.println("WiFi connected.");
  Serial.println("IP: ");
  server.on("/", serv_f);
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
  server.begin();
}

void loop() {
  server.handleClient();
  // Serial.println("Connected to mqtt");
  int input_value = ThingSpeak.readFloatField(writeChannelID, 1, "ZG36TWT6F15DHSA6");
  Serial.println(input_value);

  if(input_value == 1)
  {
    digitalWrite(led_pin, HIGH);
  }
  if(input_value == 0)
  {
    digitalWrite(led_pin, LOW);
  }
}