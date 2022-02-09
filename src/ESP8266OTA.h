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

namespace ESP8266OTA {
    void init(const char *ssid, const char *pass = "", const int serialBaud = 115200);
    void init(const char *ssid, const int serialBaud = 115200);
    void handle();
}

#endif