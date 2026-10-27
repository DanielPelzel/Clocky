//
// Created by daniel-pelzel on 10/17/26.
//

#include "Oled.h"
#include <U8g2lib.h>

void Oled::init() {

    display.begin();
    display.setFont(u8g2_font_logisoso32_tn);

}

void Oled::update(bool selecting) {
    char buffer1[2];
    char buffer2[2];
    char buffer3[2];
    char buffer4[2];


    if (selecting == false) {
        if (!_dirty) return;
        _dirty = false;

        buffer1[2];
        snprintf(buffer1, sizeof(buffer1), "%d", _dig_one);

        buffer2[2];
        snprintf(buffer2, sizeof(buffer2), "%d", _dig_two);

        buffer3[2];
        snprintf(buffer3, sizeof(buffer3), "%d", _dig_three);

        buffer4[2];
        snprintf(buffer4, sizeof(buffer4), "%d", _dig_four);
    }

    else if (selecting == true) {



        if (selected == 1) {
            snprintf(buffer1, sizeof(buffer1), "%d", _dig_one);

            if (millis() - lastTime > 500) {
                snprintf(buffer1, sizeof(buffer1), "%d", "");
                lastTime = millis();

            }

        }

        uint8_t x1 = display.getStrWidth(buffer1);
        uint8_t x2 = x1+ display.getStrWidth(buffer2);
        uint8_t xcolcon = x2 + display.getStrWidth(":");
        uint8_t x3 = xcolcon + display.getStrWidth(buffer3);
        uint8_t x4 = x3 + display.getStrWidth(buffer4);

        display.clearBuffer();
        display.drawStr(x1, 48, buffer1);
        display.drawStr(x2, 48, buffer2);
        display.drawStr(xcolcon, 48, ":");
        display.drawStr(x3, 48, buffer3);
        display.drawStr(x4, 48, buffer4);

        display.sendBuffer();
    }
}