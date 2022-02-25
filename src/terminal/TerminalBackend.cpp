#include "TerminalBackend.h"
#include "frontend/index.h"
#include "frontend/style.h"
#include "frontend/script.h"

IPAddress currentClient; //TODO verify if this will work with ESP32 API
unsigned long lastFetch = 0;

bool isFree() {
    if (currentClient == TerminalBackend::server.client().remoteIP() || millis() - lastFetch > 1000) { //TODO verify if this will work with ESP32 API
        lastFetch = millis();
        currentClient = TerminalBackend::server.client().remoteIP(); //TODO verify if this will work with ESP32 API
        return true;
    } else {
        TerminalBackend::server.send(503, "text", "Another client is currently connected"); //TODO verify if this will work with ESP32 API
        return false;
    }
}

void TerminalBackend::init() {
    server.on("/", HTTP_GET, []() { //TODO verify if this will work with ESP32 API
        if (!isFree()) return;
        server.send(200, "text/html", INDEX_HTML);
    });

    server.on("/style.css", HTTP_GET, []() { //TODO verify if this will work with ESP32 API
        if (!isFree()) return;
        server.send(200, "text/css", STYLE_CSS);
    });

    server.on("/script.js", HTTP_GET, []() { //TODO verify if this will work with ESP32 API
        if (!isFree()) return;
        server.send(200, "application/javascript", SCRIPT_JS);
    });

    server.on("/fetch", HTTP_GET, []() { //TODO verify if this will work with ESP32 API
        if (!isFree()) return;
        if (outgoing == "") {
            server.send(204, "text/plain", "Already up to date");
        } else {
            server.send(200, "text/strings", outgoing);
            outgoing = "";
        }
    });

    server.on("/send", HTTP_POST, []() { //TODO verify if this will work with ESP32 API
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
