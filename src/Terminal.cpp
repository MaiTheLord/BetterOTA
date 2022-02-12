/*
    Terminal.cpp - ESP8266 OTA Library
    Created by Mai Porat.
    Released into the public domain.
 */

#include "Terminal.h"

namespace Terminal {
    ESP8266WebServer server(160);
    String outgoing = "";

    void print(const String str) {
        outgoing += str;
    }

    void println(const String str) {
        outgoing += str + "\n";
    }
}