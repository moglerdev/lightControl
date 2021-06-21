#include "window.hpp"
/**
 * 2018 - Copyright by Christopher Mogler and Stephan Kopf
 * 
 * For more information, read in "window.hpp" the head comment.
 */


//Der Konstruktor für die Klasse "Window"
Window::Window()
{
    //Hier mit wird D8 initialisiert
    pinMode(TFT_LED, OUTPUT);
    //Hier wird dem D8 gesagt das er durch gehend Strom führen soll.
    //Da nirgendwo anderst D8 zu LOW wird, außer beim Ausschalten
    digitalWrite(TFT_LED, HIGH);
}
//Zum initialisieren von der Klasse "Window"
void Window::Start()
{
    TFT.begin();            //Hier mit wird das Dispaly initalisiert
    TFT.fillScreen(BLACK);  //Hier wird das Display komplett Schwarz gezeichnet
}
