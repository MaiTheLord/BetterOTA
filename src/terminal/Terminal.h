#ifndef TERMINAL_H
#define TERMINAL_H

#include <Arduino.h>
#include <functional>

namespace Terminal {
    void setHandler(std::function<void(String)> handler);

    void print(const String& str);
    void println(const String& str);
}

#endif //TERMINAL_H
