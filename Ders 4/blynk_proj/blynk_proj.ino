#include <deneyap.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "token"; //buraya kendi tokeninizi
int pinValue = 0;

BLYNK_WRITE(V1){
  pinValue = param.asInt();
}

void setup(){
  pinMode(D0 , OUTPUT);
  Serial.begin(115200);

    WiFi.begin("ssid", "parola");
    while(WiFi.status() != 3){
      Serial.print(".");  
    }

    Serial.println("");
    Serial.println("Baglanildi");
    Serial.println("Blynk basliyor");
    Blynk.begin(auth, "ssid", "parola");
    Serial.println("Blynk basladi");
}

void loop(){
  Blynk.run();
  digitalWrite(D0, pinValue);
}
