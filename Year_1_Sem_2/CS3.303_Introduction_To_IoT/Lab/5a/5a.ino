#include <WiFi.h>

const char* ssid = "iPhone";
const char* password = "Divya@180204";
int flag=1;
int count=0;
WiFiServer server(80);
String header; 

int outputPin = 27, pirStatus = 0;
String pir_detection = "";

void setup() {
  Serial.begin(9600);
  pinMode(outputPin, INPUT);

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

  pirStatus = digitalRead(outputPin);  
  if (pirStatus == HIGH) {            
    pir_detection = "Motion Detected"; 
    if(flag==1)
    {count++;
    flag=0;}
  } 
  else {
    pir_detection = "Motion NOT Detected";
    flag=1;
    // delay
  }

  Serial.println(pir_detection);

  if (client) {                             
  Serial.println("New Client.");          
  String currentLine = "";                
  while (client.connected()) {  
    if (client.available()) {             
      char c = client.read(); // Reads the client data about the GET request       
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
          
          client.println("<h2>PIR Motion Detection</h2><br>");

          client.println("<p>" + pir_detection + "</p><br>");
          client.println("<p> Count = " + String(count) + "</p>");


          client.println("<script>window.location.reload();</script>");
          client.println("</body></html>");
          
          client.println();
  
          break;
        } else { // if you got a newline, then clear currentLine
          currentLine = "";
        }
      } else if (c != '\r') {  // if you got anything else but a carriage return character,
        currentLine += c;      // add it to the end of the currentLine
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