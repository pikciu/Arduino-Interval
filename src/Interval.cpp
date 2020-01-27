#include "Interval.h"

Interval::Interval() {
}

Interval::Interval(unsigned long interval) : interval(interval) {
    time = millis();
    counter = 0;
}

void Interval::setInterval(unsigned long interval) {
    this->interval = interval;
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
    counter++;
    return true;
}

void Interval::setHandler(HANDLER_SIGNATURE) {
    this->handler = handler;
}

void Interval::loop() {
    if (handler) {
        if (next()) {
            handler(getCount());
        }
    }
}

unsigned long Interval::getCount() {
    return counter;
}