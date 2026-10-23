#pragma once
#include  <Arduino.h>
//Segments Pins

#define SEG_A 13
#define SEG_B 14
#define SEG_C 16
#define SEG_D 17
#define SEG_E 18
#define SEG_F 19
#define SEG_G 23
#define SEG_DP 25

#define DIG_1 26
#define DIG_2 27
#define DIG_3 32
#define DIG_4 33

constexpr uint8_t SEG_PINS[8] = {SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G, SEG_DP};
constexpr  uint8_t DIG_PINS[4] = {DIG_1, DIG_2, DIG_3, DIG_4};

// RC522 RFID-Leser (SPI)
// Die Standard-SPI-Pins 18/19/23 sind schon vom Display belegt (SEG_E/F/G),
// deshalb laufen SCK/MISO/MOSI hier über andere Pins. RST hängt fest an 3,3 V.
#define RFID_SS   5
#define RFID_SCK  4
#define RFID_MISO 34   // reiner Eingang, passt für MISO
#define RFID_MOSI 15



//IMU
#define IMU_SCL 22
#define IMU_SDA 21


//MiniPlayer
#define UART_RX 16
#define UART_TX 17


//Motoren
#define MOTOR_PIN_1 25
#define MOTOR_PIN_2 26
#define MOTOR_PIN_3
#define MOTOR_PIN_4

#define PWM_FREQ 1000
#define PWM_RES  8        // 8 Bit = 0-255, passt zu den Speed-Werten
#define MOTOR_RAMP_MS 5  // alle 5 ms ein Schritt: 0 auf 255 in ca. 1,3 s
#define PWM_CH_A 0
#define PWM_CH_B 1


//Button
#define BUTTON1 19
#define BUTTON2 18
