//
// Created by daniel-pelzel on 10/16/26.
//

#include "Motor.h"
#include "config.h"
#include <Arduino.h>


Motor::Motor(uint8_t in1, uint8_t in2) {
    MOTOR_PIN1 = in1;
    MOTOR_PIN2 = in2;

}

void Motor::init() {
    ledcSetup(PWM_CH_A, PWM_FREQ, PWM_RES);
    ledcSetup(PWM_CH_B, PWM_FREQ, PWM_RES);
    ledcAttachPin(MOTOR_PIN1, PWM_CH_A);   // jeder Pin sein eigener Kanal
    ledcAttachPin(MOTOR_PIN2, PWM_CH_B);   // kein pinMode() danach!
    write_pwm(0);


}


void Motor::accelerate() {
    if (millis()-last_time < MOTOR_RAMP_MS) return;
    last_time = millis();
    if (current_speed < target_speed) current_speed++;
    else if (current_speed > target_speed) current_speed--;
    else return;
    write_pwm(current_speed);
}

void Motor::forward(uint8_t speed) { target_speed = speed; }

void Motor::backward(uint8_t speed) {  target_speed= -speed; }

void Motor::stop() {
    target_speed = 0;
    current_speed = 0;
    write_pwm(0);
}
void Motor::right_turn() {
}

void Motor::left_turn() {
}



void Motor::write_pwm(int16_t pwm) {
    if (pwm > 0){
        ledcWrite(PWM_CH_A, pwm);
        ledcWrite(PWM_CH_B, 0); }
    else {
        ledcWrite(PWM_CH_A, 0);
        ledcWrite(PWM_CH_B, -pwm);
    }
}