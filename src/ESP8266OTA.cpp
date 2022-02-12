/*
    ESP8266OTA.cpp - ESP8266 OTA Library
    Created by Mai Porat.
    Released into the public domain.
*/

#include "ESP8266OTA.h"

namespace ESP8266OTA {
    /**
     * @brief Initialize ESP8266 OTA
     * 
     * @param ssid The name of the access point (Max 32 characters).
     * @param pass The password of the access point (8 - 64 characters, for an open access point, leave blank).
     * @param maxConnections Max simultaneous connected clients, 0 - 8.
     */
    void init(const char *ssid, const char *pass, const int maxConnections) {
        WiFi.softAP(ssid, pass, 1, 0, maxConnections);

        OTA::init();

        Terminal::server.on("/", []() {
            Terminal::server.send(200, "text/raw", "Hello World!"); //make front-end
        });
        Terminal::server.on("/fetch", []() {

        });
        Terminal::server.on("/send", []() {

        });
        Terminal::server.begin();
    }

    /**
     * @brief Initialize ESP8266 OTA
     * 
     * @param ssid The name of the access point (Max 32 characters).
     * @param maxConnections Max simultaneous connected clients, 0 - 8.
     */
    void init(const char *ssid, const int maxConnections) {
        init(ssid, "", maxConnections);
    }

    void handle() {
        OTA::handle();
        Terminal::server.handleClient();
    }
}