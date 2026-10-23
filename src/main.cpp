//
// Created by daniel-pelzel on 10/6/26.
//

#include <Arduino.h>

#include "Button.h"
#include "config.h"
#include "Display.h"
#include "Rfid.h"
#include "Imu.h"



Display display;
Rfid rfidReader;  // das Objekt (klein geschrieben, damit es nicht wie die Klasse heißt)
Imu imu;
Button button1;
Button button2;


void setup() {
    Serial.begin(115200);
    delay(2000);  // Zeit, damit der Serial Monitor nach dem Reset mitliest
    Serial.println("Clocky startet...");

    //Rfid
    if (!rfidReader.init()) {
        Serial.println("RC522 nicht gefunden, Verkabelung pruefen!");
    }

    //imu
   // imu.init();

    //buttons
    button1.init(BUTTON1);
    button2.init(BUTTON2);

}

void loop() {


    //Rfid lesen
    rfidReader.update();
   // imu.update();
    bool pressed = button1.buttonWasPressed();
    bool pressed2 = button2.buttonWasPressed();

}
