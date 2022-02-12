/*
    ESP8266OTA.cpp - ESP8266 OTA Library
    Created by Mai Porat.
    Released into the public domain.
*/

#include "ESP8266OTA.h"
#include <ESP8266WiFi.h>
#include "OTA.h"
#include "TerminalBackend.h"

namespace ESP8266OTA {
    void init(const char *ssid, const char *pass, const int maxConnections) {
        WiFi.softAP(ssid, pass, 1, 0, maxConnections);

        OTA::init();
        TerminalBackend::init();
    }

    void handle() {
        OTA::handle();
        TerminalBackend::handle();
    }
}