#ifndef _DIVISION_H
#define _DIVISION_H

class Division {
    public:
        Division(int, int);
        void begin();
        void reset();
        void next();
        int getPin() { return _pin; }
        void increment();
        void decrement();

    private:
        int _pin;
        int _steps;
        int _current;
        int _half;

};

Division::Division(int pin, int steps)
    : _pin(pin), _steps(steps), _current(-1), _half(steps / 2) {}

void Division::begin() {
    pinMode(_pin, OUTPUT);
    reset();
}

void Division::reset() {
    _current = -1;
    digitalWrite(_pin, HIGH);
    delay(2);
    digitalWrite(_pin, LOW);
    _current = -1;
}

void Division::next() {
    _current++;
    if (_current == _half) {
            digitalWrite(_pin, LOW);
    } else if (_current == _steps) {
        _current = 0;
        digitalWrite(_pin, HIGH);
    }
}

void Division::increment() {
    _steps++;
    _half = _steps / 2;
}

void Division::decrement() {
    if (_steps > 1) {
        _steps--;
        _half = _steps / 2;
    }
}   
#endif