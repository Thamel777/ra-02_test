#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>

// LoRa Pin definitions
#define LORA_NSS_PIN 5
#define LORA_RESET_PIN 14
#define LORA_DIO0_PIN 2

// LoRa frequency
#define LORA_FREQUENCY 915E6 // Change to your region's frequency if needed (e.g., 868E6 for Europe, 433E6 for Asia)

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("LoRa Single Module Test");

  LoRa.setPins(LORA_NSS_PIN, LORA_RESET_PIN, LORA_DIO0_PIN);

  if (!LoRa.begin(LORA_FREQUENCY)) {
    Serial.println("Starting LoRa failed! Check your wiring.");
    while (1);
  }

  Serial.println("LoRa Initialized OK!");
  Serial.println("Success! SPI communication with LoRa module is working.");
}

void loop() {
  // Nothing to do in the loop for this test
}