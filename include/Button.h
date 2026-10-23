//
// Created by daniel-pelzel on 10/23/26.
//
#pragma once

#include <cstdint>

class Button{
    public:
    /**
     * @param pin
     */
    void init(uint8_t pin);
    bool buttonWasPressed();

    private:
    bool _lastState;
    uint8_t _pin;
    unsigned long _lastSwitch;

};


