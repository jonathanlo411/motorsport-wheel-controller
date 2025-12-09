#include <Arduino.h>
#include <ESP32-TWAI-CAN.hpp>

// CAN pins
#define CAN_TX 23
#define CAN_RX 22

CanFrame rxFrame;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("CAN Receiver Starting...");

  // Configure and start CAN in one call
  // begin(speed, txPin, rxPin, txQueueSize, rxQueueSize)
  if (ESP32Can.begin(ESP32Can.convertSpeed(500), CAN_TX, CAN_RX, 10, 10)) {
    Serial.println("CAN bus started!");
  } else {
    Serial.println("CAN bus failed!");
    while(1);
  }
  
  Serial.println("Waiting for messages...");
}

void loop() {
  // Read frame with 1000ms timeout
  if (ESP32Can.readFrame(rxFrame, 1000)) {
    Serial.print("✓ Received frame: 0x");
    Serial.print(rxFrame.identifier, HEX);
    Serial.print(" Length: ");
    Serial.print(rxFrame.data_length_code);
    Serial.print(" Data: ");
    
    // Print data as characters
    for (int i = 0; i < rxFrame.data_length_code; i++) {
      Serial.print((char)rxFrame.data[i]);
    }
    Serial.println();
  }
}