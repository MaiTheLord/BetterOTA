#include "BetterOTA.h"
#include "terminal/Terminal.h"
#include <ArduinoOTA.h>
#include <utility>
#include <cstdarg>
BetterOTAClass BetterOTA = BetterOTAClass::getInstance();
OTACodeUploaderClass OTACodeUploader = OTACodeUploaderClass::getInstance();
OTATerminalClass OTATerminal = OTATerminalClass::getInstance();

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

void OTATerminalClass::println(const String& str) {
    terminal->outgoing += str + "\n";
}

static int iterationCounter = 0;
static String formatBuffer;


String format() {
  iterationCounter = 0;
  return formatBuffer;
  formatBuffer = "";

}

template <typename T, typename... T2>
String format (T v1, T2... v2) {
  if (iterationCounter == 0) {
    iterationCounter++;

    formatBuffer = String(v1);

    return format(v2...);

  }
  else {
    if (formatBuffer.indexOf("%s") != -1 ) {
      int i = formatBuffer.indexOf("%s");
      String left = formatBuffer.substring(0, i);
      String right = formatBuffer.substring(i + 2, formatBuffer.length());
      formatBuffer = left + String(v1) + right;
      return format(v2...);
    }
    else
    {
      iterationCounter = 0;
      return formatBuffer;
    }



  }

}
