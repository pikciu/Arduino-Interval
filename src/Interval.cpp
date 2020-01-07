#include "Interval.h"

Interval::Interval(unsigned long interval) {
    this->interval = interval;
    this->time = millis();
}

void Interval::reset() {
    this->time = millis();
}

bool Interval::next() {
    long now = millis();
    if (now - time < interval) {
        return false;
    }
    time = now;
    return true;
}

void Interval::setHandler(HANDLER_SIGNATURE) {
    this->handler = handler;
}

void Interval::loop() {
    if (handler) {
        if (next()) {
            handler();
        }
    }
}