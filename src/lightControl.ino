#include "window.hpp"
#include "vector.hpp"
#include "button.hpp"
#include <Adafruit_NeoPixel.h>

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
#define btnH 145    //Welche höhe sollen die Buttons haben    [Muss beim deklarieren mit gegeben]
#define btnW 105    //Welche breite sollen die Buttons haben  [Muss beim deklarieren mit gegeben]

#define CS_PIN D3
#define TIRQ_PIN D4

Window lc = Window();     //Display (Weiteres steht in der .hpp- und .cpp-Datei)

XPT2046_Touchscreen ts = XPT2046_Touchscreen(D3, D4);   //Touchsreen

Adafruit_NeoPixel rgb = Adafruit_NeoPixel(1, D2, NEO_GRB + NEO_KHZ800); //RGB Licht

Button one = Button(&lc.TFT, &ts, 10, 10, btnW, btnH, GREEN, RED, '1', BLACK);    //Button "one"
Button two = Button(&lc.TFT, &ts, 120, 10, btnW, btnH, GREEN, RED, '2', BLACK);    //Button "two"
Button three = Button(&lc.TFT, &ts, 10, 160, btnW, btnH, GREEN, RED, '3', BLACK);    //Button "three"
Button four = Button(&lc.TFT, &ts, 120, 160, btnW, btnH, GREEN, RED, '4', BLACK);    //Button "four"

int red, green, blue; //Diese drei Int werte sind für das RGB Licht zuständig


//Beim Starten [oder Reseten] des Arduino
void setup()
{
  pinMode(D2, OUTPUT);      //
  lc.Start();               //Window Klasse deklarieren
  Serial.begin(115200);     //Debug Modus [Console Frgz au 115200 stellen]
  one.DrawButton();         //Button "one" soll gezeichnet werden
  two.DrawButton();         //Button "two" soll gezeichnet werden
  three.DrawButton();       //Button "three" soll gezeichnet werden
  four.DrawButton();        //Button "four" soll gezeichnet werden
  ts.begin();               //Touchscreen soll initilisiert werden
  rgb.begin();              //Das RGB Licht soll initialisiert werden
}

//Die Endlos-Schleife vom Arduino
void loop()
{
  if(one.IsPressed()) //Wurde der Button "one" gedrückt? Wenn Ja gehe "true", wenn nicht "false" [Das hier gilt für die anderen auch Buttons auch]
  {
    one.SwitchState();  //Hiermit wird der Button Status geändert. [Das hier gilt für die anderen Button auch]
    
    /*
      Hier sollte eigentlich die Funktion vom Button sein wenn er sein Stauts geändert hat.
      Aber Stephan Kopf und Christopher Mogler hatten keine Lichter.
    */
  }
  if(two.IsPressed()) //Wurde der Button "two" gedrückt?
  {
    two.SwitchState(); 
    /*
      Hier sollte eigentlich die Funktion vom Button sein wenn er sein Stauts geändert hat.
      Aber Stephan Kopf und Christopher Mogler hatten keine Lichter.
    */
  }
  if(three.IsPressed()) //Wurde der Button "three" gedrückt?
  {
    three.SwitchState();
    /*
      Hier sollte eigentlich die Funktion vom Button sein wenn er sein Stauts geändert hat.
      Aber Stephan Kopf und Christopher Mogler hatten keine Lichter.
    */
  }
  if(four.IsPressed()) //Wurde der Button "four" gedrückt?
  {
    four.SwitchState();
    /*
      Hier sollte eigentlich die Funktion vom Button sein wenn er sein Stauts geändert hat.
      Aber Stephan Kopf und Christopher Mogler hatten keine Lichter.
    */
  }
  
  /*
    Das hier ist für das RGB-Licht
  */
  if(one.state) //Welchen Stauts hat der Button? (True => On; False => Off)
  {
    green = 1; 
  }
  else
  {
    green = 0;
  }
  if(two.state) //Welchen Stauts hat der Button? (True => On; False => Off)
  {
    blue = 1;
  }
  else
  {
    blue = 0;
  }
  if(three.state) //Welchen Stauts hat der Button? (True => On; False => Off)
  {
    red = 1;
  }
  else
  {
    red = 0;
  }
  if(four.state) //Welchen Stauts hat der Button? (True => On; False => Off)
  {
    rgb.setBrightness(40); //Da es nur 3 haupt farben existieren wird der 4 Button als "Verdunkler" verwendet
                            //Wenn der 4 Button On ist, soll das Licht etwas dunkler sein.
  }
  else
  {
    rgb.setBrightness(255); //Wenn der 4 Button Off ist, soll das Licht hell strahlen
  }
  rgb.setPixelColor(0, rgb.Color(red * 255, green * 255, blue * 255)); //Setze die Farbe. Bsp.: "red" * 1 = 255 (Wenn Button "one" "true" ist) | "red" * 0 = 0 (Wenn Button "one" "false" ist)
  rgb.show(); //Hier mit das RGB-Licht aktualisiert
}

