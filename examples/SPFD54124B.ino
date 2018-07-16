#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SPFD54124B.h>

#define TFT_CS    		10
#define TFT_RESET  		12

#define BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0
#define WHITE           0xFFFF

Adafruit_SPFD54124B display(TFT_RESET, TFT_CS);

void setup(void) {
  display.begin();
  display.setRotation(2);

  display.fillScreen(WHITE);
  display.fillRect(0, 0, 130, 24, BLACK);

  display.setTextColor(WHITE);
  display.setCursor(16, 16);
  display.print("Hello World");
}

void loop() {}
