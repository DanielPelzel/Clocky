//
// Created by daniel-pelzel on 10/6/26.
//

#pragma once
#include <cstdint>


class Display {
public:
    Display();
    void begin();
    void all_off();
    void set_dp(uint8_t pos, bool value);
    void set_digit(uint8_t, uint8_t);
    void update();

private:
    void writeSegment(uint8_t muster);

    uint8_t digits[4] = {0, 0, 0, 0};
    bool    dp[4]     = {false, false, false, false};
    uint8_t current   = 0;
    unsigned long lastSwitch = 0;

    static const uint8_t PATTERNS[10];

};


