//
// Created by daniel-pelzel on 10/12/26.
//

#pragma once
#include <cstdint>


class Imu {
public:
    bool init();
    void read_regist();
    bool is_still();
    void update();

    //getter
    float getAccX() const { return acc_x; }
    float getAccY() const { return acc_y; }
    float getAccZ() const { return acc_z; }






private:

    float acc_x, acc_y, acc_z;
    float betrag_acc;
    const int CLOCK_SPEED = 400000;
    const int IMU_ADRESS = 0x69;
    const int Acc_ADRESS = 0x3B;
    const float offset = 10.55;


    int16_t read_be(uint8_t hByte, uint8_t lByte);
};



