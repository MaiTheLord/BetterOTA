#ifndef TERMINAL_BACKEND_H
#define TERMINAL_BACKEND_H

#include <Arduino.h>

#ifdef ESP8266
    #include <ESP8266WebServer.h>
#elif defined(ESP32)
    #include <WiFi.h>
#endif

namespace TerminalBackend {
    inline std::function<void(String)> handler = [](const String& str) {}; //TODO ESP32 doesn't like inline variables
    inline String outgoing = "";
    #ifdef ESP8266
        inline ESP8266WebServer server(160);
    #elif defined(ESP32)
        inline WiFiServer server(160);
    #endif

    void init();

    inline void handle() {
        server.handleClient(); //TODO find replacement for ESP32
    }
}

#endif //TERMINAL_BACKEND_H
