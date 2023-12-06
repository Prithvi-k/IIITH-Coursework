#include <WiFi.h>

const char* ssid = "iPhone";
const char* password = "Divya@180204";
int flag=1;
int count=0;
WiFiServer server(80);
String header; 

int ledPIN = 27;

void setup() {
  Serial.begin(9600);
  pinMode(ledPIN, OUTPUT);
  digitalWrite(ledPIN, LOW);
  Serial.print("Connecting to ssid: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("loading");
    delay(1000);
  }
  Serial.println("WiFi connected.");
  Serial.println("IP: ");
  Serial.println(WiFi.localIP());
  server.begin();
  delay(30000);
}

void loop(){
  WiFiClient client = server.available();

  if (client) {                             
  Serial.println("New Client.");          
  String currentLine = "";                
  while (client.connected()) {  
    if (client.available()) {             
      char c = client.read(); // Reads the client data about the GET request
      Serial.write(c);   
      header += c;
      if (c == '\n') {                    
        
        if (currentLine.length() == 0) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-type:text/html");
          client.println("Connection: closed");
          client.println();
          
          client.println("<!DOCTYPE html><html>");
          client.println("<title>PIR</title>");
      
          client.println("<body><h1>ESP32 Web Server</h1>");
          
          client.println("<h1>Click <a href=\"/H\">here</a> to turn LED on.</h1><br>");
          client.println("<h1>Click <a href=\"/L\">here</a> to turn LED off.</h1><br>");
          client.println("</body></html>");
          
          client.println();
  
          break;
        } else { // if you got a newline, then clear currentLine
          currentLine = "";
        }
      } else if (c != '\r') {  // if you got anything else but a carriage return character,
        currentLine += c;      // add it to the end of the currentLine
        if(currentLine.startsWith("GET /L")) {
          digitalWrite(ledPIN, LOW);
        }
        else if (currentLine.startsWith("GET /H")) {
          digitalWrite(ledPIN, HIGH);
        }
      }
    }
  }
  // Clear the header variable
  header = "";
  // Close the connection
  client.stop();
  Serial.println("Client disconnected.");
  Serial.println("");
  }

  delay(1000);
}