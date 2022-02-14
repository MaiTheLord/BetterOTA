/*
    Terminal.h - ESP8266 OTA Library
    Created by Mai Porat.
    Released into the public domain.
*/

#ifndef TERMINAL_H
#define TERMINAL_H

#include <Arduino.h>

namespace Terminal {
    void setHandler(std::function<void(String)> handler);

    void print(const String& str);
    void println(const String& str);
}

#endif //TERMINAL_H