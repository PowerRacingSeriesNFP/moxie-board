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