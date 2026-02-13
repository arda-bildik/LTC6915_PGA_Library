# LTC6915_PGA_Library
Arduino library for the Analog Devices LTC6915 Zero-Drift PGA.

# API Reference

## void begin()
Initializes the SPI bus and sets the Strobe (CS) pin to the correct output mode.

## void setGainInt(uint16_t gainValue)
Sets the gain using a standard integer. Supported values: 0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096

## void setGain(uint8_t gainCode)
Sets the gain using the defined gain settings.
|KEYWORD | Gain Setting |
| -------- | -------- |
| LTC6915_GAIN_0 | HI-Z Output |
| LTC6915_GAIN_1 | 1x |
| LTC6915_GAIN_2 | 2x |
| LTC6915_GAIN_4 | 4x |
| LTC6915_GAIN_8 | 8x |
| LTC6915_GAIN_16 | 16x |
| LTC6915_GAIN_32 | 32x |
| LTC6915_GAIN_64 | 64x |
| LTC6915_GAIN_128 | 128x |
| LTC6915_GAIN_256 | 256x |
| LTC6915_GAIN_512 | 512x |
| LTC6915_GAIN_1024 | 1024x |
| LTC6915_GAIN_2048 | 2048x |
| LTC6915_GAIN_4096 | 4096x |
