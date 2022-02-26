#ifndef TERMINAL_BACKEND_H
#define TERMINAL_BACKEND_H

#include <Arduino.h>

#ifdef ESP8266
    #include <ESP8266WebServer.h>
#elif defined(ESP32)
    #include <WebServer.h>
#endif

namespace TerminalBackend {
    extern std::function<void(String)> handler;
    extern String outgoing;

    #ifdef ESP8266
        extern ESP8266WebServer server;
    #elif defined(ESP32)
        extern WebServer server;
    #endif

    void init();

    inline void handle() {
        server.handleClient();
    }
}

#endif //TERMINAL_BACKEND_H
