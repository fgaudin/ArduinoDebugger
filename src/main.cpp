#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial Serial1(2, 3); // RX, TX

void setup() {
  Serial.begin(115200);
  Serial1.begin(38400);
}

void loop() {
  // from pin 2 to serial USB
  if (Serial1.available()) {
    Serial.write(Serial1.read());
  }
  // from serial USB to pin 2
  if (Serial.available()) {
    Serial1.write(Serial.read());
  }
}