#ifndef _BUTTONS_H
#define _BUTTONS_H

#include <Arduino.h>
#include <OneButton.h>
#include "config.h"
#include "BPM.h"

enum ButtonState{
    PRESSED,
    LONG_PRESSED,
    RELEASED
};

ButtonState buttonStates[BUTTONS] = {RELEASED, RELEASED, RELEASED};
ButtonState oldButtonStates[BUTTONS] = {RELEASED, RELEASED, RELEASED};

// forward declarations
void confirmPressed();
void backPressed();
void encoderPressed();
void confirmLongPressed();
void backLongPressed();
void encoderLongPressed();

inline void configureButtons() {
    confirmButton.attachClick(confirmPressed);
    confirmButton.attachLongPressStart(confirmLongPressed);
    backButton.attachClick(backPressed);
    backButton.attachLongPressStart(backLongPressed);
    encoderButton.attachClick(encoderPressed);
    encoderButton.attachLongPressStart(encoderLongPressed);
}

ButtonState getButtonState(int index) {
    if (index < 0 || index >= BUTTONS) {
        return RELEASED;
    }
    return buttonStates[index];
}

ButtonState getOldButtonState(int index) {
    if (index < 0 || index >= BUTTONS) {
        return RELEASED;
    }   
    return oldButtonStates[index];
}

void resetButtonStates() {
    buttonStates[0] = RELEASED;
    buttonStates[1] = RELEASED;
    buttonStates[2] = RELEASED;
}

void resetOldButtonStates() {
    oldButtonStates[0] = RELEASED;
    oldButtonStates[1] = RELEASED;
    oldButtonStates[2] = RELEASED;
}

void confirmPressed() {
    buttonStates[0] = PRESSED;
}

void backPressed() {
    buttonStates[1] = PRESSED;
}

void encoderPressed() {
    buttonStates[2] = PRESSED;
}

void confirmLongPressed() {
    buttonStates[0] = LONG_PRESSED;
};

void backLongPressed() {
    buttonStates[1] = LONG_PRESSED;
}

void encoderLongPressed() {
    buttonStates[2] = LONG_PRESSED;
} 

#endif
