#include "deneyap.h"
#include "lsm6dsm.h"

LSM6DSM imu;
float sicaklik_degeri = 0.0;

void setup() {
    imu.begin();
    Serial.begin(115200);
}

void loop() {
    sicaklik_degeri = imu.readTempC();
    Serial.println(F("\nSicaklik degeri:"));
    Serial.println(sicaklik_degeri);
    Serial.println("...");
    delay(250);
}
