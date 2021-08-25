#include <deneyap.h>
#include <IRremote.h>

#define alici_pin D0

#define deger_1 0xFFA25D
#define deger_2 0xFF629D

IRrecv alici(alici_pin);
decode_results sonuc;

void setup(){
  Serial.begin(115200);
  alici.enableIRIn();
}

void loop(){
  if(alici.decode(&sonuc)){
    Serial.println(sonuc.value, HEX);
    if(sonuc.value == deger_1){
      Serial.println("LED yandi");
    }

    if(sonuc.value == deger_2){
      Serial.println("LED sondu");  
    }
    
    alici.resume();
  }
}
