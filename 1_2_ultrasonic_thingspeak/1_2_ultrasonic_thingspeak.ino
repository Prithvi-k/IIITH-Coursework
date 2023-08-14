      #include <PubSubClient.h>
      #include <WiFi.h>
      #include <ThingSpeak.h>
      
      //Pins
      const int trigPin = 22;
      const int echoPin = 21;
      const int buzzerpin=27;
      // defines variables
      long duration;
      double distance;
      
      
      //For wifi connection
      const char* ssid = "Prithvi";
      const char* pass = "password123";
      
      const char* server = "mqtt3.thingspeak.com";
      
      const char* mqttUserName = "LiQQLg44CwkCKQAxGhwuLxU";
      const char* clientID="LiQQLg44CwkCKQAxGhwuLxU";
      
      const char* mqttPass = "pQO6FymZGrGw/Sa+y2DXP4Rl";
      
      long writeChannelID = 2236024;
      const char* writeAPIKey = "DLTEL3804UG6PSF6";
      
      int port = 1883;
      
      WiFiClient client;
      
      
      PubSubClient mqttClient(client);
      
      void setup() {
        // put your setup code here, to run once:
        Serial.begin(9600);
          pinMode(trigPin, OUTPUT);
        pinMode(echoPin, INPUT); 
      
        WiFi.begin(ssid, pass);
        while(WiFi.status() != WL_CONNECTED){
          Serial.println("Connecting to WiFi...");
          delay(1000);
        }
        Serial.println("WiFi Connected!");
        mqttClient.setServer(server,port);
      }
      
      void loop() {
        // put your main code here, to run repeatedly:
        while(mqttClient.connected()==NULL){
          Serial.println("COnnecting to mqtt...");
          mqttClient.connect(clientID, mqttUserName, mqttPass);
          delay(1000);
        }
        mqttClient.loop();
        
        digitalWrite(trigPin, LOW);
        delayMicroseconds(10);
      
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
        duration = pulseIn(echoPin, HIGH);
      
        distance = duration * 0.034 / 2;
      
        Serial.print("Distance: ");
        Serial.print(distance);
        Serial.println(" cm");
        
        delay(1000);
        
        String dataString = "field1=" + String(distance);
        String topicString ="channels/" + String( writeChannelID ) + "/publish";
        mqttClient.publish( topicString.c_str(), dataString.c_str() );
      }