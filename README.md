# BetterOTA
Easy to use Over-The-Air Code Uploading and Terminal for the ESP8266 and ESP32.

This library allows you to easily upload code to the ESP8266 or ESP32 over the air, as well as communicate with it on a terminal over an `HTTP` port.

The Code Uploading is designed to be used with the Arduino IDE built-in OTA feature.

## Installation
You can install the library using the built-in Library Manager in the Arduino IDE.

You can also manually install the library by putting it's folder in the `libraries` folder in your sketchbook. usually `Documents/Arduino/libraries`.

Either way, make sure you have the `esp8266` board package installed if using the ESP8266, or the `esp32` board package installed if using the ESP32.

## Features
- Over-The-Air Code Uploading


- Over-The-Air Terminal


- String format function

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
2. In arduino IDE, choose the network port. it will probably be named `* at 192.168.4.1`.
3. Press the upload button.

## Using the terminal
To open the terminal, connect to the board's access point,
then open a browser window, and connect to this address:
`192.168.4.1:160`.

You can change the terminal port by passing the desired port number as an argument to `OTATerminal.begin()`.

To make the board send text through the terminal, you can use the following functions:
- `OTATerminal.print("Hello, World!")` prints text to the terminal


- `OTATerminal.println("Hello, World!")` prints text to the terminal, with a newline afterwards.


- `OTATerminal.printf("Hello, %s!", "World")` prints text to the terminal, with the format function built into it.


- `OTATerminal.printlnf("Hello, %s!", "World")` prints text to the terminal, with the format function built into it, with a newline afterwards.

**note: `print()` and `printf()` doesn't print a newline!*

**note: for more information regarding `printf()` and `printlnf()`, see [this](#using-the-format-function).*

to make the bot handle incoming messages, use `OTATerminal.setHandler()` in your `setup()` function, like this:
```cpp
#include <BetterOTA.h>

void setup() {
    WiFi.softAP("SSID", "password");
    OTACodeUploader.begin();
    OTATerminal.begin();
    
    OTATerminal.setHandler([](const String& message) {
        // handle incoming messages, for example:
        OTATerminal.printlnf("Got a message: %s", message);
    });
}

void loop() {
    BetterOTA.handle();
}
```
## Using the format function
To format a string, use the `Str.format()` function.
```cpp
Str.format("Hello %s! My favorite number is %d", "World", 42); // returns "Hello World! My favorite number is 42"
```
you can use the `%s` and `%d` format specifiers.

**note: both `%s` and `%d` function the same way.*
