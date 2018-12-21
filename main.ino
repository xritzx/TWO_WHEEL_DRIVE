#include<ESP8266WiFi.h>
#include<ESP8266WiFiMulti.h> 
#include<ESP8266WebServer.h>
#include<ESP8266WebServerSecure.h>
#include "home.h"

#define M1_1 3
#define M1_2 2
#define M1_I 4

#define M2_1 7
#define M2_2 6
#define M2_I 5

ESP8266WiFiMulti wifiMulti;  
ESP8266WebServer server(80);


//____PAGE ROUTES FOR MOTO FUNCTIONS_____

void handleRoot(){        
    String page = landingPage;
    server.send(200, "text/html", page);
}

void stop(){
    digitalWrite(M1_1, 0);
    digitalWrite(M1_2, 0);
    digitalWrite(M2_1, 0);
    digitalWrite(M2_2, 0);
}
void up(){
    stop();
    digitalWrite(M1_1, 1);
    digitalWrite(M1_2, 0);
    digitalWrite(M2_1, 1);
    digitalWrite(M2_2, 0);
}
void down(){
    stop();
    digitalWrite(M1_1, 0);
    digitalWrite(M1_2, 1);
    digitalWrite(M2_1, 0);
    digitalWrite(M2_2, 1);
}
void right(){
    stop();
    digitalWrite(M1_1, 0);
    digitalWrite(M1_2, 1);
    digitalWrite(M2_1, 0);
    digitalWrite(M2_2, 0);
}
void left(){
    stop();
    digitalWrite(M1_1, 0);
    digitalWrite(M1_2, 0);
    digitalWrite(M2_1, 0);
    digitalWrite(M2_2, 1);
}
void keth1(){
    stop();
    digitalWrite(M1_1, 1);
    digitalWrite(M1_2, 0);
    digitalWrite(M2_1, 0);
    digitalWrite(M2_2, 1);
}
void keth2(){
    stop();
    digitalWrite(M1_1, 0);
    digitalWrite(M1_2, 1);
    digitalWrite(M2_1, 1);
    digitalWrite(M2_2, 0);
}

// BOILER PLATE SETUP

void setup() {

  pinMode(M1_1, OUTPUT);
  pinMode(M1_2, OUTPUT);
  pinMode(M2_1, OUTPUT);
  pinMode(M2_2, OUTPUT);

  Serial.begin(9600);

  wifiMulti.addAP("Shower when IP", "generic_password");
  wifiMulti.addAP("Redmi", "asdf1234");

  WiFi.mode(WIFI_STA);

  while(wifiMulti.run() != WL_CONNECTED){
      delay(500);
      Serial.print("*");
  }

  Serial.println("Connected");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/stop", stop);
  server.on("/up", up);
  server.on("/down", down);
  server.on("/right", right);
  server.on("/left", left);
  server.on("/keth1", keth1);
  server.on("/keth2", keth2);
  server.begin();
  Serial.println("Server is listening on Port 80");
}

void loop() {
  server.handleClient();
}
