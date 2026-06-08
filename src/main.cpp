#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RotaryEncoder.h>

#include "config.h"
#include "Division.h"
#include "Buttons.h"

// forward declarations
void reset();
void handleButtons();
void handleEncoder();

unsigned long start;
int activeIndex = 0;

void setup() {
  pinMode(CONFIRM, INPUT_PULLUP);
  pinMode(BACK, INPUT_PULLUP);
  pinMode(ENCODER_CLK, INPUT);
  pinMode(ENCODER_DT, INPUT);
  pinMode(ENCODER_SW, INPUT_PULLUP);

  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setTextColor(SSD1306_WHITE);
  oled.setCursor(0, 0);
  oled.println("Hello, World!");
  oled.display();
  Serial.begin(9600);

  for (int i = 0; i < CHANNELS; i++) {
    divisions[i]->begin();
  }

  start = millis();
}

void loop() {
  
  for (int i = 0; i < BUTTONS; i++) {
    buttons[i]->tick();
  }

  for (int i = 0; i < CHANNELS; i++) {
    divisions[i]->next();
  } 
}

void handleButtons() {
  for (int i = 0; i < BUTTONS; i++) {
    if (getButtonState(i) == PRESSED && getOldButtonState(i) == RELEASED) {
      if (i == 2) {
        activeIndex = (activeIndex + 1) % (CHANNELS + 1);
      }
    }

    if (getButtonState(i) == LONG_PRESSED && getOldButtonState(i) != LONG_PRESSED) {
      if (i == 1) {
        bpm.setPrecisionMode(!bpm.getPrecisionMode());
      }
    }
    oldButtonStates[i] = buttonStates[i];
  }
}

void handleEncoder() {
  if (encoder.getDirection() == RotaryEncoder::Direction::CLOCKWISE) {
    if (activeIndex == 0) {
      bpm.increment();
    } else {
      divisions[activeIndex - 1]->increment();
    }
  } else if (encoder.getDirection() == RotaryEncoder::Direction::COUNTERCLOCKWISE) {
    if (activeIndex == 0) {
      bpm.decrement();
    } else {
      divisions[activeIndex - 1]->decrement();
    }
  }
} 

void reset() {
  for (int i = 0; i < CHANNELS; i++) {
    divisions[i]->reset();
    digitalWrite(divisions[i]->getPin(), LOW);
  }
}

