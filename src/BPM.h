#ifndef _BPM_H
#define _BPM_H

class BPM {
    public:
        BPM(float initialBPM = 120.0); // : _bpm(initialBPM), _interval(0.0), _precisionMode(false) {};
        void set(float bpm);
        float get();
        float getInterval();
        void setPrecisionMode(bool enabled);
        bool getPrecisionMode();
        float increment();
        float decrement();

    private:
        float _bpm;
        float _interval;
        bool _precisionMode;
};

BPM::BPM(float initialBPM) : _bpm(initialBPM), _interval(0.0), _precisionMode(false) {
    _interval = 60000.0 / _bpm;
} 

void BPM::set(float bpm) {
    _bpm = bpm;
    _interval = 60000.0 / _bpm;
}

float BPM::get() {
    return _bpm;
}

float BPM::getInterval() {
    return _interval;
}

void BPM::setPrecisionMode(bool enabled) {
    _precisionMode = enabled;
}

bool BPM::getPrecisionMode() {
    return _precisionMode;
}   

float BPM::increment() {
    if (_precisionMode) {
        set(_bpm + 0.1);
    } else {
        set(_bpm + 1.0);
    }
    return _bpm;
}

float BPM::decrement() {
    if (_precisionMode) {
        set(_bpm - 0.1);
    } else {
        set(_bpm - 1.0);
    }
    return _bpm;
}
#endif
