/*
    TerminalBackend.h - ESP8266 OTA Library
    Created by Mai Porat.
    Released into the public domain.
*/

#ifndef TERMINAL_BACKEND_H
#define TERMINAL_BACKEND_H

#include <Arduino.h>
#include <ESP8266WebServer.h>

namespace TerminalBackend {
    inline std::function<void(String)> handler = [](const String& str) {};
    inline String outgoing = "";
    inline ESP8266WebServer server(160);

    void init();

    inline void handle() {
        server.handleClient();
    }
}

#endif //TERMINAL_BACKEND_H