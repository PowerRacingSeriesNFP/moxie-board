Store moxie board points even if the power goes off! Show the points on a website.

Open this project in an arduino IDE or VSCode with arduino extension or something like that.

- Uses standard/default esp32 libraries
  - wifi
  - webserver
  - preferences for storing points even if power is lost

- IO Extension/demultiplexer: PCF8574
  - [datasheet](https://www.nxp.com/docs/en/data-sheet/PCF8574_PCF8574A.pdf)
  - using the adafruit PCF8574 arduino library
  - default i2c pins on esp32-WROOM-32
  - GPIO/D22 - SCL
  - DPIO/D21 - SDA
  - 3v3 for power


## Up next:
- AP mode
  - [tutorial](https://randomnerdtutorials.com/esp32-access-point-ap-web-server/)
- Interrupts instead of polling
  - [tutorial 1](https://circuitdigest.com/microcontroller-projects/esp32-interrupt)
  - [tutorial 2](https://learn.adafruit.com/adafruit-pcf8574/arduino)
  - "If connecting this pin, enable the internal pull-up resistor on the MCU or add an external pull-up of 10K or so." for interrupt pin from [here](https://mischianti.org/pcf8574-i2c-digital-i-o-expander-fast-easy-usage/)
  - [interrupts on gpio with arduino based esp32](https://deepbluembedded.com/esp32-external-interrupts-pins-arduino-examples/)
  - [Example code and datasheet](https://www.instructables.com/PCF8574-GPIO-Extender-With-Arduino-and-NodeMCU/)
- Debounce
  - 10-20ms
- esp8266 version
  - can't get a sketch to upload!
  - [thread scheduler library](https://github.com/bmellstrom/esp8266-arduino-threads)
  - google says preferences library exists, tbd if its a custom weird thing or standard like it is for esp32
