Store moxie board points even if the power goes off! Show the points on a website.

Open this project in an arduino IDE or VSCode with arduino extension or something like that.

- Uses standard/default esp32 libraries
  - wifi
  - webserver
  - preferences for storing points even if power is lost

- IO Extension/demultiplexer: PCF8574
  - using the adafruit PCF8574 arduino library
  - default i2c pins on esp32-WROOM-32
  - GPIO/D22 - SCL
  - DPIO/D21 - SDA
  - 3v3 for power

