#include "Keypad.h"
#include "deneyap.h"

const byte satir = 4;     // dört satır
const byte sutun = 3;     // üç sütun

char tus_takimi[satir][sutun] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte satir_pinleri[satir] = {D3, D4, D5, D6};  //satır pinleri
byte sutun_pinleri[sutun] = {D12, D13, D14};  //sütun pinleri

Keypad deneyap_keypad = Keypad( makeKeymap(tus_takimi), satir_pinleri, sutun_pinleri, satir, sutun );
void setup() {
Serial.begin(115200);      // Seri portu başlat
}

void loop() {
  char tus = deneyap_keypad.getKey();  
    if (tus != NO_KEY)
  {
    Serial.println(tus);
  }
}
