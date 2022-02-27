# BetterOTA
Easy to use Over The Air Code Uploading and OTATerminal for the ESP8266 and ESP32.

This library allows you to easily upload code to the ESP8266 or ESP32 over the air, as well as communicate with it on a terminal over an `HTTP` port.

The Code Uploading is designed to be used with the Arduino IDE built-in OTA feature.

## Installation
Clone the repo into the `libraries` folder in your sketchbook. usually `Documents/Arduino/libraries`.

Make sure you have the `esp8266` board package installed if using the ESP8266, or the `esp32` board package installed if using the ESP32.

## Usage
```cpp
#include <BetterOTA.h>

void setup() {
    WiFi.softAP("SSID", "password"); // recommended way to create an access point.
    OTACodeUploader.begin(); // call this method if you want the code uploader to work
    OTATerminal.begin(); // call this method if you want the terminal to work
}

void loop() {
    BetterOTA.handle(); // required
}
```

- ***note:** make sure not to use `delay()`, as this might cause the board to miss requests! use timers instead. for example:*
```cpp
#include <BetterOTA.h>

unsigned long timer1; // timestamp of start

void setup() {
    WiFi.softAP("SSID", "password");
    OTACodeUploader.begin();
    OTATerminal.begin();
    
    timer1 = millis();
}

void loop() {
    BetterOTA.handle();
    
    if (millis() - timer1 > 1000) {
        // 1 second have passed
        // do stuff
        
        timer1 = millis(); // reset timer, so it will run again after one more second.
    }
}
```
---

## Uploading code
To upload code to the board follow these steps:
1. Connect to the board's access point.
2. In arduino IDE, choose the network port. it will be named `* at 192.168.4.1`.
3. Press the upload button.

## Using the terminal
To open the terminal, connect to the board's access point,
then open a browser window, and connect to this address:
`192.168.4.1:160`.

You can change the terminal port by passing the desired port number as an argument to `OTATerminal.begin()`.

To make the board send text through the terminal,
use `OTATerminal.println()` or `OTATerminal.print()`.

to make the bot handle incoming messages, use `OTATerminal::setHandler()` in your `setup()` function, like this:
```cpp
#include <BetterOTA.h>

void setup() {
    WiFi.softAP("SSID", "password");
    OTACodeUploader.begin();
    OTATerminal.begin();
    
    OTATerminal::setHandler([](const String& message) {
        // handle incoming messages, for example:
        OTATerminal.println("Got a message: " + message);
    });
}

void loop() {
    BetterOTA.handle();
}
```
