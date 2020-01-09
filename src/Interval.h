#ifndef Interval_h
#define Interval_h

#include <Arduino.h>

#if defined(ESP8266) || defined(ESP32)
#include <functional>
#define HANDLER_SIGNATURE std::function<void(unsigned long)> handler
#else
#define HANDLER_SIGNATURE void(*handler)(unsigned long)
#endif

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