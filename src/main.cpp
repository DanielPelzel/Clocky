//
// Created by daniel-pelzel on 10/6/26.
//

#include <Arduino.h>
#include "Display.h"
#include "Rfid.h"
#include "Imu.h"
#include <U8g2lib.h>

#include "config.h"
#include "MiniPlayer.h"


Rfid rfidReader;  // das Objekt (klein geschrieben, damit es nicht wie die Klasse heißt)
Imu imu;
U8G2_SSD1306_128X64_NONAME_F_HW_I2C display(U8G2_R0, U8X8_PIN_NONE);
MiniPlayer miniPlayer;






void setup() {
    Serial.begin(115200);
    Serial1.begin(9600, SERIAL_8N1, UART_RX, UART_TX);
    delay(2000);  // Zeit, damit der Serial Monitor nach dem Reset mitliest
    Serial.println("Clocky startet...");

    //Rfid
    if (!rfidReader.init()) {
        Serial.println("RC522 nicht gefunden, Verkabelung pruefen!");
    }

    //imu
    imu.init();




    //Display Test
   display.begin();
    display.setFont(u8g2_font_logisoso32_tn);
    display.drawStr(10, 48, "20:12");
    display.sendBuffer();


    int stundde = 7;
    int Minute = 5;
    char test[6];
    snprintf(test, sizeof(test), "%02d:%02d", stundde, Minute);

    //miniPLayer Test
    miniPlayer.setVolumePercent(10);
    delay(200);
    miniPlayer.play();

}

void loop() {
    //Rfid lesen
    rfidReader.update();
    imu.update();


    //Display Test

}
