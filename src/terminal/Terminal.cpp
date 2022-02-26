#include "Terminal.h"
#include "TerminalBackend.h"
#include <utility>

void Terminal::setHandler(std::function<void(String)> handler) {
    TerminalBackend::handler = std::move(handler);
}

void Terminal::print(const String& str) {
    TerminalBackend::outgoing += str;
}

void Terminal::println(const String& str) {
    TerminalBackend::outgoing += str + "\n";
}
