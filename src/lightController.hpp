#pragma once
#include <Adafruit_NeoPixel.h>

#define LED_RGB D2

class LightController{
    private:
        Adafruit_NeoPixel* rgbLed;
    public:
        LightController();

        void Init();
        void SetColor(uint8_t red, uint8_t green, uint8_t blue);
};