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

TaskHandle_t WebServer;
TaskHandle_t MoxieBoard;

void setup()
{
  Serial.begin(115200);

  delay(100);
  // xTaskCreatePinnedToCore(runWebsite, "WebServer", 32768, NULL, 2, &WebServer, 0);
  xTaskCreatePinnedToCore(trackPoints, "MoxieBoard", 8192, NULL, 3, &MoxieBoard, 1);

  // vTaskStartScheduler();

  for( ;; ){}
}

void runWebsite(void *parameter)
{

  setupWebsite();

  while(true)
  {
    Serial.println("website task");
    // handleRequests();
    delay(1000);
  }
}

void trackPoints(void *parameter)
{

  setupPointStorage();
  setupIoExpanderBoards();
  
  while(true)
  {
    Serial.println("points task");
    checkForButtonPresses();
    printDiagnostics();
    delay(1000);
  }
}

void printDiagnostics(){
    addOneMoxiePoint("test");
    Serial.println("team test has:");
    Serial.println(getMoxiePoints("test"));

    Serial.println("team 0 has:");
    Serial.println(getMoxiePoints("0"));
}

// ignore
void loop(){}
