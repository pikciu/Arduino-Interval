#ifndef Interval_h
#define Interval_h

#include <Arduino.h>

#define HANDLER_SIGNATURE std::function<void(unsigned long)> handler

class Interval {
    private:
        unsigned long time;
        unsigned long interval;
        unsigned long counter;
        HANDLER_SIGNATURE;

    public:
        Interval(unsigned long interval);

        void reset();
        bool next();
        void setHandler(HANDLER_SIGNATURE);
        void loop();
        unsigned long getCount();
};

#endif