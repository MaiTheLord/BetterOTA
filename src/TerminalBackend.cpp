/*
    TerminalBackend.cpp - ESP8266 OTA Library
    Created by Mai Porat.
    Released into the public domain.
*/

#include "TerminalBackend.h"
#include "frontend/terminal/generated/index.h"
#include "frontend/terminal/generated/style.h"
#include "frontend/terminal/generated/script.h"

IPAddress currentClient;
unsigned long lastFetch = 0;

bool isFree() {
    if (currentClient == TerminalBackend::server.client().remoteIP() || millis() - lastFetch > 1000) {
        lastFetch = millis();
        currentClient = TerminalBackend::server.client().remoteIP();
        return true;
    } else {
        TerminalBackend::server.send(503, "text", "Another client is currently connected");
        return false;
    }
}

void TerminalBackend::init() {
    server.on("/", HTTP_GET, []() {
        if (!isFree()) return;
        server.send(200, "text/html", INDEX_HTML);
    });
    server.on("/style.css", HTTP_GET, []() {
        if (!isFree()) return;
        server.send(200, "text/css", STYLE_CSS);
    });
    server.on("/script.js", HTTP_GET, []() {
        if (!isFree()) return;
        server.send(200, "application/javascript", SCRIPT_JS);
    });

    server.on("/fetch", HTTP_GET, []() {
        if (!isFree()) return;
        if (outgoing == "") {
            server.send(204, "text/plain", "Already up to date");
        }
        server.send(200, "text/strings", outgoing);
        outgoing = "";
    });
    server.on("/send", HTTP_GET, []() {
        if (!isFree()) return;
        if (!server.hasArg("msg")) {
            server.send(400, "text/plain", "No message");
        } else {
            server.send(202, "text/plain", "Message received");
            handler(server.arg("msg"));
        }
    });
    server.begin();
}