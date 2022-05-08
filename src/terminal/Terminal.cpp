#include "Terminal.h"
#include "TerminalFrontend.h"

Terminal::Terminal(int port) : server{port} {
    hasStarted = true;

    server.on("/", HTTP_GET, [this]() {
        if (!isFree()) return;
        server.send(200, "text/html", INDEX_HTML);
    });

    server.on("/style.css", HTTP_GET, [this]() {
        if (!isFree()) return;
        server.send(200, "text/css", STYLE_CSS);
    });

    server.on("/script.js", HTTP_GET, [this]() {
        if (!isFree()) return;
        server.send(200, "application/javascript", SCRIPT_JS);
    });

    server.on("/fetch", HTTP_GET, [this]() {
        if (!isFree()) return;
        if (outgoing == "") {
            server.send(204, "text/plain", "Already up to date");
        } else {
            server.send(200, "text/strings", outgoing);
            outgoing = "";
        }
    });

    server.on("/send", HTTP_POST, [this]() {
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

bool Terminal::isFree() {
    if (currentClient == server.client().remoteIP() || millis() - lastFetch > 1000) {
        if (millis() - lastFetch > 5000) outgoing = "";

        lastFetch = millis();
        currentClient = server.client().remoteIP();
        return true;
    } else {
        server.send(503, "text", "Another client is currently connected");
        return false;
    }
}
