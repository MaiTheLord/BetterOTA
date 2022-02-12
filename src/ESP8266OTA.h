/*
    ESP8266OTA.h - ESP8266 OTA Library
    Created by Mai Porat.
    Released into the public domain.
*/

#ifndef ESP8266OTA_h
#define ESP8266OTA_h

#include <Arduino.h>
#include "Terminal.h"

namespace ESP8266OTA {
    /**
     * @brief Initialize ESP8266 OTA
     *
     * @param ssid The name of the access point (Max 32 characters).
     * @param pass The password of the access point (8 - 64 characters, for an open access point, leave blank).
     * @param maxConnections Max simultaneous connected clients, 0 - 8.
     */
    void init(const char *ssid, const char *pass = "", int maxConnections = 1);

    /**
     * @brief Initialize ESP8266 OTA
     *
     * @param ssid The name of the access point (Max 32 characters).
     * @param maxConnections Max simultaneous connected clients, 0 - 8.
     */
    inline void init(const char *ssid, const int maxConnections) {
        init(ssid, "", maxConnections);
    }

    void handle();
}

#endif //ESP8266OTA_h