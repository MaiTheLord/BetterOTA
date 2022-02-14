/*
    TerminalBackend.h - ESP8266 OTA Library
    Created by Mai Porat.
    Released into the public domain.
*/

#ifndef TERMINAL_BACKEND_h
#define TERMINAL_BACKEND_h

#include <Arduino.h>
#include <ESP8266WebServer.h>

namespace TerminalBackend {
    inline std::function<void(String)> handler = [](const String& str) {};
    inline ESP8266WebServer server(160);
    inline String outgoing = "";

    bool isFree();

    inline void init() {
        server.on("/", HTTP_GET, []() {
            if (!isFree()) return;
            server.send(200, "text/html", "");
        });
        server.on("/style.css", HTTP_GET, []() {
            if (!isFree()) return;
            server.send(200, "text/css", "");
        });
        server.on("/script.js", HTTP_GET, []() {
            if (!isFree()) return;
            server.send(200, "application/javascript", "");
        });

        server.on("/fetch", HTTP_GET, []() {
            if (!isFree()) return;
            if (outgoing == "") {
                server.send(204, "text/plain", "Already up to date");
            }
            server.send(200, "text/strings", outgoing);
            outgoing = "";
        });
        server.on("/send", HTTP_GET, []() {
            if (!isFree()) return;
            if (!server.hasArg("msg")) {
                server.send(400, "text/plain", "No message");
            } else {
                server.send(202, "text/plain", "Message received");
                handler(server.arg("msg"));
            }
        });
        server.begin();
    }

    inline void handle() {
        server.handleClient();
    }
}

#endif //TERMINAL_BACKEND_h