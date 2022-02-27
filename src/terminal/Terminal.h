#ifndef TERMINAL_H
#define TERMINAL_H

#include <Arduino.h>

#ifdef ESP8266
    #include <ESP8266WebServer.h>
#elif defined(ESP32)
    #include <WebServer.h>
#endif

class Terminal {
public:
    bool hasStarted = false;
    std::function<void(String)> handler = [](const String& str) {};
    String outgoing = "";

    #ifdef ESP8266
        ESP8266WebServer server;
    #elif defined(ESP32)
        WebServer server;
    #endif

    Terminal() = default;
    explicit Terminal(int port);

private:
    IPAddress currentClient;
    unsigned long lastFetch = 0;

    bool isFree();
};

#endif //TERMINAL_H
