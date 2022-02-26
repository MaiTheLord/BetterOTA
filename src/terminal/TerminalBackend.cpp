#include "TerminalBackend.h"
#include "frontend/index.h"
#include "frontend/style.h"
#include "frontend/script.h"

IPAddress currentClient; //TODO make sure ESP32 supports this
unsigned long lastFetch = 0;

bool isFree() {
    if (currentClient == TerminalBackend::server.client().remoteIP() || millis() - lastFetch > 1000) { //TODO find replacement for ESP32
        lastFetch = millis();
        currentClient = TerminalBackend::server.client().remoteIP(); //TODO find replacement for ESP32
        return true;
    } else {
        TerminalBackend::server.send(503, "text", "Another client is currently connected"); //TODO find replacement for ESP32
        return false;
    }
}

void TerminalBackend::init() {
    server.on("/", HTTP_GET, []() { //TODO find replacement for ESP32
        if (!isFree()) return;
        server.send(200, "text/html", INDEX_HTML);
    });

    server.on("/style.css", HTTP_GET, []() { //TODO find replacement for ESP32
        if (!isFree()) return;
        server.send(200, "text/css", STYLE_CSS);
    });

    server.on("/script.js", HTTP_GET, []() { //TODO find replacement for ESP32
        if (!isFree()) return;
        server.send(200, "application/javascript", SCRIPT_JS);
    });

    server.on("/fetch", HTTP_GET, []() { //TODO find replacement for ESP32
        if (!isFree()) return;
        if (outgoing == "") {
            server.send(204, "text/plain", "Already up to date");
        } else {
            server.send(200, "text/strings", outgoing);
            outgoing = "";
        }
    });

    server.on("/send", HTTP_POST, []() { //TODO find replacement for ESP32
        if (!isFree()) return;
        if (server.args() == 0) {
            server.send(400, "text/plain", "No message");
        } else {
            server.send(202, "text/plain", "Message received");
            handler(server.arg(0));
        }
    });

    server.begin();
}
