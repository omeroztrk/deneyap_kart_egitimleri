#include <deneyap.h>

int pirPin = A0;
int hareket;    //Pinler ve hareket değişkeni tanımlandı 

void setup() { //giriş ve çıkış pinleri tanımlandı
  pinMode(pirPin, INPUT);
  pinMode(led, OUTPUT);

  Serial.begin(115200);
}
void loop() {
  hareket = analogRead(pirPin); // Sensörden alınan verileri hareket değişkeninine yazdırıyoruz

  Serial.println(hareket);   
}
