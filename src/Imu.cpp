//
// Created by daniel-pelzel on 10/12/26.
//

#include "../include/Imu.h"
#include <Wire.h>
#include "config.h"


bool Imu::init() {
    Wire.begin(IMU_SDA, IMU_SCL);
    Wire.setClock(CLOCK_SPEED);
    Wire.beginTransmission(IMU_ADRESS);
    Wire.write(0x6B);
    Wire.write(0);
    Wire.endTransmission();
    return true;
}

void Imu::read_regist() {
    Wire.beginTransmission(IMU_ADRESS);
    Wire.write(Acc_ADRESS);
    Wire.endTransmission(false);
    Wire.requestFrom(IMU_ADRESS, 6);

    uint8_t xh = Wire.read();
    uint8_t xl = Wire.read();
    uint8_t yh = Wire.read();
    uint8_t yl = Wire.read();
    uint8_t zh = Wire.read();
    uint8_t zl = Wire.read();

    acc_x = read_be(xh, xl) / 16384.0f * 9.81f;
    acc_y = read_be(yh, yl) / 16384.0f * 9.81f;
    acc_z = read_be(zh, zl) / 16384.0f * 9.81f;

    betrag_acc = sqrt(acc_x * acc_x + acc_y * acc_y + acc_z * acc_z) - offset;
}

void Imu::update() {
    static unsigned long last_time = 0;
    if (millis() - last_time < 20) return;
    last_time = millis();
    read_regist();
    Serial.println(betrag_acc);
}

int16_t Imu::read_be(uint8_t hByte, uint8_t lByte) {
    return static_cast<int16_t>(hByte << 8 | lByte);
}