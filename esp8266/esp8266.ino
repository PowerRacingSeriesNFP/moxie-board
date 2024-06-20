/*
  Moxie Board
  by Power Racing Series
*/

#include "Points.h"

void setup() {
  Serial.begin(115200);

  setupPointStorage();
  // setupIoExpanderBoards();
  delay(1000);
}

void loop() {
  
  printDiagnostics();
  delay(1000);
}

void printDiagnostics(){
    addOneMoxiePoint("test");
    Serial.println("team test has:");
    Serial.println(getMoxiePoints("test"));

    Serial.println("team 0 has:");
    Serial.println(getMoxiePoints("0"));
}