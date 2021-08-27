#include <deneyap.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>

#include "lsm6dsm.h"

LSM6DSM imu;

WebServer server(80);

void anasayfa(){
  Serial.println("Ana sayfaya gelindi");

  server.send(200, "text/html", 
"<!DOCTYPE HTML>\n"
"<html>\n"
"<head>\n"
"<title>Sicaklik degeri</title>\n"
"</head>\n"
"<body>\n"
"<h1>Hosgeldiniz</h1>\n"
"<p>Sicaklik Degeri: \n"
"" + String( imu.readTempC() )  + " derece\n"
"</p>\n"
"</body>\n"
"\n"
"<script>\n"
"setTimeout(function(){\n"
"   window.location.reload(1);\n"
"}, 5000);\n"
"</script>\n"
"</html>\n"
""
  );
}

void setup(){
  imu.begin();
  
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
