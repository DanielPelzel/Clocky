//
// Created by daniel-pelzel on 10/10/26.
//

#pragma once


class Rfid {
public:
    Rfid() = default;   // nichts zu tun, deshalb vom Compiler erzeugen lassen
    bool init();
    void update();


private:

    bool tagDa = false;
    unsigned long lastTime = 0;

    bool is_close();


};
