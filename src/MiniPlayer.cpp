//
// Created by daniel-pelzel on 10/22/26.
//

#include "MiniPlayer.h"

#include <Arduino.h>
#include <HardwareSerial.h>
#include <map>



void MiniPlayer::sendCommand(uint8_t cmd, uint16_t param) {

    //TODO Send cmd only after a delay of at least 200 ms

        uint8_t buf[10];
        buf[0] = 0x7E;
        buf[1] = 0xFF;
        buf[2] = 0x06;
        buf[3] = cmd;
        buf[4] = 0x00;
        buf[5] = param >> 8;
        buf[6] = param & 0xFF;

        uint16_t sum = 0;
        for (int i =1; i <=6; i++) {
            sum += buf[i];
        }

        uint16_t checksum = -sum;

        buf[7] = checksum >> 8;
        buf[8] = checksum & 0xFF;
        buf[9] = 0xEF;

        Serial1.write(buf, 10);
    }

void MiniPlayer::setVolumePercent(uint8_t percent) {
       uint8_t volume = map(constrain(percent, 0, 100), 0, 100, 0, 30);
        sendCommand(0x06, volume);
    }

void MiniPlayer::play() {
        sendCommand(0x12, 1);
    }
void MiniPlayer::stop() {
        sendCommand(0x16, 0);

    }
