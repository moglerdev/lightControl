#pragma once
#include <XPT2046_Touchscreen.h>
/**
 * 2018 - Copyright by Christopher Mogler and Stephan Kopf
 * 
 * For more information, read in "window.hpp" the head comment.
 */

/*
    Diese Klasse ist nur für X, Y, Z zuständig.
*/

class Vector3
{
    public:
        uint16_t X = 0, Y = 0, Z = 0;       //Diese 3 Int (16bit) sind für die drei dimensonale zuständig

        Vector3() { }
        Vector3(uint16_t x, uint16_t y);
        Vector3(uint16_t x, uint16_t y, uint16_t z);

        void Set(uint16_t x, uint16_t y);
        void Set(uint16_t x, uint16_t y, uint16_t z);
        //TS_Point ist von der Lib "XPT2046_Touchscreen(.h)"
        void Set(TS_Point p);
};
