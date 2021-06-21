
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "XPT2046_Touchscreen.h"

#define TFT_DC D2
#define TFT_CS D1
#define TFT_LED D8

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

#define CS_PIN  D3
// MOSI=D7, MISO=D6 SCK=D5

// The TIRQ interrupt signal must be used for this example.
#define TIRQ_PIN D4
XPT2046_Touchscreen ts(CS_PIN, TIRQ_PIN);  // Param 2 - Touch IRQ Pin - interrupt enabled polling

boolean buttonValue1 = false;
boolean buttonValue2 = false;
boolean lastTouched = false;
boolean nowTouched = false;




void setup() {
  pinMode(TFT_LED, OUTPUT);           // set pin to input
  digitalWrite(TFT_LED, HIGH);
  Serial.begin(115200);
  Serial.println("ILI9341 Test!");
  tft.begin();
  tft.setRotation(0);
//  delay(10);
  zeichneHintergrund();

  zeichneRechteck(60, 20, 120, 120, ILI9341_RED, ILI9341_BLACK);
  zeichneRechteck(60, 180, 120, 120, ILI9341_RED, ILI9341_BLACK);

  ts.begin();
  delay(500);
 // while (!Serial && (millis() <= 1000));
}


void loop(void) {
  lastTouched = nowTouched;
  nowTouched = ts.touched();
  if (!lastTouched && nowTouched) {
    TS_Point p = ts.getPoint();
    Serial.print("Pressure = ");
    Serial.print(p.z);
    Serial.print(", x = ");
    Serial.print(p.x);
    Serial.print(", y = ");
    Serial.print(p.y);
    if (p.x  > 600 && p.x < 1800) {
      Serial.print(" Button 1");
    } else if (p.x  > 2200 && p.x < 3400) {
      Serial.print(" Button 2");
    } else {
      Serial.print(" kein Button");
    }
    Serial.println();
    delay(50);
  }

  //  for(uint8_t rotation=0; rotation<4; rotation++) {
  //    tft.setRotation(rotation);
  //    testText();
  //    delay(1000);
  //  }
}

void zeichneRechteck(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color1, uint16_t color2 ) {
  //  tft.drawRoundRect(x1,y1,x2,y2,5, ILI9341_RED);
  tft.fillRect(x1, y1, x2, y2, color1);
  tft.drawRect(x1, y1, x2, y2, color2);
}

void zeichneHintergrund() {
  tft.fillScreen(ILI9341_BLUE);
}


