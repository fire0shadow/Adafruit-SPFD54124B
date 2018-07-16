#if ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Adafruit_GFX.h"

#ifndef ADAFRUIT_SPFD54124B
#define ADAFRUIT_SPFD54124B

#define SPFD54124B_LCDWIDTH                  130
#define SPFD54124B_LCDHEIGHT                 161

#define SPFD54124B_N_NOP                     (0x00)
#define SPFD54124B_N_SWRESET                 (0x01)
#define SPFD54124B_N_RDDIDIF                 (0x04)
#define SPFD54124B_N_RDDST                   (0x09)
#define SPFD54124B_N_RDDPM                   (0x0A)
#define SPFD54124B_N_RDDMADCTL               (0x0B)
#define SPFD54124B_N_RDDCOLMOD               (0x0C)
#define SPFD54124B_N_RDDIM                   (0x0D)
#define SPFD54124B_N_RDDSM                   (0x0E)
#define SPFD54124B_N_RDDSDR                  (0x0F)
#define SPFD54124B_N_SLPIN                   (0x10)
#define SPFD54124B_N_SPLOUT                  (0x11)
#define SPFD54124B_N_PTLON                   (0x12)
#define SPFD54124B_N_NORON                   (0x13)
#define SPFD54124B_N_INVOFF                  (0x20)
#define SPFD54124B_N_INVON                   (0x21)
#define SPFD54124B_N_GAMSET                  (0x26)
#define SPFD54124B_N_DISPOFF                 (0x28)
#define SPFD54124B_N_DISPON                  (0x29)
#define SPFD54124B_N_CASET                   (0x2A)
#define SPFD54124B_N_PASET                   (0x2B)
#define SPFD54124B_N_RAMWR                   (0x2C)
#define SPFD54124B_N_RAMRD                   (0x2E)
#define SPFD54124B_N_RGBSET                  (0x2D)
#define SPFD54124B_N_PLTAR                   (0x30)
#define SPFD54124B_N_VSCRDEF                 (0x33)
#define SPFD54124B_N_TEOFF                   (0x34)
#define SPFD54124B_N_TEON                    (0x35)
#define SPFD54124B_N_MADCTL                  (0x36)
#define SPFD54124B_N_VSCRSADD                (0x37)
#define SPFD54124B_N_IDMOFF                  (0x38)
#define SPFD54124B_N_IDMON                   (0x39)
#define SPFD54124B_N_COLMOD                  (0x3A)
#define SPFD54124B_N_RDID1                   (0xDA)
#define SPFD54124B_N_RDID2                   (0xDB)
#define SPFD54124B_N_RDID3                   (0xDC)
#define SPFD54124B_N_SETOSC                  (0xB0)
#define SPFD54124B_N_SETPWCTR1               (0xB1)
#define SPFD54124B_N_SETPWCTR2               (0xB2)
#define SPFD54124B_N_SETPWCTR3               (0xB3)
#define SPFD54124B_N_SETPWCTR4               (0xB4)
#define SPFD54124B_N_SETPWCTR5               (0xB5)
#define SPFD54124B_N_SETDISCTRL              (0xB6)
#define SPFD54124B_N_SETFRMCTRL              (0xB7)
#define SPFD54124B_N_SETDISCYCCTRL           (0xB8)
#define SPFD54124B_N_SETINVCTRL              (0xB9)
#define SPFD54124B_N_RGBBPCTR                (0xBA)
#define SPFD54124B_N_SETRGBIF                (0xBB)
#define SPFD54124B_N_SETDODC                 (0xBC)
#define SPFD54124B_N_SETINTMODE              (0xBD)
#define SPFD54124B_N_SETPANEL                (0xBE)
#define SPFD54124B_N_SETOTP                  (0xC7)
#define SPFD54124B_N_SETONOFF                (0xC0)
#define SPFD54124B_N_SETEXTCMD               (0xC1)
#define SPFD54124B_N_SETGAMMAP               (0xC2)
#define SPFD54124B_N_SETGAMMAN               (0xC3)

class Adafruit_SPFD54124B : public Adafruit_GFX {
	public:
  		Adafruit_SPFD54124B(int8_t SID, int8_t SCLK, int8_t RST, int8_t CS);
  		Adafruit_SPFD54124B(int8_t RST, int8_t CS);

		void	begin(),
    			setWindow(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1),
    			fillScreen(uint16_t c),
    			pushColor(uint16_t c),
   				drawPixel(int16_t x, int16_t y, uint16_t color),
    			drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color),
    			drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color),
    			fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t c);

  		uint16_t Color565(uint8_t r, uint8_t g, uint8_t b);

	private:
  		void	writeCommand(uint8_t c),
				writeData(uint8_t c);

  		bool hwSPI;

  		int8_t	cs,
  				rst,
  				sid,
  				sclk;

  		volatile uint8_t	*dataport,
  							*clkport,
  							*csport;

  		uint8_t	datapinmask,
  				clkpinmask,
  				cspinmask,
  				spi_save;
};

#endif
