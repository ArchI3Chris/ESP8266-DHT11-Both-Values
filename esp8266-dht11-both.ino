/* Temperaturanzeige 
 * Version 1.1 vom 14.11.2022
 * Original by Der Bastelbruder (https://www.youtube.com/watch?v=23_G6gQVxog - https://www.youtube.com/channel/UCMGqOyxbKXgnbDSe7DfkLow)
 * Modification by ArchI3Chris https://github.com/ArchI3Chris
 * this code can be copied/used/modified freely provided this source statement remains included
 * Code kann mit Quellenangabe frei verwendet werden;)
 */
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "DHT.h"

const char* ssid = "SSID HERE";
const char* password = "PASSWORD HERE";
#define DHTPin D1

#define DHTTYPE DHT11
DHT dht(DHTPin, DHTTYPE);

ESP8266WebServer server(80);

void indexHTML() {    
  server.send(200, "text/html", 
  "<!DOCTYPE html>\
  <html>\
  <head>\
  <title>Temperaturanzeige</title>\
  <meta http-equiv='content-type' content='text/html'; charset='utf-8'>\
  <style>\
  body { background-color: #585858; font-size: 50px; font-family: Arial, Helvetica, Sans-Serif; color: #F2F2F2; text-align: center; }\
  h1 { color: #2ECCFA; margin-top: 50px; }\
  h2 { margin-bottom: 50px; }\
  #TempWert, #HumWert { display: inline-block; padding: 0.25em 0.5em !important; border: 5px solid #F2F2F2; text-align:center; padding: 1px; color: #9AFE2E; background-color: #000000; font-size: 60px; }\
  </style>\
  </head>\
  <body>\
  <h1>Aktuell</h1>\
  <h2>Temperatur:&nbsp;<span id='TempWert'>--.-</span></h2>\
  <h2>Feuchtigkeit:&nbsp;<span id='HumWert'>--.-</span></h2>\
  <script>\
  setInterval(function() {\
    fetch('/werte').then(res => res.json()).then(data => {\
      TempWert.innerText = data.temperature + '°C';\
      HumWert.innerText = data.humidity + '%';\
    }).catch(() => {});\
  }, 1000);\
  </script>\
  </body>\
  </html>\
  ");
}

void TempMessung() {
  String Werte = "{ \"temperature\": " + String(dht.readTemperature(),1) + ", \"humidity\": " + String(dht.readHumidity(),1) + " }";
  server.send(200, "application/json", Werte);
}

void setup(void){
  dht.begin();
  Serial.begin(9600);
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Verbunden mit ");
  Serial.println(ssid);
  Serial.print("IP Adresse: ");
  Serial.println(WiFi.localIP());
 
  server.on("/", indexHTML);
  server.on("/werte", TempMessung);

  server.begin(); 
  Serial.println("Webserver ist gestartet");
}

void loop(void){
  server.handleClient();
}
