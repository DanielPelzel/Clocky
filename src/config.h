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
