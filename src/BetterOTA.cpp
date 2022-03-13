#include "BetterOTA.h"
#include "terminal/Terminal.h"
#include <ArduinoOTA.h>
#include <utility>

BetterOTAClass BetterOTA = BetterOTAClass::getInstance();
OTACodeUploaderClass OTACodeUploader = OTACodeUploaderClass::getInstance();
OTATerminalClass OTATerminal = OTATerminalClass::getInstance();
StrClass Str = StrClass::getInstance();

BetterOTAClass BetterOTAClass::getInstance() {
    static BetterOTAClass instance;
    return instance;
}

OTACodeUploaderClass OTACodeUploaderClass::getInstance() {
    static OTACodeUploaderClass instance;
    return instance;
}

OTATerminalClass OTATerminalClass::getInstance() {
    static OTATerminalClass instance;
    return instance;
}

StrClass StrClass::getInstance() {
    static StrClass instance;
    return instance;
}

Terminal *terminal;

void BetterOTAClass::handle() {
    ArduinoOTA.handle();
    terminal->server.handleClient();
}

void OTACodeUploaderClass::begin() {
    ArduinoOTA.onStart([]() { if (terminal->hasStarted) terminal->server.close(); });
    ArduinoOTA.begin();
}

void OTATerminalClass::begin(int port) {
    terminal = new Terminal(port);
}

void OTATerminalClass::setHandler(std::function<void(String)> handler) {
    terminal->handler = std::move(handler);
}

void OTATerminalClass::print(const String& str) {
    terminal->outgoing += str;
}
