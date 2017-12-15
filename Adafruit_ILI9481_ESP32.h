/*
See rights and use declaration in License.h
This library has been modified for the Maple Mini

-----------
modified by IOXhop (www.ioxhop.com)
 - Add micro MISO MOSI and SCK pin
-----------
*/

#ifndef _ADAFRUIT_ILI9481H_
#define _ADAFRUIT_ILI9481H_

//#include "Arduino.h"
//#include "Print.h"
#include <Adafruit_GFX.h>

#define TFTWIDTH	320
#define TFTHEIGHT	480

#define ILI9481_INVOFF	0x20
#define ILI9481_INVON	0x21
#define ILI9481_CASET	0x2A
#define ILI9481_PASET	0x2B
#define ILI9481_RAMWR	0x2C
#define ILI9481_MADCTL	0x36
#define MADCTL_MY  0x80
#define MADCTL_MX  0x40
#define MADCTL_MV  0x20
#define MADCTL_ML  0x10
#define MADCTL_BGR 0x08
#define MADCTL_MH  0x04

// Color definitions
#define BLACK       0x0000      /*   0,   0,   0 */
#define NAVY        0x000F      /*   0,   0, 128 */
#define DARKGREEN   0x03E0      /*   0, 128,   0 */
#define DARKCYAN    0x03EF      /*   0, 128, 128 */
#define MAROON      0x7800      /* 128,   0,   0 */
#define PURPLE      0x780F      /* 128,   0, 128 */
#define OLIVE       0x7BE0      /* 128, 128,   0 */
#define LIGHTGREY   0xC618      /* 192, 192, 192 */
#define DARKGREY    0x7BEF      /* 128, 128, 128 */
#define BLUE        0x001F      /*   0,   0, 255 */
#define GREEN       0x07E0      /*   0, 255,   0 */
#define CYAN        0x07FF      /*   0, 255, 255 */
#define RED         0xF800      /* 255,   0,   0 */
#define MAGENTA     0xF81F      /* 255,   0, 255 */
#define YELLOW      0xFFE0      /* 255, 255,   0 */
#define WHITE       0xFFFF      /* 255, 255, 255 */
#define ORANGE      0xFD20      /* 255, 165,   0 */
#define GREENYELLOW 0xAFE5      /* 173, 255,  47 */
#define PINK        0xF81F

/*
Define pins and Output Data Registers
*/

// Control pins connect to ESP32
#define TFT_RST        23
#define TFT_RS         21
#define TFT_CS         22
#define TFT_WR         19
#define TFT_RD         32

// Data pin connect to ESP32
#define TFT_D0   18
#define TFT_D1   5
#define TFT_D2   17
#define TFT_D3   16
#define TFT_D4   33
#define TFT_D5   25
#define TFT_D6   26
#define TFT_D7   27

#define CS_ACTIVE    gpio_set_level((gpio_num_t)TFT_CS, 0);
#define CS_IDLE      gpio_set_level((gpio_num_t)TFT_CS, 1);
#define CD_COMMAND   gpio_set_level((gpio_num_t)TFT_RS, 0);
#define CD_DATA      gpio_set_level((gpio_num_t)TFT_RS, 1);

#define swap(a, b) { int16_t t = a; a = b; b = t; }

/*****************************************************************************/
class Adafruit_ILI9481_ESP32 : public Adafruit_GFX {
	public:

		Adafruit_ILI9481_ESP32(void);
	  
		void begin() ;
		void setAddrWindow(uint16_t, uint16_t, uint16_t, uint16_t) ;
		void pushColor(uint16_t) ;
		void fillScreen(uint16_t) ;
		void drawLine(int16_t, int16_t,int16_t, int16_t, uint16_t) ;
		void drawPixel(int16_t, int16_t, uint16_t) ;
		void drawFastVLine(int16_t, int16_t, int16_t, uint16_t) ;
		void drawFastHLine(int16_t, int16_t, int16_t, uint16_t) ;
		void fillRect(int16_t, int16_t, int16_t, int16_t, uint16_t) ;
		void setRotation(uint8_t) ;
		void invertDisplay(boolean) ;
		uint16_t color565(uint8_t, uint8_t, uint8_t) ;

		void reset();

	 private:
		uint8_t	tabcolor;
};


void writebus(uint8_t) ;
void writecommand(uint8_t) ;
void writedata(uint8_t) ;
void writedata16(uint16_t) ;
void writedata16(uint16_t, uint32_t) ;
void commandList(uint8_t *addr);

#endif //endif of the header file
