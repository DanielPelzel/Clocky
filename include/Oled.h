//
// Created by daniel-pelzel on 10/17/26.
//


#pragma once

#include <cstdint>
#include <U8g2lib.h>
#include "config.h"

class Oled {
    public:
    void init();
    void update(bool selecting = false);


    private:
        void setTime(uint8_t hour, uint8_t minute);
        void blink();
        uint8_t currentDigit = 1; //1-4
        unsigned long lastTime = 0;
        uint8_t selected;  //1-4
    ;


        uint8_t _dig_one = 0, _dig_two = 0, _dig_three = 0, _dig_four = 0;
        bool _dirty = false;
    U8G2_SSD1306_128X64_NONAME_F_HW_I2C display{U8G2_R0, U8X8_PIN_NONE};


};
