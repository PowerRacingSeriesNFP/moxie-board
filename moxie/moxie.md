
An esp8266 based points tracker + website used to track moxie points for the power racing series! This library code was developed on an ESP-WROOM-02 D1 [like these](https://www.aliexpress.us/w/wholesale-ESP%2525252dWROOM%2525252d02-18650.html?spm=a2g0o.home.search.0) and [these](https://www.amazon.com/dp/B0CJ9P7GWJJ).

I used vscode + the arduino extension + the arduino CLI. The regular arduino IDE should also work, but if you're starting from scratch Please give [https://platformio.org/](https://platformio.org/) + VSCode a chance first, it's better if you haven't already learned the arduino IDE.


## Programming the board
I have no idea, one board works the other doesn't. Maybe grounding GPIO 0 during boot turns on programming mode, which is waht the FLASH and RST pins should do but they don't change the behavior of one board as far as I can tell.
- simultaneously press `FLASH` and `RST` on the board
- release only `RST` while still holding down `FLASH`
- wait 1 second
- release `FLASH`
- upload code(?!)


## Arduino based dev setup


- [Board support library]( `http://arduino.esp8266.com/stable/package_esp8266com_index.json`)
  - choose `ESP8266_WEMOS_D1WROOM02`
- [Preferences](https://www.arduino.cc/reference/en/libraries/preferences/)
- [Task Scheduler](https://www.arduino.cc/reference/en/libraries/taskscheduler/)
- [Adafruit PCF8574](https://www.arduino.cc/reference/en/libraries/adafruit-pcf8574/)


`arduino.json` board config for vscode + arduino-cli
```json
{
    "configuration": "xtal=80,vt=flash,exception=disabled,stacksmash=disabled,ssl=all,mmu=3232,non32xfer=fast,eesz=2M64,ip=lm2f,dbg=Disabled,lvl=None____,wipe=none,baud=921600",
    "board": "esp8266:esp8266:d1_wroom_02",
    "sketch": "esp8266.ino",
    "port": "/dev/ttyUSB0",
    "output": "../arduinoOutput"
}
```