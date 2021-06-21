#pragma once
/**
 * Copyright by Christopher Mogler and Stephan Kopf
 * 
 * This library is made for a School-Project,
 *      named: "Geschäftsprozess - Licht Steuerrung"
 *
 * This library use and need other library's:
 *      Adafruits_ILI9341(.h)
 *      XPT2046_Touchscreen(.h)
 *      Adafruits_GFX(.h)
 *      SPI(.h)
 */
/*
    Diese Klasse "Window" ist für das Display zuständig
*/
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

//Colors
#define BLACK   0x0000      //Hex-Code für Schwarz
#define BLUE    0x001F      //Hex-Code für Blau
#define RED     0xF800      //Hex-Code für Rot
#define GREEN   0x07E0      //Hex-Code für Grün
#define CYAN    0x07FF      //Hex-Code für Cyanit
#define MAGENTA 0xF81F      //Hex-Code für Magenta
#define YELLOW  0xFFE0      //Hex-Code für Gelb
#define WHITE   0xFFFF      //Hex-Code für Weiß

//Screen
#define TFT_DC D2
#define TFT_CS D1
#define TFT_LED D8

class Window
{
    public:
        Adafruit_ILI9341 TFT = Adafruit_ILI9341(TFT_CS, TFT_DC);
        Window();

        void Start();
};