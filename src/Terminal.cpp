/*
    Terminal.cpp - ESP8266 OTA Library
    Created by Mai Porat.
    Released into the public domain.
*/

#include "Terminal.h"

namespace Terminal {
    std::function<void(String)> handler = [](const String& str) {};
    ESP8266WebServer server(160);
    String outgoing = "";
    IPAddress currentClient;
    unsigned long lastFetch = millis() - 1000;

    void init() {
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

    void handle() {
        server.handleClient();
    }

    void onAvailable(const std::function<void(String)>& func) {
        handler = func;
    }

    void print(const String& str) {
        outgoing += str;
    }

    void println(const String& str) {
        outgoing += str + "\n";
    }
}