#pragma once
#include <cstdint>

class Motor {

public:
    Motor(uint8_t in1, uint8_t in2);
    void init();
    void accelerate();              // in jedem loop() aufrufen, faehrt sanft zum Ziel

    void forward(uint8_t speed);
    void backward(uint8_t speed);
    void stop();
    void right_turn();
    void left_turn();

private:
    uint8_t  MOTOR_PIN1;
    uint8_t  MOTOR_PIN2;
    int16_t  target_speed  = 0;     // -255 (rueckwaerts) bis 255 (vorwaerts)
    int16_t  current_speed = 0;
    unsigned long last_time = 0;

    void write_pwm(int16_t pwm);

};

