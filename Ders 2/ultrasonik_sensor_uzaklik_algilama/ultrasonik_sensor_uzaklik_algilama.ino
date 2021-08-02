#include "deneyap.h"              //deneyap.h kütüphanesi projeye dahil edilir
#include "hcsr04ESP32.h"      //sensör kütüphanesi projeye dahil edilir

//sensörün trig ve echo pinlerinin bağlı olduğu pinler tanımlanır
#define trigPin D1   
#define echoPin D0 

UltraSonicDistanceSensor distanceSensor(trigPin, echoPin); 
// Ultrasonik sensor pin konfigurasyonu

void setup () {
  Serial.begin(115200);              // Seri haberleme baslatildi
}    

void loop () {
  Serial.println(distanceSensor.measureDistanceCm());       
// Kullanılan fonksiyonla ultrasonik olçüm yapılıyor ve seri terminale veri gönderiliyor.
  delay(500);
}
