//
// Created by daniel-pelzel on 10/6/26.
//

#include <Arduino.h>
#include "Display.h"

Display display;                // das Objekt

void setup() {
    display.begin();            // Pins einrichten
    display.set_digit(0, 1);
    display.set_digit(1, 2);
    display.set_digit(2, 3);
    display.set_digit(3, 4);
    display.set_dp(1, true);    // Punkt hinter der 2 → „12.34“
}

void loop() {
    display.update();           // ständig multiplexen
}
