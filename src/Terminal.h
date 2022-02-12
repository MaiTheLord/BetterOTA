/*
    Terminal.h - ESP8266 OTA Library
    Created by Mai Porat.
    Released into the public domain.
 */

#ifndef Terminal_h
#define Terminal_h

#include <Arduino.h>
#include <ESP8266WebServer.h>

namespace Terminal {
    extern ESP8266WebServer server;
    extern String outgoing;

    void print(String str);
    void println(String str);
}

#endif