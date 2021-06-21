#include "vector.hpp"
/**
 * 2018 - Copyright by Christopher Mogler and Stephan Kopf
 * 
 * For more information, read in "window.hpp" the header comment.
 */

//Hier wird die "Vector" Klasse gesetzt
void Vector3::Set(uint16_t x, uint16_t y, uint16_t z)
{
    X = x;
    Z = z;
    Y = y;
}
//Touch rechnet anders als das "sichtbare" Fenster.
//Der Touch fängt von oben rechts an (x0:y0)
//Und das Display von oben links (x0:y0)
//Breite beim Touch sind 4000 und höhe sind 4000
//beim Display sind breite 240px und höhe 320px 
//---------------------------------------------
//Diese Methode rechnet mir diesen Touch-Input so um das ich 
//es für das Display 1:1 vergleichen kann
void Vector3::Set(TS_Point p)
{
    Set(
        (uint16_t)-(p.y - 4000) / 16.66,
        (uint16_t)p.x / 12.5,
        (uint16_t)p.z
    );
}
//Setze nur X und Y
void Vector3::Set(uint16_t x, uint16_t y)
{
    Set(x, y, 0);
}
//Konstruktor für Vector3, nur mit X und Y
Vector3::Vector3(uint16_t x, uint16_t y)
{
    Set(x, y, 0);
}
//Konstruktor für Vector3 mit allen Dimensionen
Vector3::Vector3(uint16_t x, uint16_t y, uint16_t z)
{
    Set(x, y, z);
}
