//
// Created by daniel-pelzel on 10/23/26.
//

#include "../include/Button.h"
#include <Arduino.h>


void Button::init(uint8_t pin) {
    _pin = pin;
    pinMode(_pin, INPUT_PULLUP);
    _lastState = digitalRead(_pin);
    _lastSwitch = 0;
}

bool Button::buttonWasPressed() {
    bool state = digitalRead(_pin);
    if (state != _lastState && millis() - _lastSwitch > 30) {
        _lastState = state;
        _lastSwitch = millis();


        if (state == LOW)
            Serial.println("Button was pressed");
            return true;
    }
    return false;
}