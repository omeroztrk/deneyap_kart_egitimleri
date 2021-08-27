#include <deneyap.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>

WebServer server(80);

void anasayfa(){
  Serial.println("Ana sayfaya gelindi");

  server.send(200, "text/plain", "Ana Sayfaya Hosgeldin");
}

void setup(){
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

  server.begin();
}

void loop(){
  server.handleClient();
}
