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

  printDiagnostics();
  delay(1000);
}

void printDiagnostics(){
    tracker.addOnePoint("0");
    
    Serial.print("team 0: ");
    Serial.println(tracker.get("0"));
}