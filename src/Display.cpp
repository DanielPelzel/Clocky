//
// Created by daniel-pelzel on 10/6/26.
//

#include <Arduino.h>
#include "config.h"
#include "Display.h"


const uint8_t Display::PATTERNS[10] = {
    0b0111111, // 0  → A B C D E F
    0b0000110, // 1  → B C
    0b1011011, // 2  → A B D E G
    0b1001111, // 3  → A B C D G
    0b1100110, // 4  → B C F G
    0b1101101, // 5  → A C D F G
    0b1111101, // 6  → A C D E F G
    0b0000111, // 7  → A B C
    0b1111111, // 8  → alle
    0b1101111 // 9  → A B C D F G
};


Display::Display() {
}

void Display::begin() {
    for (int i = 0; i < 8; i++) {
        pinMode(SEG_PINS[i], OUTPUT);
    }

    for (int i = 0; i < 4; i++) {
        pinMode(DIG_PINS[i], OUTPUT);
    }
    all_off();
}

void Display::all_off() {
    for (int i = 0; i < 8; i++) {
        digitalWrite(SEG_PINS[i], LOW);
    }

    for (int i = 0; i < 4; i++) {
        digitalWrite(DIG_PINS[i], HIGH);
    }
}

void Display::set_digit(uint8_t pos, uint8_t value) {
    if (pos > 3 || value > 9) return;
    digits[pos] = value;
}

void Display::set_dp(uint8_t pos, bool value) {
    if (pos > 3) return;
    dp[pos] = value;
}

void Display::writeSegment(uint8_t muster) {
    for (int i = 0; i < 8; i++) {
        digitalWrite(SEG_PINS[i], (muster >> i) & 1);
    }
}

void Display::update() {
    unsigned long now = micros();
    if (now - lastSwitch < 2500) return;
    lastSwitch = now;

    all_off();

    current = (current + 1) % 4;

    uint8_t muster = PATTERNS[digits[current]];
    if (dp[current]) muster |= 0b10000000;
    writeSegment(muster);
    digitalWrite(DIG_PINS[current], LOW);
}
