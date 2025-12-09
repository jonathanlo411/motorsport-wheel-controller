#include <Arduino.h>
#include <ESP32-TWAI-CAN.hpp>

// CAN pins
#define CAN_TX 23
#define CAN_RX 22

CanFrame txFrame;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("CAN Transmitter Starting...");

  // Configure and start CAN in one call
  // begin(speed, txPin, rxPin, txQueueSize, rxQueueSize)
  if (ESP32Can.begin(ESP32Can.convertSpeed(500), CAN_TX, CAN_RX, 10, 10)) {
    Serial.println("CAN bus started!");
  } else {
    Serial.println("CAN bus failed!");
    while(1);
  }

  // Prepare the frame
  txFrame.identifier = 0x123;
  txFrame.extd = 0;  // Standard frame (not extended)
  txFrame.data_length_code = 8;
  txFrame.data[0] = 'H';
  txFrame.data[1] = 'E';
  txFrame.data[2] = 'L';
  txFrame.data[3] = 'L';
  txFrame.data[4] = 'O';
  txFrame.data[5] = '!';
  txFrame.data[6] = '!';
  txFrame.data[7] = '!';
  
  Serial.println("Ready to transmit!");
}

void loop() {
  // Send the frame (timeout defaults to 1ms)
  if (ESP32Can.writeFrame(txFrame)) {
    Serial.println("✓ Sent: HELLO!!!");
  } else {
    Serial.println("✗ Send failed");
  }
  
  delay(1000);
}