/*
  Moxie Board
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

TaskHandle_t serverTask;
TaskHandle_t pointsTask;

void setup()
{
  Serial.begin(115200);

  delay(100);
  xTaskCreatePinnedToCore(runWebsite, "serverTask", 32768, NULL, 2, &serverTask, 0);
  xTaskCreatePinnedToCore(trackPoints, "pointsTask", 8192, NULL, 3, &pointsTask, 1);


  for( ;; ){}
}

void runWebsite(void *parameter)
{

  setupWebsite();

  while(true)
  {
    printDiagnostics();
    handleRequests();
    delay(1000);
  }
}

void trackPoints(void *parameter)
{

  setupPointStorage();
  setupIoExpanderBoards();
  
  while(true)
  {
    checkForButtonPresses();
    delay(100);
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
