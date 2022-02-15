/*
    Terminal.cpp - ESP8266 OTA Library
    Created by Mai Porat.
    Released into the public domain.
*/

#include "Terminal.h"
#include "TerminalBackend.h"
#include <utility>

void Terminal::setHandler(std::function<void(String)> handler) {
    TerminalBackend::handler = std::move(handler);
}

void Terminal::print(const String& str) {
    TerminalBackend::outgoing += str;
}

void Terminal::println(const String& str) {
    TerminalBackend::outgoing += str + "\n";
}
