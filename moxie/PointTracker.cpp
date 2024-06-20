
#include <Preferences.h>

class PointTracker
{

private:
  Preferences preferences;

  void add(String team_id, uint32_t points)
  {
    uint32_t newTotal = points + preferences.getUInt(team_id.c_str(), 0);
    preferences.putUInt(team_id.c_str(), newTotal);
  }

public:
  PointTracker()
  {
    preferences.begin("moxie points", false); // false = read/write, true = read only
  }

  String get(String team_id)
  {
    return String(preferences.getUInt(team_id.c_str(), 0));
  }

  void addOnePoint(String team_id)
  {
    add(team_id, 1);
  }

  void clear(String team_id)
  {
    preferences.remove(team_id.c_str());
  }

  void clearAll()
  {
    preferences.clear();
  }
};
