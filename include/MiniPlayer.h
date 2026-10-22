//
// Created by daniel-pelzel on 10/22/26.
//
#pragma once
#include <WString.h>


class MiniPlayer {
    public:
    MiniPlayer() = default;

    void play();
    void stop();
    void setVolumePercent(uint8_t percent);
private:
    void sendCommand(uint8_t cmd, uint16_t param);
};


