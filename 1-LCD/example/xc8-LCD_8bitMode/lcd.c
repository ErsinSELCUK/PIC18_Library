#include "lcd.h"

void pulseEnable() {
    LCD_E = 0;
    __delay_us(1);
    LCD_E = 1;
    __delay_us(1);
    LCD_E = 0;
    __delay_us(50);
}


void LCD_Ayarla() {
    LCD_KomutGonder(_LCD_8BITMODE);  //function set
    LCD_KomutGonder(_LCD_RETURNHOME);  //return home
    __delay_ms(2);
    LCD_KomutGonder(_LCD_CURSOR_BLINK);  //cursor blink
    __delay_ms(15);
}


void LCD_KomutGonder(char komut) {
    LCD_RS = 0;
    LCD_DATA = komut;
    
    pulseEnable();
}


void LCD_VeriGonder(char veri) {
    LCD_RS = 1;
    LCD_DATA = veri;
    
    pulseEnable();
}


void LCD_MetinYaz(char str_satir, char str_sutun, char *metin) {
    LCD_GotoXY(str_satir, str_sutun);
    while(*metin)
        LCD_VeriGonder(*metin++);
}

void LCD_GotoXY(char satir, char sutun) {
    if (satir == 1) {
        LCD_KomutGonder(_LCD_LINE1 + (sutun-1));
    }
    if (satir == 2) {
        LCD_KomutGonder(_LCD_LINE2 + (sutun-1));
    }
}