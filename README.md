# ESP8266OTA
An ESP8266 Library for easy Over-The-Air code uploading and monitoring.

When using the library, the board will open a WiFi access point.

## Installation
Clone the repo into the `libraries` folder in your sketchbook. usually `Documents/Arduino/libraries`.

Make sure you have the `esp8266` board package installed.

## Usage
To use the library, call `ESP8266OTA::init()` in your `setup()` function, and `ESP8266OTA::handle()` in the `loop()`, like this:
```cpp
#include <ESP8266OTA.h>

void setup() {
    ESP8266OTA::init("SSID"); // replace "SSID" with the desired access point name.
}

void loop() {
    ESP8266OTA::handle();
}
```


- ***note:** make sure not to use `delay()`, as this might cause the ESP8266 to miss requests! use timers instead. for example:*
```cpp
#include <ESP8266OTA.h>

unsigned long timer1; // timestamp of start

void setup() {
    ESP8266OTA::init("SSID"); // replace "SSID" with the desired access point name.
    
    timer1 = millis(); // set timer1 to the current time
}

void loop() {
    ESP8266OTA::handle();
    
    if (millis() - timer1 > 1000) {
        // 1 second have passed
        // do stuff
        
        timer1 = millis(); // reset timer, so it will run again after one more second.
    }
}
```
---

### Setting a password
To set a password for the access point, just pass it as the second parameter of `init()`, like this:
```cpp
ESP8266OTA::init("SSID", "PASS");
```

## Uploading code
To upload code to the board follow these steps:
1. Connect to the board's access point.
2. In arduino IDE, choose the network port. it will be named `esp8266-______ at 192.168.4.1`.
3. Press the upload button.

## Using the terminal
To open the terminal, connect to the board's access point,
then open a browser window, and connect to this address:
`192.168.4.1:160`.

To make the board send text through the terminal,
use `Terminal::print()` or `Terminal::println()`.
to make the bot handle incoming messages, use `Terminal::setHandler()` in your `setup()` function, like this:
```cpp
#include <ESP8266OTA.h>

void setup() {
    ESP8266OTA::init("SSID");
    Terminal::setHandler([](const String& message) {
        // handle incoming messages
    });
    Terminal::println("Hello, world!");
}

void loop() {
    ESP8266OTA::handle();
}
```
