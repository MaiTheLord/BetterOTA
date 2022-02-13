/*
    TerminalBackend.h - ESP8266 OTA Library
    Created by Mai Porat.
    Released into the public domain.
*/

#ifndef TerminalBackend_h
#define TerminalBackend_h

#include <Arduino.h>
#include <ESP8266WebServer.h>

namespace TerminalBackend {
    inline std::function<void(String)> handler = [](const String& str) {};
    inline ESP8266WebServer server(160);
    inline String outgoing = "";

    bool isFree();

    inline void init() {
        server.on("/", []() {
            if (!isFree()) return;
            server.send(200, "text", "Hello World!"); //build front-end
        });
        server.on("/fetch", []() {
            if (!isFree()) return;
        });
        server.on("/send", []() {
            if (!isFree()) return;
            if (!server.hasArg("msg")) {
                server.send(400, "text", "No message");
            } else {
                server.send(200, "text", "Message received");
                handler(server.arg("msg"));
            }
        });
        server.begin();
    }

    inline void handle() {
        server.handleClient();
    }
}

#endif //TerminalBackend_h