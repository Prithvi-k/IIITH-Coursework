#include "ThingSpeak.h"
#include <WiFi.h>
#include "PubSubClient.h"
#include "WebServer.h"
#include "ESP32Servo.h"

#define iopin 13
Servo myservo;

const char* ssid = "Prithvi";
const char* pass = "password123";

// const char* Server = "mqtt3.thingspeak.com";

const char* mqttUserName = "LiQQLg44CwkCKQAxGhwuLxU";
const char* clientID="LiQQLg44CwkCKQAxGhwuLxU";
const char* mqttPass = "pQO6FymZGrGw/Sa+y2DXP4Rl";

long writeChannelID = 2236024;
const char* writeAPIKey = "DLTEL3804UG6PSF6";

WiFiClient client;
WebServer server(80);

String SendHTML(void){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>Servo Control</title>\n";
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
  ptr +="<h4>Control the Servo</h4>\n";
  ptr +="<a class=\"button button-on\" href=\"https://api.thingspeak.com/update?api_key=DLTEL3804UG6PSF6&field1=90\">ON</a>\n";
  ptr +="<a class=\"button button-off\"href=\"https://api.thingspeak.com/update?api_key=DLTEL3804UG6PSF6&field1=0\">OFF</a>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
};

void serv_f() {
  server.send(200, "text/html", SendHTML());
} 

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, pass);
  while(WiFi.status() != WL_CONNECTED){
    Serial.println("loading...");
    delay(1000);
  }
  Serial.println("WiFi connected.");
  Serial.println("IP: ");
  server.on("/", serv_f);
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
  myservo.write(0);
  server.begin();
}

void loop() {
  server.handleClient();
  // Serial.println("Connected to mqtt");
  int input_value = ThingSpeak.readFloatField(writeChannelID, 1, "TD3OC5AM62OEPRTG");
  Serial.println(input_value);

  if(input_value == 90)
  {
    myservo.write(90);
  }
  if(input_value == 0)
  {
    myservo.write(0);
  }
}
