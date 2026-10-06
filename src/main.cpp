//
// Created by daniel-pelzel on 10/6/26.
//

#include <Arduino.h>
#include "config.h"

void setup() {

    for (int i = 0; i < 8; i++) {
        pinMode(SEG_PINS[i], OUTPUT );
        digitalWrite(SEG_PINS[i], HIGH);
    }

    for(int i = 0; i < 4; i++) {
        pinMode(DIG_PINS[i], OUTPUT );
        digitalWrite(DIG_PINS[i], LOW);
    }


}

void loop() {

}
