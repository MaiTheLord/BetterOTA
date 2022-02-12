/*
    OTA.h - ESP8266 OTA Library
    Created by Mai Porat.
    Released into the public domain.
*/

#ifndef OTA_H
#define OTA_H

#include <Arduino.h>
#include <ArduinoOTA.h>

namespace OTA {
    void init();
    void handle();
}

#endif //OTA_H
