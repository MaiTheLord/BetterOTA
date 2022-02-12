/*
    Terminal.cpp - ESP8266 OTA Library
    Created by Mai Porat.
    Released into the public domain.
*/

#include "Terminal.h"

namespace Terminal {
    ESP8266WebServer server(160);
    String outgoing = "";

    void init() {
        server.on("/", []() {
            server.send(200, "text/raw", "Hello World!"); //make front-end
        });
        server.on("/fetch", []() {

        });
        server.on("/send", []() {

        });
        server.begin();
    }

    void handle() {
        server.handleClient();
    }

    void print(const String str) {
        outgoing += str;
    }

    void println(const String str) {
        outgoing += str + "\n";
    }
}