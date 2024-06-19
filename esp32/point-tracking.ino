/*
########################
###############   Storage
########################
*/

String getMoxiePoints(String team_id)
{
  return String(preferences.getUInt(team_id.c_str(), 0));
}

void addOneMoxiePoint(String team_id)
{
  addMoxie(team_id, 1);
}

void addOneMoxiePoint(uint8_t team_id)
{
  addMoxie(String(team_id), 1);
}


void addMoxie(String team_id, uint32_t points)
{
  uint32_t newTotal = points + preferences.getUInt(team_id.c_str(), 0);
  preferences.putUInt(team_id.c_str(), newTotal);
}

void clearAllMoxiePoints()
{
  preferences.clear();
}

void clearTeam(String team_id)
{
  preferences.remove(team_id.c_str());
}

void setupPointStorage()
{
  preferences.begin("moxie points", false); // false = read/write, true = read only
}

/*
########################
###############   buttons
########################
*/

void checkForButtonPresses() {
  for (uint8_t p=0; p<8; p++) {
    if(!ioBoard0.digitalRead(p)){
      addOneMoxiePoint(p);
    }
    if(!ioBoard1.digitalRead(p)){
      addOneMoxiePoint(p + 8);
    }
    if(!ioBoard2.digitalRead(p)){
      addOneMoxiePoint(p + 16);
    }
  }
}

void setupIoExpanderBoards() {
  
  ioBoard0.begin(0x20, &Wire);
  ioBoard1.begin(0x21, &Wire);
  ioBoard2.begin(0x22, &Wire);

  for (uint8_t p=0; p<8; p++) {
    ioBoard0.pinMode(p, INPUT_PULLUP);
    ioBoard1.pinMode(p, INPUT_PULLUP);
    ioBoard2.pinMode(p, INPUT_PULLUP);
  }
}