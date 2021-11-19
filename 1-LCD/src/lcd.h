#include <xc.h>

#define _XTAL_FREQ  64000000

#define LCD_RS      LATC0
#define LCD_E       LATC1
#define LCD_DATA    LATD


#define _LCD_8BITMODE           0x38
#define _LCD_RETURNHOME         0x02
#define _LCD_CURSOR_BLINK       0x0F
#define _LCD_LINE1              0x80
#define _LCD_LINE2              0xC0


void pulseEnable(void);
void LCD_Ayarla(void);
void LCD_KomutGonder(char komut);
void LCD_VeriGonder(char veri);
void LCD_MetinYaz(char str_satir, char str_sutun, char *metin);
void LCD_GotoXY(char satir, char sutun);