/*
  Moxie Board tracking
  by Power Racing Series
*/

#include <WiFi.h>
#include <WebServer.h>
#include <Preferences.h>
#include <Adafruit_PCF8574.h>

WebServer server(80);
Preferences preferences;
Adafruit_PCF8574 ioBoard0;
Adafruit_PCF8574 ioBoard1;
Adafruit_PCF8574 ioBoard2;
Adafruit_PCF8574 ioBoard3;

TaskHandle_t WebServer;
TaskHandle_t MoxieBoard;

void setup()
{
  Serial.begin(115200);

  delay(100);

  xTaskCreatePinnedToCore(runWebsite, "WebServer", 20000, NULL, 1, &WebServer, 0);
  xTaskCreatePinnedToCore(trackPoints, "MoxieBoard", 5000, NULL, 1, &MoxieBoard, 1);

  delay(500);
}

void runWebsite(void *parameter)
{

  setupWebsite();

  while (true)
  {
    printDiagnostics();
    handleRequests();
    delay(5000);
  }
}

void trackPoints(void *parameter)
{

  setupPointStorage();
  setupIoExpanderBoards();
  
  while (true)
  {
    checkForButtonPresses();
    delay(100);
  }
}

void printDiagnostics()
{
  Serial.println(WiFi.localIP());
  addOneMoxiePoint("test");
  Serial.println(getMoxiePoints("test"));
}

// ignore
void loop()
{
}
