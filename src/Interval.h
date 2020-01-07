#ifndef Interval_h
#define Interval_h

#include <Arduino.h>

#define HANDLER_SIGNATURE std::function<void()> handler

class Interval {
    private:
        unsigned long time;
        unsigned long interval;
        HANDLER_SIGNATURE;

    public:
        Interval(unsigned long interval);

        void reset();
        bool next();
        void setHandler(HANDLER_SIGNATURE);
        void loop();
};

#endif