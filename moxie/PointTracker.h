#include <Preferences.h>

class PointTracker
{
private:
    Preferences preferences;
    void add(String team_id, uint32_t points);

public:
    PointTracker();
    String get(String team_id);
    void addOnePoint(String team_id);
    void clear(String team_id);
    void clearAll();
};