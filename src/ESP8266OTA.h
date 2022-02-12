/*
    ESP8266OTA.h - ESP8266 OTA Library
    Created by Mai Porat.
    Released into the public domain.
*/

#ifndef ESP8266OTA_h
#define ESP8266OTA_h

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "OTA.h"
#include "Terminal.h"

namespace ESP8266OTA {
    /**
     * @brief Initialize ESP8266 OTA
     *
     * @param ssid The name of the access point (Max 32 characters).
     * @param pass The password of the access point (8 - 64 characters, for an open access point, leave blank).
     * @param maxConnections Max simultaneous connected clients, 0 - 8.
     */
    inline void init(const char *ssid, const char *pass = "", const int maxConnections = 1) {
        WiFi.softAP(ssid, pass, 1, 0, maxConnections);

        OTA::init();
        Terminal::init();
    }

    /**
     * @brief Initialize ESP8266 OTA
     *
     * @param ssid The name of the access point (Max 32 characters).
     * @param maxConnections Max simultaneous connected clients, 0 - 8.
     */
    inline void init(const char *ssid, const int maxConnections) {
        init(ssid, "", maxConnections);
    }

    inline void handle() {
        OTA::handle();
        Terminal::handle();
    }
}

#endif //ESP8266OTA_h