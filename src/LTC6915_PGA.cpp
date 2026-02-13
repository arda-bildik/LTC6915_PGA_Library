/*
 * LTC6915_PGA Library
 * Copyright (c) 2026 Arda Bildik (Bildik Tech Labs)
 * Licensed under the MIT License.
 */

#include "LTC6915_PGA.h"

LTC6915_PGA::LTC6915_PGA(uint8_t csPin) {
    _csPin = csPin;
    // Updated to SPI_MODE3: CPOL=1, CPHA=1
    // LTC6915 max clock is 10MHz at 5V, 2MHz at 2.7V. 1MHz is safe for both.
    _spiSettings = SPISettings(1000000, MSBFIRST, SPI_MODE3);
}

void LTC6915_PGA::begin() {
    pinMode(_csPin, OUTPUT);
    digitalWrite(_csPin, LOW); // Data is latched when LOW
    SPI.begin();
}

void LTC6915_PGA::setGain(uint8_t gainCode) {
    uint8_t data = gainCode & 0x0F;

    SPI.beginTransaction(_spiSettings);
    
    // Enable the transparent latch (Strobe HIGH)
    digitalWrite(_csPin, HIGH);
    delayMicroseconds(1); // Small safety buffer for setup time
    
    // Send 8 bits (xxxx GGGG)
    SPI.transfer(data);
    
    // Latch the data on the falling edge
    digitalWrite(_csPin, LOW);
    
    SPI.endTransaction();
}

void LTC6915_PGA::setGainInt(uint16_t gainValue) {
    uint8_t code = LTC6915_GAIN_0; // Default to shutdown if no match

    switch (gainValue) {
        case 0:    code = LTC6915_GAIN_0;    break;
        case 1:    code = LTC6915_GAIN_1;    break;
        case 2:    code = LTC6915_GAIN_2;    break;
        case 4:    code = LTC6915_GAIN_4;    break;
        case 8:    code = LTC6915_GAIN_8;    break;
        case 16:   code = LTC6915_GAIN_16;   break;
        case 32:   code = LTC6915_GAIN_32;   break;
        case 64:   code = LTC6915_GAIN_64;   break;
        case 128:  code = LTC6915_GAIN_128;  break;
        case 256:  code = LTC6915_GAIN_256;  break;
        case 512:  code = LTC6915_GAIN_512;  break;
        case 1024: code = LTC6915_GAIN_1024; break;
        case 2048: code = LTC6915_GAIN_2048; break;
        case 4096: code = LTC6915_GAIN_4096; break;
        default:
            // Optional: If user enters an invalid number, 
            // you could default to 1x gain instead of shutdown.
            code = LTC6915_GAIN_1; 
            break;
    }
    
    setGain(code);
}