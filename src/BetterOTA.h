#ifndef BETTER_OTA_H
#define BETTER_OTA_H

#ifdef ESP8266
    #include <ESP8266WiFi.h>
#elif defined(ESP32)
    #include <WiFi.h>
#else
    #error "This library only supports boards based on ESP8266 or ESP32."
#endif

#include <Arduino.h>
#include <functional>

class BetterOTAClass {
private:
    BetterOTAClass() = default;

public:
    static BetterOTAClass getInstance();

    void handle();
};

class OTACodeUploaderClass {
private:
    OTACodeUploaderClass() = default;
public:
    static OTACodeUploaderClass getInstance();

    void begin();
};

class OTATerminalClass {
private:
    OTATerminalClass() = default;
public:
    static OTATerminalClass getInstance();

    void begin(int port = 160);
    void setHandler(std::function<void(String)> handler);

    void print(const String& str);
    void println(const String& str);

    template <typename T>
    inline void print(T value) {
        print(String(value));
    }

    template <typename T>
    inline void println(T value) {
        println(String(value));
    }
};

extern BetterOTAClass BetterOTA;
extern OTACodeUploaderClass OTACodeUploader;
extern OTATerminalClass OTATerminal;

#endif //BETTER_OTA_H
