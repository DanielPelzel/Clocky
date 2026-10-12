//
// Created by daniel-pelzel on 10/6/26.
//

#include <Arduino.h>
#include "Display.h"
#include "Rfid.h"

Display display;
Rfid rfidReader;  // das Objekt (klein geschrieben, damit es nicht wie die Klasse heißt)



void setup() {
    Serial.begin(115200);
    delay(2000);  // Zeit, damit der Serial Monitor nach dem Reset mitliest
    Serial.println("Clocky startet...");

    //Rfid
    if (!rfidReader.init()) {
        Serial.println("RC522 nicht gefunden, Verkabelung pruefen!");
    }
}

void loop() {


    //Rfid lesen
    rfidReader.update();

}
