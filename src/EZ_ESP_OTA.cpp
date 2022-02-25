#include "EZ_ESP_OTA.h"
#include "ota/OTA.h"
#include "terminal/TerminalBackend.h"

#ifdef ESP8266
    #include <ESP8266WiFi.h>
#elif defined(ESP32)
    #include <WiFi.h>
#endif

void EZ_ESP_OTA::init(const char *ssid, const char *pass, const int maxConnections) {
    WiFi.softAP(ssid, pass, 1, 0, maxConnections);

    OTA::init();
    TerminalBackend::init();
}

void EZ_ESP_OTA::handle() {
    OTA::handle();
    TerminalBackend::handle();
}
