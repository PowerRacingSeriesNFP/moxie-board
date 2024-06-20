#include <Preferences.h>

String getMoxiePoints(String team_id);
void addOneMoxiePoint(String team_id);
void addOneMoxiePoint(uint8_t team_id);
void addMoxie(String team_id, uint32_t points);
void clearAllMoxiePoints();
void clearTeam(String team_id);
void setupPointStorage();
void checkForButtonPresses();
void setupIoExpanderBoards();