#pragma once
#include <cstdint>
#include <U8g2lib.h>

//Uhrzeit enzeigen lassen.

//Eine ausgewählte Zahl alle 0,5 sekunden blinken lassen für 0,5 Sekunden

//ausgewählte Zahl festlegen (eigene FUnktion)



class Oled {
    public:

    void init();
    void showTime();
    void blink();
    void setSelected(uint8_t select);

    private:


    uint8_t selected;
    U8G2_SSD1306_128X64_NONAME_F_HW_I2C display{U8G2_R0, U8X8_PIN_NONE};
    unsigned long lastTime = 0;
    uint8_t dig1 = 0;
    uint8_t dig2 = 0;
    uint8_t dig3 = 0;
    uint8_t dig4 = 0;
};