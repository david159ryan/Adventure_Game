#ifndef LOCATIONMANAGER_H
#define LOCATIONMANAGER_H
#include "location.h"
#include "utility/eventmanager.h"
#include <vector>

using namespace std;

class LocationManager
{
private:
    Location * currentLocation_;
    vector<Location*> locations_;
    map<string, list<Updateable*>> events;

public:
    LocationManager();

    void AddLocation(Location *location);
    Location * GetCurrentLocation();
    void GoToLocation(string locationName);
};

#endif // LOCATIONMANAGER_H
