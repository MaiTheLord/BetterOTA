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
#include "../terminal/TerminalBackend.h"

namespace OTA {
    inline void init() {
        ArduinoOTA.onStart([]() {
            // NOTE: if updating FS this would be the place to unmount FS using FS.end()
            TerminalBackend::server.close();
        });

        ArduinoOTA.begin();
    }

    inline void handle() {
        ArduinoOTA.handle();
    }
}

#endif //OTA_H
