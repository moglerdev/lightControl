#include "button.hpp"
/**
 * 2018 - Copyright by Christopher Mogler and Stephan Kopf
 * 
 * For more information, read in "lightcontrol.hpp" the head comment.
 */
//Der Konstruktor für die Klasse "Button"
//Hier wird alles Deklariert die für den Button notwendig ist
Button::Button(Adafruit_ILI9341* _tft, XPT2046_Touchscreen* _touch, uint16_t _x, uint16_t _y, uint16_t _w, uint16_t _h, uint16_t _a_color, uint16_t _d_color, unsigned char _text, uint16_t _text_color)
{
    position = Vector3(_x, _y);
    size = Vector3(_w, _h);
    color_active = _a_color;
    color_deactive = _d_color;
    tft = _tft;
    touch = _touch;
    text = _text;
    color_text = _text_color;
}
//Hier mit wird der Button gezeichnet.
//-----------------------------------
//Wenn der Button sein Status ändert wird der Button bei Off => Rot oder bei On => Grün gezeichnet
void Button::draw(uint16_t _color)
{
    tft->fillRoundRect(position.X, position.Y, size.X, size.Y, 10, _color);
    tft->drawChar(position.X + (size.X * 0.5), position.Y + (size.Y * 0.2), text, color_text, 0, 5);
}
//Hier mit wird der Button gezeichnet. Mit dem Aktuellen Stauts
void Button::DrawButton() 
{
    draw(color_active);
}
//Hier mit wird geschaut ob der Button gedrückt wird oder nicht
//Nicht gedrückt => false
//Wird gedrückt => true
bool Button::IsPressed()
{
    if(touch->touched())
    {
        if(!touched)
        { 
            lastHit.Set(touch->getPoint());
            if(position.X <= lastHit.X && size.X + position.X >= lastHit.X &&
            position.Y <= lastHit.Y && size.Y + position.Y >= lastHit.Y)
            {
                touched = true;
                return true;
            }
        }
    }
    else
    {
        touched = false; 
    }
    return false;
}
//Um den Status vom Button zu ändern 
void Button::ChangeState(bool isActive)
{
    state = isActive;
    if(isActive)
    {
        draw(color_active);
    }
    else
    {
        draw(color_active);
    }
}
//Ändert die den Status des Buttons
//On => Off | Off => On
void Button::SwitchState()
{
    if(touch)
    {
        if(state)
        {
            draw(color_deactive);
        }
        else
        {
            draw(color_active);
        }
        state = !state;
    }
}
