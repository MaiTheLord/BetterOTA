/*
    Terminal.h - ESP8266 OTA Library
    Created by Mai Porat.
    Released into the public domain.
*/

#ifndef Terminal_h
#define Terminal_h

#include <Arduino.h>
#include <ESP8266WebServer.h>

namespace Terminal {
    std::function<void(String)> handler = [](const String& str) {};
    ESP8266WebServer server(160);
    String outgoing = "";
    IPAddress currentClient;
    unsigned long lastFetch = millis() - 1000;

    inline void init() {
        server.on("/", []() {
            server.send(200, "text", "Hello World!"); //make front-end
        });
        server.on("/fetch", []() {

        });
        server.on("/send", []() {
            if (!server.hasArg("msg")) {

            } else {
                server.send(200, "text/raw", "Message received.");
                handler(server.arg("msg"));
            }
        });
        server.begin();
    }

    inline void handle() {
        server.handleClient();
    }

    inline void print(const String& str) {
        outgoing += str;
    }

    inline void println(const String& str) {
        outgoing += str + "\n";
    }
}

#endif //Terminal_h