/*
  Moxie Board
  by Power Racing Series
*/

#include "PointTracker.h"

PointTracker tracker;

void setup()
{
  Serial.begin(115200);
  delay(1000);
}

void loop()
{

  // printDiagnostics();
  tracker.get("0");
  delay(1000);
}

// void printDiagnostics(){
//     tracker.addOnePoint("test");
//     Serial.println("team test has:");
//     Serial.println(tracker.get("test"));

//     Serial.println("team 0 has:");
//     Serial.println(tracker.get("0"));
// }