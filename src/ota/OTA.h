/*
    OTA.h - ESP8266 OTA Library
    Created by Mai Porat.
    Released into the public domain.
*/

#ifndef OTA_H
#define OTA_H

#include <Arduino.h>
#include <ArduinoOTA.h>
#include "../terminal/Terminal.h"

namespace OTA {
    inline void init() {
        ArduinoOTA.onStart([]() {
            // NOTE: if updating FS this would be the place to unmount FS using FS.end()
            Terminal::println((ArduinoOTA.getCommand() == U_FLASH) ?
                              "Started updating sketch" :
                              "Started updating filesystem");
        });

        ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
            Terminal::println(String(progress / (total / 100)) + "%");
        });

        ArduinoOTA.onEnd([]() {
            Terminal::println("\nFinished");
        });

        ArduinoOTA.onError([](ota_error_t error) {
            Terminal::println("Error " + String(error) + ": ");
            switch (error) {
                case OTA_AUTH_ERROR: Terminal::println("Auth Failed"); break;
                case OTA_BEGIN_ERROR: Terminal::println("Begin Failed"); break;
                case OTA_CONNECT_ERROR: Terminal::println("Connect Failed"); break;
                case OTA_RECEIVE_ERROR: Terminal::println("Receive Failed"); break;
                case OTA_END_ERROR: Terminal::println("End Failed"); break;
            }
        });

        ArduinoOTA.begin();
    }

    inline void handle() {
        ArduinoOTA.handle();
    }
}

#endif //OTA_H
