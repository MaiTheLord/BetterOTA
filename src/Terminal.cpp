/*
    Terminal.cpp - ESP8266 OTA Library
    Created by Mai Porat.
    Released into the public domain.
*/

#include "Terminal.h"
#include "TerminalBackend.h"
#include <utility>

namespace Terminal {
    void setHandler(std::function<void(String)> handler) {
        TerminalBackend::handler = std::move(handler);
    }

    void print(const String& str) {
        TerminalBackend::outgoing += str;
    }

    void println(const String& str) {
        TerminalBackend::outgoing += str + "\n";
    }
}