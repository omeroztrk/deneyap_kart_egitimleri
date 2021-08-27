#include <deneyap.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>

#include "lsm6dsm.h"

LSM6DSM imu;

WebServer server(80);

String HTMLkodu = "<!DOCTYPE HTML>\n"
"<html>\n"
"  <head>\n"
"    <title>Role uygulamasi</title>\n"
"  </head>\n"
"  <body>\n"
"    <a href=\"/ac\">Role Ac</a>\n"
"    <br \\>\n"
"    <a href=\"/kapa\">Role Kapa</a>\n"
"  </body>\n"
"</html>";

void anasayfa(){
  Serial.println("Ana sayfaya gelindi");

  server.send(200, "text/html", HTMLkodu);
}

void roleac(){
  Serial.println("Role acildi");
  digitalWrite(D0, LOW);
  server.send(200, "text/html", HTMLkodu);
}

void rolekapa(){
  Serial.println("Role kapandi");
  digitalWrite(D0, HIGH);
  server.send(200, "text/html", HTMLkodu);
}


void setup(){
  imu.begin();
  pinMode(D0, OUTPUT);
  
  Serial.begin(115200);
  delay(100);

  Serial.println("Internete baglaniliyor ...");
  WiFi.begin("Bilim Uskudar","BUmth2023");

  while(WiFi.status() != 3){
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println(WiFi.localIP());

  server.on("/", anasayfa);
  server.on("/ac", roleac);
  server.on("/kapa", rolekapa);

  server.begin();
}

void loop(){
  server.handleClient();
}
