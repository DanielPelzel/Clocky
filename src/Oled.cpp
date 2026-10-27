#include "Oled.h"

void Oled::init() {
    display.begin();
    display.setFont(u8g2_font_logisoso32_tn);
}

void Oled::showTime() {

    char buffer1[2];
    snprintf(buffer1, 2, "%d", dig1);

    char buffer2[2];
    snprintf(buffer2, 2, "%d", dig2);

    char buffer3[2];
    snprintf(buffer3, 2, "%d", dig3);

    char buffer4[2];
    snprintf(buffer4, 2, "%d", dig4);

    display.clearBuffer();

    uint8_t y = display.getMaxCharHeight() /2  + display.getDisplayHeight()/2;


    uint8_t x1 = 10;
    display.drawStr(x1,y, buffer1);

    uint8_t x2 = x1 + display.getStrWidth(buffer1);
    display.drawStr(x2,y, buffer2);

    uint8_t doubleDot = x2 + display.getStrWidth(buffer2);
    display.drawStr(doubleDot,y, ":");

    uint8_t x3 = doubleDot + display.getStrWidth(":");
    display.drawStr(x3,y, buffer3);

    uint8_t x4 = x3 + display.getStrWidth(buffer3);
    display.drawStr(x4,y, buffer4);

    display.sendBuffer();

}

void Oled::blink() {
}
