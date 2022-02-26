#include "EZ_ESP_OTA.h"
#include <ESP8266WiFi.h>
#include "ota/OTA.h"
#include "terminal/TerminalBackend.h"

void EZ_ESP_OTA::init(const char *ssid, const char *pass, const int maxConnections) {
    WiFi.softAP(ssid, pass, 1, 0, maxConnections);

    OTA::init();
    TerminalBackend::init();
}

void EZ_ESP_OTA::handle() {
    OTA::handle();
    TerminalBackend::handle();
}
