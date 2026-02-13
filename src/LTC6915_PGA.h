/*
 * LTC6915_PGA Library
 * Copyright (c) 2026 Arda Bildik (Bildik Tech Labs)
 * Licensed under the MIT License.
 */

#ifndef LTC6915_PGA_H
#define LTC6915_PGA_H

#include <Arduino.h>
#include <SPI.h>

// Gain Definitions (4 LSBs)
#define LTC6915_GAIN_0    0x00  // Shutdown
#define LTC6915_GAIN_1    0x01
#define LTC6915_GAIN_2    0x02
#define LTC6915_GAIN_4    0x03
#define LTC6915_GAIN_8    0x04
#define LTC6915_GAIN_16   0x05
#define LTC6915_GAIN_32   0x06
#define LTC6915_GAIN_64   0x07
#define LTC6915_GAIN_128  0x08
#define LTC6915_GAIN_256  0x09
#define LTC6915_GAIN_512  0x0A
#define LTC6915_GAIN_1024 0x0B
#define LTC6915_GAIN_2048 0x0C
#define LTC6915_GAIN_4096 0x0D

class LTC6915_PGA {
public:
    // Constructor: pass the CS (Strobe) pin
    LTC6915_PGA(uint8_t csPin);

    void begin();
    void setGain(uint8_t gainCode);
    void setGainInt(uint16_t gainValue);

private:
    uint8_t _csPin;
    SPISettings _spiSettings;
};

#endif