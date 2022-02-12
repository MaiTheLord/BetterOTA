/*
    ESP8266OTA.h - ESP8266 OTA Library
    Created by Mai Porat.
    Released into the public domain.
*/

#ifndef ESP8266OTA_h
#define ESP8266OTA_h

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>
#include "Terminal.h"

namespace ESP8266OTA {
    void init(const char *ssid, const char *pass = "", int maxConnections = 1);
    void init(const char *ssid, int maxConnections);
    void handle();
}

#endif