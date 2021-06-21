#pragma once
/**
 * 2018 - Copyright by Christopher Mogler and Stephan Kopf
 * 
 * For more information, read in "lightcontrol.hpp" the head comment.
 */
#include <SPI.h>
#include <XPT2046_Touchscreen.h>
#include "window.hpp"
#include "vector.hpp"

/*  
    Diese Klasse "Button" ist zuständig für die Buttons, 
    die Deklariert und initalisiert werden.
*/
class Button
{
    private:
        XPT2046_Touchscreen* touch;         //Der Touchscreen wird als Pointer übergeben, damit die Klasse den Touchscreen erkennen kann
        Vector3 position;                   //Die Position vom Button
        Vector3 size;                       //Die Größe vom Button
        Adafruit_ILI9341* tft;              //Der Display vom Button, damit die Klasse den Button leichter Zeichnen kann [Wird auch als Pointer übergeben]
        uint16_t color_active;              //Welche Farbe soll der Button habe wenn er aktiviert ist?
        uint16_t color_deactive;            //Welche Farbe soll der Button haben wenn er nicht aktiviert ist?
        uint16_t color_text;                //Welche Farbe soll der Text vom Button haben?
        Vector3 lastHit;                    //Wo wurde der Button zuletzte gedrückt?
        bool change;                        //Hat der Button sein Status geändert?
        bool touched;                       //Wurde der Button gedrückt?
        unsigned char text = '1';           //Welchen Name soll der Button haben [Es wird nur ein Buchstabe gezeichnet und hat nichts mit dem Namen des Objektes zu tuhen]

        void draw(uint16_t _color);         //Private Methode zum Zeichnes des Buttons [Der Button selbst und der Name (unsigned char text)]
    public:
        Button(Adafruit_ILI9341* _tft, XPT2046_Touchscreen* _touch, uint16_t _x, uint16_t _y, uint16_t _w, uint16_t _h, uint16_t _a_color, uint16_t _d_color,
                unsigned char _text, uint16_t _textcolor);

        void DrawButton();
        bool IsPressed();
        void ChangeState(bool isActive);
        void SwitchState();

        bool state;                         //Welchen Stauts hat der Button
};
