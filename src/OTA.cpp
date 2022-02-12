/*
    OTA.cpp - ESP8266 OTA Library
    Created by Mai Porat.
    Released into the public domain.
*/

#include "OTA.h"

namespace OTA {
    void init() {
        ArduinoOTA.onStart([]() {
            String type;
            if (ArduinoOTA.getCommand() == U_FLASH) type = "sketch";
            else type = "filesystem"; // U_FS

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
    }

    void handle() {
        ArduinoOTA.handle();
    }
}