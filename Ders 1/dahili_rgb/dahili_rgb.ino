#include "deneyap.h"  //deneyap.h kütüphanemizi import ediyoruz

#define beklemeSuresi 500  // milisaniye

void setup() {
    pinMode(LEDR, OUTPUT);  // Kirmizi led cikis olarak ayarlandi
    pinMode(LEDG, OUTPUT);  // Yesil led cikis olarak ayarlandi
    pinMode(LEDB, OUTPUT);  // Mavi led cikis olarak ayarlandi
}

void loop() {  // 0.5 saniye aralıklarla sırayla kırmızı - yeşil - mavi - sarı
               // renkler led üzerinde görünür
    // Kirmizi  - kartta kirmizi renk icin LEDR low, LEDG ve LEDB high
    // olmalidir. bu durum tum renkler icin gecerli
    digitalWrite(LEDR, LOW);   // LEDR (Dahili RGB Kırmızı Bacak)
    digitalWrite(LEDG, HIGH);  // LEDG (Dahili RGB Yesil Bacak)
    digitalWrite(LEDB, HIGH);  // LEDB (Dahili RGB Mavi Bacak)
    delay(beklemeSuresi);
    // Yesil
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDB, HIGH);
    delay(beklemeSuresi);
    // Mavi
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDB, LOW);
    delay(beklemeSuresi);
    // Sari
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDB, HIGH);
    delay(beklemeSuresi);
}
