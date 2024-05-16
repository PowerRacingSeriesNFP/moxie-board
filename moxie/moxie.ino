/*
  Moxie Board tracking
  by Power Racing Series
*/

#include <WiFi.h>
#include <WebServer.h>
#include <Preferences.h>

WebServer server(80);
Preferences preferences;

TaskHandle_t WebServer;
TaskHandle_t MoxieBoard;

void setup()
{
  Serial.begin(115200);

  xTaskCreatePinnedToCore(runWebsite, "WebServer", 20000, NULL, 1, &WebServer, 0);
  xTaskCreatePinnedToCore(trackPoints, "MoxieBoard", 5000, NULL, 1, &MoxieBoard, 1);

  delay(500);
}

void runWebsite(void *parameter)
{

  setupWebsite();

  while (true)
  {
    handleRequests();
    delay(1000);
  }
}

void trackPoints(void *parameter)
{

  setupPointStorage();

  while (true)
  {
    printDiagnostics();
    listenForInterrupts(updateMoxieTotals);
    delay(5000);
  }
}

void printDiagnostics()
{
  Serial.println(WiFi.localIP());
  Serial.println(getMoxiePoints("1"));
}

// ignore
void loop()
{
}
