/*
    TerminalBackend.cpp - ESP8266 OTA Library
    Created by Mai Porat.
    Released into the public domain.
*/

#include "TerminalBackend.h"

IPAddress currentClient;
unsigned long lastFetch = 0;

bool TerminalBackend::isFree() {
    if (currentClient == server.client().remoteIP() || millis() - lastFetch > 1000) {
        lastFetch = millis();
        currentClient = server.client().remoteIP();
        return true;
    } else {
        server.send(503, "text", "Another client is currently connected");
        return false;
    }
}