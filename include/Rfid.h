//
// Created by daniel-pelzel on 10/10/26.
//

#pragma once


class Rfid {
public:
    Rfid() = default;   // nichts zu tun, deshalb vom Compiler erzeugen lassen
    bool init();
    bool is_close();

private:
};
