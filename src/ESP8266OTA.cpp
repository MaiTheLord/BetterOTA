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

        ArduinoOTA.onStart([]() {
            String type;
            if (ArduinoOTA.getCommand() == U_FLASH) type = "sketch";
            else type = "filesystem"; // U_FS

            if (Serial.available()) {
                if (Serial.baudRate() != 115200) Serial.updateBaudRate(115200);
            } else Serial.begin(115200);

            // NOTE: if updating FS this would be the place to unmount FS using FS.end()
            Serial.println("Start updating " + type);
        });

        ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
            Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
        });

        ArduinoOTA.onEnd([]() {
            Serial.println("\nEnd");
        });

        ArduinoOTA.onError([](ota_error_t error) {
            Serial.printf("Error[%u]: ", error);
            switch (error) {
                case OTA_AUTH_ERROR: Serial.println("Auth Failed"); break;
                case OTA_BEGIN_ERROR: Serial.println("Begin Failed"); break;
                case OTA_CONNECT_ERROR: Serial.println("Connect Failed"); break;
                case OTA_RECEIVE_ERROR: Serial.println("Receive Failed"); break;
                case OTA_END_ERROR: Serial.println("End Failed"); break;
            }
        });

        ArduinoOTA.begin();

        Terminal::server.on("/", []() {Terminal::server.send(200, "text/raw", "Hello World!");});
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
        ArduinoOTA.handle();
        Terminal::server.handleClient();
    }
}