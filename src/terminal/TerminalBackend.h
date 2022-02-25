#ifndef TERMINAL_BACKEND_H
#define TERMINAL_BACKEND_H

#include <Arduino.h>

#ifdef ESP8266
    #include <ESP8266WebServer.h>
#elif defined(ESP32)
    #include <WiFi.h>
#endif

namespace TerminalBackend {
    inline std::function<void(String)> handler = [](const String& str) {};
    inline String outgoing = "";
    inline ESP8266WebServer server(160); //TODO verify if this will work with ESP32 API

    void init();

    inline void handle() {
        server.handleClient(); //TODO verify if this will work with ESP32 API
    }
}

#endif //TERMINAL_BACKEND_H
