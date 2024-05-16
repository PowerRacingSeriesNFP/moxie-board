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
    delay(500);
  }
}

void trackPoints(void *parameter)
{

  setupPointStorage();

  while (true)
  {
    printDiagnostics();
    handleNewMoxiePoints(updateWebsite);
    delay(5000);
  }
}

void handleNewMoxiePoints(void (*tellWebsiteAboutNewMoxiePoints)(void))
{
  tellWebsiteAboutNewMoxiePoints();
}

void printDiagnostics()
{
  addOneMoxiePoint("test");
  Serial.println(WiFi.localIP());
  Serial.println(getMoxiePoints("test"));
}

// ignore
void loop()
{
}
