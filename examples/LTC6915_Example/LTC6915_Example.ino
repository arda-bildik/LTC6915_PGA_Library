/*
 * LTC6915_PGA Library
 * Copyright (c) 2026 Arda Bildik (Bildik Tech Labs)
 * Licensed under the MIT License.
 */

#include <SPI.h>
#include "LTC6915_PGA.h"

const int CS_PIN = 10;

LTC6915_PGA pga(CS_PIN);

void setup() {
    Serial.begin(9600);
    pga.begin();
    
    Serial.println("LTC6915 Initialized.");
    
    pga.setGain(LTC6915_GAIN_1);
    delay(2000);
}

void loop() {
    Serial.println("Setting Gain to 64x");
    pga.setGain(LTC6915_GAIN_64);
    delay(5000);

    Serial.println("Setting Gain to 1024x");
    pga.setGain(LTC6915_GAIN_1024);
    delay(5000);
    
    Serial.println("Entering Shutdown...");
    pga.setGain(LTC6915_GAIN_0);
    delay(2000);
}