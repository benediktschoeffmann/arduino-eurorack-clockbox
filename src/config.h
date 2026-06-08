#include <Arduino.h>
#include <OneButton.h>
#include <Wire.h>
#include "Buttons.h"
#include "Division.h"

#ifndef _PINS_H
#define _PINS_H

#define ENCODER_CLK 4
#define ENCODER_DT 5
#define ENCODER_SW 3

#define OLED_RESET -1
#define OLED_SDA A5
#define OLED_SCL A6

#define CONFIRM 2
#define BACK 8

#define OUT_A 9
#define OUT_B 10
#define OUT_C 11
#define OUT_D 12

const int BUTTON_LONG_PRESS_DURATION = 1000;
const int BUTTONS = 3;
const int CHANNELS = 4;


RotaryEncoder encoder(ENCODER_CLK, ENCODER_DT);
Adafruit_SSD1306 oled(OLED_RESET);

Division divisionA(OUT_A, 2);
Division divisionB(OUT_B, 4);
Division divisionC(OUT_C, 8);
Division divisionD(OUT_D, 16);

Division *divisions[CHANNELS] = {&divisionA, &divisionB, &divisionC, &divisionD};

OneButton confirmButton(CONFIRM);
OneButton backButton(BACK);
OneButton encoderButton(ENCODER_SW);

OneButton *buttons[BUTTONS] = {&confirmButton, &backButton, &encoderButton};

BPM bpm(120.0);


#endif
