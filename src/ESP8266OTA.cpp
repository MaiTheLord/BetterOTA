/*
    ESP8266OTA.cpp - ESP8266 OTA Library
    Created by Mai Porat.
    Released into the public domain.
*/

#include "ESP8266OTA.h"
#include <ESP8266WiFi.h>
#include "ota/OTA.h"
#include "terminal/TerminalBackend.h"

void ESP8266OTA::init(const char *ssid, const char *pass, const int maxConnections) {
    WiFi.softAP(ssid, pass, 1, 0, maxConnections);

    OTA::init();
    TerminalBackend::init();
}

void ESP8266OTA::handle() {
    OTA::handle();
    TerminalBackend::handle();
}
