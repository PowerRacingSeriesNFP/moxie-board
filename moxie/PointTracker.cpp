
#include <Preferences.h>
#include "PointTracker.h"

PointTracker::PointTracker()
{
  preferences.begin("moxie points", false); // false = read/write, true = read only
}

void PointTracker::add(String team_id, uint32_t points)
{
  uint32_t newTotal = points + preferences.getUInt(team_id.c_str(), 0);
  preferences.putUInt(team_id.c_str(), newTotal);
}

String PointTracker::get(String team_id)
{
  return String(preferences.getUInt(team_id.c_str(), 0));
}

void PointTracker::addOnePoint(String team_id)
{
  add(team_id, 1);
}

void PointTracker::clear(String team_id)
{
  preferences.remove(team_id.c_str());
}

void PointTracker::clearAll()
{
  preferences.clear();
}
