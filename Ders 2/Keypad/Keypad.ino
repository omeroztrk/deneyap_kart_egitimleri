#include <deneyap.h>
#include "Keypad.h"

char tus_takimi[4][3] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}  
};


byte satir_pinleri[4] = {D3, D4, D5, D6};
byte sutun_pinleri[3] = {D12, D13, D14};

Keypad deneyap_keypad = Keypad(
    makeKeymap(tus_takimi),
    satir_pinleri,
    sutun_pinleri,
    4,
    3
  );

void setup() {
  Serial.begin(115200);
}


void loop() {
  char tus = deneyap_keypad.getKey();
  if(tus != NO_KEY){
    Serial.println(tus);  
  }
}
